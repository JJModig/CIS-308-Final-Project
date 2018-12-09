#ifndef list_h
#define list_h

#include <stdlib.h>
#include <string.h>
//This implements a dynamic array.
//Solution taken from https://stackoverflow.com/questions/3536153/c-dynamically-growing-array
//and modified for strings: maximum 15 characters
#define STR_LEN 15
typedef struct List{
  char **array;
  size_t used;
  size_t size;
} List;

void initList(List *a, size_t initialSize) {
  	a->array = (char **) malloc(initialSize * sizeof(char*));
	for(int i=0; i<initialSize; i++) {
		a->array[i] = (char *) malloc((STR_LEN+1) * sizeof(char));
	}
  a->used = 0;
  a->size = initialSize;
}

void insertList(List *a, char *element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    	a->size *= 2;
    	a->array = (char **) realloc(a->array, a->size * sizeof(char*));
	for(int i=(a->size)/2; i< a->size; i++) {
		a->array[i] = (char *) malloc((STR_LEN+1) * sizeof(char));
	}
  }
  strcpy(a->array[a->used++], element);
}

void freeList(List *a) {
	for(int i=0; i < a->size; i++) {
		free(a->array[i]);
	}
  	free(a->array);
  	a->array = NULL;
  	a->used = a->size = 0;
}
#endif // list_h
