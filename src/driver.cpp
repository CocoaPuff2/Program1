#include "CDLinkedList.h"
#include "mtflist.h"
#include "transposelist.h"
#include <iostream>
// #include <gtest/gtest.h> //  for automated testing


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

    // test contains method
    std::cout << "CDLinkedList: contains 20? " << (list.contains(20) ? "Yes" : "No") << std::endl;
    std::cout << "MtfList: contains 25? " << (mtfList.contains(25) ? "Yes" : "No") << std::endl;
    std::cout << "TransposeList: contains 30? " << (transList.contains(30) ? "Yes" : "No") << std::endl;

    // test retrieve method
    std::cout << "CDLinkedList element at index 1 is... " << list.retrieve(1) << std::endl;
    std::cout << "MtfList element at index 1 is..." << mtfList.retrieve(1) << std::endl;
    std::cout << "TransposeList element at index 1 is.... " << transList.retrieve(1) << std::endl;

    // test remove method
    std::cout << "Remove 20 from CDLinkedList... " << (list.remove(20) ? "Success" : "Failure") << std::endl;
    std::cout << "Remove 30 from MtfList..." << (mtfList.remove(30) ? "Success" : "Failure") << std::endl;
    std::cout << "Remove 10 from TransposeList..." << (transList.remove(10) ? "Success" : "Failure") << std::endl;

    // test the getCurrentSize method
    std::cout << "CDLinkedList current size is..." << list.getCurrentSize() << std::endl;
    std::cout << "MtfList current size is ..." << mtfList.getCurrentSize() << std::endl;
    std::cout << "TransposeList current size is... " << transList.getCurrentSize() << std::endl;

    // test the resetTraverseCount method
    list.resetTraverseCount();
    mtfList.resetTraverseCount();
    transList.resetTraverseCount();

    // test getTraverseCount again after reset
    list.contains(10);
    mtfList.contains(10);
    transList.contains(10);

    std::cout << "CDLinkedList traverse count... " << list.getTraverseCount() << std::endl;
    std::cout << "MtfList traverse count... " << mtfList.getTraverseCount() << std::endl;
    std::cout << "TransposeList traverse count... " << transList.getTraverseCount() << std::endl;

    return 0;

}
