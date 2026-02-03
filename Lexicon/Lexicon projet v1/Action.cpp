#include "Actions.h"

#pragma warning(disable : 4996)

void commmencement(Pile& talon, Pile& exposee, Paquet_De_Cartes& pack, joueur* participants, int nb_joueurs) {
	initialise(talon, nb_cartes); // Initialisation de la liste talon.
	initialise(exposee, nb_cartes); // Initialisation de la liste exposee.
	creation(talon, pack); // Creation du talon
	empiler(exposee, sommet(talon)); // Prise de la première carte du talon pour la mettre sur l'exposée.
	depiler(talon);
	pioche_debut(participants, nb_joueurs, talon); // Distribution des cartes aux joueurs. 
}

void T(joueur* participants, int num_joueur, Pile& exposee, Pile& talon, bool* verif_ext , char lettre1[nb_max_mot]) {
	bool verif = false;
	int indic = 0;
	char lettre;
	if (strlen(lettre1) > 1) {
		*verif_ext = true;
		cout << "Coup invalide, recommensez " << endl;
		return;
	}
	lettre = lettre1[0];
	for (int i = 0; i < Max_nb_carte; i++) {
		if (participants[num_joueur - 1].main[i].lettre == lettre) {
			verif = true;
			indic = i;
		}
	}
	Carte save;
	if (verif) {
		empiler(exposee, participants[num_joueur - 1].main[indic]);
		save = sommet(talon);
		depiler(talon);
		participants[num_joueur - 1].main[indic] = save;
		*verif_ext = false;
	}
	else
	{
		cout << "Coup invalide, recommensez " << endl;
		*verif_ext = true;
	}
}

void E(joueur* participants, int num_joueur, Pile& exposee, bool* verif_ext, char lettre1[nb_max_mot]) {
	bool verif = false;
	int indic = 0;
	char lettre;
	if (strlen(lettre1) > 1) {
		*verif_ext = true;
		cout << "Coup invalide, recommensez " << endl;
		return;
	}
	lettre = lettre1[0];
	for (int i = 0; i < Max_nb_carte; i++) {
		if (participants[num_joueur - 1].main[i].lettre == lettre) {
			verif = true;
			indic = i;
		}
	}
	Carte save;
	if (verif) {
		save = sommet(exposee);
		depiler(exposee);
		empiler(exposee, participants[num_joueur - 1].main[indic]);
		participants[num_joueur - 1].main[indic] = save;
		*verif_ext = false;
	}
	else
	{
		cout << "Coup invalide, recommensez " << endl;
		*verif_ext = true;
	}
}

bool verifierMotDansDictionnaire(char* mot) {
	char ligne[nb_max_mot];
	std::ifstream dico("dico.txt");
	while (dico.getline(ligne, sizeof(ligne))) {
		if (strcmp(ligne, mot) == 0) {
			dico.close();
			return true;
		}
	}
	dico.close();
	return false;
}

void P(joueur* participants, int num_joueur, Liste* plateau, bool* verif_ext, char mot[nb_max_mot]) {
	int longeur = strlen(mot);
	for (int i = 0; i < longeur; ++i) {
		// Vérifie si le caractère est une lettre minuscule (a-z)
		if (mot[i] >= 'a' && mot[i] <= 'z') {
			// Convertit en majuscule en soustrayant la différence entre 'a' et 'A'
			mot[i] = mot[i] - ('a' - 'A');
		}
	}
	bool verif = false;
	Carte save_main[Max_nb_carte];
	for (int i = 0; i < Max_nb_carte; i++) {
		save_main[i].lettre = participants[num_joueur - 1].main[i].lettre;
		save_main[i].nb_points = participants[num_joueur - 1].main[i].nb_points;
	}
	for (int i = 0; i < longeur; i++) {
		verif = false;
		for (int y = 0; y < Max_nb_carte; y++) {
			if (save_main[y].lettre != -1) {
				if (save_main[y].lettre == mot[i]) {
					verif = true;
					save_main[y].lettre = -1;
					break;
				}
			}
		}
		if (!verif)
		{
			cout << "Coup invalide, recommensez " << endl;
			*verif_ext = true;
			return;
		}
	}
	if (!verifierMotDansDictionnaire(mot)) {
		cout << "Mot invalide, vous passez votre tour" << endl;
		participants[num_joueur - 1].score += 3;
		*verif_ext = false;
		return;
	}
	Pile pack;
	initialise(pack, Max_nb_carte);
	for (int i = 0; i < longeur; i++) {
		for (int y = 0; y < Max_nb_carte; y++) {
			if (participants[num_joueur - 1].main[y].lettre != -1) {
				if (participants[num_joueur - 1].main[y].lettre == mot[i]) {
					empiler(pack, participants[num_joueur - 1].main[y]);
					participants[num_joueur - 1].main[y].lettre = -1;
					participants[num_joueur - 1].main[y].nb_points = -1;
					break;
				}
			}
		}
	}
	inserer(*plateau, plateau->nb, pack);
	*verif_ext = false;
}

