#ifndef _variable_
#define _variable_

#include "mylib.hpp"
#include <boost/intrusive_ptr.hpp>

class Function;

class Variable {
private:	
public:
	float a;
	Function* creator;
	Variable(float _a);
};

using PVariable = shared_ptr <Variable>;

#endif
