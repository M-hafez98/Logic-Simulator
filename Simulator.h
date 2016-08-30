#include "Gate.h"
#include <vector>
#include <iostream>
#include "ANDGate.h"
#include "NANDGate.h"
#include "ORGate.h"
#include "NORGate.h"
class Simulator
{
	vector<Node*>NA;
	vector<Gate*>GA;
public:
	Node* FindNode(string N);
	Node* AddNode(string N);
	Node* FindOrAdd (string N);
	Gate* AddGate(string G);
	void Sim();
	void PrintAll();
	void Load(string FilePath);
};