void affichage_jeux(int num_joueur, joueur* participants, Pile& exposee, Pile& talon, Liste* plateau) {
	cout << "* Joueur " << num_joueur << " (" << sommet(exposee).lettre << ") : ";
	for (unsigned int i = 0; i < Max_nb_carte; i++) {
		if (participants[num_joueur - 1].main[i].lettre != -1) {
			cout << participants[num_joueur - 1].main[i].lettre;
		}
	}
	cout << endl;
	affichageliste(*plateau); // Affichage ddes mots posés.
}

void R(Liste* plateau, joueur* participants, int num_joueur, bool* verif_ext, char saisie2[nb_max_mot], char mot[nb_max_mot]) {
	int longeur = strlen(mot);
	for (int i = 0; i < longeur; ++i) {
		// Vérifie si le caractère est une lettre minuscule (a-z)
		if (mot[i] >= 'a' && mot[i] <= 'z') {
			// Convertit en majuscule en soustrayant la différence entre 'a' et 'A'
			mot[i] = mot[i] - ('a' - 'A');
		}
	}
	int num_mot = saisie2[0] - '0';
	if (saisie2[1] - '0' > 0) {
		num_mot += saisie2[1] - '0';
	}
	if (num_mot > plateau->nb || num_mot < 1) {
		cout << "Coup invalide, recommensez " << endl;
		*verif_ext = true;
		return;
	}
	char mot_plateau[nb_max_carte_traitement];
	for (int i = 0; i < plateau->c[num_mot - 1].sommet + 1; i++) {
		if (plateau->c[num_mot - 1].tab[i].lettre != -1) {
			mot_plateau[i] = plateau->c[num_mot - 1].tab[i].lettre;
		}
	}
	mot_plateau[plateau->c[num_mot - 1].sommet + 1] = '\0';
	if (strcmp(mot_plateau, mot) == 0) {
		cout << "Coup invalide, recommensez " << endl;
		*verif_ext = true;
		return;
	}
	if (strlen(mot) != plateau->c[num_mot - 1].sommet + 1)
	{
		cout << "Coup invalide, recommensez " << endl;
		*verif_ext = true;
		return;
	}
	Carte traitement[nb_max_carte_traitement];
	for (int i = 0; i < nb_max_carte_traitement; i++) {
		traitement[i].lettre = -1;
		traitement[i].nb_points = -1;
	}
	int repaire = 0;
	for (int i = 0; i < Max_nb_carte; i++) {
		if (participants[num_joueur - 1].main[i].lettre != -1) {
			traitement[repaire].lettre = participants[num_joueur - 1].main[i].lettre;
			traitement[repaire].nb_points = participants[num_joueur - 1].main[i].nb_points;
			++repaire;
		}
	}
	for (int i = 0; i < plateau->c[num_mot - 1].sommet + 1; i++) {
		if (plateau->c[num_mot - 1].tab[i].lettre != -1) {
		traitement[repaire].lettre = plateau->c[num_mot - 1].tab[i].lettre;
		traitement[repaire].nb_points = plateau->c[num_mot - 1].tab[i].nb_points;
		++repaire;
		}
	}
	bool verif = false;
	Carte save_main[nb_max_carte_traitement];
	for (int i = 0; i < nb_max_carte_traitement; i++) {
		save_main[i].lettre = -1;
		save_main[i].nb_points = -1;
	}
	for (int i = 0; i < nb_max_carte_traitement; i++) {
		save_main[i].lettre = traitement[i].lettre;
		save_main[i].nb_points = traitement[i].nb_points;
	}
	for (int i = 0; i < longeur; i++) {
		verif = false;
		for (int y = 0; y < nb_max_carte_traitement; y++) {
			if (save_main[y].lettre != -1) {
				if (save_main[y].lettre == mot[i]) {
					verif = true;
					save_main[y].lettre = -1;
					break;
				}
			}
		}
		if (!verif)
		{
			cout << "Coup invalide, recommensez " << endl;
			*verif_ext = true;
			return;
		}
	}
	if (!verifierMotDansDictionnaire(mot)) {
		cout << "Mot invalide, vous passez votre tour" << endl;
		participants[num_joueur - 1].score += 3;
		*verif_ext = false;
		return;
	}
	int help = 0;
	Pile pack;
	initialise(pack, Max_nb_carte);
	for (int i = 0; i < longeur; i++) {
		for (int y = 0; y < nb_max_carte_traitement; y++) {
			if (traitement[y].lettre == -1);
			else {
				if (traitement[y].lettre == mot[i]) {
					empiler(pack, traitement[y]);
					traitement[y].lettre = -1;
					traitement[y].nb_points = -1;
					help++;
					break;
				}
			}
		}
	}
	supprimer(*plateau, num_mot - 1);
	inserer(*plateau, num_mot - 1, pack);
	for (int i = 0; i < Max_nb_carte; i++) {
		participants[num_joueur - 1].main[i].lettre = -1;
		participants[num_joueur - 1].main[i].nb_points = -1;
	}
	for (int i = 0; i < Max_nb_carte; i++) {
		for (int y = 0; y < nb_max_carte_traitement; y++) {
			if (traitement[y].lettre != -1) {
				participants[num_joueur - 1].main[i].lettre = traitement[y].lettre;
				participants[num_joueur - 1].main[i].nb_points = traitement[y].nb_points;
				traitement[y].lettre = -1;
				traitement[y].nb_points = -1;
				break;
			}
		}
	}
	*verif_ext = false;
}

