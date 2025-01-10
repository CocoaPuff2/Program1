#include "mtflist.h"
#include "CDLinkedList.h"

/*
 * ex:
 * dummy head node -> 1 <-> 2 <-> 3 <-> 4 -> dummy head node
 * anEntry = 3
 *
 * current = header->next start at 1
 *
 * 3 iterations of current->item == anEntry (3) so traverseCount = 3
 *
 * current->prev->next = current->next;  // 2 -> 4
 * current->next->prev = current->prev // 2 <--> 4
 *
 *  current->next = header->next; // 3 -> 1
 *  header->next->prev = current;  // 3 <--> 1
 *
 *   header->next = current; dummy -> 3
 * current->prev = header; dummy <--> 3
 *
 */
bool MtfList::contains(int anEntry) {
    DListNode* current = header->next;
    while (current != header) {
        if (current->item == anEntry) { // move element to front
            // if it's not already the first node
            if (current->prev != header) {
                // Remove the node from the current pos
                current->prev->next = current->next; // prev node next --> next node (after current)
                current->next->prev = current->prev; // next node prev --> prev node (skip current)

                // now insert the current node!
                current->next = header->next; // current node next --> first actual node
                header->next->prev = current; // first node prev --> current node

                header->next = current; // dummy head next --> current
                current->prev = header; // current's prev --> dummy head
            }
            traverseCount++;
            return true;
        }
        current = current->next;
        traverseCount++;
    }
    return false;
}