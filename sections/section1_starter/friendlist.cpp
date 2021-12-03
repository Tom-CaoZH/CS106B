/*
 * CS106B Section Handout Test Harness: Section 1
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
#include<fstream>
#include<set.h>
#include "map.h"
#include "vector.h"
#include "filelib.h"
#include "strlib.h"
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
using namespace std;

/*
 * Friend List (Code Write)
 * ----------------------------------
 * Write a function named friendList that takes in a file name and reads
 * friend relationships from a file and writes them to a Map.
 * friendList should return the populated Map. Friendships are bi-directional.
 * The file contains one friend relationship per line, with names separated
 * by a single space. You do not have to worry about malformed entries.
 */

Map<string, Vector<string>> friendList(string filename){
    ifstream input;
    input.open(filename);
    Vector<string> words;
    Map<string,Vector<string>> ret;
    Vector<string> values;
    Set<string> keys;
    string word;
    while(input >> word)
    {
        words.add(word);
        if(!keys.contains(word))
        {
            keys.add(word);
        }
    }
    for(string t_word1 : keys)
    {
        values.clear();
        for(int i = 0;i < words.size() ;i++)
        {
            string t_word2 = words[i];
            if(t_word1 == t_word2)
            {
                if(i % 2 == 0)
                {
                    values.add(words[i+1]);
                }
                else
                {
                    values.add(words[i-1]);
                }
            }
        }
        ret.put(t_word1,values);
    }
    input.close();

    return ret;
}


///* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("provided test case from handout"){
    Map<string, Vector<string>> soln;
    soln["Abby"] = {"Barney", "Clyde"};
    soln["Barney"] = {"Abby"};
    soln["Clyde"] = {"Abby"};
    EXPECT_EQUAL(soln, friendList("res/buddies.txt"));
}