void C(Liste* plateau, joueur* participants, int num_joueur, bool* verif_ext, char saisie2[nb_max_mot], char mot[nb_max_mot]) {
	int taille_mot = strlen(mot);
	for (int i = 0; i < taille_mot; ++i) {
		// Vérifie si le caractère est une lettre minuscule (a-z)
		if (mot[i] >= 'a' && mot[i] <= 'z') {
			// Convertit en majuscule en soustrayant la différence entre 'a' et 'A'
			mot[i] = mot[i] - ('a' - 'A');
		}
	}
	int num_mot = saisie2[0] - '0';
	if (saisie2[1] - '0' > 0) {
		num_mot += saisie2[1] - '0';
	}
	if (num_mot > plateau->nb || num_mot < 1) {
		cout << "Coup invalide, recommensez " << endl;
		*verif_ext = true;
		return;
	}
	char mot_plateau[nb_max_carte_traitement];
	for (int i = 0; i < plateau->c[num_mot - 1].sommet + 1; i++) {
		if (plateau->c[num_mot - 1].tab[i].lettre != -1) {
			mot_plateau[i] = plateau->c[num_mot - 1].tab[i].lettre;
		}
	}
	mot_plateau[plateau->c[num_mot - 1].sommet + 1] = '\0';
	if (strcmp(mot_plateau, mot) == 0) {
		cout << "Coup invalide, recommensez " << endl;
		*verif_ext = true;
		return;
	}
	int compteur = 0;
	int verif1 = 0;
	for (int i = 0; i < plateau->c[num_mot - 1].sommet + 1; i++) {
		for (int y = 0; y < taille_mot; y++) {
			if (plateau->c[num_mot - 1].tab[i].lettre == mot[compteur]) {
				verif1++;
				compteur++;
				break;
			}
			compteur++;
		}
	}
	if (verif1 != plateau->c[num_mot - 1].sommet + 1) {
		cout << "Coup invalide, recommensez " << endl;
		*verif_ext = true;
		return;
	}
	Carte traitement[nb_max_carte_traitement];
	for (int i = 0; i < nb_max_carte_traitement; i++) {
		traitement[i].lettre = -1;
		traitement[i].nb_points = -1;
	}
	int repaire = 0;
	for (int i = 0; i < Max_nb_carte; i++) {
		if (participants[num_joueur - 1].main[i].lettre != -1) {
			traitement[repaire].lettre = participants[num_joueur - 1].main[i].lettre;
			traitement[repaire].nb_points = participants[num_joueur - 1].main[i].nb_points;
			++repaire;
		}
	}
	for (int i = 0; i < plateau->c[num_mot - 1].sommet + 1; i++) {
		if (plateau->c[num_mot - 1].tab[i].lettre != -1) {
			traitement[repaire].lettre = plateau->c[num_mot - 1].tab[i].lettre;
			traitement[repaire].nb_points = plateau->c[num_mot - 1].tab[i].nb_points;
			++repaire;
		}
	}
	bool verif = false;
	Carte save_main[nb_max_carte_traitement];
	for (int i = 0; i < nb_max_carte_traitement; i++) {
		save_main[i].lettre = -1;
		save_main[i].nb_points = -1;
	}
	for (int i = 0; i < nb_max_carte_traitement; i++) {
		save_main[i].lettre = traitement[i].lettre;
		save_main[i].nb_points = traitement[i].nb_points;
	}
	for (int i = 0; i < taille_mot; i++) {
		verif = false;
		for (int y = 0; y < nb_max_carte_traitement; y++) {
			if (save_main[y].lettre != -1) {
				if (save_main[y].lettre == mot[i]) {
					verif = true;
					save_main[y].lettre = -1;
					break;
				}
			}
		}
		if (!verif)
		{
			cout << "Coup invalide, recommensez " << endl;
			*verif_ext = true;
			return;
		}
	}
	if (!verifierMotDansDictionnaire(mot)) {
		cout << "Mot invalide, vous passez votre tour" << endl;
		participants[num_joueur - 1].score += 3;
		*verif_ext = false;
		return;
	}
	int help = 0;
	Pile pack;
	initialise(pack, Max_nb_carte);
	for (int i = 0; i < taille_mot; i++) {
		for (int y = 0; y < nb_max_carte_traitement; y++) {
			if (traitement[y].lettre == -1);
			else {
				if (traitement[y].lettre == mot[i]) {
					empiler(pack, traitement[y]);
					traitement[y].lettre = -1;
					traitement[y].nb_points = -1;
					help++;
					break;
				}
			}
		}
	}
	supprimer(*plateau, num_mot - 1);
	inserer(*plateau, num_mot - 1, pack);
	for (int i = 0; i < Max_nb_carte; i++) {
		participants[num_joueur - 1].main[i].lettre = -1;
		participants[num_joueur - 1].main[i].nb_points = -1;
	}
	for (int i = 0; i < Max_nb_carte; i++) {
		for (int y = 0; y < nb_max_carte_traitement; y++) {
			if (traitement[y].lettre != -1) {
				participants[num_joueur - 1].main[i].lettre = traitement[y].lettre;
				participants[num_joueur - 1].main[i].nb_points = traitement[y].nb_points;
				traitement[y].lettre = -1;
				traitement[y].nb_points = -1;
				break;
			}
		}
	}
	*verif_ext = false;
}

