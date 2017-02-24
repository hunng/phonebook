#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

entry *hashfindName(char fName[], table *tabb)
{
    unsigned int key = hashit(fName);
    entry *tmp = tabb->store[key][0];

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
    entry *tmp = tabb->store[key][0];
    if (tmp == NULL) {
        /* the key didnt store anything */
        tmp = tabb->store[key][0] = (entry *) malloc(sizeof(entry));
        strcpy(tmp->lastName, newName);
        tmp->pNext = NULL;
        /* first entry is the last entry now */
        tabb->store[key][1] = tabb->store[key][0];
    } else {
        /* the key have store something, append new key from last entry */
        tmp = tabb->store[key][1]->pNext = (entry *) malloc(sizeof(entry));
        strcpy(tmp->lastName, newName);
        tmp->pNext = NULL;
        tabb->store[key][1] = tmp;
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
