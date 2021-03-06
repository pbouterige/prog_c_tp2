#include "fichier.h"
#include "fonction.c"

double* li(Liste* L, int i) {
    element* e = L->head;
    for (int j = 1; j < i; j++) e = e->next_;
    double xi = e->xi;
    int l = (LongueurListe(L));
    double* tab = (double*)malloc((l) * sizeof(double));
    for (int j = 0; j < l; j++) tab[j] = 0;
    Liste* coefAB = ClisteVide();
    RemplirL(coefAB, (l - 1));
    element* e1 = coefAB->head;
    element* e2 = L->head;
    for (int j = 1; j <= l; j++) {
        if (i != j) {
            e1->xi = ((double)1 / (xi - e2->xi));
            e1->yi = (-e2->xi / (xi - e2->xi));
            e1 = e1->next_;
            e2 = e2->next_;
        } else
            e2 = e2->next_;
    }
    devpoly(tab, coefAB, l);
    freeListe(coefAB);
    return tab;
}

double* lagrange(Liste* L) {
    int l = (LongueurListe(L));
    element* e = L->head;
    double* polynome = (double*)malloc(l * sizeof(double));
    for (int i = 0; i < l; i++) {
        if (e->yi == 0)
            e = e->next_;
        else {
            double* l_i = li(L, i + 1);
            for (int j = 0; j < l; j++) polynome[j] += e->yi * l_i[j];
            free(l_i);
            e = e->next_;
        }
    }
    return polynome;
}
