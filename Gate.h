#pragma once
#include "Node.h"

class Gate
{
protected:
	Node* In1;
	Node* In2;
	Node* Out1;
public:
	Gate(void);
	void SetIn1(Node* I1);
	void SetIn2(Node* I2);
	void SetOut1(Node* O);
	Node* GetIn1();
	Node* GetIn2();
	Node* GetOut1();
	virtual void CalcOut() = 0; // pure virtual function
};

