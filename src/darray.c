#include <stdlib.h>

typedef struct darray{
    int array_size;
    char array_object[];
} darray;

darray *da_create()
{
   darray *new_array = malloc(sizeof(darray));
   if (new_array = NULL) {
    return NULL;
    }
    (*new_array).array_size = 0;
    return new_array;
}


int *da_get(darray *array, size_t idx)
{
    
}

int da_append(darray *array, int value)
{}

size_t da_size(darray *array)
{
    if (array = NULL){
        return 0;
    }
    else {
        return array->array_size;
    }
}

void da_delete(darray *array)
{
    if  (array = NULL) {}
    else {
        free(array);
        array = NULL;
    }

}