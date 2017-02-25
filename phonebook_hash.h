#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 256

#define HAS 1

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

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    entry_detail *pDetail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

enum entryStore {
    FIRST,
    LAST
};

typedef struct __HASH_TABLE {
    entry *store[TABLE_SIZE][2];
} table;

entry *hashfindName(char lastName[], table *tabb);
void append(char lastName[], table *tabb);
unsigned int hashit(char lastName[]);

#endif
