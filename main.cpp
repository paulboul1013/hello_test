#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <list>
#include <cstring>
#include <stack>
#include <queue>
#include <climits>
#include <map>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int x){
            data=x;
            next=nullptr;
        }
};

Node * sortedmerge(Node *head1,Node *head2){
    vector<int> arr;
    
    while(head1!=nullptr){
        arr.push_back(head1->data);
        head1=head1->next;
    }

    while(head2!=nullptr){
        arr.push_back(head2->data);
        head2=head2->next;
    }

    sort(arr.begin(),arr.end());

    Node *dummy=new Node(-1);
    Node *curr=dummy;

    for(int i=0;i<arr.size();i++){
        curr->next=new Node(arr[i]);
        curr=curr->next;
    }

    return dummy->next;

    
}

Node * sorted_merge_2(Node *head1,Node *head2){
    if (head1==nullptr){
        return head2;
    }
    if (head2==nullptr){
        return head1;
    }

    if (head1->data<=head2->data){
        head1->next=sorted_merge_2(head1->next,head2);
        return head1;
    }else{
        head2->next=sorted_merge_2(head1,head2->next);
        return head2;
    }
}

Node *removeduplicates(Node *head){
    unordered_set<int> st;

    Node *new_head=nullptr;
    Node *tail=nullptr;

    Node *curr=head;

    while(curr!=nullptr){

        if (st.find(curr->data)==st.end()){
            Node *new_Node=new Node(curr->data);
        
            if (new_head==nullptr){
                new_head=new_Node;
                tail=new_head;
            }else{
                tail->next=new_Node;
                tail=new_Node;
            }
            st.insert(curr->data);
        }

        curr=curr->next;
      
    }

    return new_head;

}

Node * removeduplicates_2(Node *head){
    Node * curr=head;
    while(curr!=NULL&&curr->next!=NULL){
        if (curr->data==curr->next->data){
            Node *next_next=curr->next->next;
            curr->next=next_next;
        }else{
            curr=curr->next;
        }

    }

    return head;
}

Node *get_tail(Node *curr){
    while(curr!=nullptr&&curr->next!=nullptr){
        curr=curr->next;
    }
    return curr;
}

Node *partition(Node *head,Node *tail){
    Node *pivot=head;

    Node *pre=head;
    Node *curr=head;

    while(curr!=tail->next)
    {
        
        if (curr->data<pivot->data){
            swap(curr->data,pre->next->data);

            pre=pre->next;
        }

        curr=curr->next;
    }
  
    

    

    swap(pivot->data,pre->data);

    return pre;
}

void quicksorthelper(Node * head,Node *tail){
    if (head==nullptr||head==tail){
        return;
    }

    Node *pivot=partition(head,tail);

    quicksorthelper(head,pivot);

    quicksorthelper(pivot->next,tail);
}

Node *quicksort(Node *head){
    Node *tail=get_tail(head);
    quicksorthelper(head,tail);
    return head;
}

void printlist(Node *curr){
    while(curr!=nullptr){
        cout<<curr->data;
        if (curr->next!=nullptr){
            cout<<" ";
        }
        curr=curr->next;
    }
    cout<<endl;
}

Node *rotate(Node *head,int k){
    if (k==0||head==nullptr){
        return head;
    }
    
    for(int i=0;i<k;i++){
        Node *curr=head;
        while (curr->next!=nullptr){
            curr=curr->next;
        }
        
        curr->next=head;
        curr=curr->next;
        head=head->next;
        curr->next=nullptr;
        
        
    }
    return head;
}

Node *rotate_2(Node* head,int k){
    if (k==0||head==nullptr){
        return head;
    }

    Node * curr=head;
    int len=1;

    while(curr->next!=nullptr){
        curr=curr->next;
        len+=1;
    }

    k%=len;

    curr->next=head;

    for(int i=1;i<k;i++){
        curr=curr->next;
    }

    head=curr->next;

    curr->next=nullptr;

    return head;
}

bool detectloop(Node *head){
    unordered_set<Node*> st;

    while (head!=nullptr){
        if (st.find(head)!=st.end()){
            return true;
        }
        st.insert(head);
        head=head->next;
    }

    return false;
}

bool detectloop_2(Node *head){

    Node *slow=head,*fast=head;

    while(slow&&fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if (slow==fast){
            return true;
        }
    }

    return false;

}

int cmp(const int &a,const int &b){
    return a>b;
}

