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
#include "vector.h"
using namespace std;

/*
 * All out of Sorts (Code Writing)
 * --------------------------------------------------------
 * Write a function that takes in a pointer to the front of a
 * linked list of integers and returns whether or not the list
 * that's pointed to is in sorted (nondecreasing) order. An
 * empty list is considered to be sorted.
 */
//bool isSortedHelper(Node* front,int prev)
//{
//    if(front->data >= prev)
//    {

//    }
//    (void) front;
//    return false;
//}

bool isSorted(Node* front) {
    if(front == nullptr)
    {
        return true;
    }
    else
    {
        Vector<int> nums;
        Node* temp = front;
        int counter = 0;
        while(temp != nullptr)
        {
            nums.add(temp->data);
            temp = temp->next;//this one could not be forgotten
        }
        if(nums[0] <= nums[1])
        {
            for(int i = 0;i < nums.size() - 1;i++)
            {
                if(nums[i] <= nums[i+1])
                {
                    counter++;
                }
            }
        }
        else
        {
            for(int i = 0;i < nums.size() - 1;i++)
            {
                if(nums[i] >= nums[i+1])
                {
                    counter++;
                }
            }

        }
        if(counter == nums.size() - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


/* * * * * Provided Tests Below This Point * * * * */


PROVIDED_TEST("Simple Sorted Example") {
    Node *list = createListFromVector({1,2,3,3,4,5});
    EXPECT(isSorted(list));
    freeList(list);
}

PROVIDED_TEST("Simple Unsorted Example") {
    Node *list = createListFromVector({1,2,3,1,4});
    EXPECT(!isSorted(list));
    freeList(list);
}
