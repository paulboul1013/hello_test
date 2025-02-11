#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "elastic_hashing.h"



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