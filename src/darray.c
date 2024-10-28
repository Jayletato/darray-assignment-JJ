#include <stdlib.h>

typedef struct darray{
    size_t array_size;
    int array_object[];
} darray;

darray *da_create()
{
   darray *new_array = (darray *)malloc(sizeof(darray));
   if (new_array == NULL) {
    return NULL;
    }
    (*new_array).array_size = 0;
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
    array = realloc(array, sizeof(array) + sizeof(int));
    array->array_size += 1;
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
        free(array);
        array = NULL;
    }

}