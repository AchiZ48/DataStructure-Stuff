#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* next;
    Node(){
    }
    Node(int v){
        value = v;
        next = nullptr;
    }
};
class LinkList{
public:
    Node *head;
    LinkList(){
        head = nullptr;
    }

    void insertEnd(int value){
        Node* temp = new Node(value);
        if(head == nullptr){
            head = temp;
        }
        else{
            Node* curr = head;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
    void insertBefore(int position, int value){
        Node* temp = new Node(value);
        Node* curr = head;
        if(head == nullptr){
            head = temp;
            return;
        }
        if (head->value == position) {
            temp->next = head;
            head = temp;
            return;
        }                
        
        while(curr->next != nullptr && curr->next->value != position){
            curr = curr->next;
        }
        if(curr->next != nullptr){
            temp->next = curr->next;
            curr->next = temp;
        }
        else{
            insertEnd(value);
            delete temp;
        }
        
    }

    void insertAfter(int position, int value){
        Node* temp = new Node(value);
        Node* curr = head;
        if (head == nullptr) {
            head = temp;
            return;
        }      
        while(curr != nullptr && curr->value != position){
            curr = curr->next;
        }
        if(curr != nullptr){
            temp->next = curr->next;
            curr->next = temp;
        }
        else{
            insertEnd(value);
            delete temp;
        }
    }
    void deleteNode(int value){
        if(head == nullptr) return;
        Node *curr = head;
        if(head->value == value){
            head = head->next;
            delete curr;
            return;
        }
        while(curr->next != nullptr && curr->next->value != value){
            curr = curr->next;
        }
        if(curr->next != nullptr){
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        else{
            cout << "Value not found in the list." << endl;
        }
    }
    void printList(){
        Node *temp = head;
        while(temp != nullptr){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    LinkList a;
    char cmd;
    while (true) {
        cin >> cmd;
        if (cmd == 'i') {
            int value;
            cin >> value;
            a.insertEnd(value);
            a.printList();
            cout << endl;
        } else if (cmd == 'b') {
            int position, value;
            cin >> position >> value;
            a.insertBefore(position, value);
            a.printList();
            cout << endl;
        } else if (cmd == 'a') {
            int position, value;
            cin >> position >> value;
            a.insertAfter(position, value);
            a.printList();
            cout << endl;
        } else if (cmd == 'd') {
            int value;
            cin >> value;
            a.deleteNode(value);
            a.printList();
            cout << endl;
        } else if (cmd == 'x') {
            break;
        }
    }    
}