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
template <class T> class ST{
private: int n, N;
    vector<T> seg;
    vi lazy;
    const T O = T(0);
public: ST(){}
    ST(int _n) : n(_n), N(2 << __lg(n - 1) + 1){seg.assign(N + 2, O), lazy.assign(N + 2, -inf);}
    T op(T x, T y){return (x + y);}
    void push(int x, int s, int e){
        if (lazy[x] == -inf) return;
        seg[x] = lazy[x];
        if (s != e) lazy[x << 1] = lazy[x], lazy[x << 1 | 1] = lazy[x];
        lazy[x] = -inf;
    }
    void _update(int x, int s, int e, int l, int r, int u){
        push(x, s, e);
        if (e < s or s > r or e < l) return;
        if (l <= s and r >= e) return lazy[x] = u, push(x, s, e);
        int m = (s + e) >> 1;
        _update(x << 1, s, m, l, r, u), _update(x << 1 | 1, m + 1, e, l, r, u);
        seg[x] = op(seg[x << 1], seg[x << 1 | 1]);
    }
    T _query(int x, int s, int e, int l, int r){
        push(x, s, e);
        if (l > e or r < s or s > e) return O;
        if (l <= s and r >= e) return seg[x];
        int m = (s + e) >> 1;
        return op(_query(x << 1, s, m, l, r), _query(x << 1 | 1, m + 1, e, l, r));
    }   
    T query(int l, int r){return l > r ? 0 : _query(1, 1, n, l, r);}
    T query(int p){return query(p, p);}
    void update(int l, int r, int u){_update(1, 1, n, l, r, u);}
    void update(int p, int u){update(p, p, u);}
};
struct node{
    int sum, pre, suf, maxi;
    node(){}
    node(int val){
        sum = val;
        pre = suf = maxi = max(0LL, val);
    }
    node operator+(node &a){
        node f(sum + a.sum);
        f.pre = max({f.pre, pre, sum + a.pre});
        f.suf = max({f.suf, a.suf, suf + a.sum});
        f.maxi = max({f.maxi, f.pre, f.suf, maxi, a.maxi, suf + a.pre});
        return f;
    }
    void operator=(int a){
        this->sum = a;
        this->pre = this->suf = this->maxi = max(0LL, a);
    }
};
void solve(){
    int n, q; cin >> n >> q;
    ST<node> seg(n);
    rep(i, 0, n){
        int x; cin >> x;
        seg.update(i + 1, x);
    }
    rep(i, 0, q){
        int x, y; cin >> x >> y;
        seg.update(x, y);
        cout << seg.query(1, n).maxi << endl;
    }
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