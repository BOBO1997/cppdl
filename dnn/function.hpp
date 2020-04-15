#include "mylib.hpp"
#include "variable.hpp"

class Function {
private:
public:
	vector <PVariable> v;
	PVariable forward(PVariable v1, PVariable v2);
	PVariable forward(PVariable v1);
};

void traverse(PVariable v);


