#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <list>
#include <cstring>

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

int main(){

    const int &ref=10;

    cout<<ref<<endl;

    int a=10;
    show_value(a);

	


    return 0;
}