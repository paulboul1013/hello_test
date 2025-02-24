#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

int countnodes(struct node * node){
    int count=1;
    struct node * curr=node;
    while(curr->next!=node){
        count++;
        curr=curr->next;
    }
    return count;
}

int countnodesinloop(struct node *head){
    struct node *slow=head,*fast=head;
    
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if (slow==fast){
            return countnodes(slow);
        }

    }
    return 0;

}

struct node * createnode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}


int main(){


    struct node *head=createnode(1);
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);
    head->next->next->next->next=createnode(5);

    head->next->next->next->next->next = head->next;

    printf("%d\n",countnodesinloop(head));

    

    return 0;
}