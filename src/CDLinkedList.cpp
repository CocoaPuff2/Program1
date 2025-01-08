#include "CDLinkedList.h"

CDLinkedList::CDLinkedList() {
    // creating a new dummy header node with val 0
    // next and prev point to nullptr
    header = new DlistNode(0, nullptr, nullptr);

    // dummy head node's next and prev should point to itself (CDLL)
    head->next = header;
    header->prev = header;

    // counter keeps track of how many nodes have been traversed during
    // operations (add, remove, contains)
    traverseCount = 0;


    // Copy nodes from rhs list
    DlistNode* current = rhs.header->next;
    while (current != rhs.header) { // while not circled back around
        add(current->item);
        current = current->next;
    }

}

// Destructor (I don't want memory leaks!!)
CDLinkedList::~CDLinkedList() {
    clear(); // for the nodes
    delete header; // delete dummy
}

// add new entry
bool CDLinkedList::add(int newEntry) {
    DlistNode* newNode = new DlistNode;

    // inserting after dummy node
    header->next->prev = newNode;
    header->next = newNode;

    traverseCount++;
    return true;
}

// remove entry
bool CDLinkedList::remove(int anEntry) {
    DlistNode* current = header->next;
    while (current != header) {
        if (current->item == anEntry) {
            current->prev->next = current->next; // skip current
            current->next->prev = current->prev; // fix prev connection

            delete current; // no mem leaks today!
            traverseCount--;
            return true;
        }
        current = current->next;
    }
    return false;
}

// clear list
void CDLinkedList::clear() {
    DlistNode* current = header->next;

    while (current != header) {
        DlistNode* temp = current;
        current = current->next;
        delete temp;
    }

    header->next = header;
    header->prev = header;
    traverseCount = 0;
}

// contains
bool CDLinkedList::contains(int anEntry) {
    DlistNode* current = header->next;

    while (current != header) {
        if (current->item == anEntry) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// get traversal count
int CDLinkedList::getTraverseCount() const {
    return traverseCount;
}

// retrive entry based on an index
int CDLinkedList::retrieve(int index) {
    if (index < 0 || index > getCurrentSize()) {
        throw std::out_of_range("Oops, the index out of range");
    }

    DlistNode* current = header->next;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->item;
}

// reset traverse count
void CDLinkedList::resetTraverseCount() {
    traverseCount = 0;
}

