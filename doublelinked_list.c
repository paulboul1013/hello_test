#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
} node;


struct node *create_node(int value){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));

    new_node->data=value;
    new_node->next=new_node->prev=NULL;
    return new_node;
}

struct noe *forwardtarversal(struct node * head){
    struct node *curr=head;

    while(curr!=NULL){
        printf("%d ",curr->data);

        curr=curr->next;
    }

    printf("\n");
}
void backwardtraversal(struct node *tail){
    struct node *curr=tail;

    while(curr!=NULL){
        printf("%d ",curr->data);

        curr=curr->prev;
    }

    printf("\n");
}

int findlength(struct node *head){
    int count=0;
    for(struct node *cur=head;cur!=NULL;cur=cur->next){
        count++;
    }
    return count;
}

struct node *insertbegin(struct node *head,int data){
    struct node *new_node=create_node(data);

    new_node->next=head;

    if (head!=NULL){
        head->prev=new_node;
    }

    return new_node;
}

void printlist(struct node *head){
    struct node *curr=head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}

struct node *insertend(struct node *head,int data){
    struct node *new_node=create_node(data);

    if (head==NULL){
        head=new_node;
    }

    else{
        struct node *curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }

        curr->next=new_node;
        new_node->prev=curr;
    }

    return head;
}

struct node * insertatposition(struct node *head,int pos,int data){
    struct node *new_node=create_node(data);

    if (pos==1){
        new_node=insertbegin(head,data);
        return new_node;
    }

    struct node *curr=head;

    for (int i=1;i<pos-1&&curr!=NULL;i++){
        curr=curr->next;
    }

    if (curr==NULL){
        printf("position is out of bounds\n");
        free(new_node);
        return head;
    }

    new_node->prev=curr;
    new_node->next=curr->next;

    curr->next=new_node;

    // If the new node is not the last node, update
  	//the prev of next node to new node
    if (new_node->next!=NULL){
        new_node->next->prev=new_node;
    }

    return head;

    

    
}

struct node *delhead(struct node*head){
    if (head==NULL){
        return NULL;
    }

    struct node *temp=head;

    head=head->next;

    if (head!=NULL){
        head->prev=NULL;
    }

    free(temp);

    return head;
}

struct node *dellast(struct node *head){
    if (head==NULL){
        return NULL;
    }
    if (head->next==NULL){
        free(head);
        return NULL;
    }

    struct node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }

    curr->prev->next=NULL;

    free(curr);

    return head;
}

struct node *delpos(struct node *head,int pos){
    if (head==NULL){
        return head;
    }

    struct node * curr=head;

    for(int i=1;curr&&i<pos;i++){
        curr=curr->next;
    }

    if (curr==NULL){
        return head;
    }

    if (curr->prev){
        curr->prev->next=curr->next;
    }

    if (curr->next){
        curr->next->prev=curr->prev;
    }

    if (head==curr){
        head=curr->next;
    }

    free(curr);

    return head;
    
}

int main(){

    struct node *head=create_node(1);
    struct node *second=create_node(2);
    struct node *third=create_node(3);

    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    

    printf("forward traversal: ");
    forwardtarversal(head);


    printf("backware traversal:\n");
    backwardtraversal(third);

    printf("legnth of the doubly liked list: %d \n",findlength(head));

    head=insertbegin(head,89);

    printlist(head);

    head=insertbegin(head,1);

    printlist(head);

    third=insertend(third,88);

    printlist(head);


    head=insertatposition(head,2,3333);

    printlist(head);


    head=delhead(head);

    printlist(head);

    head=dellast(head);

    printlist(head);


    head=delpos(head,1);
    printlist(head);


    head=delpos(head,findlength(head));
    printlist(head);


    head=delpos(head,findlength(head)/2);
    printlist(head);


    free(head);
    free(second);
    free(third);

}