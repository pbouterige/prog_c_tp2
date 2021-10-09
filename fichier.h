#ifndef main_h_
#define main_h_

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct element{
    double xi;
    double yi;
    struct element* next_;
    struct element* prev_;
}element;

typedef struct liste{
    element* head;
    element* tail;
    int nb_elements_;
}Liste;

#endif