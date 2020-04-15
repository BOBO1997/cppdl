#include <iostream>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;

const double eps = 1e-7;

using ll = long long;
using vi = vector<int>; using vi2 = vector<vi>; using vi3 = vector<vi2>;
using vll = vector<ll>; using vll2 = vector<vll>; using vll3 = vector<vll2>;
using vd = vector<double>; using vd2 = vector<vd>; using vd3 = vector<vd2>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using vpi = vector<pi>; using vpll = vector<pll>;
using vstr = vector<string>;
using mapsi = map<string, int>;

#define loopi(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define loop(i, n) for (int i = 0; i < (int)n; i++)
#define loopeq(i, n) for (int i = 0; i <= (int)n; i++)
#define loopll(i, n) for (ll i = 0; i < (ll)n; i++)
#define looplleq(i, n) for (ll i = 0; i <= (ll)n; i++)
#define rloopi(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define rloop(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define rloopeq(i, n) for (int i = (int)n - 1; i >= 1; i--)
#define rloopll(i, n) for (int i = (ll)n - 1; i >= 0; i--)
#define rlooplleq(i, n) for (int i = (ll)n - 1; i >= 1; i--)
#define all(a) (a).begin(), (a).end()

bool feq(float x, float y) { return abs(x-y) <= eps; }
bool deq(double x, double y) { return abs(x-y) <= eps; }
int ceillog2(ll x) { return int (ceil(log2(x))); }
int floorlog2(ll x) { return int (floor(log2(x))); }
template<class T> T reversed (T container) { reverse(container.begin(), container.end()); return container; }
template<class T> T sort (T container) { sort(container.begin(), container.end()); return container; }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return m * n / gcd(m, n); }

/*============================================================*/

class Function;

class Variable {
public:
	float a = 0;
	Function* creator = NULL;
	Variable(float _a) { this->a = _a; }
};

using PVariable = shared_ptr <Variable>;

class Function {
public:
	vector <PVariable> v;

	PVariable forward(PVariable v1, PVariable v2) {
		v.push_back(v1);
		v.push_back(v2);
		PVariable pv = PVariable(new Variable(0));
		pv->creator = this;
		pv->a += v1->a + v2->a;
		return pv;
	}

	PVariable forward(PVariable v1) {
		v.push_back(v1);
		PVariable pv = PVariable(new Variable(0));
		pv->creator = this;
		pv->a += v1->a;
		return pv;
	}
};

void traverse(PVariable v) {
	cout << v->a << endl;
	Function* f = v->creator;
	if (f == NULL) return;
	cout << "size: " << f->v.size() << endl;
	loop(i, f->v.size()) traverse(f->v[i]);
}

/*============================================================*/

float dot(float* v1, float* v2, int len) {
	float ret = 0;
	loop(i, len) ret += v1[i] * v2[i];
	return ret;
}
float step(float v) { return v > 0 ? 1 : 0; }
float forward(float* x, float* w, int len) { return step(dot(x, w, len)); }
void train(float* w, float* x, float t, float e, int len) { 
	float z = forward(x, w, len);
	loop(i, len) w[i] += (t - z) * e * x[i];
}

#define DATA_NUM 4
#define WEIGHT_NUM 3

int main() {
	shared_ptr<int> p = shared_ptr<int> (new int(3));
	cout << *p << endl;
	shared_ptr<int> q = p;
	cout << *p << endl;
	cout << *q << endl;

	PVariable v1 = PVariable(new Variable(1));
	PVariable v2 = PVariable(new Variable(2));
	Function* f1 = new Function();
	Function* f2 = new Function();
	Function* f3 = new Function();
	PVariable r1 = f1->forward(v1, v2);
	PVariable r2 = f2->forward(r1);
	PVariable r3 = f3->forward(r2);
	traverse(r3);

	const float e = 0.1;

	float x[DATA_NUM][WEIGHT_NUM] = {{1,0,0},{1,0,1},{1,0,1},{1,1,1}};
	float w[WEIGHT_NUM] = {0,0,0};
	float t[DATA_NUM] = {0,0,0,1};

	const int epoch = 10;
	loop(i, epoch) {
		cout << "epoch : " << i << " ";
		loop(j, DATA_NUM) train(w, x[j], t[j], e, WEIGHT_NUM);
		cout << " weight ";
		loop(j, WEIGHT_NUM) cout << w[i] << " ";
		cout << endl;
	}
	loop(i, DATA_NUM) cout << forward(w, x[i], WEIGHT_NUM) << " ";
	cout << endl;

}
