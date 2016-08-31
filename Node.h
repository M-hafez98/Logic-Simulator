#pragma one
#include <string>
#include <iostream>
using namespace std;
class Node
{
	string Name;
	short Value;
public:
	Node();
	Node(string );
	Node(string , short );
	void SetName(string );
	string GetName();
	void SetValue(short );
	short GetValue();
	void PrintNode();
};
