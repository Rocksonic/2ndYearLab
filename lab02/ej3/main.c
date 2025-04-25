#include <stdio.h>
#include <stdlib.h>
#include "cima_log.h"

int main(void) {
    int a[] = {-2, 8, 9, 5, 0};
    int length = sizeof(a)/sizeof(a[0]);
    int result;

    result = cima_log(a, length);

    printf("Resultado: %i\n", result);

    return EXIT_SUCCESS;
}
