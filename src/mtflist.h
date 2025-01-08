
#ifndef PROGRAM1_MTFLIST_H
#define PROGRAM1_MTFLIST_H

#include "CDLinkedList.h"

// implements the move-to-front strategy
// the most currently accessed node is moved to the front

class MtfList : public CDLinkedList {
public:
    // override contains() method so that if it contains the entry,
    // move the target node to front.
    bool contains(int anEntry) override;
};

#endif //PROGRAM1_MTFLIST_H
