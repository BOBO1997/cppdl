#include "mylib.hpp"

bool feq(float x, float y) { return abs(x-y) <= eps; }
bool deq(double x, double y) { return abs(x-y) <= eps; }
int ceillog2(ll x) { return int (ceil(log2(x))); }
int floorlog2(ll x) { return int (floor(log2(x))); }
template<class T> T reversed (T container) { reverse(container.begin(), container.end()); return container; }
template<class T> T sort (T container) { sort(container.begin(), container.end()); return container; }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return m * n / gcd(m, n); }
