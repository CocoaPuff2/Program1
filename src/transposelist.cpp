#include "transposelist.h"

bool TransposeList::contains(int anEntry) {

    DListNode* current = header->next;
    while ( current != header) {
        if (current->item == anEntry) {
            // every time an element is accessed,
            // it is swapped with the previous node of the list
            // assuming the current element is not the head
            if (current->prev != header) {
                // ex: dummy --> 1 <--> 2 <--> 3 --> dummy header
                // ex: current = 2
                DListNode* prevNode = current->prev; // 1

                // should be the node after current
                current->prev = prevNode->prev; // 2 --> 1

                // since prevNode is the 1, prevNode->prev is dummy
                prevNode->prev->next = current; // update pointer of dummy --> 2

                // NOW: dummy -> 2 <--> 1
                prevNode->next = current->next; // 1 --> 3 --> dummy header

                current->next->prev = prevNode; //  1 <--> 3
                current->next = prevNode;
            }
            traverseCount++;
            return true;
        }
        current = current->next;
        traverseCount++;
    }
    return false;
}