#pragma once

/**
 * @file Cartes.h
 * @brief Composant d'une carte et composition d'un paquet de cartes
 */

#include <iostream>
#include <fstream> 
using namespace std;

enum {nb_cartes = 51};

struct Carte {
	char lettre; // Lettre de la carte ( Si -1 carte non valide ).
	unsigned int nb_points; // Point de la carte.
};

struct Paquet_De_Cartes {
	Carte paquet[nb_cartes]; //Paquet de 51 cartes(le nombre de cartes dans le jeu).
};

/**
 * @brief Initialiser le paquet de cartes via un fichier 
 * @param[out] pack le paquet de cartes à initialiser et à remplir via le fichier, carte par carte.
 * @param[in] fichier , le fichier contenant les informations des cartes à initialiser.
 */
void initialiser(std:: istream & fichier, Paquet_De_Cartes& pack );

/**
 * @brief Mélange d'un paquet de cartes.
 * @param[in,out] pack le paquet de cartes à mélanger
 */
void melanger(Paquet_De_Cartes& pack);

/**
 * @brief Initialisation d'un paquet de cartes vide 
 * @param[in] pack le paquet de cartes à initialiser.
 */
void initialiser_vide(Paquet_De_Cartes& pack);