#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

entry *hashfindName(char fName[], table *tabb)
{
    unsigned int key = hashit(fName);

    /* find from the first entry */
    entry *tmp = tabb->store[key][FIRST];

    while (tmp != NULL) {
        if (strcasecmp(fName, tmp->lastName) == 0)
            return tmp;
        tmp = tmp->pNext;
    }

    return NULL;
}

void append(char newName[], table *tabb)
{
    unsigned int key = hashit(newName);
    /* check whether it has the first entry */
    entry *tmp = tabb->store[key][FIRST];
    if (tmp == NULL) {
        /* the key didnt store anything */
        tmp = tabb->store[key][FIRST] = (entry *) malloc(sizeof(entry));
        strcpy(tmp->lastName, newName);
        tmp->pNext = NULL;

        /* first entry is the last entry now */
        tabb->store[key][LAST] = tabb->store[key][FIRST];
    } else {
        /* the key have store something, append new key from last entry */
        tmp = tabb->store[key][LAST]->pNext = (entry *) malloc(sizeof(entry));
        strcpy(tmp->lastName, newName);
        tmp->pNext = NULL;
        /* update the last entry */
        tabb->store[key][LAST] = tmp;
    }
}

unsigned int hashit(char lastName[])
{
    unsigned int seed = 131;
    unsigned int value = 0;
    while (*lastName) {
        value = value * seed + (*lastName++);
    }
    return value % TABLE_SIZE;
}
