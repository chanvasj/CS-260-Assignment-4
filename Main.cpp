#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to add a value
    void add(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < position - 1 && current != nullptr; i++) {
                current = current->next;
            }
            if (current != nullptr) {
                newNode->next = current->next;
                current->next = newNode;
            } else {
                std::cerr << "Invalid position!" << std::endl;
            }
        }
    }

    // Function to remove a value at any position and return it 
    int remove(int position) {
        if (head == nullptr) {
            std::cerr << "List is empty!" << std::endl;
            return -1;
        }
        if (position == 0) {
            Node* temp = head;
            int removedValue = temp->data;
            head = head->next;
            delete temp;
            return removedValue;
        } else {
            Node* current = head;
            for (int i = 0; i < position - 1 && current != nullptr; i++) {
                current = current->next;
            }
            if (current != nullptr && current->next != nullptr) {
                Node* temp = current->next;
                int removedValue = temp->data;
                current->next = temp->next;
                delete temp;
                return removedValue;
            } else {
                std::cerr << "Invalid position!" << std::endl;
                return -1;
            }
        }
    }

    // Function to get the value at a given position without removing it
    int get(int position) {
        Node* current = head;
        for (int i = 0; i < position && current != nullptr; i++) {
            current = current->next;
        }
        if (current != nullptr) {
            return current->data;
        } else {
            std::cerr << "Invalid position!" << std::endl;
            return -1;
        }
    }

    // Function to print the linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Test function for adding elements to the list
void testAddFunction() {
    LinkedList myList;
    
    myList.add(1, 0); 
    myList.add(2, 1); 
    myList.add(3, 1); 

    // Verify the list after adding elements
    std::cout << "List after adding elements: ";
    myList.printList();
}

// Test function for removing elements from the list
void testRemoveFunction() {
    LinkedList myList;
    
    myList.add(1, 0);
    myList.add(2, 1); 
    myList.add(3, 1); 

    int removedValue = myList.remove(1); // Remove element at position 1
    std::cout << "Removed value: " << removedValue << std::endl;
    std::cout << "List after removing an element: ";
    myList.printList();
}

// Test function for getting elements from the list
void testGetFunction() {
    LinkedList myList;
    
    myList.add(1, 0); 
    myList.add(2, 1); 
    myList.add(3, 1); 

    int valueAtIndex2 = myList.get(2);
    std::cout << "Value at index 2: " << valueAtIndex2 << std::endl;
}

int main() {

    testAddFunction();
    testRemoveFunction();
    testGetFunction();
    
    return 0;
}
