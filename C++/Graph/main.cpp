#include<iostream>
using namespace std;
#include"Graph.h"
int main()
{
	int n=input();
	setup(n);
	DFS(n);
	return 0;
}