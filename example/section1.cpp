/* #include<iostream> */
/* #include<vector> */

/* using namespace std; */

/* void printVector(const vector<int>& values) { */
/*     for (int elem: values) { */
/*         cout << elem << " "; */
/*     } */
/*     cout << endl; */
/* } */

/* void maui(vector<int> values) { */
/*     for (int i = 0; i < values.size(); i++) { */
/*         values[i] = 1258 * values[i] * (values[2] - values[0]); */
/*     } */
/* } */

/* void moana(vector<int>& values) { */
/*     for (int elem: values) { */
/*         elem *= 137; */
/*     } */
/* } */

/* void heihei(vector<int>& values) { */
/*     for (int& elem: values) { */
/*         elem++; */
/*     } */
/* } */

/* vector<int> teFiti(const vector<int>& values) { */
/*     vector<int> result(values.size()); */
/* 	int i = 0; */
/*     for (int elem: values) { */
/*         result[i] += (elem * 137); */
/* 		i++; */
/*     } */
/*     return result; */
/* } */

/* int main() { */
/*     vector<int> values = { 1, 3, 7 }; */
/*     maui(values); */
/*     printVector(values); */
/*     moana(values); */
/*     printVector(values); */
/*     heihei(values); */
/*     printVector(values); */
/*     teFiti(values); */
/*     printVector(values); */
/*     return 0; */
/* } */
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main(void)
{
		string filename;
		/* vector<string> names; */
		
		/* cout << names[0] <<endl; */
		/* cout << names[1] <<endl; */
		/* cout << names[2] <<endl; */
		getline(cin,filename);
		ifstream input;
		input.open(filename);
		string context;
		if(input.fail())
		{
				cout << "bome bome !" << endl;
		}
		else 
		{
				while(getline(input,context))
				{
						cout << context << endl;
				}
		}
		return 0;
}



































