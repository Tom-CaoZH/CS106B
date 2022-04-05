#include "Plotter.h"
#include "strlib.h"
using namespace std;

#define PD 1  //pen down
#define PU 2  //pen up
#define MA 3  //move pen absolutely
#define MR 4  //move pen relatively
#define PC 5  //pen colour
#define PW 6  //pen width

int checkType(string command) {
    if(equalsIgnoreCase(command,"PenUp")){
        return PU;
    }
    else if(equalsIgnoreCase(command,"PenDown")){
        return PD;
    }
    else if(equalsIgnoreCase(command,"moveabs")){
        return MA;
    }
    else if(equalsIgnoreCase(command,"moverel")){
        return MR;
    }
    else if(equalsIgnoreCase(command,"pencolor")){
        return PC;
    }
    else if(equalsIgnoreCase(command,"penwidth")){
        return PW;
    }
    return -1;
}

void drawHelper(int status,double &x,double &y,double x1,double y1,PenStyle pen) {
    if(status == 1) {
        drawLine(x,y,x1,y1,pen);
    }
    x = x1;
    y = y1;
}

void runPlotterScript(istream& input) {
    PenStyle pen = {1,"black"};
    double x = 0;
    double y = 0;
    int status = 0; // represent pen up
    for(string line;getline(input,line);) {
        string delimiter = " ";
        Vector<string> items = stringSplit(line,delimiter);
        int flag = checkType(items[0]);
        switch(flag) {
        case PD:
            status = 1;
            break;
        case PU:
            status = 0;
            break;
        case MA:
            drawHelper(status,x,y,stringToReal(items[1]),stringToReal(items[2]),pen);
            break;
        case MR:
            drawHelper(status,x,y,x + stringToReal(items[1]),y + stringToReal(items[2]),pen);
            break;
        case PC:
            pen.color = items[1];
            break;
        case PW:
            pen.width = stringToReal(items[1]);
            break;
        default:
            error("unknow command");
        }
    }
}
