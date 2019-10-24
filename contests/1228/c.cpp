#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

template<typename T, typename U>
pair<T, U>& operator+=(pair<T, U> &lhs, const pair<T, U> &rhs){
	lhs.first += rhs.first;
	lhs.second += rhs.second;
	return lhs;
}

template<typename T, typename U>
pair<T, U>& operator-=(pair<T, U> &lhs, const pair<T, U> &rhs){
	lhs.first -= rhs.first;
	lhs.second -= rhs.second;
	return lhs;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &container) {
	for (auto &u : container) os << u << " ";
	return os;
}

template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds; 
using namespace std; 

template<typename T>
using pb_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#if DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string>) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#else
#define error(...) do {} while (0)
#endif

template<typename T, typename U>
pair<T, U> operator-(const pair<T, U> &l, const pair<T, U> &r) {
	return {l.first - r.first, l.second - r.second};
}
template<typename T, typename U>
pair<T, U> operator+(const pair<T, U> &l, const pair<T, U> &r) {
	return {l.first + r.first, l.second + r.second};
}

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int P = 100 * 1000 + 10;
bool not_prime[P];

// vector<int> get_primes() {
// 	vector<int> res; 
// 	for (int i = 2; i < P; i++) {
// 		if (not_prime[i]) continue;
// 		res.push_back(i);
// 		for (int j = i * i; j < P; j += i) not_prime[j] = true;
// 	}

// 	return res;
// }

vector<int> get_divs(int x) {
	vector<int> res;

	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) res.push_back(i);
		while (x % i == 0) x /= i;
	}

	if (x != 1) {
		// assert(res.empty());
		res.push_back(x);
	}

	return res;
}

const ll M = 1000 * 1000 * 1000 + 7;

ll fast_pow(ll x, ll n) {
	if (n == 0) return 1;
	ll r = fast_pow(x, n / 2LL);
	r = (r * r) % M;

	if (n & 1) {
		r = (r * x) % M;
	}

	return r;
}

ll get_res(ll x, ll n) {
	ll sum = 0;
	ll curr = n / x;

	while (curr > 0) {
		sum += curr;
		curr /= x;
	}

	return fast_pow(x, sum);
}

int main() {
	_upgrade;

	int x;
	ll n;
	cin >> x >> n;

	auto ps = get_divs(x);
	ll res = 1;

	for (ll p : ps) {
		ll r = get_res(p, n);
		// error(p, r);
		res = (res * r) % M;
	}

	cout << res << "\n";
}
