#include "elastic_hashing.h"


hashtable *create_table(int capacity){
    hashtable *table=(hashtable*)malloc(sizeof(hashtable));
    table->capacity=capacity;
    table->size=0;
    table->array=(slot*)malloc(capacity*sizeof(slot));
    for(int i=0;i<capacity;i++){
        table->array[i].occupied=false;
    }
    return table;
}

int probesequence(int key,int attempt ,int capacity){
    
    return (key+attempt)%capacity;
}



bool insert(hashtable *table,int key){
    if (table->size>=table->capacity*(1-delta)){
        printf("table is full\n");
        return false;
    }

    int attempt=0;
    while(attempt<max_probes){
        int index=probesequence(key,attempt,table->capacity);
        if(!table->array[index].occupied){
            table->array[index].key=key;
            table->array[index].occupied=true;
            table->size++;
            return true;

        }
        attempt++;
    }

    printf("failed to insert key %d after %d probes\n",key,max_probes);
    return false;
}

bool search(hashtable *table,int key){
    int attempt=0;
    while(attempt<max_probes){
        int index=probesequence(key,attempt,table->capacity);
        if (table->array[index].occupied&&table->array[index].key==key){
            return true;
        }
        if (!table->array[index].occupied){
            break;
        }
        attempt++;
    }
    return false;
}

