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

vector<int> lens;
int k;

bool check(int mid) {
	int used = 1;
	int row = 0;

	for (int l : lens) {
		if (l > mid) return false;

		if (l + row > mid) {
			used++;
			row = l;
		} else {
			row += l;
		}
		
		// error(mid, used, row);
	}


	return used <= k;
}

int main() {
	_upgrade;

	cin >> k;

	string s;
	while (cin >> s) {
		int cnt = 0;
		for (char c : s) {
			if (c == '-') {
				lens.push_back(cnt + 1);
				cnt = 0;
			} else {
				cnt++;
			}
		}

		if (cnt > 0) lens.push_back(cnt + 1);
		else {
			assert(lens.size());
			lens[int(lens.size()) - 1]++;
		}
	}

	assert(lens.size());
	lens[int(lens.size()) - 1]--;
	// error(lens);

	int beg = 0;
	int end = 1000 * 1000 + 10;
	while (beg != end - 1) {
		int mid = (beg + end) / 2;

		if (check(mid)) end = mid;
		else beg = mid;
	}

	cout << end << "\n";
}

