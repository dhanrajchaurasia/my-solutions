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
#define double long double
#define vi vector<int>
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define FIND(x, y) binary_search(all(x), y)
#define MEM(x, y) memset(x, y, sizeof(x))
#define CNT(x) __builtin_popcountll(x)
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define bck(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define endl '\n' // remove for interactives
using i64 = int64_t; using u64 = uint64_t; using u128 = __uint128_t;
/* --------------------------------------------------------- TEMPLATES --------------------------------------------------- */
class custom_hash{public: static u64 splitmix64(u64 x){ x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);}
    size_t operator()(u64 x) const {static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}
    template<typename P, typename Q>
    size_t operator()(const pair<P, Q> &Y) const{static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);}
};
template<typename P, typename Q> istream& operator>>(istream &in, pair<P, Q> &p){return (in >> p.first >> p.second);}
template<typename P, typename Q> ostream& operator<<(ostream &out, const pair<P, Q> &p){return (out << p.first << " " << p.second); }
template<typename T> istream& operator>>(istream &in, vector<T> &a){for(auto &e : a) cin >> e; return in;}
template<typename T> ostream& operator<<(ostream &out, const vector<T> &a){for (auto &e : a) cout << e << " "; return out;}
template<typename T, size_t N> istream& operator>>(istream &in, array<T, N> &a){for(auto &e : a) cin >> e; return in;}
template<typename T, size_t N> ostream& operator<<(ostream &out, array<T, N> &a){for (auto &e : a) cout << e << " "; return out;}
template<typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vec = vector<vector<T>>;
template<typename P, size_t Q> using var = vector<array<P, Q>>;
template<typename P, typename Q> using gphash = gp_hash_table<P, Q, custom_hash>;
template<typename P, typename Q> using umap = unordered_map<P, Q, custom_hash>;
template<typename P, typename Q> void amax(P &x, Q y){if(x < y) x = y;}
template<typename P, typename Q> void amin(P &x, Q y){if(x > y) x = y;}
template<typename T> void unique(vector<T> &a){sort(all(a)); a.resize(unique(all(a)) - a.begin());}
template<typename T> T ceil(T x, T y){return (x >= 0 ? (x + y - 1) / y : x / y);}
template<typename T> T floor(T x, T y){return x / y - ((x ^ y) < 0 and x % y);}
template<typename T> T gcd(T x, T y){return (x ? gcd(y % x, x) : y);}
template<typename T> T lcm(T x, T y){return x / gcd(x, y) * y;}
template<typename T> T ncr(T n, T k){if (n < k){return 0;} k = min(k, n - k); T ans = 1; rep(i, 1, k + 1){ans *= (n - i + 1), ans /= i;} return ans;}
template<typename P, typename Q> P expo(P x, Q y, u64 m = LLONG_MAX){P res = 1; x = x % m; while (y > 0){if (y & 1) res = (u128)res * x % m; y = y >> 1, x = (u128)x * x % m;} return res;}
template<typename P, typename Q> P bpow(P x, Q y){P res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1, x *= x;} return res;}
template<typename P, typename Q> P inv(P n, Q m){return expo(n, m - 2, m);}
template<typename T> T sqr(T x){return x * x;}
/* --------------------------------------------------------- UNIVERSAL CONSTANTS --------------------------------------------------- */
const double eps = 1e-9;
const int mod = 1e9 + 7;// 998244353LL; // 10000000069LL; // 3006703054056749LL;
const i64 inf = 1LL << 60;
const double pi = 3.14159265358979323846264338327950;
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};
/* --------------------------------------------------------- USEFUL FUNCTIONS ---------------------------------------------------- */
int testcase;
bool isOverflow(int x, int y){return (x > LLONG_MAX / y or y > LLONG_MAX / x);}
bool ispow2(int x){return (x ? !(x & (x - 1)) : 0);}
bool Meta(){return cout << "Case #" << ++testcase << ": ", true;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
u64 uniform_gen(u64 x, u64 y){return uniform_int_distribution<u64>(x, y)(rng);}
u64 gen(i64 x = LLONG_MIN, i64 y = LLONG_MAX){return x + rng() % static_cast<u64>(y - x + 1);}
#define JAI_SHREE_RAAM ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout.precision(20), cout.setf(ios::fixed);
/* ------------------------------------------------------- SOLUTION TO THE PROBLEM ------------------------------------------------- */
namespace Treap{
    struct node{
        node *l, *r;
        int wt, id, sz, rev;
        node(int i) : wt(rand()), id(i), sz(1), rev(0){}
    };
    int sz(node *t){return t ? t->sz : 0LL;}
    void split(node *t, node *&l, node *&r, int k){// l = [1....k], r = [k+1.......n]
        if (!t) return void(l = r = NULL);
        if (sz(t->l) < k) split(t->r, t->r, r, k - sz(t->l) - 1), l = t;
        else split(t->l, l, t->l, k), r = t;
        t->sz = sz(t->l) + sz(t->r) + 1;
    }
    void push(node *t){
        if (!t or !t->rev) return;
        t->rev = false, swap(t->l, t->r);
        if (t->l) t->l->rev ^= true;
        if (t->r) t->r->rev ^= true;
    }
    void merge(node *&t, node *l, node *r){// t = l + r
        push(l), push(r);
        if (!l or !r) return void(t = !l ? r : l);
        if (l->wt < r->wt) merge(l->r, l->r, r), t = l;
        else merge(r->l, l, r->l), t = r;
        t->sz = sz(t->l) + sz(t->r) + 1;
    }
    void rev(node *&t, int l, int r){
        node *t1, *t2, *t3;
        split(t, t1, t2, l), split(t2, t2, t3, r - l + 1);
        t2->rev = true, merge(t, t1, t2), merge(t, t, t3);
    }
    node *init(int n){
        node *t = 0;
        rep(i, 0, n) merge(t, t, new node(i));
        return t;
    }
    vi inorder(node *t){
        vi order;
        stack<node*> s; s.push(t);
        function<void(node*)> dfs = [&](node *u){
            if (!u) return;
            dfs(u->l), order.pb(u->id), dfs(u->r);
        };
        dfs(t);
        return order;
    }
};
using namespace Treap;
void solve(){
    int n, m; cin >> n >> m;
    node *t = init(n);
    string s; cin >> s;
    auto f = inorder(t);
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        node *A, *B, *C, *D;
        split(t, A, B, x - 1); // A = [1......x-1], B = [x........n]
        split(B, C, D, y - x + 1); // C = [x........y], D = [y+1......n]
        merge(t, A, D), merge(t, t, C);
    }
    auto id = inorder(t);
    rep(i, 0, n) cout << s[id[i]]; cout << endl;
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