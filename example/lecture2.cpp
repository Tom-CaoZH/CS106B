#include<string>
#include<iostream>

using namespace std;

void namediamand(string s);
int main(void)
{
		/* string s = "hi cs106b"; */
		/* int len = s.length(); */
		/* cout << s[0] << endl; */
		/* cout << s[1] << endl; */
		/* s = s.erase(0,3); */
		/* cout << s[0] << endl; */
		/* cout << s[1] << endl; */
		/* s = s.append("hello"); */
		/* cout << s << endl; */
		/* cout << string :: npos << endl; */
		string s = "caozhang";
		namediamand(s);
		return 0;
}
void namediamand(string s)
{
		int len = s.length();
		for(int i = 0;i < len ;i++)
		{
				cout << s.substr(0,i+1) << endl;
		}
		for(int i = 0;i < len ;i++)
		{
				for(int j = 0;j < i+1;j++)
				{
						cout << " ";
				}
				cout << s.substr(i+1) << endl;
		}
}
