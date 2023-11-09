# HashTables in C

## Description

This project requires you to implement a hash table using structures in C. The primary goal is to create a hash table that supports various operations, including initialization, insert, lookup, remove, and print. Both the keys and values in the table will be of type char *, represented as null-terminated strings.

You should use the provided `hashtable.c` as a starting point for your implementation. The `hashtable.h` header file contains function prototypes and structure definitions.

By working on this project, you'll gain experience in memory allocation and structure implementation to build a non-trivial data structure. Additionally, you'll work with hash functions and arrays of pointers, which are valuable skills in computer science.

## Background

A hash table is a data structure used to store key-value pairs efficiently. It allows for average O(1) insert and lookup times as long as the load on the table is not too high. In a chained hash table, an array of buckets is used, with each bucket containing a linked list of nodes that store key-value pairs.

To insert a key-value pair into the table, you need to calculate an integer from the key and use it to determine the bucket that should hold the new pair. Here's a simplified pseudo-C implementation:

```c
void hashtableInsert(HashTable *h, char *key, char *value) {
    unsigned long int hashCode = hash(key); // Calculate the hash code from the key.
    int b = hashCode % h->size; // Determine the bucket index based on the hash code.
    // Insert the key-value pair into h->buckets[b]
}
```

In your implementation, you must create functions to insert, lookup, and remove key-value pairs from the table. You are not required to implement load-based rebalancing in this project.

It's important to note that the table can contain duplicate keys, and a lookup or remove operation will be satisfied by the first matching key encountered.

The provided `hashtable.c` already includes a hash function that implements Java's basic String hashing function. **Do not modify the hash function** because doing so may result in incorrect bucket assignments and mismatched test outputs.
