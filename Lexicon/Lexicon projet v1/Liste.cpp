/**
 * @file Liste.cpp
 * @brief Composant de liste en mémoire dynamique et extensible
 */

#include <cassert> 
#include "Liste.h"

void initialiserliste(Liste& l, unsigned int capa, unsigned int pas) {
    assert((capa > 0) && (pas > 0));
    l.c = new Pile[capa];
    l.nb = 0;
    l.capa = capa; 
    l.pas = pas;  
}

void detruireListe(Liste& l) {
    // Libérer la mémoire allouée pour le tableau de Paquet_De_Cartes
    delete[] l.c;
    l.c = nullptr;
    l.nb = 0;
    l.capa = 0;
}

unsigned int longueur(const Liste& l) {
    return l.nb;
}

Pile lire(const Liste& l, unsigned int pos) {
    assert(pos < l.nb);
    return l.c[pos];
}

void ecrire(Liste& l, unsigned int pos, const Pile& it) {
    assert(pos < l.nb);
    l.c[pos] = it;
}

void inserer(Liste& l, unsigned int pos, const Pile& it) {
    assert(pos <= l.nb);
    // Vérifiez si la liste est pleine et doit être étendue
    if (l.nb == l.capa) {
        l.capa += l.pas;
        Pile* newContainer = new Pile[l.capa];
        for (unsigned int i = 0; i < l.nb; i++) {
            newContainer[i] = l.c[i];
        }
        delete[] l.c;
        l.c = newContainer;
    }
    // Décalez tous les éléments après la position d'insertion
    for (unsigned int i = l.nb; i > pos; i--) {
        l.c[i] = l.c[i - 1];
    }
    l.c[pos] = it;
    l.nb++;
}

void supprimer(Liste& l, unsigned int pos) {
    assert((l.nb != 0) && (pos < l.nb));
    for (unsigned int i = pos; i < l.nb - 1; ++i) {
        l.c[i] = l.c[i + 1];
    }
    l.nb--;
}

void affichageliste(Liste& l) {
    for (int i = 0; i < l.nb; i++) {
        cout << i+1 << " - ";
        afficherPile(l.c[i]); // Affichage de la pile de carte
        cout << endl;
    }

}