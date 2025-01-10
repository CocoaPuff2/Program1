
#ifndef PROGRAM1_CDLINKEDLIST_H
#define PROGRAM1_CDLINKEDLIST_H


/*
 * Design and implement a Circular Doubly Linked List with dummy header
 * with all listed methods with a Node class/struct that holds an int,
 * and two pointers point to previous and next node.
 *
 * Since it is circular and with a dummy header, the first node is a dummy header
 * and last node's next node should point this dummy header, and dummy header's
 * previous node is the list's last node.
 */

struct DListNode {
    int item;  // Node class/struct that holds an int
    DListNode* prev; // two pointers point to previous
    DListNode* next;  // and next nod
};

class CDLinkedList {
    // used the P1 assignment description on canvas as a guide
public:
    CDLinkedList();
    CDLinkedList(const CDLinkedList &rhs)
    ~CDLinkedList(); // the destructor

    int getCurrentSize() const;
    bool isEmpty() const;

    // add: add a Node in front if the data is not already in the list.
    // If it is already in the list, then ignore
    // should also update the traverse count
    bool add(int newEntry);
    bool remove(int anEntry);
    void clear();

    virtual bool contains(int anEntry);
    int getTraverseCount() const; // holds  count of # of nodes traversed during list usage
    int retrieve(int index);
    void resetTraverseCount();


protected:
    DListNode *header;  // dummy head node
    int traverseCount;

};

#endif //PROGRAM1_CDLINKEDLIST_H
