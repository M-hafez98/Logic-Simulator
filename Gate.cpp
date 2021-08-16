#include "Gate.h"


Gate::Gate()
{
	In1 = NULL;
	In2 = NULL;
	Out1 = NULL;
}
void Gate::SetIn1(Node* I1)
{
	In1 = I1;
}
void Gate::SetIn2(Node* I2)
{
	In2 = I2;
}
void Gate::SetOut1(Node* O)
{
	Out1 = O;
}
Node* Gate::GetIn1()
{
	return In1;
}
Node* Gate::GetIn2()
{
	return In2;
}
Node* Gate::GetOut1()
{
	return Out1;
}