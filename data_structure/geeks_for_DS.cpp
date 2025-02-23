#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <stack>
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

node * delete_k(node *head,int k){
    //if list is emtpy or k is 0
    if (head==nullptr||k<=0){
        return head;
    }

    node *curr=head;
    node *prev=nullptr;

    int count=0;

    while(curr!=nullptr){
        count++;

        if (count%k==0){
            if (prev!=nullptr){
                prev->next=curr->next;
            }
            else{
                head=curr->next;
            }
        }
        else{
            prev=curr;
        }
        curr=curr->next;
    }

    return head;
}

void printlist(node *head){
    node *curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;   
    }
}
int getlength(node *head){
    int length=0;
    while(head){
        length++;
        head=head->next;
    }
    return length;
}

int getmiddle(node *head){
    int length=getlength(head);

    int mid_index=length/2;
    while(mid_index--){
        head=head->next;
    }
    return head->data;
}

int get_middle_2(struct node *head){
    struct node *slow_ptr=head;
    struct node *fast_ptr=head;

    while(fast_ptr!=NULL&&fast_ptr->next!=NULL){
        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
    }

    return slow_ptr->data;
}

int count_value_in_linklist(struct node *head,int key){
    if (head==NULL){
        return 0;
    }
    int ans=count_value_in_linklist(head->next,key);

    if (head->data==key){
        ans++;
    }

    return ans;
    
}

int count_value_in_linklist_no_recursion(struct node *head,int key){
    struct node *curr=head;
    int count=0;
    while(curr!=NULL){
        if (curr->data==key){
            count++;
        }
        curr=curr->next;
    }
    return count;
}

void printlist_circurly_list(struct node *curr,node *head){
    if (head==nullptr){
        return;
    }
    cout<<curr->data<<" ";

    if (curr->next==head){
        return;
    }
    
    printlist_circurly_list(curr->next,head);
}

void printlist_circurly_list_no_recursion(struct node *head){
    if (head==nullptr){
        return;
    }

    struct node *curr=head;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;
}

bool isCircular(struct node *head){
    if (!head){
        return true;
    }
    
    struct node *curr=head;
    while(curr&&curr->next!=head){
        curr=curr->next;
    }

    if (!curr){
        return false;
    }
    
    return true;
}

bool iscircular_slow_fast_ptr(struct node *head){
    if (!head){
        return true;
    }

    struct node *slow=head;
    struct node *fast=head->next;

    while(fast&&fast->next){
        if (slow==fast){
            return true;
        }
        slow=slow->next;
        fast=fast->next->next;
    }

    return false;
}

int countnodes_circulrlist(struct node *head){
    if (head==nullptr){
        return 0;
    }

    struct node *curr=head;
    int result=0;
    do{
        curr=curr->next;
        result++;
    }while(curr!=head);

    return result;
}

node *delet_first_node_circulr_list(struct node *last){
    if (last==nullptr){
        cout<<"List is empty "<<endl;
        return nullptr;
    }

    struct node *head=last->next;
    
    if (head==last){
        delete head;
        last=nullptr;
    }else{
        last->next=head->next;
        delete head;
    }

    return last;
    
}


void print_list_circular(struct node *last){
    if (last==NULL){
        return;
    }
    struct node *head=last->next;

    while(true){
        cout<<head->data<<" ";
        head=head->next;
        if (head==last->next) break;
    }
    cout<<endl;
}

struct node * delete_specific_node(struct node *last,int key){
    if (last==nullptr){
        cout<<"list is empty , nothing to delete"<<endl;
        return nullptr;
    }

    node *curr=last->next;
    node *prev=last;

    if (curr==last&&curr->data==key){
        delete curr;
        last=nullptr;
        return last;
    }

    if (curr->data==key){
        last->next=curr->next;
        delete curr;
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
        delete  curr;
    }else{
        cout<<"Node with data "<<key<<" not found."<<endl;
    }

    return last;
}

void convert_singlelist_to_circularlist(struct node *curr,struct node *head){
    if (curr->next==nullptr){
        curr->next=head;
        return;
    }

    convert_singlelist_to_circularlist(curr->next,head);
}


struct node * convert_singlelist_to_circularlist_no_recursion(struct node *head){
    struct node *curr=head;

    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=head;

    return head;
}

struct node *exchangesnodes(struct node *head){
       // If list is of length less than 2
       if (head == NULL || head->next == NULL) {
        return head;
    }
    node* tail = head;
   
    // Find pointer to the last node
    while (tail->next != head) {
        tail = tail->next;
    }
    /* Exchange first and last nodes using
       head and p */
   
    // temporary variable to store
    // head data
    int temp = tail->data; 
    tail->data = head->data;
    head->data = temp;
    return head;
}

struct node *reverselist(struct node *head){
    struct node *curr=head;
    struct node *prev=nullptr,*next;

    while(curr!=nullptr){
        next=curr->next;

        curr->next=prev;

        prev=curr;

        curr=next;
    }

    return prev;
}

struct node *reverselist_2(struct node *head){
    if (head==NULL||head->next==NULL){
        return head;
    }
    struct node *reset=reverselist_2(head->next);

    head->next->next=head;
    head->next=NULL;
    
    return reset;
}

struct node *reverselist_stack(struct node *head){
    stack<node*> s;
    struct node *temp=head;
    while(temp->next!=NULL){
        s.push(temp);
        temp=temp->next;
    }

    head=temp;

    while(!s.empty()){
        temp->next=s.top();
        
        s.pop();

        temp=temp->next;
    }

    temp->next=NULL;

    return head;
}

void pairwiseswap(struct node *head){
    if (head==nullptr||head->next==nullptr){
        return;
    }

    swap(head->data,head->next->data);

    pairwiseswap(head->next->next);
}

void paireiseswap_2(struct node *head){
    struct node *curr=head;
    while(curr!=nullptr&&curr->next!=nullptr){
        swap(curr->data,curr->next->data);
        curr=curr->next->next;
    }
}

int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);

    printlist(head);
    cout<<endl;

    paireiseswap_2(head);

    
    printlist(head);
    
    return 0;
}