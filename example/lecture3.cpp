#include<iostream>
#include<string>
/* #include<fstream> */
/* #include<vector> */

using namespace std;

int main(void)
{
		string str = "hel9o wprld";
		cout << str << endl;
		int position = str.find('9');
		str = str.substr(position);
		cout << str << endl;
		/* ifstream input; */
		/* input.open("hello.txt"); */
		/* string line; */
		/* while(getline(input,line)) */
		/* { */
		/* 		cout << line <<endl; */
		/* } */
		/* input.close(); */
		return 0;
}
/* string helli() */
/* { */
/* 		return "hello"; */
/* } */
