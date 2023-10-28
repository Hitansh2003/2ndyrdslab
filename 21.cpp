#include <iostream>

// Define a simple Node structure for a singly linked list.
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// Function to merge two linked lists at a common point.
Node* mergeLinkedLists(Node* list1, Node* list2) {
    if (!list1 || !list2) {
        std::cerr << "Both lists must not be empty." << std::endl;
        return nullptr;
    }

    // Find the last node of the first linked list.
    Node* current = list1;
    while (current->next) {
        current = current->next;
    }

    // Connect the last node of list1 to the head of list2.
    current->next = list2;

    return list1;  // Return the merged list.
}

// Function to print a linked list.
void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create two linked lists.
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    Node* list2 = new Node(4);
    list2->next = new Node(5);

    // Merge list2 into list1.
    mergeLinkedLists(list1, list2);

    // Print the merged list.
    printList(list1);

    return 0;
}
