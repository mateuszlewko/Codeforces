#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

const int N = 5005;
int A[2][N];

bool print_ans(int bb, int ba, int ab, int aa, int n) {
	vector<int> ans;
	int fst_got = 0;
	int snd_got = 0;

	For (i, n) {
		int x = A[0][i];
		int y = A[1][i];

		if (x && y && bb) {
			bb--;
			fst_got++;
			ans.push_back(i + 1);
		}
		else if (x && !y && ba) {
			ba--;
			fst_got++;
			ans.push_back(i + 1);
		}
		else if (!x && y && ab) {
			ab--;
			ans.push_back(i + 1);
		}
		else if (!x && !y && aa) {
			aa--;
			ans.push_back(i + 1);
		} else if (y) {
			snd_got++;
		}
	}

	// if (fst_got != snd_got) return false;

	// if (int(ans.size()) != n / 2 || bb || ba || ab | aa) return false;
	writeln(ans);
	return true;
}

int main() {
    _upgrade;

	int n;
	read(n);

	For (i, 2) {
		For (j, n) {
			char c;
			read(c);
			A[i][j] = c - '0';
		}
	}

	int bb_cnt = 0;
	int ba_cnt = 0;

	int ab_cnt = 0;
	int aa_cnt = 0;

	For (i, n) {
		int x = A[0][i];
		int y = A[1][i];

		if (x && y) bb_cnt++;
		else if (x && !y) ba_cnt++;
		else if (!x && y) ab_cnt++;
		else aa_cnt++;
	}

	for (int i = 0; i <= ab_cnt; i++) {
		for (int j = 0; j <= ba_cnt; j++) {
			int take = i + j;
			int d2 = ab_cnt + bb_cnt - take;

			if (d2 % 2 != 0 || d2 / 2 > bb_cnt) continue;
			int d = d2 / 2;
			int a = n / 2 - take - d;
			if (a < 0 || a > aa_cnt) continue;

			if (d + j + i + a != n / 2) continue;

			print_ans(d, j, i, a, n);
			return 0;
		}
	}

	writeln(-1);
}

