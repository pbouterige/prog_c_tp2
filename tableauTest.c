#include "fichier.h"

void densite(double tabX[], double tabY[]){
    double tab[20] = {0.99987, 0.99997, 1.00000, 0.99997, 0.99988, 0.99973, 0.99953, 0.99927, 0.99897, 0.99846, 0.99805, 0.999751, 0.99705, 0.99650, 0.99664, 0.99533, 0.99472, 0.99472, 0.99333, 0.99326};
    for (int i = 0; i < 20; i++)
        tabY[i] = tab[i];  
    
    int j=0;
    for (double i = 0 ; i<39 ; i=i+2){
        tabX[j] = i;
        j++;
    }  
} 

void S1(double tabX[], double tabY[]){
    double tab[11] = {3.1, 4.74, 6.13, 7.26, 8.14, 8.77, 9.14, 9.26, 9.13, 8.74, 8.1};
    for (int i = 0; i < 11; i++)
        tabY[i] = tab[i];  
    
    int j=0;
    for (double i = 4 ; i<15 ; i++){
        tabX[j] = i;
        j++;
    }  
}

void S2(double tabX[], double tabY[]){
    double tab[11] = {5.39, 5.73, 6.08, 6.42, 6.77, 7.11, 7.46, 7.81, 8.15, 12.74, 8.84};
    for (int i = 0; i < 11; i++)
        tabY[i] = tab[i];  
    
    int j=0;
    for (double i = 4 ; i<15 ; i++){
        tabX[j] = i;
        j++;
    }  
}

void S3(double tabX[], double tabY[]){
    double tab[11] = {6.58, 5.76, 7.71, 8.84, 8.47, 7.04, 5.25, 12.5, 5.56, 7.91, 6.89};
    for (int i = 0; i < 11; i++)
        tabY[i] = tab[i];  
    
    for (int i = 0 ; i<11 ; i++){
        tabX[i] = 8;
    }  
    tabX[7] = 19; 
}

void depenses(double tabX[], double tabY[]){
    double tabR[21] = {752, 855, 871, 734, 610, 582, 921, 492, 569, 462, 907, 643, 862, 524, 679, 902, 918, 828, 875, 809, 894};
    for (int i = 0; i < 21; i++)
        tabX[i] = tabR[i]; 
    
    double tabD[21] = {85, 83, 162, 79, 81, 83, 281, 81, 81, 80, 243, 84, 84, 82, 80, 226, 260, 82, 186, 77, 223};
    for (int i = 0; i < 21; i++)
        tabY[i] = tabD[i];
}

void AfficheTab(double tab[], int N){
    for (int i = 0 ; i < N ; i++){
        printf("%f ", tab[i]);
    } 
    printf("\n");
}
