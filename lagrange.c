#include "fichier.h"
#ifndef liste_h
#define liste_h
#include "fonction.c"
#endif

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

int main() {
    srand(time(NULL));
    Liste* test = densiteEauTemp();
    afficheListe(test);
    puts("");
    double* resultat = lagrange(test);
    printf("%gx%d", resultat[test->nb_elements_ - 1], test->nb_elements_ - 1);
    for (int i = test->nb_elements_ - 2; i >= 0; i--)
        printf(" + %gx%d", resultat[i], i);
    puts("\n");
    double somme = 0;
    element* e = test->head;
    for (int i = 0; i < test->nb_elements_; i++) {
        int a = e->xi;
        for (int j = 0; j < test->nb_elements_; j++)
            somme += resultat[j] * powf(a, j);
        printf("f(%d) = %g et Yi = %g\n", a, somme, e->yi);
        somme = 0;
        e = e->next_;
    }

    free(resultat);
    freeListe(test);
    return 0;
}
