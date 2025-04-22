#include <stdio.h>
#include <stdlib.h>
#include "k_esimo.h"

int main(void) {
    int a[] = {8, 0, 9, -2, 13};
    int length = 5;
    int k = 1;
    int result;

    result = k_esimo(a, length, k);
    printf("[");
    for (int i = 0; i < length; i++)
    {
        (i != length - 1) ? printf("%d," ,a[i]) : printf("%d",a[i]);
    }
    printf("]");
    printf("Resultado: %i\n", result);

    
    return EXIT_SUCCESS;
}
