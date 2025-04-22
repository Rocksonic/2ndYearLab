#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;

    res.is_lowerbound = true;
    res.is_upperbound = true;
    res.exists = false;

    for (int i = 0; i < (int)length; i++)
    {
        if (value > arr[i])
        {
            res.is_lowerbound = false;
        }
        else if (value < arr[i])
        {
            res.is_upperbound = false;
        }
        
        if (value == arr[i])
        {
            res.exists = true;
            res.where = i;
        }
    }

    if (!res.exists)
    {
        res.is_lowerbound = false;
        res.is_upperbound = false;
    }
    
    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;
    int aux;

    printf("Please, input the next 4 numbers for the array. \n");
    
    for (int i = 0; i < (int)ARRAY_SIZE; i++)
    {
        printf("Input a number: \n");
        scanf("%d", &aux);
        a[i] = aux;
    }

    printf("\n\nNow input the number you want to find in the array.\n");
    printf("Input a number: \n");
    scanf("%d", &aux);
    value = aux;

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.is_upperbound)
    {
        printf("The number %d is the upperbound of the array.\n", value);
    }
    else if (result.is_lowerbound)
    {
        printf("The number %d is the lowerbound of the array.\n", value);
    }
    else
    {
        printf("The number %d is neither upper or lowerbound.\n", value);
    }
    
    if (result.exists)
    {
        printf("The number %d exists in the array in the position %d.\n", value, result.where);
    }
    else
    {
        printf("The number %d number doesnt exists in the array.\n", value);
    }

    return EXIT_SUCCESS;
}

