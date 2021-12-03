// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "queue.h"
#include "stack.h"
#include "strlib.h"
#include "console.h"
#include "lexicon.h"

using namespace std;

int main() {
    cout << "Dictionary file name ?" << endl;
    ifstream input;
    string tar_file;
    string tar_word1;
    string tar_word2;
    string recover;
    Stack<string> recover_stack;
    Queue<Stack<string>> ret_collec;
    Stack<string> ret_word;
    Stack<string> temp_stack;
    string peek_word;
    Set<string> record_words;
tar1:
    cin >> tar_file;
    input.open(tar_file);
    if(input.fail())
    {
        cout << "Unable to open that file.Try again." << endl;
        goto tar1;
    }
    Lexicon dic(input);
    input.close();
tar4:
    cout << "Word #1(or Enter to quit):" ;
    cin >> tar_word1;
//    if(cin.get() == '\n')
//    {
//        goto tar2;
//    }
    tar_word1 = toLowerCase(tar_word1);
    cout << "Word #2(or Enter to quit):" ;
    cin >> tar_word2;
//    if(cin.get() == '\n')
//    {
//        goto tar2;
//    }
    tar_word2 = toLowerCase(tar_word2);
    if(tar_word1 == tar_word2)
    {
        cout << "Please input two different words." << endl;
        return 0;
    }
    else if(tar_word1.length() != tar_word2.length())
    {
        cout << "The two words must be the same length." << endl;
        return 0;
    }
    else if((!dic.contains(tar_word1)) || (!dic.contains(tar_word2)))
    {
        cout << "The two words must be found in the dictionary." << endl;
        return 0;
    }
    ret_word.push(tar_word1);
    ret_collec.enqueue(ret_word);
    while(!ret_collec.isEmpty())
    {
        temp_stack = ret_collec.dequeue();
        peek_word = temp_stack.peek();
        recover = peek_word;
        recover_stack = temp_stack;
        for(unsigned long i = 0;i < peek_word.length();i++)
        {
            for(char j = 'a';j < 123;j++)
            {
                peek_word[i] = j;
                if(dic.contains(peek_word))
                {
                    if(!record_words.contains(peek_word))
                    {
                        if(peek_word == tar_word2)
                        {
                            temp_stack.add(tar_word2);
                            goto tar3;
                        }
                        else
                        {
                            temp_stack.push(peek_word);
                            ret_collec.enqueue(temp_stack);
                            temp_stack = recover_stack;
                        }
                    }
                    record_words.add(peek_word);
                }
            }
            peek_word = recover;
        }
    }
tar3:
    cout << "A ladder from " << tar_word2 << " back to " << tar_word1 << " : " ;
    while(!temp_stack.isEmpty())
    {
        cout << temp_stack.pop() << " ";
    }
    cout << endl;
    ret_collec.clear();
    ret_word.clear();
    temp_stack.clear();
    record_words.clear();
    goto tar4;
tar2:
    cout << "Have a nice day." << endl;
    return 0;
}




