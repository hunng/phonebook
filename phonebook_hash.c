#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"
/* use a entry to avoid every call function need to create an entry */
entry *hashfindName(char fName[], table *tabb)
{
    unsigned int key = hashit(fName);
    entry *tmp = tabb->store[key];

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
    entry *tmp = tabb->store[key];
    if (tmp == NULL) {
        tmp = tabb->store[key] = (entry *) malloc(sizeof(entry));
        strcpy(tmp->lastName, newName);
        tmp->pNext = NULL;
    } else {
        while( tmp->pNext != NULL)
            tmp = tmp->pNext;
        tmp = tmp->pNext = (entry *) malloc(sizeof(entry));
        strcpy(tmp->lastName, newName);
        tmp->pNext = NULL;
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
