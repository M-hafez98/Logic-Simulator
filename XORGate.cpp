#include "XORGate.h"


void XORGate::CalcOut()
{
	if(In1->GetValue() == In2->GetValue())
		Out1->SetValue(0);
	else
		Out1->SetValue(1);
}
