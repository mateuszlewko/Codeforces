#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#ifndef JUST_CPP11
template<typename... Args>
void read(Args&... args)
{
    ((cin >> args), ...);
}

template<typename... Args>
void write(Args... args)
{
    ((cout << args << " "), ...);
}

template<typename... Args>
void writeln(Args... args)
{
    ((cout << args << " "), ...);
	cout << "\n";
}
#endif

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

#pragma endregion 

const int N = 10 * 1000 + 10;
const int M = 110;
bitset<N> possible[M];
int A[N];

bool check(int n, int t) {
	For (i, M) {
		For (j, N) possible[i][j] = 0;
	}

	For (i, t + 1) possible[0][i] = true;

	For (i, n) {
		int len = A[i];

		For (j, t + 1) {
			if (!possible[i][j]) continue;

			int nj = j + len;
			if (nj <= t) possible[i + 1][nj] = true;

			nj = j - len;
			if (nj >= 0) possible[i + 1][nj] = true;
		}

		// For (j, t + 1) cout << possible[i + 1][j] << " ";
		// cout << " | " << i + 1 << endl;
	}

	For (i, t + 1) {
		// error()
		if (possible[n][i]) return true;
	}

	return false;
}

int main() {
	_upgrade;

	int f;
	cin >> f;

	For (i, f) {
		int t, n;
		cin >> t >> n;

		For (j, n) {
			int x, y;
			cin >> x >> y;

			A[j] = y - x;
		}

		if (!check(n, t)) {
			cout << "impossible\n";
			return 0;
		}
	}

	cout << "possible\n";
}

