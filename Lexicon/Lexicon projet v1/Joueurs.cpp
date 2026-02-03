#include "Joueurs.h"

void intialisation(int nb_jouers, joueur* participants) {
	for (int i = 0; i < Max_nb_joueurs; ++i) { // Initialisation de tous les joueurs à l'état de non-joueurs
		participants[i].numero = -1;
		participants[i].score = -1;
		participants[i].vivant = -1;
	}
	for (int i = 0; i < nb_jouers ; i++) // Initilisation de tous les joueurs devant jouer 
	{
		participants[i].numero = i + 1;
		participants[i].score = 0;
		participants[i].vivant = 1;
	}
}

void pioche_debut(joueur* participants, int nb_joueurs, Pile& talon) {
	for (int i = 0; i < nb_joueurs; i++) {
		if (participants[i].vivant == 1) {
			for (int y = 0; y < Max_nb_carte; y++) {
				participants[i].main[y] = sommet(talon);
				depiler(talon);
			}
		}
	}
}

bool compte_cartes(joueur* participants, int nb_joueurs) {
	for (int i = 0; i < Max_nb_carte; i++) {
		if (participants[nb_joueurs - 1].main[i].lettre != -1) {
			return false;
		}
	}
	return true;
}

void compte_point(joueur* participants) {
	for (int i = 0; i < Max_nb_joueurs; i++) {
		if (participants[i].vivant == 1) {
			for (int y = 0; y < Max_nb_carte; y++) {
				if (participants[i].main[y].lettre != -1) {
					participants[i].score = participants[i].score + participants[i].main[y].nb_points;
					participants[i].main[y].nb_points = -1;
					participants[i].main[y].lettre = -1;
				}
			}
		}
	}
}

void compter_joueur(joueur* participants, bool* verif_ext) {
	int compteur = 0;

	for (unsigned int i = 0; i < Max_nb_joueurs; i++) {
		if (participants[i].vivant == 1) {
			compteur++;
		}
	}

	if (compteur > 1) {
		*verif_ext = true;
	}
	else {
		*verif_ext = false;
	}
}