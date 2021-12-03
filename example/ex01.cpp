#include<iostream>

#include<cmath>

using namespace std;

/* void a_to_z_print(); */
/* int main(void) */
/* { */
/* 		/1* string name = "tomcaoxzhang"; *1/ */
/* 		/1* for(int nameindex = 0;nameindex < name.length();nameindex++) *1/ */
/* 		/1* { *1/ */
/* 		/1* 		cout << name[nameindex] << endl; *1/ */
/* 		/1* } *1/ */
/* 		/1* cout << "another way to realize it." << endl; *1/ */
/* 		/1* for(char cha : name) *1/ */
/* 		/1* { *1/ */
/* 		/1* 		cout << cha << endl; *1/ */
/* 		/1* } *1/ */
/* 		a_to_z_print(); */
/* 		return 0; */
/* } */
/* void a_to_z_print() */
/* { */
/* 		for(char letter = 'a';letter <= 'z';letter++) */
/* 		{ */
/* 				cout << letter << endl; */
/* 		} */
/* } */
/* int main(void) */
/* { */
/* 		/1* string s1 = "abc"; *1/ */
/* 		/1* string s2 = "bc"; *1/ */
/* 		/1* if(s1 < s2) *1/ */
/* 		/1* { *1/ */
/* 		/1* 		cout << "abc < bc" << endl; *1/ */
/* 		/1* } *1/ */
/* 		/1* else *1/ */
/* 		/1* { *1/ */
/* 		/1* 		cout << "abc > bc" << endl; *1/ */
/* 		/1* } *1/ */
/* 		string first_name; */
/* 		string favourite_name; */
/* 		/1* cout << "what is your first name." << endl; *1/ */
/* 		/1* cin >> first_name; *1/ */
/* 		/1* getline(cin,first_name); *1/ */
/* 		/1* cout << "what is your favourite name." << endl; *1/ */
/* 		/1* /2* cin >> favourite_name; *2/ *1/ */
/* 		/1* getline(cin,favourite_name); *1/ */
/* 		cout << "hello " + first_name + " " + favourite_name + " nice to meet you" << endl;; */
/* 		return 0; */
/* } */


void quadratic(double a, double b,double c,double& root1, double& root2);
int main(void)
{
		double root1;
		double root2;
		double a,b,c;
		cin >> a;
		cin >> b;
		cin >> c;
		quadratic(a,b,c,root1,root2);
		cout << "the two roots are " << root1 << "and" << root2 << endl;
		return 0;
}
void quadratic(double a, double b,double c,double& root1, double& root2)
{
		double delta = sqrt(b*b-4*a*c);
		root1 = (-b+delta)/(2*a);
		root2 = (-b-delta)/(2*a);
}















