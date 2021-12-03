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
#include "set.h"
using namespace std;

/*
 * Doubling a List (Code Writing)
 * --------------------------------------------------------
 * Write a function that takes a pointer to the front of a
 * linked list of integers and appends a copy of the original
 * sequence to the end of the list. Do not use any auxiliary
 * data structures to solve this problem. You should only
 * construct one additional node for each element in the
 * original list. Your function should run in O(n) time where
 * n is the number of nodes in the list.
 */

void doubleList(Node*& front) {
    Node* add_temp = front;
    while(add_temp->next != nullptr)
    {
        add_temp = add_temp->next;
    }
    Node* flag = front;
    while(flag->next != nullptr)
    {
        flag = flag->next;
    }
    Node* search_temp = front;
    while(search_temp != flag->next)
    {
        Node* newnode = new Node();
        newnode->data = search_temp->data;
        add_temp->next = newnode;
        add_temp = add_temp->next;
        search_temp = search_temp->next;
    }
}


/* * * * * Provided Tests Below This Point * * * * */
PROVIDED_TEST("Example from handout") {
    Node *originalList = createListFromVector({1, 3, 2, 7});
    Node *doubled = createListFromVector({1, 3, 2, 7, 1, 3, 2, 7});

    doubleList(originalList);

    EXPECT(listEqual(originalList, doubled));

}


