#include <bits/stdc++.h>
using namespace std;
/* Link list node */
class Node {
public:
    int key;
    Node* next;
};

void insert(Node** head_ref, int new_key);
void printList(Node* head);
void insertAt(int post, Node** head_ref, int new_key);
void remove(Node** head_ref, int key);
void readNnumbers(Node** head_ref);
void readNnumbers(Node** head_ref);
void processCommand(char cmd, Node** head_ref);

int main() {
    Node* head = NULL;
    readNnumbers(&head);
    char command;
    cin >> command;
    while (command != 'q'){
    processCommand(command, &head);
    cin >> command;
    }
return 0;
}
void readNnumbers(Node** head_ref){
    int n, key;
    do {
        cin >> n;
        if (n <= 0 || n >= 20) {
            cout << "n must be between 1 and 19" << endl;
        }
    } while (n <= 0 || n >= 20);
    
    for (int i=0; i<n; i++){
        cin >> key;
        insert(head_ref, key);
    }
}

void insert(Node** head_ref, int new_key){
    /* allocate node */
    Node* new_node = new Node();
    /* put in the key */
    new_node->key = new_key;
    /* link the old list of the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref) = new_node;
    
}
void printList(Node* head){
    if (head == NULL) cout << "empty\n";
        while (head) {
        if (head->next == NULL)
        cout << "[" << head->key << "] " << endl;
        else
        cout << "[" << head->key << "] ";
        head = head->next;
    }
}
void processCommand(char cmd, Node** head_ref){
    if (cmd == 'i'){
        int pos,key;
        cin>>pos>>key;
        insertAt(pos,head_ref,key);
    }
    else if (cmd == 'd'){
        int key;
        cin>>key;
        remove(head_ref,key);
    }
}
void insertAt(int post, Node** head_ref, int new_key)
{
    Node* new_node = new Node();
    new_node->key = new_key;
    new_node->next = NULL;
    if(post == 1 || *head_ref == NULL){
        new_node->next = *head_ref;
        *head_ref = new_node;
        printList(*head_ref);
        return;
    }
    Node* temp = *head_ref;
    for(int i = 1; temp->next != NULL && i<post-1; i++){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    printList(*head_ref);
}
void remove(Node** head_ref, int key)
{ 
    if((*head_ref) == NULL) return;
    if((*head_ref)->key == key){
        Node * temp = *head_ref;
        *head_ref = (*head_ref)->next;
        delete temp;
        cout<<key<<" deleted"<<endl;
        printList(*head_ref);
        return;
    }
    Node* curr = *head_ref;
    while(curr->next != NULL && curr->next->key != key){
        curr = curr->next;
    }
    if(curr->next != NULL){
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        cout<<key<<" deleted"<<endl;
    }else cout<<key<<" not existed"<<endl;
    printList(*head_ref);
}

