/*
 * CS106B Section Handout Test Harness: Section 6
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B Spring 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "testing/SimpleTest.h"
#include "node.h"
#include "utility.h"
#include "error.h"
#include "vector.h"
using namespace std;

/*
 * Linked List Warmup (Code Writing)
 * --------------------------------------------------------
 * Write a function that adds up the values of all the elements
 * in the linked list. Next, write a function that returns a
 * pointer to the last element of a linked list (and reports an
 * error if the list is empty).
 */
//the recursive version
//int sumofElementsInHelper(Node* list,int sum)
//{
//    if(list == nullptr)
//    {
//        return sum;
//    }
//    else
//    {
//        return sumofElementsInHelper(list->next,sum+list->data);
//    }
//}

int sumOfElementsIn(Node* list) {
    //the iteration version
    int sum = 0;
    while(list != nullptr)
    {
        sum += list->data;
        list = list->next;
    }
//    //the recursive version
//    int result = sumofElementsInHelper(list,0);
//    return result;
    return sum;
}

Node* lastElementOf(Node* list) {
    //the iteration version
    while(list->next != nullptr)
    {
        list = list->next;
    }
//    //the recursive version
//    if(list == nullptr)
//    {
//        error("there is a error");
//    }
//    else
//    {
//       if(list->next == nullptr)
//       {
//           return list;
//       }
//       else
//       {
//           return lastElementOf(list->next);
//       }
//    }
    return list;
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Basic Sum Example") {
    Node *list = createListFromVector({1, 2, 3, 4, 5});
    EXPECT_EQUAL(sumOfElementsIn(list), 15);
    freeList(list);
}

PROVIDED_TEST("Basic Find Last Example") {
    Node *list = createListFromVector({1,2,3});
    EXPECT_EQUAL(lastElementOf(list), list->next->next);
    freeList(list);
}


