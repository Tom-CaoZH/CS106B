#include "WhatAreYouDoing.h"
#include <ctype.h>
#include "strlib.h"
using namespace std;


// backtrace
void helper_f(Vector<string>& tokens,Set<string> &ret,string &str) {
    if(tokens.isEmpty()) {
        ret.add(str);
    }
    else {
        string word = tokens[0];
        string ori = str;
        tokens.remove(0);
        if(!isalpha(word[0])) {
            str += word;
            helper_f(tokens,ret,str);
        }
        else {
            str += toUpperCase(word);
            helper_f(tokens,ret,str);
            ori += toLowerCase(word);
            helper_f(tokens,ret,ori);
        }
        // backtrace
        tokens.insert(0,word);
    }
}

Set<string> allEmphasesOf(const string& sentence) {
    Vector<string> tokens = tokenize(sentence);
    Set<string> ret;
    string str = "";
    helper_f(tokens,ret,str);
    return ret;
}

/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"



PROVIDED_TEST("case 1") {
    Set<string> expected = {
        "what are you doing?",
        "what are you DOING?",
        "what are YOU doing?",
        "what are YOU DOING?",
        "what ARE you doing?",
        "what ARE you DOING?",
        "what ARE YOU doing?",
        "what ARE YOU DOING?",
        "WHAT are you doing?",
        "WHAT are you DOING?",
        "WHAT are YOU doing?",
        "WHAT are YOU DOING?",
        "WHAT ARE you doing?",
        "WHAT ARE you DOING?",
        "WHAT ARE YOU doing?",
        "WHAT ARE YOU DOING?",
    };

    EXPECT_EQUAL(allEmphasesOf("what are YOU doing?"), expected);
}



PROVIDED_TEST("case 2") {
    Set<string> expected = {
"quoth the raven, \"nevermore.\"",
"quoth the raven, \"NEVERMORE.\"",
"quoth the RAVEN, \"nevermore.\"",
"quoth the RAVEN, \"NEVERMORE.\"",
"quoth THE raven, \"nevermore.\"",
"quoth THE raven, \"NEVERMORE.\"",
"quoth THE RAVEN, \"nevermore.\"",
"quoth THE RAVEN, \"NEVERMORE.\"",
"QUOTH the raven, \"nevermore.\"",
"QUOTH the raven, \"NEVERMORE.\"",
"QUOTH the RAVEN, \"nevermore.\"",
"QUOTH the RAVEN, \"NEVERMORE.\"",
"QUOTH THE raven, \"nevermore.\"",
"QUOTH THE raven, \"NEVERMORE.\"",
"QUOTH THE RAVEN, \"nevermore.\"",
"QUOTH THE RAVEN, \"NEVERMORE.\"",
    };

    EXPECT_EQUAL(allEmphasesOf("Quoth the raven, \"Nevermore.\""), expected);
}










/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Enumerates all options in a simple case.") {
    Set<string> expected = {
        "hello",
        "HELLO",
    };

    EXPECT_EQUAL(allEmphasesOf("Hello"), expected);
}

PROVIDED_TEST("Each option has the right length.") {
    string sentence = "Hello, world!";
    for (string option: allEmphasesOf(sentence)) {
        EXPECT_EQUAL(option.length(), sentence.length());
    }
}

PROVIDED_TEST("Enumerates all options in a more typical case.") {
    Set<string> expected = {
        "you are?",
        "you ARE?",
        "YOU are?",
        "YOU ARE?"
    };

    EXPECT_EQUAL(allEmphasesOf("You Are?"), expected);
}

PROVIDED_TEST("Stress Test: Recursion only branches on words (should take under a second)") {
    /* We're producing a string consisting of fifty copies of the * character. This tokenizes
     * into fifty separate stars. A star is the same whether or not you capitalize it - there
     * is no such thing as an "upper-case" or "lower-case" star. Therefore, your code should
     * not try to form two versions of the sentence, one with the star capitalized and one
     * without, because the two versions will end up being the same and the work to compute
     * both options will dramatically increase the runtime.
     *
     * For reference, if you do try branching the recursion and checking what happens both if
     * you capitalize the star and if you don't, you'll try exploring 2^50 different possible
     * capitalizations. That's 1,125,899,906,842,624 options, and even doing a billion of
     * these a second is going to take over two years to generate them all! And of course,
     * that's all wasted work, since there's only one way to capitalize this sentence, and
     * that's just to leave it as-is.
     *
     * If your code is hanging when this test is running, it likely means that your code is
     * trying to enumerate all of these options. See if you can edit your code so that, if
     * you're given a non-word token, you just leave it as-is and don't change anything.
     */
    string punctuation(50, '*'); // 50 copies of *

    /* The only emphasis is itself. */
    Set<string> expected = {
        punctuation
    };

    EXPECT_EQUAL(allEmphasesOf(punctuation), expected);
}

PROVIDED_TEST("Stress test: Generates each option once (should take at most a few seconds)") {
    /* This sentence has 13 words in it. There are therefore 2^13 = 8192 possible emphases for
     * the words there, which is a big number but not so large that the computer can't handle
     * it if generates each emphasis exactly once.
     *
     * On the other hand, if your code tries to generate the same emphases multiple times,
     * this test may take a very, very long time to complete, and might even appear to freeze
     * up.
     *
     * If your code gets stuck in this test, trace through your code and confirm that you can't
     * produce the same emphasis multiple times. Check to make sure you aren't, for example,
     * looping over every token in the input sentence and deciding which one to capitalize
     * next. The recursion here follows more of an include/exclude type pattern (more like
     * subsets and combinations) than it does a "which is next?" type pattern (more like
     * permutations).
     */
    string yeats = "Turing and turning in a widening gyre / the falcon cannot hear the falconer.";
    EXPECT_EQUAL(allEmphasesOf(yeats).size(), 8192);
}
