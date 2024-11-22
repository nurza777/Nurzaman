#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct SinglyLinkedList {

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

    void displayList(Node *pNode) {
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


    void destroyList(Node* head) {
        Node* current = head;
        Node* next;

        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Code for organizing a circular list
    void makeCircularList() {
        Node* current = head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = head;
    }

    // Code for merging two or three lists
    static Node* mergeLists(Node* list1, Node* list2, Node* list3) {
        Node* mergedList = NULL;
        Node* tail = NULL;

        if (list1 != NULL) {
            mergedList = list1;
            tail = list1;
        }

        while (tail->next != NULL) {
            tail = tail->next;
        }

        if (list2 != NULL) {
            tail->next = list2;
            while (tail->next != NULL) {
                tail = tail->next;
            }
        }

        if (list3 != NULL) {
            tail->next = list3;
        }

        return mergedList;
    }

    // Code for creating two lists with even and odd numbers
    static void createEvenOddLists(Node* head, Node** evenList, Node** oddList) {
        Node* current = head;

        while (current != NULL) {
            if (current->data % 2 == 0) {
                insertNode(evenList, current->data);
            } else {
                insertNode(oddList, current->data);
            }
            current = current->next;
        }
    }

    // Code for forming a unidirectional list from an input string
    static Node* formListFromString(string input) {
        Node* head = NULL;
        Node* tail = NULL;

        for (char c : input) {
            Node* newNode = new Node;
            newNode->data = c;
            newNode->next = nullptr;

            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        if (head != NULL && head->data == 'A') {
            Node* newNode = new Node;
            newNode->data = 'A';
            newNode->next = nullptr;

            tail->next = newNode;
            tail = newNode;
        }

        return head;
    }

    // Code for sorting elements of a singly linked list
    void sortList() {
        Node* current = head;
        Node* index = NULL;
        int temp;

        if (head == NULL) {
            return;
        } else {
            while (current != NULL) {
                index = current->next;

                while (index != NULL) {
                    if (current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }

    // Function to insert a node at the end of the list
    static void insertNode(Node** list, int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (*list == nullptr) {
            *list = newNode;
        } else {
            Node* temp = *list;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    Node* head;
};

int main() {
    SinglyLinkedList myList;
    int choice;

    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at a position\n";
        cout << "3. Insert after a value\n";
        cout << "4. Delete at a position\n";
        cout << "5. Delete by value\n";
        cout << "6. Search by key\n";
        cout << "7. Search by value\n";
        cout << "8. Display list\n";
        cout << "9. Clean list\n";
        cout << "10. Destroy list\n";
        cout << "11. Make circular list\n";
        cout << "12. Merge lists\n";
        cout << "13. Create even and odd lists\n";
        cout << "14. Form list from string\n";
        cout << "15. Sort list\n";
        cout << "16. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
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
                    cout << "Element found: " << searchResult->data << std::endl;
                } else {
                    cout << "Element not found." << std::endl;
                }
                break;
            }
            case 7: {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                int position = myList.searchByValue(value);
                if (position != -1) {
                    cout << "Element found at position: " << position << std::endl;
                } else {
                    cout << "Element not found." << std::endl;
                }
                break;
            }
            case 8: {
                myList.displayList(nullptr);
                break;
            }
            case 9: {
                myList.cleanList();
                cout << "List cleaned." << endl;
                break;
            }
            case 10: {
                myList.destroyList();
                cout << "List destroyed." << endl;
                break;
            }
            case 11: {
                myList.makeCircularList();
                cout << "List made circular." << endl;
                break;
            }
            case 12: {

                SinglyLinkedList list1, list2, list3;



                Node* mergedList = SinglyLinkedList::mergeLists(list1.head, list2.head, list3.head);
                cout << "Lists merged." << endl;
                break;
            }
            case 13: {
                Node* evenList = nullptr;
                Node* oddList = nullptr;


                myList.createEvenOddLists(myList.head, &evenList, &oddList);

                cout << "Even list: ";
                SinglyLinkedList::displayList(evenList);
                cout << "Odd list: ";
                SinglyLinkedList::displayList(oddList);
                break;
            }
            case 14: {
                string input;
                cout << "Enter a string: ";
                cin >> input;

                Node* formedList = SinglyLinkedList::formListFromString(input);

                cout << "Formed list: ";
                SinglyLinkedList::displayList(formedList);
                break;
            }
            case 15: {
                myList.sortList();
                cout << "List sorted." << endl;
                break;
            }
            case 16: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }
        }
    } while (choice != 16);

    return 0;
}
