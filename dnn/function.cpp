#include "variable.hpp"
#include "function.hpp"

PVariable Function::forward(PVariable v1, PVariable v2) {
	v.push_back(v1);
	v.push_back(v2);
	PVariable pv = PVariable(new Variable(0));
	pv->creator = this;
	pv->a += v1->a + v2->a;
	return pv;
}

PVariable Function::forward(PVariable v1) {
	v.push_back(v1);
	PVariable pv = PVariable(new Variable(0));
	pv->creator = this;
	pv->a += v1->a;
	return pv;
}
