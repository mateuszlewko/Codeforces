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

ll first_after(ll n_mult, ll m_mult, ll which, ll x) {
	ll mm = which == 2 ? n_mult : m_mult;
	if (x % mm == 0) return x;
	else return x - (x % mm) + mm;
}

ll n, m;
ll gg;

bool can_move(ll n_mult, ll m_mult, ll sx, ll sy, ll ex, ll ey) {
	if (sx == ex) {
			ll ft = first_after(n_mult, m_mult, sx, sy);
			error(ft, ey);

			if (sy != ey && ft < ey) return false;
			else return true;
		} else {
			ll ft = first_after(n_mult, m_mult, sx, sy);
			ll sd = ex == 2LL ? ft / m_mult * gg
							          : ft / n_mult * gg;

			error(sy, ft, ey, sd);
			return sd >= ey;
		}
}

int main() {
	_upgrade;
	ll q;
	cin >> n >> m >> q;

	gg = __gcd(n, m);
	ll n_mult = (m / gg);
	ll m_mult = (n / gg);

	error(n_mult, m_mult);

	while (q--) {
		ll sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		if (can_move(n_mult, m_mult, sx, sy, ex, ey) || 
		    can_move(n_mult, m_mult, ex, ey, sx, sy)) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
}

