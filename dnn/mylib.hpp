#ifndef _mylib_
#define _mylib_

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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

bool feq(float x, float y);
bool deq(double x, double y);
int ceillog2(ll x);
int floorlog2(ll x);
template<class T> T reverse (T container);
template<class T> T sort (T container);
ll gcd(ll m, ll n);
ll lcm(ll m, ll n);

#endif
