#include <stdio.h>
#include <stdlib.h>
#include "cima.h"

int main(void) {
    int a[] = {-2, 3, 6, 7, 9, 0};
    int length = sizeof(a)/sizeof(a[0]);
    int result;
    result = cima(a, length);
    printf("Resultado: %i\n", result);

    return EXIT_SUCCESS;
}
