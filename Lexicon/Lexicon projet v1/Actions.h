#pragma once

/**
 * @file Liste.h
 * @brief Action mettant en commun l'ensemble des données.
 */

#include <cstring> 
#include <limits>
#include <iostream>
#include <sstream>
#include "Joueurs.h"
#include "Liste.h"

enum { nb_max_mot = 50, nb_max_carte_traitement = 20, max_saisie = 1000 };

/**
 * @brief Initialise les éléments pour commencer une partie.
 * @param[in,out] talon , la liste des cartes du talon.
 * @param[out] exposee, la liste des cartes exposee.
 * @param[in] pack , paquet de cartes à distribuer dans le talon , exposee et les joueurs
 * @param[in,out] participants , le tableau des joueurs
 * @param[in] nb_joueurs Le nombre de joueurs jouant.
*/
void commmencement(Pile& talon, Pile& exposee, Paquet_De_Cartes& pack, joueur* participants, int nb_joueurs);

/**
 * @brief Permet d'éxécuter la commande T pour un joueur.
 * @param[in,out] talon , la liste des cartes du talon.
 * @param[in,out] exposee, la liste des cartes exposee.
 * @param[in,out] participants , le tableau des joueurs
 * @param[in] num_joueur Le num du joueur qui joue.
 * @param[in] verif_ext le bool vérification erreur.
*/
void T(joueur* participants, int num_joueur, Pile& exposee, Pile& talon, bool* verif_ext, char saisie1[nb_max_mot]);

/**
 * @brief Permet d'éxécuter la commande E pour un joueur.
 * @param[in,out] exposee, la liste des cartes exposee.
 * @param[in,out] participants , le tableau des joueurs
 * @param[in] num_joueur Le num du joueur qui joue.
 * @param[in] verif_ext le bool vérification erreur.
*/
void E(joueur* participants, int num_joueur, Pile& exposee, bool* verif_ext, char saisie1[nb_max_mot]);

/**
 * @brief Permet de savoir si un mot est dans le dictionnaire.
 * @param[in] mot , Le tableau de caractères contenant le mot à vérifier.
*/
bool verifierMotDansDictionnaire(const char* mot);

/**
 * @brief Permet d'éxécuter la commande P pour un joueur.
 * @param[in,out] plateau , la liste dynamique et extensible des mots posés.
 * @param[in,out] participants , le tableau des joueurs
 * @param[in] num_joueur Le nim du joueur qui joue.
 * @param[in] verif_ext le bool vérification erreur.
*/
void P(joueur* participants, int num_joueur, Liste* plateau, bool* verif_ext, char saisie1[nb_max_mot]);

/**
 * @brief Permet d'afficher les informations pour jouer par rapport à un joueur.
 * @param[in] talon , la liste des cartes du talon.
 * @param[in] exposee, la liste des cartes exposee.
 * @param[in] plateau , la liste dynamique et extensible des mots posés.
 * @param[in] participants , le tableau des joueurs
 * @param[in] num_joueur Le nim du joueur qui joue.
*/
void affichage_jeux(int num_joueur, joueur* participants, Pile& exposee, Pile& talon, Liste* plateau);

/**
 * @brief Permet d'éxécuter la commande R pour un joueur.
 * @param[in,out] plateau , la liste dynamique et extensible des mots posés.
 * @param[in,out] participants , le tableau des joueurs
 * @param[in] num_joueur Le nim du joueur qui joue.
 * @param[in] verif_ext le bool vérification erreur.
*/
void R(Liste* plateau, joueur* participants, int num_joueur, bool* verif_ext, char saisie1[nb_max_mot], char saisie2[nb_max_mot]);

/**
 * @brief Manipulation de fin de tour.
 * @param[in,out] talon , la liste des cartes du talon.
 * @param[in,out] exposee, la liste des cartes exposee.
 * @param[in, out] plateau , la liste dynamique et extensible des mots posés.
 * @param[in,out] participants , le tableau des joueurs
*/
void fin_de_tour(joueur* participants, Pile& exposee, Pile& talon, Liste* plateau);

/**
 * @brief Permet à un joueur de jouer son tour.
 * @param[in,out] talon , la liste des cartes du talon.
 * @param[in,out] exposee, la liste des cartes exposee.
 * @param[in, out] plateau , la liste dynamique et extensible des mots posés.
 * @param[in,out] participants , le tableau des joueurs
 * @param[in] num_joueur Le num du joueur qui joue.
*/
void On_joue(joueur* participants, Pile& exposee, Pile& talon, Liste* plateau, int num_joueur);

/**
 * @brief Affichage des scores des joueurs jouant.
 * @param[in,out] participants , le tableau des joueurs à afficher
*/
void affichage_fin(joueur* participants);

/**
 * @brief Permet d'éxécuter la commande C pour un joueur.
 * @param[in,out] plateau , la liste dynamique et extensible des mots posés.
 * @param[in,out] participants , le tableau des joueurs
 * @param[in] num_joueur Le nim du joueur qui joue.
 * @param[in] verif_ext le bool vérification erreur.
*/
void C(Liste* plateau, joueur* participants, int num_joueur, bool* verif_ext, char saisie1[nb_max_mot], char saisie2[nb_max_mot]);