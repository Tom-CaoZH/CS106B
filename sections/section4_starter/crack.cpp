/*
 * CS106B Section Handout Test Harness: Section 2
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
using namespace std;

/*
 * Cracking Passwords (Code Writing)
 * --------------------------------------------------------
 * Write a function crack that takes in the maximum length a
 * site allows for a user's password and tries to find the
 * password into an account by using recursive backtracking to
 * attempt all possible passwords up to that length (inclusive).
 */

bool login(string password) {
    return (password == "csizawesome");
}


void crackingPasswordsHelper(int n,string &path,string &result){
    if(path.size() >= n)
    {
        if(login(path))
        {
            result = path;
        }
        else
        {
            return;
        }
    }
    else
    {
       for(char ch = 'a';ch <= 'z';ch++)
       {
           string old = path;
           string cur;
           cur = path + ch;
           crackingPasswordsHelper(n ,path,result);
           crackingPasswordsHelper(n ,cur,result);
           path = old;
       }
    }
}

string crackingPasswords(int n){
    string path = "";
    string result = "";
    crackingPasswordsHelper(n,path,result);
    return result;
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Example from handout.") {
    EXPECT_EQUAL(crackingPasswords(11), "csizawesome");
}
