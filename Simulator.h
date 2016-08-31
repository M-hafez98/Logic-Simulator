#pragma once
#include <vector>
#include "Gate.h"

class Simulator
{
	vector<Node*>NA;
	vector<Gate*>GA;
public:
	~Simulator();
	Node* FindNode(string N);
	Node* AddNode(string N);
	Node* FindOrAdd (string N);
	Gate* AddGate(string G);
	void Sim();
	void PrintAll();
	void Load(string FilePath);
};
