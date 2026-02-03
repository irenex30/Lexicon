#include "Cartes.h"

void initialiser(std::istream& fichier, Paquet_De_Cartes& pack) {
    for (unsigned int i = 0; i < nb_cartes; i++) { // Initialisation de toutes les cartes du paquet de cartes via le fichier. 
        fichier >> pack.paquet[i].lettre >> pack.paquet[i].nb_points;
    }
}

void melanger(Paquet_De_Cartes& pack) {
    srand(time(0));
    for (int i = 0 ; i < nb_cartes ; i++) { // Mélange aléatoire des cartes valides.
        if (pack.paquet[i].lettre != -1) {
            int alea = rand() % (nb_cartes);
            if (pack.paquet[i].lettre != alea) {
                Carte save = pack.paquet[i];
                pack.paquet[i] = pack.paquet[alea];
                pack.paquet[alea] = save;
            }
        }
    }
}

void initialiser_vide(Paquet_De_Cartes& pack) {
    for (int i = 0; i < nb_cartes; i++) {
        pack.paquet[i].lettre = -1;
        pack.paquet[i].nb_points = -1;
    }
}