int search(vector<int>&nums,int target){
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
        int middle=left+((right-left)/2);
        if (nums[middle]>target){
            right=middle-1;
        }else if (nums[middle]<target){
            left=middle+1;
        }else{
            return middle;
        }
    }

    return -1;
}

int search_2(vector<int>&nums,int target){

    int left=0;
    int right=nums.size();
    while(left<right){
        int middle=left+((right-left)>>1);
        if (nums[middle]>target){
            right=middle;
        }else if (nums[middle]<target){
            left=middle+1;
        }else{
            return middle;
        }
    }

    return -1;

}

int mysqrt(int x){
    if (x == 0)
        return x;
    int first = 1, last = x;
    while (first <= last) {
    int mid = first + (last - first) / 2;

    if (mid  == x / mid)
        return mid;
    else if (mid > x / mid) {
        last = mid - 1;
    }
    else {
        first = mid + 1;
    }
}
return last;
}


class box{
    public:
        static int objectcount;

        box(double l=2.0,double b=2.0,double h=2.0){
            cout<<"constructor called."<<endl;
            length=l;
            breadth=b;
            height=h;

            objectcount++;
        }
        double getvolume(void){
            return  length*breadth*height;
        }
        void setlength(double len){
            length=len;
        }
        void setbreath(double bre){
            breadth=bre;
        }
        void setheight(double hei){
            height=hei;
        }
        box operator+(const box &b){
            box box;
            box.length=this->length+b.length;
            box.breadth=this->breadth+b.breadth;
            box.height=this->height+b.height;
            return box;
        }
        double volume(){
            return length*breadth*height;
        }
        static int getcount(){
            return objectcount;
        }
        private:
            double length;
            double breadth;
            double height;
};



int box::objectcount=0;

class shape
{
    public:
        void setwidth(int w){
            width=w;
        }
        void setheight(int h){
            height=h;
        }
    protected:
        int width;
        int height;
};

class paintcost{
    public:
        int getcost(int area){
            return area*70;
        }
};

class rectangle:public shape,public paintcost{
    public:
        int getarea(){
            return (width*height);
        }
        
};


class printdata{
    public:
        void print(int i){
            cout<<"integer:"<<i<<endl;
        }
        void print(double f){
            cout<<"float:"<<f<<endl;
        }
        void print(char c[]){
            cout<<"string:"<<c<<endl;
        }
};

class Distance{
    private:
        int feet;
        int inches;
    public:
        Distance(){
            feet=0;
            inches=0;
        }
        Distance(int f,int i){
            feet=f;
            inches=i;
        }
        void displaydistance(){
            cout<<"F: "<<feet<<" I: "<<inches<<endl;
        }
        Distance operator- (){
            feet=-feet;
            inches=-inches;
            return Distance(feet,inches);
        }
};

class Time{
    private:
        int hours;
        int minutes;
    public:
        Time(){
            hours=0;
            minutes=0;
        }
        Time(int h,int m){
            hours=h;
            minutes=m;
        }

        void show_time(){
            cout<<"H: "<<hours<<" M:"<<minutes<<endl;
        }

        Time operator++(){
            ++minutes;

            if (minutes>=60){
                ++hours;
                minutes-=60;
            }

            return Time(hours,minutes);
        }

        Time operator++(int){
            Time T(hours,minutes);

            ++minutes;

            if (minutes>=60){
                ++hours;
                minutes-=60;
            }

            return T;
        }

        
};

