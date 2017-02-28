#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 256

#define TRI 1

/* use the opt version of struct */
typedef struct __PHONE_BOOK_ENTRY_DETAIL {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} entry_detail;

/* delete the pNext for reducing the space */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    entry_detail *pDetail;
} entry;

/* binary search tree node */
typedef struct __TRIE_NODE {
    /* if needed more information add a entry_detail */
    char str[MAX_LAST_NAME_SIZE];
    struct __TRIE_NODE *pLeft[2], *pRight;
} node;

node *triefindName(char fName[], node *troot);
void append(char aName[], node *troot);

#endif
