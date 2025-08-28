#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* next;
    string data;
    Node() {
        key = -1;
        data = "";
        next = nullptr;
    }
    Node(int k, string d) {
        key = k;
        data = d;
        next = nullptr;
    }
};

class separate_chain_hash {
private:
    static const int hashSize = 10;
    Node* table[hashSize];

    int hashFunction(int key) {
        return key % hashSize;
    }

public:
    separate_chain_hash() {
        for (int i = 0; i < hashSize; i++) {
            table[i] = nullptr;
        }
    }

    void insert(int key, string data) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, data);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* curr = table[index];
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    string search(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->data;
            }
            curr = curr->next;
        }
        return "Not found";
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr) {
                    table[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};
int main(){
    separate_chain_hash hashTable;
    hashTable.insert(1, "Data 1");
    hashTable.insert(2, "Data 2");
    hashTable.insert(3, "Data 3");

    cout << "Search key 2: " << hashTable.search(2) << endl;
    cout << "Search key 4: " << hashTable.search(4) << endl;

    hashTable.remove(2);
    cout << "Search key 2 after removal: " << hashTable.search(2) << endl;

    return 0;
}