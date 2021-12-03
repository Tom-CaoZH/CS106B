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
#include "testing/TextUtils.h"
#include "vector.h"
#include<vector>
using namespace std;

/*
 * Win some, lose sum (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function named canMakeSum that takes a
 * reference to a Vector<int> and an int target value and
 * returns true if it is possible to have some selection of
 * values from the Vector that sum to the target value.
 */


//int sum_v(vector<int> v)
//{
//    int sum = 0;
//    for(int elem : v)
//    {
//        sum += elem;
//    }
//    return sum;
//}

//void canMakeSumHelper(Vector<int>& values,int startindex,vector<int> path,vector<vector<int>> & result)
//{
//    result.push_back(path);
//    if(startindex < values.size())
//    {
//        for(int i = startindex;i < values.size();i++)
//        {
//            path.push_back(values[startindex]);
//            canMakeSumHelper(values,i+1,path,result);
//            path.pop_back();
//        }
//    }
//}
bool canMakeSumHelper(Vector<int> & values,int target,int sum,int index)
{
    if(index >= values.size())
    {
        return (target == sum);
    }
    else
    {
        return (canMakeSumHelper(values,target,sum+values[index],index+1)
                || canMakeSumHelper(values,target,sum,index+1));
    }
}
bool canMakeSum(Vector<int>& values, int target) {
//    int startindex = 0;
//    vector<int> path;
//    vector<vector<int>> result;
//    canMakeSumHelper(values,startindex,path,result);
//    for(vector<int> elem : result)
//    {
//        if(sum_v(elem) == target)
//        {
//            return true;
//        }
//    }
//    return false;
    return canMakeSumHelper(values,target,0,0);
}
/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Positive example from handout.") {
    Vector<int> nums = {1,1,2,3,5};
    EXPECT(canMakeSum(nums, 9));
}

PROVIDED_TEST("Provided Test: Negative example from handout"){
    Vector<int> nums = {1,4,5,6};
    EXPECT(!canMakeSum(nums, 8));
}
