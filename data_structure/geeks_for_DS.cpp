#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;


int remove_duplicates(vector<int>& arr){
    unordered_set<int> s;
    int index=0;
    for(int i=0;i<arr.size();i++){
        if (s.find(arr[i])==s.end()){
            s.insert(arr[i]);
            arr[index++]=arr[i];
        }
    }

    return s.size();
    
}

int largest(vector<int>&arr){
    int max=arr[0];

    for(int i=1;i<arr.size();i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }

    return max;
}

int largest_2(vector<int> &arr){
    return *max_element(arr.begin(),arr.end());
}


void reverse_array(vector<int>&arr){
    int left=0,right=arr.size()-1;

    while(left<right){
        swap(arr[left],arr[right]);

        left++;

        right--;
    }
}

void reverse_array_2(vector<int>&arr){

    for(int i=0;i<arr.size()/2;i++){
        swap(arr[i],arr[arr.size()-1-i]);
    }

}

void reverse_array_3(vector<int> &arr,int l,int r){

    if (l>=r){
        return;
    }

    swap(arr[l],arr[r]);

    reverse_array_3(arr,l+1,r-1);
}

void reverse_array_4(vector<int> &arr){
    reverse(arr.begin(),arr.end());
}

void rotate_arr(vector<int>&arr,int d){
    int n=arr.size();
    
    for(int i=0;i<d;i++){
        int last=arr[n-1];
        for(int j=n-1;j>0;j--){

            arr[j]=arr[j-1];
        }

        arr[0]=last;
    }
}

void rotate_array_2(vector<int> &arr,int d){
    int n=arr.size();
    
    d%=n; //deal d size bigger than arr size condition

    vector<int> temp(n);

    //copy the number of d elements to temp
    for (int i=0;i<d;i++){
        temp[i]=arr[n-i-1];
    }

    //copy left data to temp
    for(int i=0;i<n-d;i++){
        temp[i+d]=arr[i];
    }

    //copy all temp data to arr
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }


}

int gcd(int a,int b){
    if (a%b==0){
        return b;
    }
    return gcd(b,a%b);
}
void rotate_array_3(vector<int> &arr,int d){
    int n=arr.size();
    
    //deal with d > size of array
    d%=n;

    //cal the number of cycles in the rotation
    int cycles=gcd(n,d);

    for(int i=0;i<cycles;i++){
        
        //start index of current cycle
        int curridx=i;
        int currele=arr[curridx];
        
        do{
          int nextidx=(curridx+d)%n;
          int nextele=arr[nextidx];  

          arr[nextidx]=currele;

          currele=nextele;

          curridx=nextidx;

          
        }while(curridx!=i);
    }
    
}

void  rotate_array_4(vector<int> &arr,int d){
    int n=arr.size();

    d%=n;

    reverse(arr.begin(),arr.end()); //first reverse

    reverse(arr.begin(),arr.begin()+d); //reverse first d elements

    reverse(arr.begin()+d,arr.end()); // reverse the remaining n-d elements
    

}

void pushzerostoend(vector<int>&arr){
    int count=0;

    for(int i=0;i<arr.size();i++){
        arr[count++]=arr[i];
    }

    while(count<arr.size()){
        arr[count++]=0;
    }
}

void pushzerostoend_2(vector<int>&arr){

    int count=0;

    for(int i=0;i<arr.size();i++){
        if (arr[i]!=0){
            swap(arr[i],arr[count]);

            count++;
        }
    }

}

void pushzerostoend_3(vector<int>&arr){
    stable_partition(arr.begin(),arr.end(),[](int n){return n!=0;});
}

bool odd(int i){return (i%2)==1;}

struct node{
    int data;

    node *next;

    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};


void traversel_linked_list(struct node *head){
    struct node * current=head;

    while(current!=nullptr){
        printf("%d ",current->data);
        current=current->next;
    }

    printf("\n");
}

bool search_linked_list(struct node *head,int target){
    while(head!=nullptr){
        if (head->data==target){
            return true;
        }

        else{
            head=head->next;
        }
    }
    return false;
}


int findlength(struct node *head){
    int length=0;

    struct node *curr=head;

    while(curr!=nullptr){
        length++;
        curr=curr->next;
    }

    return length;
}

struct node * insert_at_beginning(struct node * head,int value){
    struct node* newnode=new node(value);
    
    newnode->next=head;

    head=newnode;
    
    return head;
    
}

struct node * insert_at_end(struct node * head,int value){

    struct node* newnode=new node(value);

    if (head==nullptr){
        return newnode;
    }

    node *curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=newnode;

    return head;
    
}

struct node * insertpos(struct node * head,int pos,int data){
    if (pos<1){
        printf("\ninvalid position!\n");
        return head;
    }

    if (pos==1){
        struct node *temp=new node(data);
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
    
    struct node *temp=new node(data);
    temp->next=prev->next;
    prev->next=temp;

    return head;
}

struct node *remove_first_node(struct node *head){
    if (head==nullptr){
        return nullptr;
    }

    struct node *temp=head;
    head=head->next;

    delete temp;

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
        delete temp;
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

    delete temp;

    return head;


}


int main(){

    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushzerostoend_3(arr);


    for(int i = 0; i < arr.size(); i++) 
    cout << arr[i] << " ";
    cout<<endl;





    
    return 0;
}