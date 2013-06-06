#include<iostream>
#include"Hashtable.h"
using namespace std;
int main()
{
	int number=setup();
	Hash_table A;
	A.len(number);
	for(int i=0;i<number;i++)
		A.insert(Hash_data[i]);
	//A.show();
	cout<<A.have_key(1573)<<" "<<A.have_key(990);
	return 0;
}