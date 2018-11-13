#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#pragma endregion 

const int N = 1010;
int A[N]; 
int res[N];

bool check(int n, int k) {
	For (i, N) res[i] = 0;
	res[0] = A[0];
	
	for (int i = 1; i < n; i++) {
		if (i < k) {
			res[i] = A[i] - A[i - 1];
		} else if (res[i % k] != A[i] - A[i - 1]) return false;
	}

	return true;
}

int main() {
    _upgrade;
	int n;

	cin >> n;
	For (i, n) cin >> A[i];

	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (check(n, i)) ans.push_back(i);
	}

	cout << ans.size() << "\n";
	for (int x : ans) cout << x << " ";
}

