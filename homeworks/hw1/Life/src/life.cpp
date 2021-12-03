#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
#include "strlib.h"
#include "lifegui.h"
using namespace std;

int main() {
    // TODO: Finish the program!
    //what i want to is to compelete this.
    Grid<char> presentation;
    ifstream input;
    string filename;
    cout << "Grid input file name ?" <<endl;
    getline(cin,filename);
    openFile(input,filename);
    string context;
    while(getline(input,context))
    {

    }
    cout << "Have a nice Life!" << endl;
    return 0;
}
