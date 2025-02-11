#ifndef HEAD_FILE
#define HEAD_FILE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define max_probes 1000
#define delta 0.1

typedef struct{
    int key;
    bool occupied;
}slot;

typedef struct {
    slot *array;
    int size;
    int capacity;
}hashtable;



hashtable *create_table(int capacity);
int probesequence(int key,int attempt ,int capacity);
bool insert(hashtable *table,int key);
bool search(hashtable *table,int key);






#endif