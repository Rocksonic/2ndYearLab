#include <stdbool.h>
#include <stdio.h>
#include "k_esimo.h"

// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */
int k_esimo(int a[], int length, int k) 
{
    int pivot = partition(a, 0, length);
    printf("Wompa\n");
    printf("This is the first pivot position: %d and the value of the pivot is %d\n", pivot, a[pivot]);
    while (pivot != k)
    {
        if (k > pivot)
        {
            printf("Need a bigger pivot, new iteration of partition.\n");
            pivot = partition(a, pivot, length);
            printf("New pivot is: %d\n", pivot);
        }
        else
        {
            printf("Need a smaller pivot, new iteration of partition.\n");
            pivot = partition(a, 0, pivot);
            printf("New pivot is: %d\n", pivot);
        }
    }
    return a[k];
}

int partition(int a[], int izq, int der) 
{
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) 
    {
        if (goes_before(a[i], a[ppiv])) 
        {
            i = i + 1;
        } 
        else if (goes_before(a[ppiv], a[j])) 
        {
            j = j - 1;
        } 
        else 
        {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

bool goes_before(int x, int y) 
{
    return x <= y;
}

void swap(int a[], int i, int j) 
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
