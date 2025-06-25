// 1. Design a Singly Linked List and write functions to
// ○ Insert at beginning
// ○ Insert at end
// ○ Insert at any index
// ○ Delete at beginning
// ○ Delete at end
// ○ Delete at index
// ○ Delete first occurrence of node with given value
#include<iostream>
using namespace std;


class Node{
    public:
    int val;
    Node* next;

    Node(): val(0), next(nullptr){};
    Node(int x): val(x), next(nullptr){};
    Node(int x, Node* ptr): val(x), next(ptr){};
};

class LinkedList{
    public:
    Node* head;
    int length;

    LinkedList(): head(nullptr), length(0){};

    void displayList(){
        if(!head) cout<<"List is empty"<<endl;

        Node* curr = head;
        while(curr){
            cout<<curr->val<<" ";
            curr =curr->next;
        }
        cout<<endl;
    }

    void insertAtStart(int x){
        Node* newHead = new Node(x,head);
        head = newHead;
        length++;
    }

    void insertAtEnd(int x){
        if(!head){
            head = new Node(x);
            length++;
            return;
        }

        Node* curr = head;
        while(curr->next){
            curr= curr->next;
        }
        curr->next = new Node(x);
        length++;
    }

    void insertAtIndex(int x, int pos){
        if(pos > 0 && pos <= length+1){
            Node dummy(-1,head);
            Node* curr = &dummy;
            for(int i = 0; i < pos-1; i++){
                curr = curr->next;
            }
            if(curr->next)
                curr->next = new Node(x,curr->next);
            else    
                curr->next = new Node(x,nullptr);

            head = dummy.next;
            length++;
        }

        else{
            cout<<"Invalid index entered."<<endl;
            cout<<"Index must be from 1 to "<<length+1<<"."<<endl;
        }
    }

    void deleteFromStart(){
        if(!head){
            cout<<"List is already empty"<<endl;
            return;
        }
        
        if(!head->next) head = nullptr;
        else{
            head = head->next;
        }
        length--;
    }

    void deleteFromEnd(){
        if(!head){
            cout<<"List is already empty"<<endl;
        }

        if(!head->next) head = nullptr;
        else{
            Node* curr = head;
            while(curr->next->next){
                curr = curr->next;
            }
            curr->next = nullptr;
        }
        length--;
    }

    void deleteAtIndex(int pos){
        if(head == nullptr){
            cout<<"List is already empty."<<endl;
        }

        else if(pos>0 && pos<length+1){
            Node dummy(-1,head);
            Node* curr = &dummy;
            for(int i = 0; i < pos-1; i++){
                curr = curr->next;
            }
            curr->next = curr->next->next;
            length--;
            head = dummy.next;
        }

        else{
            cout<<"Please enter valid index."<<endl;
            cout<<"Index must be from 1 to "<<length<<"."<<endl;
        }
    }

    void deleteFirstOccurence(int x){
        if(!head){
            cout<<"List is empty"<<endl;
            return;
        }

        Node dummy(INT_MIN,head);
        Node* curr = &dummy;
        while(curr->next && curr->next->val != x){
            curr = curr->next;
        }

        if(!curr->next){
            cout<<"Element "<<x<< " does not exist in the list."<<endl;
            return;
        }

        curr->next = curr->next->next;
        head = dummy.next;
        length--;
    }


};



int main(){
    LinkedList list1;
    list1.insertAtStart(5);
    list1.insertAtStart(6);
    list1.displayList();

    list1.insertAtEnd(56);
    list1.insertAtEnd(500);
    list1.displayList();

    list1.insertAtIndex(100,1);
    list1.displayList();
    list1.insertAtIndex(200,5);
    list1.insertAtIndex(300,7);
    list1.displayList();

    list1.deleteFromStart();
    list1.deleteFromStart();
    list1.displayList();

    list1.deleteFromEnd();
    list1.deleteFromEnd();
    list1.displayList();

    list1.insertAtStart(1);
    list1.insertAtStart(0);
    list1.displayList();
    list1.deleteAtIndex(2);
    list1.deleteAtIndex(100);
    list1.deleteAtIndex(4);
    list1.displayList();


    list1.deleteFirstOccurence(65);
    // list1.deleteFirstOccurence(0);
    list1.deleteFirstOccurence(56);
    // list1.deleteFirstOccurence(5);
    list1.displayList();
    
}