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

int cnt[30];

int main() {
    _upgrade;
	int n;
	cin >> n;
	string s;
	cin >> s;

	SORT(s);
	// for (char c : s) 
	// 	cnt[c - 'a']++;

	// int odd = -1;
	// For (i, 30) {
	// 	if (cnt[i] % 2 == 1) {
	// 		odd = i;
	// 		break;
	// 	}
	// }

	// string res;
	// if (odd != -1) {
	// 	res.push_back('a' + odd);
	// 	cnt[odd]--;
	// }

	// For (i, 30) {
	// 	For (j, cnt[i] / 2) {
	// 		res.push_back('a' + i);
	// 	}
	// } 

	// reverse(res.begin(), res.end());
	// For (i, 30) {
	// 	For (j, cnt[i] / 2) {
	// 		res.push_back('a' + i);
	// 	}
	// } 

	// For (i, 30) {
	// 	if (cnt[i] % 2 == 1) {
	// 		res.push_back('a' + i);
	// 	}
	// } 

	cout << s;
}

