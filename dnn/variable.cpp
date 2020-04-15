#include "variable.hpp"

Variable::Variable(float _a) { this->a = _a; this->creator = NULL;}

void traverse(PVariable v) {
	cout << v->a << endl;
	Function* f = v->creator;
	if (f == NULL) return;
	cout << "size: " << f->v.size() << endl;
	loop(i, f->v.size()) traverse(f->v[i]);
}

