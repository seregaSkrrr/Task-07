#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addElementToStart(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void addElementToEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = tail;
        newNode->next = nullptr;
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
    }

    void showAllElements() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void removeElementFromStart() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        if (temp == tail) {
            tail = nullptr;
        }
        delete temp;
    }

    void removeElementFromEnd() {
        if (tail == nullptr) {
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        if (temp == head) {
            head = nullptr;
        }
        delete temp;
    }

    void addElementAt(int position, int data) {
        if (position == 0) {
            addElementToStart(data);
            return;
        }
        Node* newNode = new Node;
        newNode->data = data;
        Node* current = head;
        int count = 0;
        while (current != nullptr && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
        else {
            tail = newNode;
        }
    }

    void removeElementAt(int position) {
        if (position == 0) {
            removeElementFromStart();
            return;
        }
        Node* current = head;
        int count = 0;
        while (current != nullptr && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current == nullptr || current->next == nullptr) {
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = current;
        }
        else {
            tail = current;
        }
        delete temp;
    }

    int searchElement(int value) {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    void removeAllElements() {
        while (head != nullptr) {
            removeElementFromStart();
        }
    }

    void reverseList() {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    DoublyLinkedList operator+(DoublyLinkedList& other) {
        DoublyLinkedList newList;
        Node* current = head;
        while (current != nullptr) {
            newList.addElementToEnd(current->data);
            current = current->next;
        }
        current = other.head;
        while (current != nullptr) {
            newList.addElementToEnd(current->data);
            current = current->next;
        }
        return newList;
    }

};

int main() {

    DoublyLinkedList list;
    list.addElementToStart(5);
    list.addElementToStart(10);
    list.addElementToEnd(15);
    list.addElementToEnd(20);

    list.showAllElements();

    list.removeElementFromStart();
    list.removeElementFromEnd();

    list.showAllElements();

    list.removeElementAt(1);
    list.showAllElements();
    cout << "Which element you want to find? ";
    int temp;
    cin >> temp;
    if (list.searchElement(temp) != -1) {
        cout << "Element found at index: " << list.searchElement(temp) << endl;
    }
    else
        cout << "There is no such an element in this List!" << endl;

    list.removeAllElements();
    list.showAllElements();

    list.addElementToStart(5);
    list.addElementToStart(10);
    list.addElementToEnd(15);
    list.addElementToEnd(20);
    list.reverseList();
    list.showAllElements();

    DoublyLinkedList list2;
    list2.addElementToStart(25);
    list2.addElementToStart(30);
    list2.addElementToEnd(35);
    list2.addElementToEnd(40);
    DoublyLinkedList list3 = list + list2;
    list3.showAllElements();

    return 0;
}