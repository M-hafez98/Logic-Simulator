#include "Simulator.h"
#include <fstream>
#include "ANDGate.h"
#include "NANDGate.h"
#include "ORGate.h"
#include "NORGate.h"
#include "XORGate.h"
#include "XNORGate.h"
using namespace std;

Simulator::~Simulator()
{
	int i;
	for(i=0; i<GA.size(); i++)
		delete GA[i];
	for(i=0; i<NA.size(); i++)
		delete NA[i];
}
Node* Simulator::FindNode(string N)
{
	for(int i=0; i<NA.size(); i++)
		if(NA[i]->GetName() == N)
			return NA[i];
	return NULL;
}
Node* Simulator::AddNode(string N)
{
	Node* P = new Node(N);
	NA.push_back(P);
	return NA[NA.size()-1];
}
Node* Simulator::FindOrAdd(string N)
{
	Node* P = FindNode(N);
	if (P != NULL)
		return P;
	P = AddNode(N);
	return P;
}
Gate* Simulator::AddGate(string G)
{
	Gate* P;
	if(G == "AND")
		P = new ANDGate();
	else if(G == "OR")
		P = new ORGate();
	else if(G == "NOR")
		P = new NORGate();
	else if(G == "NAND")
		P = new NANDGate();
	else if(G == "XOR")
		P = new XORGate();
	else if(G == "XNOR")
		P = new XNORGate();

	GA.push_back(P);
	return GA[GA.size()-1];
}
void Simulator::Set(string N, short V)
{
	for(int i=0; i<NA.size(); i++)
		if(NA[i]->GetName() == N)
			NA[i]->SetValue(V);
}
void Simulator::Sim()
{
	for(int i=0; i<GA.size(); i++)
		GA[i]->CalcOut();
}
void Simulator::PrintAll()
{
	for(int i=0; i<NA.size(); i++)
		NA[i]->PrintNode();
}
void Simulator::Load(string FilePath)
{
	ifstream file;
	file.open(FilePath);
	while (!file.eof())
	{
		string s;
		file>>s;
		if(s.length() == 0) // for any enter press from the user in the circuit file describtion! 
			continue;
		if(s == "OUT")
		{
			string output;
			file>>output;
			if(output == "ALL")
				PrintAll();
			else
			{
				Node* P = FindOrAdd(output);
				P->PrintNode();
			}
		}
		else if(s == "SIM")
			Sim();
		else if(s == "SET")
		{
			string N;
			short V;
			file>>N>>V;
			Set(N, V);
		}
		else
		{
			Gate* G = AddGate(s);
			string input1,input2,output;
			file>>input1>>input2>>output;
			G->SetIn1(FindOrAdd(input1));
			G->SetIn2(FindOrAdd(input2));
			G->SetOut1(FindOrAdd(output));
		}
	}
	file.close();
}