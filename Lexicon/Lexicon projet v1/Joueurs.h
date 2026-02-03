#pragma once

/**
 * @file Joueurs.h
 * @brief Composant des joueurs
*/

#include <iostream>
#include "Cartes.h"
#include "Pile.h"
using namespace std;

enum {Max_nb_carte = 10, Max_nb_joueurs = 4, Min_nb_joueurs = 2 };

struct joueur {
	int numero; // Numéro du joueur 
	Carte main[Max_nb_carte]; // Tableau des cartes que le joueur possède
	int score; // Score du joueur 
	int vivant; // État du joueur, -1 = n'est pas dans la partie, 0 = a été éliminé, 1 = est dans la partie et joue.
};

/**
 * @brief Initialisation des joueurs jouant et ne jouant pas.
 * @param[out] participants Le tableau de joueur à initialiser.
 * @param[in] nb_joueurs Le nombre de joueurs jouant.
 */
void intialisation(int nb_jouers, joueur* participants);

/**
 * @brief Distribution de 10 cartes aux joueurs qui jouent.
 * @param[out] participants Le tableau de joueur , avec les joueurs à qui distribuer les cartes.
 * @param[in] nb_joueurs Le nombre de joueurs jouant.
 * @param[in] talon , la pile ou prendre les cartes à distribuer.
 */
void pioche_debut(joueur* participants, int nb_joueurs, Pile& talon);

/**
 * @brief Vérification que le joueur n'a pas zéro cartes.
 * @param[in] participants Le tableau de joueur , avec les joueurs à qui distribuer les cartes.
 * @param[in] nb_joueurs Le nombre du joueur à qui les cartes sont verifié.
 */
bool compte_cartes(joueur* participants, int nb_joueurs);

/**
 * @brief Comptage des points pour les joueurs jouant.
 * @param[in,out] participants Le tableau de joueur.
 */
void compte_point(joueur* participants);

/**
 * @brief Comptage des joueurs restants
 * @param[in] participants Le tableau de joueur.
 * @param[in] verif_ext , indicateur de continuité pour la partie.
 */
void compter_joueur(joueur* participants, bool* verif_ext);
