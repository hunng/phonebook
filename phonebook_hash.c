#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

/* original version */
entry *findName(char lastName[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *hashfindName(char fName[], table *tabb)
{
    unsigned int key = hashit(fName) % TABLE_SIZE;
    /* use the original func to find the last linked list in hash table */
    if (tabb->store[key] != NULL)
        return findName(fName,tabb->store[key]);

    return NULL; /* not found */
}

void append(char newName[], table *tabb)
{
    unsigned int key = hashit(newName) % TABLE_SIZE;
    if (tabb->store[key] == NULL) {
        tabb->store[key] = (entry *) malloc(sizeof(entry));
        strcpy(tabb->store[key]->lastName, newName);
        tabb->store[key]->pNext = NULL;
    } else {
        entry *tmp = tabb->store[key];
        while (tmp->pNext != NULL)
            tmp = tmp->pNext;
        tmp->pNext = (entry *) malloc(sizeof(entry));
        strcpy(tmp->pNext->lastName, newName);
        tmp->pNext->pNext = NULL;
    }

}

unsigned int hashit(char lastName[])
{
    unsigned int seed = 131;
    unsigned int value = 0;
    while (*lastName) {
        value = value * seed + (*lastName++);
    }
    return value;
}
