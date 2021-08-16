#include "Node.h"

Node::Node()
{
	Name = "";
	Value = 0;
}
Node::Node(string N)
{
	Name = N;
	Value = 0;
}
Node::Node(string N, short V)
{
	Name = N;
	Value = V;
}
void Node::SetName(string N)
{
	Name = N;
}
void Node::SetValue(short V)
{
	Value = V;
}
string Node::GetName()
{
	return Name;
}
short Node::GetValue()
{
	return Value;
}
void Node::PrintNode()
{
	cout<<Name<<"="<<Value<<endl;
}