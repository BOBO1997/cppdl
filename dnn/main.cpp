//#include "mylib.hpp"
#include "variable.hpp"
//#include <iostream>

int main() {
	loop(i, 3) cout << endl;
	cout << feq(2.0, 2.0) << endl;
	//Variable v = Variable(1.0f);
	PVariable v1 = PVariable(new Variable(1.0));
	PVariable v2 = PVariable(new Variable(2.0));
	Function* f1 = new Function();
	Function* f2 = new Function();
	Function* f3 = new Function();
	PVariable r1 = f1->forward(v1, v2);
	PVariable r2 = f2->forward(r1);
	PVariable r3 = f3->forward(r2);
	traverse(r3);
}
