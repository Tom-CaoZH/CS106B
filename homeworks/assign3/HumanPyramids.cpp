#include "HumanPyramids.h"
#include "map.h"
#include "error.h"
using namespace std;

#define WEIGHT 160
#define HASH 100000  // The success depends on the hash value.This method is not a good one.

int hash_f(int row,int col) {
    return row*HASH + col;
}

double weightOnBackOf_helper(int row, int col, int pyramidHeight,Map<int,double>& table) {
    // basic case
    if(row == 0 && col == 0) {
        return 0;
    }
    else if(col > row || col < 0 || row < 0) {
        // deal with the narrow case
        return -(WEIGHT);
    }
    else {
        // just do recursive
        int hash_v = hash_f(row,col);
        if(table.containsKey(hash_v)) {
            return table[hash_v];
        }
        else {
            table[hash_v] = (weightOnBackOf_helper(row -1,col - 1,pyramidHeight,table) + WEIGHT) / 2 +
                (weightOnBackOf_helper(row - 1,col, pyramidHeight,table) + WEIGHT) /2;
            return table[hash_v];
        }
    }
}


double weightOnBackOf(int row, int col, int pyramidHeight) {
    if(row < 0 || col < 0 || col > row || row > pyramidHeight - 1) {
        error("The row and col should all be positive!");
    }
    Map<int,double> table;
    double ret =  weightOnBackOf_helper(row,col,pyramidHeight,table);
    return ret;
}






/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Check the small case!") {
    EXPECT_EQUAL(weightOnBackOf(1, 0, 10), 80);
    EXPECT_EQUAL(weightOnBackOf(1, 1, 10), 80);
    EXPECT_EQUAL(weightOnBackOf(0, 0, 10), 0);
}



PROVIDED_TEST("Check the big case!") {
    EXPECT_EQUAL(weightOnBackOf(3, 1, 5), 340);
    EXPECT_EQUAL(weightOnBackOf(3, 0, 5), 140);
    EXPECT_EQUAL(weightOnBackOf(4, 2, 5), 500);
}



/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* TODO: Yes, we are asking you to make a change to this test case! Delete the
     * line immediately after this one - the one that starts with SHOW_ERROR - once
     * you have implemented memoization to test whether it works correctly.
     */
//    SHOW_ERROR("This test is configured to always fail until you delete this line from\n         HumanPyramids.cpp. Once you have implemented memoization and want\n         to check whether it works correctly, remove the indicated line.");

    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
