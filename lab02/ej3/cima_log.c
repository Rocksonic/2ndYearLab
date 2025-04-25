#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
bool tiene_cima(int a[], int length) {
    bool cima_is_real = true;
    bool subiendo = true;
    for (int i = 0; i < length - 1  && cima_is_real; i++)
    {
        if (!(a[i] < a[i+1]) && subiendo)
        {
            subiendo = false;
        }
        
        if (a[i] < a[i+1] && !subiendo)
        {
            cima_is_real = false;
        } 
    }
    return cima_is_real && !subiendo;
}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima_log(int a[], int length) {
    bool has_cima = tiene_cima(a, length);
    int left = 0;
    int right = length - 1;
    int middle = length/2;
    int index = -1;
    while (left < right && has_cima)
    {
        if (a[middle] < a[middle+1]) ++left;
        if (a[middle] > a[middle+1]) --right;
        if (left == right) index = left;
        middle = (left + right)/2;
    }
    
    return index;
}
