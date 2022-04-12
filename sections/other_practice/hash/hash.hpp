
#include<iostream>

using namespace std;

class OpenHashTable
{
public:
		OpenHashTable();
		~OpenHashTable();

		//puts the key/value pair into the map
		void put(string key,string value);

		//returns the value associated with the key , or "" if the key does not exist
		string get(string ket);

		//removes the key/value pair from the map, or does nothing if it does not exist.
		void remove(string key);

private:
		int hash(string key);

		struct OpenEntry
		{
				string key;
				string value;
				bool inUse;
		};

};
