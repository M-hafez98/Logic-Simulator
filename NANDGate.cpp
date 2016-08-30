#include "NANDGate.h"


void NANDGate::CalcOut()
{
	if(In1->GetValue() && In2->GetValue())
		Out1->SetValue(0);
	Out1->SetValue(1);
}
