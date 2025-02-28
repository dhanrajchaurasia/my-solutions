#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
#ifdef coderdhanraj
#include "debug.h"
#else
#define debug(...) 
#endif
#define int long long
#define double long double
#define vi vector<int>
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back()
#define in insert
#define lb lower_bound
#define ub upper_bound
#define fr front()
#define bk back()
#define MP make_pair
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define MEM(x, y) memset(x, y, sizeof(x))
#define CNT(x) __builtin_popcountll(x)
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define bck(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define endl '\n' // remove for interactives
/* --------------------------------------------------------- TEMPLATES --------------------------------------------------- */
class custom_hash{public: static uint64_t splitmix64(uint64_t x){ x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);}
    size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);}
};
ostream& operator<<(ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) os << '-';
    else if (T == 0) return os << '0';
    for(; T > 0; ++index, T /= 10) buffer[index] = static_cast<char>('0' + (T % 10));
    while(index > 0) os << buffer[--index];
    return os;
}
istream& operator>>(istream& is, __int128& T){
    static char buffer[64]; is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-') ++index, mul *= -1;
    for(; index < len; ++index) T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;
    return is;
}
#define bigint __int128
template <typename T1, typename T2> istream& operator>>(istream &in, pair<T1, T2> &p){return (in >> p.first >> p.second);}
template <typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &p){return (out << p.first << " " << p.second); }
template <typename T> istream& operator>>(istream &in, vector<T> &a){for(auto &e : a) cin >> e; return in;}
template <typename T> ostream& operator<<(ostream &out, const vector<T> &a){for (auto &e : a) cout << e << " "; return out;}
template <typename T, size_t N> istream& operator>>(istream &in, array<T, N> &a){for(auto &e : a) cin >> e; return in;}
template <typename T, size_t N> ostream& operator<<(ostream &out, array<T, N> &a){for (auto &e : a) cout << e << " "; return out;}
template <typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec = vector<vector<T>>;
template <typename T1, int T2> using var = vector<array<T1, T2>>;
template <typename T1, typename T2> using gphash = gp_hash_table<T1, T2, custom_hash>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2, custom_hash>;
template <typename T1, typename T2> void amax(T1 &x, T2 y){if(x < y) x = y;}
template <typename T1, typename T2> void amin(T1 &x, T2 y){if(x > y) x = y;}
template <typename T> void unique(vector<T> &a){sort(all(a)); a.resize(unique(all(a)) - a.begin());}
/* --------------------------------------------------------- UNIVERSAL CONSTANTS --------------------------------------------------- */
const double eps = 1e-9;
const int mod = 1e9 + 7;// 998244353LL;
const int64_t inf = 1LL << 60;
const double pi = 3.14159265358979323846264338327950;
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};
/* --------------------------------------------------------- USEFUL FUNCTIONS ---------------------------------------------------- */
int testcase;
bool isOverflow(int x, int y){return (x > LLONG_MAX / y or y > LLONG_MAX / x);}
bool ispow2(int x){return (x ? !(x & (x - 1)) : 0);}
int roundUP(int x, int y){return (x >= 0 ? (x + y - 1) / y : x / y);}
int roundDN(int x, int y){return x / y - ((x ^ y) < 0 and x % y);}
int gcd(int x, int y){return (x ? gcd(y % x, x) : y);}
int lcm(int x, int y){return x / gcd(x, y) * y;}
int expo(int x, int y, uint64_t m = LLONG_MAX){int res = 1; x = x % m; while (y > 0){if (y & 1) res = (res * x) % m; y = y >> 1LL, x = (x * x) % m;} return res;}
double bpow(double x, int y){double res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1LL, x *= x;} return res;}
int inv(int n, int m = mod){return expo(n, m - 2, m);}
bool google(){return cout << "Case #" << ++testcase << ": ", true;}
int ncr(int n, int k){if (n < k){return 0;} k = min(k, n - k); int ans = 1; rep(i, 1, k + 1){ans *= (n - i + 1), ans /= i;} return ans;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int64_t uniform_gen(int64_t x, int64_t y){return uniform_int_distribution<int64_t>(x, y)(rng);}
int64_t gen(int64_t x = LLONG_MIN, int64_t y = LLONG_MAX){return x + rng() % static_cast<int64_t>(y - x + 1);}
#define JAI_SHREE_RAAM ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout.precision(20), cout.setf(ios::fixed);
/* ------------------------------------------------------- SOLUTION TO THE PROBLEM ------------------------------------------------- */
map<int, int> mp;
int ID = 0;
int get(int x){
    return (!mp[x] ? mp[x] = ++ID : mp[x]);
}
template <class T> class FenwickTree{
private: int n;
    vector<T> Tree[2];
public: FenwickTree(){}
    FenwickTree(int _n) : n(_n){Tree[0].assign(n + 1, 0), Tree[1].assign(n + 1, 0);}
    void _modify(bool k, int p, T u){for(; p <= n; p += (p & -p)) Tree[k][p] += u;}
    void modify(int l, int r, T u){
        _modify(0, l, u), _modify(0, r + 1, -u);
        _modify(1, l, u * (l - 1)), _modify(1, r + 1, -u * r);
    }
    T _query(bool k, int p){T res = 0; for(; p > 0; p -= (p & -p)) res += Tree[k][p]; return res;}
    T __query(int p){return _query(0, p) * p - _query(1, p);}
    T query(int l, int r){return (l > r ? 0 : __query(r) - __query(l - 1));}
    T query(int p){return query(p, p);}
    void modify(int p, T u){modify(p, p, u);}
    void update(int p, T u){modify(p, u - query(p));}
};
void solve(){
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;
    indexed_set<pii> s;
    vi c = a; unique(c);
    for (auto &e : c) e = get(e);
    FenwickTree<int> F(ID);
    auto m = [&]()->int{
        int p = (size(s) - 1) / 2;
        return s.find_by_order(p)->ff;
    };
    auto q = [&](int m)->int{
        int sumL = F.query(1, get(m));
        int sumR = F.query(get(m), ID);
        int L = s.order_of_key({m, inf});
        int R = k - s.order_of_key({m, -inf});
        int ans = L * m - sumL;
        ans += sumR - R * m;
        return ans;
    };
    rep(i, 0, k){
        F.modify(get(a[i]), a[i]);
        s.in({a[i], i});
    }
    cout << q(m()) << ' ';
    rep(i, k, n){
        s.erase({a[i - k], i - k});
        s.in({a[i], i});
        F.modify(get(a[i - k]), -a[i - k]);
        F.modify(get(a[i]), a[i]);
        cout << q(m()) << ' ';
    }
    cout << endl;
}
int32_t main(){
#ifdef coderdhanraj
    auto start = high_resolution_clock::now();
    freopen("error.txt", "w", stderr);
#endif
    JAI_SHREE_RAAM
    int ttc = 1;
    // cin >> ttc;
    while (ttc--) solve();
#ifdef coderdhanraj
    auto time =  duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000;
    cerr << "Time: " << time << " ms!" << endl;
#endif
    return 0;
}