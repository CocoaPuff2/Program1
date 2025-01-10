#include "CDLinkedList.h"
#include <stdexcept>

CDLinkedList::CDLinkedList() {
    // creating a new dummy header node with val 0
    // next and prev point to nullptr
    header = new DListNode{0, nullptr, nullptr};

    // dummy head node's next and prev should point to itself (CDLL)
    header->next = header;
    header->prev = header;

    // counter keeps track of how many nodes have been traversed during
    // operations (add, remove, contains)
    traverseCount = 0;
}

// Copy constructor
CDLinkedList::CDLinkedList(const CDLinkedList &rhs) {
    // Creating a new dummy header node with val 0
    header = new DListNode{0, nullptr, nullptr};

    // Dummy header's next and prev point to itself initially
    header->next = header;
    header->prev = header;

    // Copy nodes from rhs list
    DListNode* current = rhs.header->next;
    while (current != rhs.header) { // while not circled back around
        add(current->item);
        current = current->next;
    }

    // Counter for traversal (this will be same as rhs traversal count)
    traverseCount = rhs.traverseCount;
}

// Destructor (I don't want memory leaks!!)
CDLinkedList::~CDLinkedList() {
    clear(); // for the nodes
    delete header; // delete dummy node
}

// Add new entry
bool CDLinkedList::add(int newEntry) {
    // Check if entry already exists
    if (contains(newEntry)) {
        return false;
    }

    // Create a new node
    DListNode* newNode = new DListNode{newEntry, header, header->next};

    // Insert after dummy node
    header->next->prev = newNode;
    header->next = newNode;

    // Increment the traversal count
    traverseCount++;
    return true;
}

// Remove entry
bool CDLinkedList::remove(int anEntry) {
    DListNode* current = header->next;
    while (current != header) {
        if (current->item == anEntry) {
            current->prev->next = current->next; // Skip current
            current->next->prev = current->prev; // Fix prev connection

            delete current; // Avoid memory leaks
            traverseCount--;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Clear list
void CDLinkedList::clear() {
    DListNode* current = header->next;

    while (current != header) {
        DListNode* temp = current;
        current = current->next;
        delete temp;
    }

    header->next = header;
    header->prev = header;
    traverseCount = 0;
}

// Contains
bool CDLinkedList::contains(int anEntry) {
    DListNode* current = header->next;

    while (current != header) {
        if (current->item == anEntry) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Get traversal count
int CDLinkedList::getTraverseCount() const {
    return traverseCount;
}

// Retrieve entry based on an index
int CDLinkedList::retrieve(int index) {
    if (index < 0 || index >= getCurrentSize()) {  // index should be less than getCurrentSize
        throw std::out_of_range("Oops, the index is out of range");
    }

    DListNode* current = header->next;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->item;
}

// Reset traverse count
void CDLinkedList::resetTraverseCount() {
    traverseCount = 0;
}
