#include  "fichier.h"

Liste* ClisteVide() {
    Liste* L = (Liste*)malloc(sizeof(Liste));
    L->head = NULL;
    L->tail = NULL;
    L->nb_elements_ = 0;
    return L;
}

int LongueurListe(Liste* L) { return L->nb_elements_; }

void AElement(Liste* L, double xi, double yi) {
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

void RemplirL(Liste* L, int nb){
    for (int i = 0 ; i<nb ; i++)
        AElement(L,0,0);
}


void afficheListe(Liste* L) {
    element* iterateur = L->head;
    printf("[xi] ");
    for (int i = 0; i < L->nb_elements_; i++) {
        printf("[ %f ]", iterateur->xi);
        iterateur = iterateur->next_;
    }
    puts("");
    iterateur = L->head;
    printf("[yi] "); 
    for (int i = 0; i < L->nb_elements_; i++) {
        printf("[ %f ]",iterateur->yi);
        iterateur = iterateur->next_;
    } 
    printf("NULL\n");
}

long factorial(int n)
{
  int i;
  long fact = 1;
 
  for (i = 1; i <= n; i++)
    fact = fact * i;
 
  return fact;
}

int combinaison(int k, int n) {
    
    return (factorial(n)/factorial(k)*factorial(n-k));
}