#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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




int main(){


    srand(time(0));
    int capacity=100;
    hashtable *table=create_table(capacity);

    for(int i=0;i<90;i++){
        int key=rand()%1000;
        if (!insert(table,key)){
            printf("insertion failed for key %d \n",key);
        }
    }

    for(int i=0;i<100;i++){

        int key=rand()%1000;
        if (search(table,key)){
            printf("key %d found in table\n",key);
        }
        else{
            printf("key %d not found in table\n",key);
   
        }
    }

    free(table->array);
    free(table);

    

    

    return 0;
}