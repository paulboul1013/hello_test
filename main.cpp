#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

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

int main(){

    Node* head = new Node(30);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(5);
    printlist(head);

    head=quicksort(head);


    printlist(head);


    

    return 0;
}