#include <stdlib.h>
#include <stdio.h>

typedef struct darray{
    size_t array_size;
    int *array_object;
} darray;

darray *da_create()
{
   darray *new_array = (darray *)malloc(sizeof(darray) + sizeof(int));
   if (new_array == NULL) {
    return NULL;
    }
    (*new_array).array_size = sizeof(int);

    new_array->array_object = (int *)malloc(sizeof(int));
    if (new_array->array_object == NULL) {
    free(new_array);
    return NULL;
    }
    return new_array;
}


int *da_get(darray *array, size_t idx)
{
    if ((array == NULL)||(idx > sizeof(array))||array->array_size == 0)
    {
        return NULL;
    }
    else {
        return array->array_object[idx];
    }
}

int da_append(darray *array, int value)
{
    darray *temp_array = realloc(array, sizeof(array) * sizeof(int));
    if (temp_array == NULL){
        printf("Realloc error 1 in append");
        return NULL;
    }
    array = temp_array;

    array->array_size = sizeof(int);
    
    darray *temp_array = realloc(array->array_object, sizeof(array) * sizeof(int));
    if (temp_array == NULL){
        printf("Realloc error 2 in append");
        return NULL;
    }
    array->array_object = temp_array;
}

size_t da_size(darray *array)
{
    if (array == NULL){
        return 0;
    }
    else {
        return array->array_size;
    }
}

void da_delete(darray *array)
{
    if  (array == NULL) {}
    else {
        free(array->array_object);
        free(array);
        array = NULL;
    }

}