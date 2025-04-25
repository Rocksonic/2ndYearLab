#include <stdio.h>
#include <stdbool.h>
#include "cima.h"

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
    bool bajando = false;
    for (int i = 0; i < length - 1  && cima_is_real; i++)
    {
        if (!(a[i] < a[i+1]) && !bajando)
        {
            subiendo = false;
            bajando = true;
        }
        
        if (a[i] < a[i+1] && bajando)
        {
            cima_is_real = false;
        } 
    }
    return cima_is_real && bajando;
}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
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
int cima(int a[], int length) {
    int top = -1;
    if (tiene_cima(a, length))
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (a[i] < a[i+1]) top = i+1;
        }
    }
    return top;
}