void fin_de_tour(joueur* participants, Pile& exposee, Pile& talon, Liste* plateau) {
	detruire(talon);
	detruire(exposee);
	detruireListe(*plateau);
	compte_point(participants); // Comptage des points joueur jouant. 
}

void On_joue(joueur* participants, Pile& exposee, Pile& talon, Liste* plateau, int num_joueur) {
	bool verif = true;
	char indic[nb_max_mot];

	while (verif) {

		affichage_jeux(num_joueur, participants, exposee, talon, plateau); //Affichage des informations pour jouer.
		cout << "> ";
		cin.getline(indic, max_saisie);

		char saisie1[nb_max_mot];
		char saisie2[nb_max_mot];
		char saisie3[nb_max_mot];

		istringstream is(indic);
		
		is >> saisie1;
		is >> saisie2;
		is >> saisie3;
		
		if (strlen(saisie1) > 1) {
			cout << "Coup invalide, recommensez " << endl << endl;
			verif = true;
		}
		else {
			switch (*saisie1) { // Exécution des actions joueurs.
			case 'T': T(participants, num_joueur, exposee, talon, &verif, saisie2);
				break;
			case 'E': E(participants, num_joueur, exposee, &verif, saisie2);
				break;
			case 'P': P(participants, num_joueur, plateau, &verif, saisie2);
				break;
			case 'R': R(plateau, participants, num_joueur, &verif, saisie2, saisie3);
				break;
			case 'C': C(plateau, participants, num_joueur, &verif, saisie2, saisie3);
				break;
			default:

				cout << "Coup invalide, recommensez " << endl;
				verif = true;
			}
			cout << endl;
		}

	}
}

void affichage_fin(joueur* participants) {
	cout << "Le tour est fini" << endl;
	cout << "* Score" << endl;
	for (int i = 0; i < Max_nb_joueurs; i++) {
		if (participants[i].vivant == 1) {
			cout << "Joueur " << i + 1 << " : " << participants[i].score << " points " << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < Max_nb_joueurs; i++) {
		if (participants[i].vivant == 1) {
			if (participants[i].score > 100) {
				participants[i].vivant = 0;
			}
		}
	}
}