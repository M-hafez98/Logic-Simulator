#include "ORGate.h"

void ORGate::CalcOut()
{
	if (In1->GetValue() || In2->GetValue())
		Out1->SetValue(1);
	Out1->SetValue(0);
}