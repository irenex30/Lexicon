#include <iostream>
#include <fstream> 
#include "Actions.h"
#pragma warning(disable : 4996)

	
int main(int argc, const char* argv[]) {
	int indice_joueur;
	//sscanf(argv[1], "%d", indice_joueur);
	indice_joueur = atoi(argv[1]);

	cout << "(Commandes valides : TEPRC)" << endl << endl;

	joueur participants[Max_nb_joueurs]; 
	intialisation(indice_joueur, participants); //Création des joueurs et initialisation

	bool verif1 = true; //Vérificateur pour savoir si une personne n'a plus de cartes.
	bool verif2 = true; //Vérificateur pour savoir s'il reste seulement une personne.

	int compteur1 = 1; //Compteur pour le joueur devant jouer en premier au tour.
	int pas_plateau = 2;

	while (verif2) {
		Paquet_De_Cartes pack;
		ifstream Fichier;
		Fichier.open("Cartes.txt", ios::in);
		initialiser(Fichier, pack);
		Fichier.close();
		melanger(pack); // Création , initialisation et mélange d'un paquet de cartes de 51 cartes.

		Pile talon; 
		Pile exposee;

		Liste plateau;
		initialiserliste(plateau, Max_nb_carte, pas_plateau); // Initialisation de la liste dynamique des mots posés. 

		commmencement(talon, exposee, pack, participants, indice_joueur); // Commencement de la partie : initialisation et mise en commun des éléments pour débuter la partie.

		verif1 = true;

		while (verif1) { // Boucle de verification pour savir si une personne n'a plus de cartes.
			for (unsigned int i = 0; i < indice_joueur; i++) {
				int affichage = (compteur1 + i) % indice_joueur; // Systeme pour choisir le joueur qui joue 
				if (affichage == 0) affichage = indice_joueur;

				if (participants[affichage - 1].vivant == 1) { // Condition laissant seulement les joueurs devant jouer. 
					On_joue(participants, exposee, talon, &plateau, affichage); // Fait jouer le joueur. 

					if (estVide(talon)) { // Remplissage du talon si il est vide. 

						Paquet_De_Cartes tempo;
						initialiser_vide(tempo); // Initialise un paquet de cartes vide.

						for (int i = 0; !estVide(exposee); i++) {
							tempo.paquet[i] = sommet(exposee);
							depiler(exposee);
						}

						melanger(tempo);

						for (int y = 0; y < nb_cartes; y++) {
							if (tempo.paquet[y].lettre != -1) {
								empiler(talon, tempo.paquet[y]);
							}
						}
					}


					if (compte_cartes(participants, affichage)) { // Verification des cartes du joueurs si il en a 0.
						verif1 = false;
						break;
					}
				}				
			}
		}
		cout << endl;
		compteur1 = (compteur1 % indice_joueur) + 1; // Systeme pour choisir le joueur qui joue 

		fin_de_tour(participants, exposee, talon, &plateau); //Manipulation de fin de tour. 

		affichage_fin(participants); //Affichage score des joueurs jouant. 

		compter_joueur(participants, &verif2); //Comptage des joueurs encore en partie.
	}

	cout << "La partie est finie";
}