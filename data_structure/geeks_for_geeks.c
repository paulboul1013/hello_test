#include <stdio.h>
#include <stdlib.h>

void subarray(int arr[],int n){
    
    for(int i=0;i<n;i++){

        for(int j=i;j<n;j++){

            for(int k=i;k<=j;k++){

                printf("%d ",arr[k]);
            }
            printf("\n");
        }
    }
}


int remove_duplicates(int arr[],int n){
    if (n<=1){
        return n;
    }
    int idx=1;

    for(int i=1;i<n;i++){
        if (arr[i]!=arr[i-1]){ //比較前後兩個元素是否相同，不相同才可放入原本陣列
            arr[idx++]=arr[i];
        }
    }
    return idx;
}

int array_sort_or_not(int arr[],int n){
    if (n==0||n==1){
        return 1;
    }

    for(int i=1;i<n;i++){
        if (arr[i-1]>arr[i]){ //sorted是遞增數列，比較是否小於後面元素，否則就是unsorted array
            return 0;
        }
    }
    //sorted array
    return 1;
}


int arraySorytedOrNot(int arr[],int n){
    if (n==1||n==0){
        return 1;
    }

    return arr[n-1]>=arr[n-2] && arraySorytedOrNot(arr,n-1);
}

int largest(int arr[],int n){
    int i;
    int max=arr[0];

    for(i=1;i<n;i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b); //用於比較中的大於
}

int largest_2(int arr[],int n){
    qsort(arr,n,sizeof(int),compare);
    return arr[n-1];
}

void reverse_array(int arr[],const int  n){
    int *temp=(int*)malloc(sizeof(int)*n);

    //copy arr reverse order element to temp  
    for(int i=0;i<n;i++){
        temp[i]=arr[n-i-1];
    }

    //copy temp element to arr
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
    free(temp);
    temp=NULL;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void reverse_array_2(int arr[],const int n){
    int left=0,right=n-1;
    while(left<right){
        swap(&arr[left],&arr[right]);

        left++;

        right--;
    }
}


void rotatearr(int arr[],int n,int d){
    for(int i=0;i<d;i++){
        int last=arr[n-1];
        for(int j=n-1;j>0;j--){
            arr[j]=arr[j-1];
        }
        arr[0]=last;
    }
}

void pushzerostoend(int *arr,int n){
    int *temp=(int*)malloc(sizeof(int)*n);

    int j=0;//to keep track of the index in temp[]

    //copy non-zero element to temp[]
    for(int i=0;i<n;i++){
        if (arr[i]!=0){
            temp[j++]=arr[i];
        }
    }

    //fill with zero in temp[]
    while(j<n){
        temp[j++]=0;
    }

    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }

    
}

void pushzerostoend_2(int *arr,int n){

    int count=0;

    for(int i=0;i<n;i++){
        if (arr[i]!=0){
            arr[count++]=arr[i];
        }
    }

    while(count<n){
        arr[count++]=0;
    }

}

void pushzerostoend_3(int *arr,int n){

    int count=0;


    for(int i=0;i<n;i++){
        if (arr[i]!=0){
            int temp=arr[i];
            arr[i]=arr[count];
            arr[count]=temp;

            count++;
        }
    }

}

struct node{
    int data;
    struct node*next;
};

struct node *newnode(int data)
{
    struct node * temp=(struct node*)malloc(sizeof(struct node));

    temp->data=data;
    temp->next=NULL;

    return temp;
    
}

void traversel_linked_list(struct node *head){
    struct node * current=head;

    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }

    printf("\n");
}

int search_linked_list(struct node *head,int target){
    while(head!=NULL){
        if (head->data==target){
            return 1;
        }

        else{
            head=head->next;
        }
    }
    return 0;
}

struct node * insert_at_beginning(struct node * head,int value){
    struct node* temp=newnode(value);
    
    temp->next=head;

    head=temp;
    
    return head;
    
}

struct node * insert_at_end(struct node * head,int value){

    struct node* temp=newnode(value);

    if (head==NULL){
        return temp;
    }

    struct node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;

    return head;
    
}

struct node * insertpos(struct node * head,int pos,int data){
    if (pos<1){
        printf("\ninvalid position!\n");
        return head;
    }

    if (pos==1){
        struct node *temp=newnode(data);
        temp->next=head;
        return temp;
    }

    struct node* prev=head;
    int count=1;
    while(count<pos-1&&prev!=NULL){
        prev=prev->next;
        count++;
    }

    if (prev==NULL){
        printf("Invalid position!\n");
        return head;
    }
    
    struct node *temp=newnode(data);
    temp->next=prev->next;
    prev->next=temp;

    return head;
}


int findlength(struct node *head){
    int length=0;

    struct node *curr=head;

    while(curr!=NULL){
        length++;
        curr=curr->next;
    }

    return length;
}

struct node *remove_first_node(struct node *head){
    if (head==NULL){
        return NULL;
    }

    struct node *temp=head;
    head=head->next;

    free(temp);

    return head;
}

struct node *remove_last_node(struct node *head){
    if (head==NULL){
        return NULL;
    }
    if (head->next==NULL){
        free(head);
        return NULL;
    }

    struct node *second_last=head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    
    free(second_last->next);

    second_last->next=NULL;

    return head;

}

struct node *deletatposition(struct node *head,int pos){
    if (head==NULL|pos<1){
        return head;
    }

    if (pos==1){
        struct node *temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    struct node *curr=head;

    for(int i=1;i<pos-1&&curr!=NULL;i++){
        curr=curr->next;
    }

    if (curr==NULL||curr->next==NULL){
        return head;
    }
    
    struct node *temp=curr->next;

    curr->next=curr->next->next;

    free(temp);

    return head;


}


int main(){
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    pushzerostoend_3(arr, n);


    for(int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    

    return 0;
}
