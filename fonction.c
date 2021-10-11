#include "fichier.h"

Liste* ClisteVide() {
    Liste* L = (Liste*)malloc(sizeof(Liste));
    L->head = NULL;
    L->tail = NULL;
    L->nb_elements_ = 0;
    return L;
}

int LongueurListe(Liste* L) { return L->nb_elements_; }

void AElement(Liste* L, long  double xi, long  double yi) {
    if (LongueurListe(L) == 0) {
        element* nouveau = (element*)malloc(sizeof(element));
        nouveau->next_ = NULL;
        nouveau->prev_ = NULL;
        nouveau->xi = xi;
        nouveau->yi = yi;
        L->head = nouveau;
        L->tail = nouveau;
        L->nb_elements_++;
    } else {
        element* nouveau = (element*)malloc(sizeof(element));
        nouveau->next_ = NULL;
        nouveau->prev_ = L->tail;
        nouveau->prev_->next_ = nouveau;
        L->tail = nouveau;
        nouveau->xi = xi;
        nouveau->yi = yi;
        L->nb_elements_++;
    }
}

void RemplirL(Liste* L, int nb) {
    for (int i = 0; i < nb; i++) AElement(L, 0, 0);
}

void afficheListe(Liste* L) {
    element* iterateur = L->head;
    printf("[xi] ");
    for (int i = 0; i < L->nb_elements_; i++) {
        if (iterateur->xi >= 0)
            printf("[  %Lg ]", iterateur->xi);
        else
            printf("[ %Lg ]", iterateur->xi);
        iterateur = iterateur->next_;
    }
    puts("");
    iterateur = L->head;
    printf("[yi] ");
    for (int i = 0; i < L->nb_elements_; i++) {
        if (iterateur->yi >= 0)
            printf("[  %Lg ]", iterateur->yi);
        else
            printf("[ %Lg ]", iterateur->yi);
        iterateur = iterateur->next_;
    }
    puts("");
}

void devpoly(long  double* tab, Liste* L, int l) {
    tab[0] = L->head->yi;
    tab[1] = L->head->xi;
    element* e = L->head;
    for (int j = 0; j < l - 2; j++) {
        e = e->next_;
        long  double* stocke = (long  double*)malloc((l) * sizeof(long  double));
        for (int i = 1; i < l; i++) stocke[i] = tab[i - 1] * e->xi;
        for (int i = 0; i < l - 1; i++) stocke[i] += tab[i] * e->yi;
        for (int i = 0; i < l; i++) tab[i] = stocke[i];
        free(stocke);
    }
}

void freeListe(Liste* L) {
    element* e1 = L->head;
    element* e2 = L->head->next_;
    for (int i = 0; i < L->nb_elements_ - 1; i++) {
        free(e1);
        e1 = e2;
        e2 = e2->next_;
    }
    free(e1);
    free(L);
}

Liste* densiteEauTemp(void) {
    Liste* tab = ClisteVide(20);
    long  double tmp[20] = {0.99987, 0.99997,  1.00000, 0.99997, 0.99988,
                      0.99973, 0.99953,  0.99927, 0.99897, 0.99846,
                      0.99805, 0.999751, 0.99705, 0.99650, 0.99664,
                      0.99533, 0.99472,  0.99472, 0.99333, 0.99326};
    for (int i = 0; i < 20; i++) AElement(tab, 2 * i, tmp[i]);
    return tab;
}