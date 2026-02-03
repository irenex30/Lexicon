#include "Pile.h"

/**
 * @file Pile.cpp
 * @brief Implémentation du composant de pile à capacité paramétrée.
*/

void initialise(Pile& p, unsigned int c) {
	assert(c > 0);
	p.capacite = c;
	p.tab = new Carte[c];
	p.sommet = -1;
}

void detruire(Pile& p) {
	delete[] p.tab;
	p.tab = NULL;
}

bool estPleine(const Pile& p) {
	return (p.sommet == (p.capacite - 1));
}

bool estVide(const Pile& p) {
	return (p.sommet == -1);
}

Carte sommet(const Pile& p) {
	assert(!estVide(p));
	return p.tab[p.sommet];
}

void empiler(Pile& p, const Carte& it) {
	assert(!estPleine(p));
	p.sommet++;
	p.tab[p.sommet] = it;
}

void depiler(Pile& p) {
	assert(!estVide(p));
	p.sommet--;
}

void creation(Pile& manip , Paquet_De_Cartes& pack) {
	for (int i = 0; i < nb_cartes; ++i) {
		empiler(manip, pack.paquet[i]);
	}
}

void afficherPile(const Pile& p) {
	for (int i = 0; i <= p.sommet; i++) {
		cout << p.tab[i].lettre;
	}
}