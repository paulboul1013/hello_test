#ifndef QUEUE_lab
#define QUEUE_lab


#include <stdbool.h>
#include <stddef.h>
#include "list.h"


/*
 element_t - linked list element
 value : pointer to array string
 list: node of a doubly-linked list
*/
typedef struct{
    char *value; //needs to be explicity(顯性) allocated and free
    struct list_head list;
}element_t;

/*
    queue_context_t - the context manage a chain of queues
    q : pointer to head of queue
    chain :  use chaining the heads of queues
    size : the length of queue
    id : the unique identification number
*/
typedef struct{
    struct list_head *q;
    struct list_head chain;
    int size;
    int id;
} queue_context_t;


/*
    q_new() - create an empty whose next and prev pointer point to itself
    
    return : NULL for allocation failed
*/
struct list_head *q_new();


/*
    q_free() - free all stroage used by queue ,no effect if header is NULL
    head : header of queue
*/
void q_free(struct list_head *head);

/*
    q_size() - get the size of the queue
    head : header of queue

    return: the number of elements in queue, zero if queue is NULL or empty
*/
int q_size(struct list_head *head);


/*
    q_insert_head() - insert an element in the head index
    head: header of queue
    s: string will inserted
    

    return: true is success,false for allocation failed or queue is NULL
*/
bool q_insert_head(struct list_head *head ,char *s);


/*
    q_insert_head() - insert an element in the tail index
    head: header of queue
    s: string will inserted

    return: true is success,false for allocation failed or queue is NULL
*/
bool q_insert_tail(struct list_head *head ,char *s);

/*
    q_remove_head() - remove the element from head of queue
    head : header of queue
    sp : output buffer where the removed string is copied
    bufsize : size of the string
    注意:是移除，不是刪除，把prev和next link pointer給斷開，並把被移除的string移到sp  array of string pointer
*/  
element_t *q_remove_head(struct list_head *head,char *sp,size_t bufsize);


/*
    q_remove_tail() - remove the element from tail of queue
    head: header of queue
    sp : output buffer where the removed string is copied
    bufsize : size of the string
    注意:是移除，不是刪除，把prev和next link pointer給斷開，並把被移除的string移到sp  array of string pointer

*/

element_t *q_remove_tail(struct list_head *head,char *sp,size_t bufsize);


/*
    q_delete_mid() - delete the middle node in queue
    head: header of queue

    return: true of success,false if list is NULL or empty
*/
bool q_delete_mid(struct list_head *head);


/*
    q_release_element() - releaes the element
    e: element would be free
*/
static inline void q_release_element(element_t *e){
    return;
}

/*
    q_delete_dup() - delete all nodes that have duplicate string, leavning dinstinct strings from the original queue
    head: header of queue

    return: true for success, false if list is NULL or empty
*/

bool q_delete_dup(struct list_head *head);

/*
    void q_swap() - swap every two adjacent nodes
    head: header of queue
*/

void q_swap(struct list_head *head);


/*
    q_reverse() - reverse elements in queue
    head: header of queue

    no effect if queue is NULL or empty
    not allocate or free any list elements
*/

void q_reverse(struct list_head *head);


/*
    q_reverse() - reverse elements in queue
    head: header of queue

    no effect if queue is NULL or empty
    not allocate or free any list elements
*/


/*  q_reverse() - Given the head of a linked list, reverse the nodes of the list k at a time.
    head: header of queue
    k: is a positive integer and is less than or equal to the length of the linked list

    no effect if queue is NULL or empty

*/
void q_reverseK(struct list_head *head,int k);


/*
    q_sort() - sort elements of queue in ascending/descending order
    head:header of queue
    descend: whether or not to sort in desecending order 
*/
void q_sort(struct list_head *head,bool descend);


/*
    q_acend() - remove eveyy node which has 
    a node with a strictly less value anywhere to the right side of it

    head:header of queue
    one elment ,do thing 
    memory allocated to removed nodes must be free
*/
int q_descend(struct list_head *head);

/*
    q_acend() - remove eveyy node which has 
    a node with a strictly greater value anywhere to the right side of it

    head:header of queue
    one elment ,do thing 
    memory allocated to removed nodes must be free
*/
int q_ascend(struct list_head *head);


int merge_queue(struct list_head *first,struct list_head *second);

/*
    q_merge() - merge all the queues into one sorted queue,which is in ascending/descending order
    head:header of chain
    descend: determine to merge queues sorted in descending order
*/

int q_merge(struct list_head *head,bool descend);

#endif 
