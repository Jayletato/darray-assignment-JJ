#include <stdlib.h>
#include <stdio.h>

typedef struct darray{
    size_t array_size;
    int *array_object;
} darray;

darray *da_create()
{
   darray *new_array = (darray *)malloc(sizeof(darray));
   if (new_array == NULL) {
        free(new_array);
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
        return &(array->array_object[idx]);
    }
}

void da_append(darray *array, int value)
{
    darray *temp_array1 = realloc(array, sizeof(array) * sizeof(int));
    if (temp_array1 == NULL){
        printf("Realloc error 1 in append");
        free(temp_array1);
        goto append_end;
    }
    array = temp_array1;

    array->array_size += sizeof(int);
    
    darray *temp_array2 = realloc(array->array_object, sizeof(array) * sizeof(int));
    if (temp_array2 == NULL){
        printf("Realloc error 2 in append");
        free(temp_array2);
        goto append_end;
    }
    array->array_object = temp_array2;
    array->array_object[(sizeof(array) * sizeof(int))] = value;
    
    append_end:  
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