#pragma once
#include "Super.h"

class Sub : public Super
{
	public:
		void someMethod () override;	// override : 
		void someOtherMethod ();
};