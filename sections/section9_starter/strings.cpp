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
#include <string>
#include "testing/SimpleTest.h"
#include "error.h"
using namespace std;

/*
 * String Review (Code Writing)
 * --------------------------------------------------------
 * Write a function that reverses a string “in-place.” That is,
 * you should take the string to reverse as a reference parameter
 * and modify it so that it ends up holding its reverse. Your
 * function should use only O(1) auxiliary space.
 *
 * Then, imagine you have a string containing a bunch of words
 * from a sentence.Here’s a nifty little algorithm for reversing
 * the order of the words in the sentence: reverse each individual
 * string in the sentence, then reverse the entire resulting
 * string. (Try it – it works!) Go and code a function that
 * accomplishes this task and uses only O(1) auxiliary storage space.
 */
void Swap(char &ch1,char &ch2)
{
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
}

void reverseInPlace(string& str) {
    int first = 0;
    int last = str.size() - 1;
    while(last - first > 1) {
        Swap(str[first],str[last]);
        first++;
        last--;
    }
}

void reverse(string& str,int first,int last){
    while(last - first > 1) {
        Swap(str[first],str[last]);
        first++;
        last--;
    }
}

void reverseWordOrderingIn(string& sentence) {
    int lastword = 0;
    int counter = -1;
    for(int i = 0;i < sentence.size();i++){
        char ch = sentence[i];
        if(ch != ' ') {
            counter++;
            if(i == sentence.size() - 1){
                reverse(sentence,lastword,counter);
            }
        }
        else{
            reverse(sentence,lastword,counter);
            counter++;
            lastword = counter + 1;
        }
    }
    reverseInPlace(sentence);
}

PROVIDED_TEST("Simple Tests of Reverse String") {
    string s = "Hello, World!";
    string soln = "!dlroW ,olleH";
    reverseInPlace(s);
    EXPECT_EQUAL(s, soln);

    s = "";
    soln = "";
    reverseInPlace(s);
    EXPECT_EQUAL(s, soln);

    s = "I";
    soln = "I";
    reverseInPlace(s);
    EXPECT_EQUAL(s, soln);
}

PROVIDED_TEST("Simple Tests of Reverse Sentence") {
    string s = "Hello, World!";
    string soln = "World! Hello,";
    reverseWordOrderingIn(s);
    EXPECT_EQUAL(s, soln);

    s = "Congrats on finishing CS106B";
    soln = "CS106B finishing on Congrats";
    reverseWordOrderingIn(s);
    EXPECT_EQUAL(s, soln);

    s = "";
    soln = "";
    reverseWordOrderingIn(s);
    EXPECT_EQUAL(s, soln);

    s = "I";
    soln = "I";
    reverseWordOrderingIn(s);
    EXPECT_EQUAL(s, soln);
}
