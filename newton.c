#include "fichier.h"
#include "tableauTest.c"

double deltaInvers(double tabX[], double tabY[], int i, int k){
    if (k==1)  { 
        return ((tabY[i-1]-tabY[k-1])/(tabX[i-1]-tabX[k-1]));
    }   
    else if(k > 1) {
        return ((deltaInvers(tabX, tabY, i, k-1) - deltaInvers(tabX, tabY, k, k-1))/ (tabX[i-1]-tabX[k-1]));
    }  
} 

void Bi(double tabB[], double tabX[], double tabY[], int N){

    //remplissage première case du tableau
    tabB[0] = tabY[0]; 

    //remplissage du reste du tableau 
    for (int j = 1; j < N; j++) //numéro de case du tableau
        tabB[j]=deltaInvers(tabX, tabY, j+1, j); 

} 

void polynome(double degre[], double tabX[], double tabB[], int N){
    //initialisation tableau degre
    degre[0]=tabB[N-1];
    for (int j = 1; j < N; j++)
        degre[j]=0;
    //remplissage tableau
    for (int j = 1; j < N; j++)
    {
        for (int t = N-1; t > 0; t--){ 
            degre[t] = degre[t-1] - degre[t]*tabX[N-j-1]; 
        }       
        degre[0] = tabB[N-j-1] - degre[0]*(tabX[N-j-1]);
          
    }
    
} 

void newton(double xi[], double yi[], int N){ 
    //tableau B i
    double tabB[N];
    Bi(tabB, xi, yi, N);
    //tableau degre
    double degre[N];
    polynome(degre, xi, tabB, N); 

    printf("Le polynôme de Newton s'écrit ici sous la forme : ");
    for (int j = N-1; j > 0; j--)
    {
        printf("(%f)x^%d", degre[j], j);
        printf("+");
    }
    printf("(%f)\n", degre[0]);
} 

int main(){
    
    //exemple exercice TD
    double xi[5] = {-1, -0.5, 0, 0.5, 1};
    double yi[5] = {-1.5, 0, 0.25, 0, 0};

    //exemple cours
    //double xi[4] = {0, 2, 4, 6};  
    //double yi[4] = {0, 4, 0, 4};

    int N = 5;

    //exemple tableaux tests
    //double xi[N];
    //double yi[N];

    //depenses(xi, yi);
    newton(xi, yi, N);

}
