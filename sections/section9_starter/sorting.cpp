/*
 * CS106B Section Handout Test Harness: Section 8
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
#include "listnode.h"
#include "utility.h"
#include "vector.h"
using namespace std;

/*
 * Sorting Review (Code Writing)
 * --------------------------------------------------------
 * Write an implementation of insertion sort that works on
 * singly-linked lists. Implement the provided function header.
 */


void listInsertionSort(ListNode*& list) { // Question to ponder: why by reference?
    /* TODO: Your code goes here! */
    (void) list;
}

PROVIDED_TEST("Simple Sorting Tests") {
    Vector<int> vals = {1, 100, 10};
    ListNode *list = createListFromVector(vals);
    listInsertionSort(list);
    vals.sort();
    ListNode *soln = createListFromVector(vals);
    EXPECT(listEqual(soln, list));
    freeList(list);
    freeList(soln);

    vals = {100, 10, 1};
    list = createListFromVector(vals);
    listInsertionSort(list);
    vals.sort();
    soln = createListFromVector(vals);
    EXPECT(listEqual(soln, list));
    freeList(list);
    freeList(soln);

    vals = {1, 10, 100};
    list = createListFromVector(vals);
    listInsertionSort(list);
    vals.sort();
    soln = createListFromVector(vals);
    EXPECT(listEqual(soln, list));
    freeList(list);
    freeList(soln);

    vals = {};
    list = createListFromVector(vals);
    listInsertionSort(list);
    vals.sort();
    soln = createListFromVector(vals);
    EXPECT(listEqual(soln, list));
    freeList(list);
    freeList(soln);

    vals = {3, 9, 10, 1, 2, 7, 8, 4, 6, 5};
    list = createListFromVector(vals);
    listInsertionSort(list);
    vals.sort();
    soln = createListFromVector(vals);
    EXPECT(listEqual(soln, list));
    freeList(list);
    freeList(soln);
}

