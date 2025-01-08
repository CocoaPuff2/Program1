#include "CDLinkedList.h"
#include "mtflist.h"
#include "transposelist.h"
#include <gtest/gtest.h> //  for automated testing


int main() {
    // create instances
    CDLinkedList list;
    MtfList mtfList;
    TransposeList transList;

    // testing for add
    list.add(10);
    list.add(20);
    list.add(30);

    mtfList.add(10);
    mtfList.add(20);
    mtfList.add(30);

    transList.add(10);
    transList.add(20);
    transList.add(30);

    // testing for contains
    bool contains10 = list.contains(10);
    bool contains45 = mtfList.contains(25);

    // printing for test purposes
    std::cout << "Contains 10 in list? " << (contains10 ? "Yes" : "No") << std::endl;
    std::cout << "Contains 25 in MtfList? " << (contains25 ? "Yes" : "No") << std::endl;

    // Testing remove
    bool removedFromList = list.remove(20);
    bool removedFromMtf = mtfList.remove(30);
    bool removedFromTrans = transList.remove(10);

    // printing for test purposes
    std::cout << "Removed 20 from CDLinkedList...? " << (removedFromList ? "Yes" : "No") << std::endl;
    std::cout << "Removed 30 from MtfList...? " << (removedFromMtf ? "Yes" : "No") << std::endl;
    std::cout << "Removed 10 from TransposeList...?" << (removedFromTrans ? "Yes" : "No") << std::endl;

}
