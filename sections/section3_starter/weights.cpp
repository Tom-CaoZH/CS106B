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
#include "error.h"
#include "vector.h"
#include<vector>
using namespace std;

/*
 * Weights and Balances (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function that determines whether it is
 * possible to measure out the desired target amount with a
 * given set of weights, which is stored in the vector
 * weights.
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

//void isMeasurableHeple(Vector<int> & weights,vector<vector<int>> & result,vector<int> & path,int index)
//{
//    result.push_back(path);
//    if(index < weights.size())
//    {
//        for(int i = index;i < weights.size();i++)
//        {
//            path.push_back(weights[index]);
//            isMeasurableHeple(weights,result,path,i+1);
//            path.pop_back();
//        }
//    }
//}
bool isMeasurableHelper(int target,Vector<int> & weights,int index)
{
    if(weights.size() == index)
    {
        return (target == 0);
    }
    else
    {
        return (isMeasurableHelper(target - weights[index],weights,index+1)
                || isMeasurableHelper(target,weights,index+1)
                || isMeasurableHelper(target+ weights[index],weights,index+1));
    }
}
bool isMeasurable(int target, Vector<int>& weights){
//    vector<vector<int>> result;
//    vector<int> path;
//    int index = 0;
//    isMeasurableHeple(weights,result,path,index);
//    for(vector<int> elem : result)
//    {
//        int all_sum = sum_v(elem) + target;
//        for(vector<int> num : result)
//        {
//            if(2*sum_v(num) == all_sum)
//            {
//                return true;
//            }
//        }
//    }
//    if(weights.isEmpty())
//    {
//        return (target == 0);
//    }
//    else
//    {
//        int first = weights[0];
//        weights.remove(0);
//        bool result =  (isMeasurable(target - first,weights)
//                || isMeasurable(target+first,weights)
//                || isMeasurable(target,weights));
//        weights.insert(0,first);
//        return result;
//    }
    return isMeasurableHelper(target,weights,0);
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Simple Positive Example"){
    Vector<int> weights = {1, 3};
    EXPECT(isMeasurable(2, weights));
}

PROVIDED_TEST("Provided Test: Simple Negative Example"){
    Vector<int> weights = {1, 3};
    EXPECT(!isMeasurable(5, weights));
}

PROVIDED_TEST("Provided Test: Complex Positive Example"){
    Vector<int> weights = {1, 3, 7};
    EXPECT(isMeasurable(6, weights));
}
