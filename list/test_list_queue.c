#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// #include "list.h"
// #include "queue.h"
#include "queue.c"
#include "list.c"

void check_len_queue(struct list_head *head){
    int len_queue=q_size(head);
    printf("The number elements in the queue:%d\n",len_queue);

}

void check_insert_success(struct list_head *head,char *test_str,int choice){

    int insert_status=0;
    if(choice==0){
        insert_status=q_insert_head(head,test_str);
    }else{
        insert_status=q_insert_tail(head,test_str);

    }

    if (insert_status){
        printf("insert success\n");
    }else{
        printf("insert failed\n");
    }
}

void print_queue_list(struct list_head *head)
{
    struct list_head *node,*safe;
    printf("[");
    list_for_each_safe(node,safe,head){
        printf(" %s ",list_entry(node,element_t,list)->value);
        
    }
    printf("]\n");
}

void insert_multiple(struct list_head *head,int count,char *str){
    for(int i=0;i<count;i++){
        q_insert_head(head,str);
    }
}

int main(){


    struct list_head *q=q_new();
    struct list_head *q2=q_new();

    
    
    char test_str[]="HELLO,QUEUE";
    int choice_insert_head_tail=1; //0: head,1:tail

    // check_insert_success(q,test_str,choice_insert_head_tail);
    
    q_insert_head(q,"offican");
    q_insert_head(q,"paul");
    q_insert_tail(q,"MAYU");
    q_insert_tail(q,"KKKKK");
    q_insert_head(q,"WISE");
    q_insert_tail(q,"dona");
    q_insert_tail(q,"dona");
    q_insert_tail(q,"dona");
    q_insert_tail(q,"dona");
    q_insert_tail(q,"dona");
    q_insert_head(q,"parrot");
    q_insert_tail(q,"shyla");

    char save_pointer[]=""; //save remove string of array

    printf("remove string:%s\n",save_pointer);


    q_remove_head(q,save_pointer,5);
    q_remove_tail(q,save_pointer,5);
    q_delete_mid(q);
    q_delete_dup(q);

    check_len_queue(q);

    print_queue_list(q);

    q_swap(q);

    print_queue_list(q);

    q_reverse(q);

    printf("reverse list:");
    print_queue_list(q);

    printf("reverse list k=3:");
    q_reverseK(q,3);
    print_queue_list(q);

    q_ascend(q);
    print_queue_list(q);

    q_descend(q);
    print_queue_list(q);


    printf("q insert mulitple:");
    insert_multiple(q,3,"hello");
    insert_multiple(q,10,"3");
    insert_multiple(q,7,"7");
    print_queue_list(q);

    printf("q2 insert mulitple:");
    insert_multiple(q2,20,"world");
    print_queue_list(q2);

    printf("q_sorted:");
    q_sort(q,0);
    print_queue_list(q);


    printf("merge queue:");
    merge_queue(q,q2);
    print_queue_list(q);


    q_free(q2);
    q_free(q);


    return 0;
}