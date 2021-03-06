#include "fichier.h"

double deltaInvers(double tabX[], double tabY[], int i, int k) {
    if (k == 1)
        return ((tabY[i - 1] - tabY[k - 1]) / (tabX[i - 1] - tabX[k - 1]));
    else {
        return ((deltaInvers(tabX, tabY, i, k - 1) -
                 deltaInvers(tabX, tabY, k, k - 1)) /
                (tabX[i - 1] - tabX[k - 1]));
    }
}

void Bi(double tabB[], double tabX[], double tabY[], int N) {
    // remplissage première case du tableau
    tabB[0] = tabY[0];

    // remplissage du reste du tableau
    for (int j = 1; j < N; j++)  // numéro de case du tableau
        tabB[j] = deltaInvers(tabX, tabY, j + 1, j);
}

void polynome(double degre[], double tabX[], double tabB[], int N) {
    // initialisation tableau degre
    degre[0] = tabB[N - 1];
    for (int j = 1; j < N; j++) degre[j] = 0;

    // remplissage tableau
    for (int j = 1; j < N; j++) {
        for (int t = N - 1; t > 0; t--)
            degre[t] = degre[t - 1] - degre[t] * tabX[N - j - 1];
        degre[0] = tabB[N - j - 1] - degre[0] * (tabX[N - j - 1]);
    }
    // degre[N-1] = tabB[N-1];
}

void newton(double xi[], double yi[], int N) {
    // tableau B i
    double tabB[N];
    Bi(tabB, xi, yi, N);
    // tableau degre
    double degre[N];
    polynome(degre, xi, tabB, N);

    puts("Polynôme de Newton :\n");
    for (int j = N - 1; j > 0; j--) {
        printf("%.17g*x^%d", degre[j], j);
        printf(" + ");
    }
    printf("%.17g\n", degre[0]);
    fonction_erreurN(xi, yi, degre, N);
}

void densiteEauTempN(double* tabx, double* taby) {
    long double tmp[20] = {0.99987, 0.99997,  1.00000, 0.99997, 0.99988,
                           0.99973, 0.99953,  0.99927, 0.99897, 0.99846,
                           0.99805, 0.999751, 0.99705, 0.99650, 0.99664,
                           0.99533, 0.99472,  0.99472, 0.99333, 0.99326};
    for (int i = 0; i < 20; i++) {
        tabx[i] = i * 2;
        taby[i] = tmp[i];
    }
}