void bubblesort(int *arr,int len){
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void printarray(int arr[],int len){
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

struct student{
    string name;
    int age;
    int score;
}stu3;


int *funct(){
    int *a=new int(10);
    return a;
}

void func(int &ref){
    ref=100;
}

void show_value(const int &v){
    cout<<v<<endl;
}

string find_LCS(string str1,string str2){
    int len1=str1.size();
    int len2=str2.size();

    vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if (str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    string lcs;

    int i=len1,j=len2;
    while(i>0&&j>0){
        if (str1[i-1]==str2[j-1]){
            lcs.push_back(str1[i-1]);
            --i;
            --j;
        }
        else if (dp[i-1][j]>dp[i][j-1]){
            --i;
        }else{
            --j;
        }
     

    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
}

Node * reverse_k_group(Node *head,int k){
    if (!head||k==1){
        return head;
    }

    stack<Node*> st;
    Node *curr=head;
    Node *prev=nullptr;

    while(curr!=nullptr){
        int count=0;

        while(curr!=nullptr&&count<k){
            st.push(curr);
            curr=curr->next;
            count++;
        }

        while(!st.empty()){
            if (prev==nullptr){
                prev=st.top();
                head=prev;
                st.pop();
            }else{
                prev->next=st.top();
                prev=prev->next;
                st.pop();
            }
        }
    }

    prev->next=nullptr;

    return head;
}

Node *reverse_k_group_2(Node *head,int k){
    if (head==nullptr){
        return head;
    }

    Node *curr=head;
    Node *new_head=nullptr;
    Node *tail=nullptr;


    while(curr!=nullptr){
        Node *group_head=curr;
        Node *prev=nullptr;
        Node *next_node=nullptr;
        int count=0;

        while(curr!=nullptr&&count<k){
            next_node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_node;
            count++;
        }

        if (new_head==nullptr){
            new_head=prev;
        }

        if (tail!=nullptr){
            tail->next=prev;
        }

        tail=group_head;
    }

    return new_head;
    
}

class STACK{
    private:
        Node *head;

    public:
        STACK(){
            this->head=nullptr;
        }

        bool isempty(){
            return head==nullptr;
        }

        void push(int new_data){
            Node *new_node=new Node(new_data);

            if (!new_node){
                cout<<"\nStack overflow"<<endl;
            }

            new_node->next=head;

            head=new_node;
            
        }

        void pop(){
            if (this->isempty()){
                cout<<"\nstack underflow"<<endl;
            }else{
                Node *temp=head;

                head=head->next;

                delete temp;
            }
        }

        int peek(){
            if (!isempty()){
                return head->data;
            }else{
                cout<<"\nstack is empty"<<endl;
                return INT_MIN;
            }
        }
};

class QUEUE{
    Node *front,*rear;

    public:
        QUEUE(){
            front=rear=nullptr;
        }

        bool isempty(){
            if (front==nullptr){
                return true;
            }

            return false;
        }

        void enqueue(int new_data){
            Node *new_node=new Node (new_data);

            if (this->isempty()){
                front=rear=new_node;
                return;
            }

            rear->next=new_node;
            rear=new_node;
        }

        void dequeue(){
            if (this->isempty()){
                cout<<"Queue underflow\n";
                return;
            }

            Node *temp=front;
            front=front->next;

            if (front==nullptr){
                rear=nullptr;
            }

            delete temp;
        }

        int getfront(){
            if (this->isempty()){
                return INT_MIN;
            }

            return front->data;
        }

        int getrear(){
            if (this->isempty()){
                cout<<"queue is empty"<<endl;
                return INT_MIN;
            }

            return rear->data;
        }
};


vector<vector<int>> merge_arrays(vector<vector<int>>&nums1,vector<vector<int>>&nums2){
    map<int,int> sum;

    for(auto nums:nums1){
        sum[nums[0]]=nums[1];
    }

    for(auto nums:nums2){
        sum[nums[0]]+=nums[1];
    }

    vector<vector<int>> merge;

    for(auto it:sum){
        merge.push_back({it.first,it.second});
    }

    return merge;
}

void test_merge_array(){
    vector<vector<int>> v1;

    v1={{1,2},
        {2,3},
        {4,5}};

    vector<vector<int>> v2;
    v2={
        {1,4},
        {3,2},
        {4,1}

    };
    vector<vector<int>>::iterator it;

    vector<vector<int>> v3;
    v3=merge_arrays(v1,v2);


    cout<<v3.size()<<endl;

    for(it=v3.begin();it!=v3.end();it++){

        vector<int> inner=*it;
        
        for(vector<int>::iterator it=inner.begin();it!=inner.end();++it){
            cout<<" "<<*it;
        }
        cout<<endl;
    }
    cout<<endl;
}

bool bfs(int start,vector<vector<int>> &adj,vector<bool> &visited){
    queue<pair<int,int>> q;
    q.push({start,-1});
    visited[start]=true;

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(int neighbor:adj[node]){
            if (!visited[neighbor]){
                visited[neighbor]=true;
                q.push({neighbor,node});
            }

            else if (neighbor!=parent){
                return true;
            }
        }

        
    }

    return false;

    
}

bool iscycle(vector<vector<int>> & adj){
    int n=adj.size();
    vector<bool> visited(n,false);

    for(int i=0;i<n;i++){
        if (!visited[i]){
            if (bfs(i,adj,visited)){
                return true;
            }
        }
    }

    return false;
}

void bsf_for_search(vector<vector<int>> &adj,int s){
    queue<int> q;

    vector<bool> visisted(adj.size(),false);

    visisted[s]=true;
    q.push(s);
    
    while(!q.empty()){
        int curr=q.front();
        q.pop();

        cout<<curr<<" ";

        for(int node:adj[curr]){
            if(!visisted[node]){
                visisted[node]=true;
                q.push(node);
            }
        }
    }
}

void add_edge(vector<vector<int>> &adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u); //undirected graph
}


void bfs_for_disconnected(vector<vector<int>> &adj,int s,vector<bool> &visisted){
    queue<int> q;
    visisted[s]=true;
    q.push(s);

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";

        for(int node:adj[curr]){
            if (!visisted[node]){
                visisted[node]=true;
                q.push(node);
            }
        }
    }
}

void bfs_disconnected(vector<vector<int>> &adj){
    vector<bool> visisted(adj.size(),false);

    for(int i=0;i<adj.size();i++){
        if (!visisted[i]){
            bfs_for_disconnected(adj,i,visisted);
        }
    }
}

class tree_node{
  public:
    int data;
    tree_node *left,*right;
    
    tree_node(int x){
        data=x;
        left=right=nullptr;
    }
};


void recursive_right_view(tree_node *root,int level,int &maxlevel,vector<int> &result){
    if (!root)return;

    if (level>maxlevel){
        result.push_back(root->data);
        maxlevel=level;
    }

    recursive_right_view(root->right,level+1,maxlevel,result);

    recursive_right_view(root->left,level+1,maxlevel,result);


}

vector<int> rightview(tree_node *root){
    vector<int> result;

    int maxlevel=-1;

    recursive_right_view(root,0,maxlevel,result);

    return result;
}

void printarray(vector<int> &arr){
    for(auto val:arr){
        cout<<val<<" ";
    }
    cout<<endl;
}

int partition(vector<int>&arr,int low,int high){
    int pivot=arr[high];

    int i=low-1;

    for(int j=low;j<=high;j++){
        if (arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

int partition_r(vector<int> &arr,int low,int high);

void quicksort(vector<int> &arr,int low,int high){
    if (low<high){
        int pi=partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

void heapify(vector<int>&arr,int n,int i){
    int largest=i;

    int l=2*i+1;

    int r=2*i+2;

    if (l<n&&arr[l]>arr[largest]){
        largest=l;
    }

    if (r<n&&arr[r]>arr[largest]){
        largest=r;
    }

    if (largest!=i){
        swap(arr[i],arr[largest]);

        heapify(arr,n,largest);
    }
}

void heapsort(vector<int>&arr){
    int n=arr.size();

    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void merge(vector<int>&arr,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    vector<int> L(n1),R(n2);

    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }

    int i=0,j=0;
    int k=left;

    while (i<n1&&j<n2){
        if (L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
    
}

void mergesort(vector<int>&arr,int left,int right){
    if (left>=right){
        return;
    }
    int mid=left+(right-left)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

void insertsort(vector<int> &arr,int n){
    for(int i=1;i<n;i++){
        int key=arr[i];

        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

}

const int run=32;

void insertion_sort_v2(int arr[],int left,int right){
    for(int i=left+1;i<=right;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=left&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void merge_v2(int arr[],int l,int m,int r){
    int len1=m-l+1;
    int len2=r-m;
    int left[len1];
    int right[len2];
    for(int i=0;i<len1;i++){
        left[i]=arr[l+i];
    }
    for(int i=0;i<len2;i++){
        right[i]=arr[m+1+i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<len1&&j<len2){
        if (left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<len1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<len2){
        arr[k]=right[j];
        j++;
        k++;
    }

}


void timsort(int arr[],int n){
    for(int i=0;i<n;i+=run){
        insertion_sort_v2(arr,i,min((i+run-1),(n-1)));
    }

    for(int size=run;size<n;size=2*size){
        for(int left=0;left<n;left+=2*size){
            int mid=left+size-1;

            int right=min((left+2*size-1),(n-1));

            if (mid<right){
                merge_v2(arr,left,mid,right);
            }
        }
    }

}

int main(){

    int arr[] = { -2, 7,  15,  -14, 0, 15,  0, 7, 
        -7, -4, -13, 5,   8, -14, 12 }; 

    


    int n=sizeof(arr)/sizeof(arr[0]);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    timsort(arr,n);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    


    return 0;
}