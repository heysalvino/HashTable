// HashTable Implementation Starter Code
// CMS 230, 2017

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hashtable struct definitions and function prototypes
#include "hashtable.h"


//*** Hash a string to an integer ***//
// Input
//    char *s: the string to hash
// Output
//    The integer hash code
//
// Implements the basic hashing String hashing algorithm used by Java.
unsigned long int hash(char *s) {
    unsigned long int h = 0;

    int i;
    for (i = 0; i < strlen(s); i++) {
        h += h * 31 + (unsigned long int) s[i];
    }

    return h;
}


//*** Create a new hashtable_t ***//
// Input
//    tableSize: the number of buckets in the new table
// Output
//    A pointer to the new table
HashTable * hashtableInit(int tableSize) {
    
    // Allocate memory for a new HashTable
    HashTable *hashtable = malloc(sizeof(HashTable));
    
    // Allocate memory for an array of buckets and assign
    // them to the table's buckets field
    //HashNode **buckets = malloc(sizeof(HashNode) * tableSize);
    hashtable->buckets = malloc(tableSize * sizeof(HashNode *));
    
    // Set the new HashTable's size field
    hashtable->size = tableSize;
    
    // Return the new HashTable
    return hashtable; 
}


//*** Insert a key-value pair into a table ***//
// Inputs
//    hashtable *h: the hashtable performing the insertion
//    char *key: the key string
//    char *value: the value string
// Output
//    Nothing
void hashtableInsert(HashTable *h, char *key, char *value) {
    unsigned long int HashFunction = hash(key);
    int hashVal = HashFunction % h->size;
    
    if (h->buckets[hashVal] == NULL){
        HashNode *node = malloc(sizeof(HashNode*));
        node->key = key;
        node->value = value;
        node->next = NULL;
        h->buckets[hashVal] = node;
    } else {
        HashNode *newNode = malloc(sizeof(HashNode*));
        newNode->key = key;
        newNode->value = value;
        newNode->next = h->buckets[hashVal];
        h->buckets[hashVal] = newNode;
    }
}


//*** Lookup the value associated with a particular key ***//
// Inputs
//    hashtable_t *h: the table
//    char *key: the key to find
// Output
//    The char *value associated with the key or NULL if no match exists
char * hashtableLookup(HashTable *h, char *key) {
    unsigned long int HashFunction = hash(key);
    int hashVal = HashFunction % h->size;
    
    HashNode *node = malloc(sizeof(HashNode));
    node = h->buckets[hashVal];
    
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        } else {
            node = node->next;
        }
    }
    
    return NULL;
}


//*** Remove a key-value pair from the table if it exists ***//
// Inputs
//    hashtable_t *h: the table
//    char *key: the key to find and remove
// Output
//    The char *value associated with the key or NULL if no match exists
//    The pair is removed if it exists in the table
char * hashtableRemove(HashTable *h, char *key) {
    int hashFunction = hash(key);
    int hashVal = hashFunction % h->size;
    
    HashNode *node = malloc(sizeof(HashNode*));
    node = h->buckets[hashVal];
    HashNode *lastNode = malloc(sizeof(HashNode*));
    lastNode = NULL;
    
    while (node != NULL) {
        if (strcmp(node->key,key) == 0) {
            if (lastNode == NULL) {
                h->buckets[hashVal] = node->next;
            } else {
                lastNode->next = node->next;
            }
            return node->value;
        }
        lastNode = node;
        node = node->next;
    }
    
    return NULL;
}


//*** Print a hashtable ***//
// Input
//    hashtable_t *h: the table
void hashtablePrint(HashTable *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        HashNode *node = h->buckets[i];
        printf("Contents of bucket %d:\n", i);

        while (node != NULL) {
            printf("    <%s, %s>\n", node->key, node->value);
            node = node->next;
        }
    }
}

//*** There is no main function --- use the Python test script ***//