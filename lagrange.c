#include "fichier.h"
#ifndef liste_h
#define liste_h
#include "fonction.c"
#endif

int** CombLineaire(Liste* coefAB, int c, int k) {
    int** tab = (int**)malloc(c*sizeof(int*));
    for (int i = 0; i < c; i++)
        tab[i] = (int*)malloc(coefAB->nb_elements_*sizeof(int));
    for (int i = 0; i < coefAB->nb_elements_; i++){
        if (i<k)
            tab[0][i]=1;
        else tab[0][i]=0;
    }
    for (int i = 1 ; i<k;){
        int* ligne = tab[0];
        for (int rando = 0 ; rando<100 ; rando++){
            int a = 0,b,c;
            b = rand() %(coefAB->nb_elements_);
            c = rand() %(coefAB->nb_elements_);
            a = ligne[b];
            ligne[b] = ligne[c];
            ligne[c] = a;
        }
        if
    }

}

Liste* li(Liste* L, int i) {
    element* e = L->head;
    for (int j = 1 ; j<i ; j++)
        e = e->next_ ;
    double xi = e->xi;   
    int l =(LongueurListe(L));
    // double* tab = (double*)malloc((l-1)*sizeof(double));
    Liste* coefAB = (Liste*)malloc(sizeof(Liste));
    RemplirL(coefAB,(l-1));
    element * e1 = coefAB->head;
    element* e2 = L->head;
    for (int j = 1 ; j <= l ; j++){
        if (i !=j){
        e1->xi = ((double)1/(xi-e2->xi));
        e1->yi = (-e2->xi/(xi-e2->xi));
        e1 = e1->next_;
        e2 = e2->next_;
        }else e2 = e2->next_;
    }
    



    for (int i = 0; i < LongueurListe(L)-1; i++)
    {
        for (int j = 0; j < combinaison(i,l); j++)
        {
            int c = combinaison(i,l);
            
        }
        
    }
    
}


int main(){
    srand(time(NULL));
    Liste* test = ClisteVide();
    AElement(test,-1.0,-1.5);
    AElement(test,-0.5,0.0);
    AElement(test,0,0.25);
    AElement(test,0.5,0);
    AElement(test,1,-0);
    afficheListe(test);
    test = li(test,1);
    afficheListe(test);
}