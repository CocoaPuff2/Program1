
#ifndef PROGRAM1_TRANSPOSELIST_H
#define PROGRAM1_TRANSPOSELIST_H

// implements the swap strategy
// Every time an element is accessed, it is swapped with the previous node of the list

class TransposeList : public CDLinkedList {
public:
    //  override contains() method so that if it contains,
    // swap the target node with the previous node.
    bool contains(int anEntry) override;
};


#endif //PROGRAM1_TRANSPOSELIST_H
