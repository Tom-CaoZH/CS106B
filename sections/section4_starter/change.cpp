/*
 * CS106B Section Handout Test Harness: Section 3
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Chase Davis for CS106B
 * Fall 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "testing/SimpleTest.h"
#include "error.h"
#include "stack.h"
#include "set.h"
#include<vector>
using namespace std;

/*
 * Make Chance (Code Writing)
 * --------------------------------------------------------
 * Your task is to write a function fewestCoinsFor that takes
 * as input a number of cents and a Set indicating the different
 * denominations of coins used in a country, then returns the
 * minimum number of coins required to make change for that total.
 */

int fewestCoinsFor(int cents, Set<int>& coins) {
    if(cents == 0)
    {
        return 0;
    }
    else
    {
        int bestsofar = INT32_MAX; //a value that will never be get,just make sure that it is more big
        for(int elem : coins)
        {
            if(elem <= cents)
            {
                bestsofar = min(bestsofar,fewestCoinsFor(cents-elem,coins));
            }
        }
        return bestsofar+1;
    }
}
///**
// * Given a collection of denominations and an amount to give in change, returns
// * the minimum number of coins required to make change for it.
// *
// * @param cents How many cents we need to give back.
// * @param coins The set of coins we can use.
// * @return The minimum number of coins needed to make change.
// */
//int fewestCoinsFor(int cents, Set<int>& coins) {
//    /* Base case: You need no coins to give change for no cents. */
//    if (cents == 0) {
//        return 0;
//    }
//    /* Recursive case: try each possible coin that doesn’t exceed the total as
//    * as our first coin.
//    */
//    else {
//        int bestSoFar = cents + 1; // Can never need this many coins;
//        for (int coin: coins) {
//            /* If this coin doesn’t exceed the total, try using it. */
//            if (coin <= cents) {
//                bestSoFar = min(bestSoFar,
//                    fewestCoinsFor(cents - coin, coins));
//            }
//        }
//        return bestSoFar + 1; // For the coin we just used.
//    }
//}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: US Currency System") {
    Set<int> coins = {1, 5, 10, 25, 50};
    EXPECT_EQUAL(fewestCoinsFor(31, coins), 3);
}

PROVIDED_TEST("Provided Test: Recursia Currency System") {
    Set<int> coins = {1, 12, 14, 63};
    EXPECT_EQUAL(fewestCoinsFor(24, coins), 2);
}

