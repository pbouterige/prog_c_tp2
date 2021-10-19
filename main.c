#include "lagrange.c"
#include "newton.c"

int main() {
    int choix = 0;
    Liste* Final;
    while (choix != 1 && choix != 2 && choix != 3 && choix != 4) {
        puts("\nChoix liste :\n");
        puts("[Densité de l'eau]     [1]");
        puts("[Trois séries]         [2]");
        puts("[Dépense mensuelles]   [3]");
        puts("[Liste personelle]     [4]\n");
        scanf("%d", &choix);
        if (choix == 1)
            Final = densiteEauTemp();
        else if (choix == 2)
            Final = TroisSeries();
        else if (choix == 3)
            Final = depense();
        else if (choix == 4)
            RemplirL(Final, 1);
        else {
            puts("choix incorrect");
            while (getchar() != '\n') {
            }
        }
    }
    choix = -1;
    afficheListe(Final);
    if (ListeValide(Final)) {
        puts(
            "La liste n'est pas valide; En effet, deux xi ont la même valeur.");
        freeListe(Final);
        return 0;
    }
    while (choix != 1 && choix != 2 && choix != 3) {
        puts("\nChoix méthode interpolation :\n");
        puts("[Lagrange]     [1]");
        puts("[Newton]       [2]");
        puts("[Les deux]     [3]\n");
        scanf("%d", &choix);
        bool test = false;
        if (choix == 3) test = true;
        if (choix == 1 || test) {
            double* resultat = lagrange(Final);
            puts("\nPolynôme de Lagrange :");
            puts("");
            printf("%.17g*x^%d", resultat[Final->nb_elements_ - 1],
                   Final->nb_elements_ - 1);
            for (int i = Final->nb_elements_ - 2; i >= 0; i--)
                printf(" + %.17g*x^%d", resultat[i], i);
            fonction_erreurG(Final, resultat);
            puts("\n");
            free(resultat);
        }
        if (choix == 2 || test) {
            int N = Final->nb_elements_;
            double* xi = (double*)malloc(N * sizeof(double));
            double* yi = (double*)malloc(N * sizeof(double));
            liste_New(Final, xi, yi);
            newton(xi, yi, N);
            free(xi);
            free(yi);
        } else if (choix != 1 && choix != 3) {
            puts("choix incorrect");
            while (getchar() != '\n') {
            }
        }
    }
    freeListe(Final);
    return 0;
}