// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "map.h"
#include "random.h"
#include "vector.h"
#include "lexicon.h"
#include "console.h"

using namespace std;

int main() {
    ifstream input;
    string file_name;
    int ran_word;
    int n_value;
    Map<Vector<string>,Vector<string>> n_gram;
    Vector<string> dic;
    Vector<string> temp_key;
    Vector<string> temp_value;
    Vector<string> randomkey;
    string randomelem;
    string ret;
lab1:
    cout << "Input file name ?" ;
    cin >> file_name;
    input.open(file_name);
    if(input.fail())
    {
        cout << "Unable to open that file. Try again." << endl;
        goto lab1;
    }
    string word;
    while(input >> word)
    {
        dic.add(word);
    }
    input.close();
lab2:
    cout << "Value of N?" ;
    cin >> n_value;
    if(cin.fail())
    {
        cout << "Illegal integer format. Try again." <<endl;
        goto lab2;
    }
    else if(2 > n_value)
    {
        cout << "N must be 2 or greater." << endl;
        goto lab2;
    }
    for(int  i = 0;i < dic.size() - n_value;i++)
    {
        for(int j =0;j < n_value;j++)
        {
            temp_key.add(dic[i+j]);
        }
        temp_value.add(dic[i+n_value]);
        if(n_gram.containsKey(temp_key))
        {
            n_gram[temp_key] += temp_value;
        }
        else
        {
            n_gram.put(temp_key,temp_value);
        }
    }
lab3:
    cout << "# of random words to generate (0 to quit)?" ;
    cin >> ran_word;
    if(ran_word == 0)
    {
        goto lab_ret;
    }
    else if(cin.fail())
    {
        cout << "Illegal integer format. Try again." <<endl;
        goto lab3;
    }
    else if(4 > ran_word)
    {
        cout << "Must be at least 4 words." << endl;
        goto lab3;
    }
    cout << "..." ;
    randomkey = randomKey(n_gram);
    while(ret.size() <= ran_word + 1 - n_value)
    {
        randomelem = randomElement(n_gram[randomkey]);
        randomkey.add(randomelem);
        ret += randomkey[0];
        randomkey.remove(0);
    }
    for(string str : randomkey)
    {
        ret += str;
    }
    cout << ret << endl;
    cout << "..." << endl;
lab_ret:
    cout << "Exiting." << endl;
    return 0;
}
