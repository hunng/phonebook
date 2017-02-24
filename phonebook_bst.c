#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_bst.h"

node *bstfindName(char fName[], node *troot)
{
    if (fName[0] - troot->str[0] == 0) { /* first letter same */
        node *tmp = troot->pLeft[0];
        while (tmp != NULL) {
            if (strcasecmp(fName, tmp->str) == 0)
                return tmp;
            tmp = tmp->pLeft[0];
        }
        return NULL;
    } else
        return bstfindName(fName, troot->pRight);
}

void append(char aName[], node *troot)
{
    if (strlen(troot->str) == 0) { /* had not use this node*/
        strcpy(troot->str, aName);
        troot->pLeft[0] = troot->pLeft[1] = troot->pRight = NULL;
    } else {
        int cmp = aName[0] - troot->str[0];
        if ( cmp == 0 ) {
            node *tmp = troot->pLeft[0];
            if(tmp == NULL) {
                tmp = troot->pLeft[0] = (node *) malloc(sizeof(node));
                strcpy(tmp->str, aName);
                tmp->pLeft[0] = tmp->pLeft[1] = tmp->pRight = NULL;
                troot->pLeft[1] = troot->pLeft[0];
            } else {
                tmp = troot->pLeft[1]->pLeft[0] = (node *) malloc(sizeof(node));
                strcpy(tmp->str, aName);
                tmp->pLeft[0] = tmp->pLeft[1] = tmp->pRight = NULL;
                troot->pLeft[1] = tmp; /* make last one be */
            }
        } else { /* other first letter */
            node *tmp = troot->pRight;
            if(tmp == NULL) {
                tmp = troot->pRight = (node *) malloc(sizeof(node));
                strcpy(tmp->str, aName);
                tmp->pLeft[0] = tmp->pLeft[1] = tmp->pRight = NULL;
            } else
                append(aName, tmp);
        }
    }
}

