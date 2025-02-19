#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *createnode(int value){
    struct node * newnode=(struct node*)malloc(sizeof(struct node));
    
    newnode->data=value;
    newnode->next=newnode;

    return newnode;
}

void printlist(struct node *last){
    if (last==NULL) return;

    struct node *head=last->next;
    while(1){
        printf("%d ",head->data);
        head=head->next;
        if (head==last->next) break;
    }

    printf("\n");
}

struct node * insertinemptylist(struct node *last,int data){
    if (last!=NULL){
        return last;
    }
    
    struct node *newnode=createnode(data);

    last=newnode;

    return last;
}


struct node *inserbeginning(struct node *last,int value){
    struct node *newnode=createnode(value);

    if (last==NULL){
        newnode->next=newnode;
        return newnode;
    }

    newnode->next=last->next;
    last->next=newnode;

    return last;
}

struct node *insertend(struct node *tail,int value){
    struct node *newnode=createnode(value);

    if (tail==NULL){
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}

struct node *insertposition(struct node *last,int data,int pos){
    if (last==NULL){
        if (pos!=1){
            printf("invalid posistion!\n");
            return last;
        }
        struct node *newnode=createnode(data);
        last=newnode;
        last->next=last;
        return last;
    }

    struct node *newnode=createnode(data);

    struct node *curr=last->next;

    if (pos==1){
        newnode->next=curr;
        last->next=newnode;
        return last;
    }

    for(int i=1;i<pos-1;i++){
        curr=curr->next;

        if (curr==last->next){
            printf("invalid position!\n");
            return last;
        }
    }

    newnode->next=curr->next;
    curr->next=newnode;

    if (curr==last) last=newnode;

    return last;

}

struct node *deletspecifinode(struct node *last ,int key){
    if (last==NULL){
        printf("list is empty, nothing ot delete.\n");
        return NULL;
    }

    struct node *curr=last->next;
    struct node *prev=last;

    if (curr==last&&curr->data==key){
        free(curr);
        last=NULL;
        return last;
    }

    if (curr->data==key){
        last->next=curr->next;
        free(curr);
        return last;
    }

    while(curr!=last&&curr->data!=key){
        prev=curr;
        curr=curr->next;
    }


    if (curr->data==key){
        prev->next=curr->next;
        if (curr==last){
            last=prev;
        }

        free(curr);
    }else{
        printf("Node with data %d not found.\n",key);
    }

    return last;

}

int search(struct node *last ,int key){
    if (last==NULL){
        return 0;
    }

    struct node *head=last->next;

    struct node *curr=head;

    while(curr!=last){
        if (curr->data==key){
            return 1;
        }
        curr=curr->next;
    }

    if (last->data==key){
        return 1;
    }
    
    return 0;
}


int main(){

    struct node *last=NULL;

    last=insertinemptylist(last,5);

    last=inserbeginning(last,44);

    last=insertend(last,3333);

    last=insertposition(last,11111,1);

    last=insertposition(last,999999,5);


    printf("list after insertion: ");
    printlist(last);


    int found=search(last,999999);
    if (found){
        printf("found it \n");
    }
    else{
        printf("not found it\n");
    }

    last=deletspecifinode(last,999999);
    printlist(last);


    last=deletspecifinode(last,11111);
    printlist(last);

    last=deletspecifinode(last,5);
    printlist(last);

    
    return 0;
}