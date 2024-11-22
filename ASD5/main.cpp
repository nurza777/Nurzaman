#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    Node* createNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }

    void insertAtBeginning(int data) {
        Node* newNode = createNode(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int data, int position) {
        Node* newNode = createNode(data);
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void insertAfterValue(int data, int value) {
        Node* newNode = createNode(data);
        Node* current = head;
        while (current->data != value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteAtPosition(int position) {
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void deleteByValue(int value) {
        Node* current = head;
        while (current->next->data != value) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    Node* searchByKey(int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    int searchByValue(int value) {
        Node* current = head;
        int position = 1;
        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    void displayList ( ) {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void cleanList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    void destroyList() {
        cleanList();
        delete head;
    }
};

int main() {
    SinglyLinkedList myList;
    int a;

    do {

        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at a position\n";
        cout << "3. Insert after a value\n";
        cout << "4. Delete at a position\n";
        cout << "5. Delete by value\n";
        cout << "6. Search by key\n";
        cout << "7. Search by value\n";
        cout << "8. Display list\n";
        cout << "9. Clean list\n";
        cout << "10. Destroy list and exit\n";
        cout << "Enter your choice: ";
        cin >> a;

        switch (a) {
            case 1: {
                int data;
                cout << "Enter data: ";
                cin >> data;
                myList.insertAtBeginning(data);
                break;
            }
            case 2: {
                int data, position;
                cout << "Enter data and position: ";
                cin >> data >> position;
                myList.insertAtPosition(data, position);
                break;
            }
            case 3: {
                int data, value;
                cout << "Enter data and value to insert after: ";
                cin >> data >> value;
                myList.insertAfterValue(data, value);
                break;
            }
            case 4: {
                int position;
                cout << "Enter position to delete: ";
                cin >> position;
                myList.deleteAtPosition(position);
                break;
            }
            case 5: {
                int value;
                cout << "Enter value to delete: ";
                cin >> value;
                myList.deleteByValue(value);
                break;
            }
            case 6: {
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                Node* searchResult = myList.searchByKey(key);
                if (searchResult != nullptr) {
                    cout << "Element found: " << searchResult->data << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            }
            case 7: {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                int position = myList.searchByValue(value);
                if (position != -1) {
                    cout << "Element found at position: " << position << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            }
            case 8: {
                myList.displayList ();
                break;
            }
            case 9: {
                myList.cleanList();
                cout << "List cleaned." << endl;
                break;
            }
            case 10: {
                myList.destroyList();
                cout << "List destroyed. Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }
        }
    } while (a != 10);

    return 0;
}
