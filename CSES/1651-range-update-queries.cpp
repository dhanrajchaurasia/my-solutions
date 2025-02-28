#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
#ifdef coderdhanraj
#include "libs/debug.h"
#else
#define debug(...) 
#endif
#define int long long
#define double long double
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
using i64 = int64_t; using u64 = uint64_t; using i128 = __int128_t; using u128 = __uint128_t;
using vi = vector<int>; using mii = map<int, int>; using pii = pair<int, int>; using vii = vector<pii>;
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
template<typename P, typename Q> using indexed_map = tree<P, Q, less<P>, rb_tree_tag, tree_order_statistics_node_update>;
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
const int mod = 998244353LL; // 10000000069LL; // 3006703054056749LL;
const i64 inf = 1LL << 60;
const double pi = 3.14159265358979323846264338327950;
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};
/* --------------------------------------------------------- USEFUL FUNCTIONS ---------------------------------------------------- */
int testcase;
bool isOverflow(int x, int y){return (x > LLONG_MAX / y or y > LLONG_MAX / x);}
bool ispow2(int x){return (x ? !(x & (x - 1)) : 0);}
bool Case(){return cout << "Case #" << ++testcase << ": ", true;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
i64 rand(i64 x, i64 y){return uniform_int_distribution<i64>(x, y)(rng);}
#define JAI_SHREE_RAAM ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout.precision(20), cout.setf(ios::fixed);
/* ------------------------------------------------------- SOLUTION TO THE PROBLEM ------------------------------------------------- */
template <class T, T mod, class U = typename conditional<is_same<T, int32_t>::value, int64_t, __int128_t>::type> class modnum{
    T phi = mod - 1, u; // prime mod, a ^ b % mod = a ^ (b % phi) % mod
public: modnum(U v) : u(v >= 0 ? v % mod : (mod - (-v) % mod) % mod){}
    modnum() : modnum(0){}
    explicit operator T()const{return u;}
    operator bool()const{return u != 0;}
    modnum &operator+=(const modnum &p){u += p.u; if (u >= mod) u -= mod; return *this;}
    modnum &operator-=(const modnum &p){u += mod - p.u; if (u >= mod) u -= mod; return *this;}
    modnum &operator*=(const modnum &p){u = T((U)u * (p.u) % mod); return *this;}
    modnum &operator/=(const modnum &p){return *this *= p.inv();}
    modnum &operator++(){return *this += 1;} 
    modnum &operator--(){return *this -= 1;}
    modnum operator++(T){modnum tmp = *this; ++*this; return tmp;}
    modnum operator--(T){modnum tmp = *this; --*this; return tmp;}
    modnum operator+(const modnum &p)const{return modnum(*this) += p;}
    modnum operator-(const modnum &p)const{return modnum(*this) -= p;}
    modnum operator*(const modnum &p)const{return modnum(*this) *= p;}
    modnum operator/(const modnum &p)const{return modnum(*this) /= p;}
    modnum operator-()const{return modnum(0) - *this;}
    bool operator!()const{return !u;}
    bool operator~()const{return ~u;}
    bool operator==(const modnum &p)const{return u == p.u;}
    bool operator==(const U val)const{return *this == modnum(val);}
    bool operator!=(const U val)const{return *this != modnum(val);}
    bool operator!=(const modnum &p)const{return u != p.u;} 
    modnum inv()const{assert(*this); return expo(phi - 1);}
    modnum expo(U k)const{modnum now = *this, ret = 1; for (; k; k >>= 1, now *= now) if (k & 1) ret *= now; return ret;}
    modnum pow(U k)const{return k < 0 ? inv().expo(-k) : expo(k);}
    friend modnum operator+(U lhs, const modnum& rhs){return rhs + lhs;}
    friend modnum operator-(U lhs, const modnum& rhs){return -rhs + lhs;}
    friend modnum operator*(U lhs, const modnum& rhs){return rhs * lhs;}
    friend modnum operator/(U lhs, const modnum& rhs){return rhs.inv() * lhs;}
    friend bool operator==(U lhs, const modnum& rhs){return rhs == lhs;}
    friend bool operator!=(U lhs, const modnum& rhs){return rhs != lhs;}
    friend istream &operator>>(istream &is, modnum &p){U a; is >> a; p = a; return is;}
    friend ostream &operator<<(ostream &os, const modnum &p){return os << static_cast<T>(p);}
    friend void __print(modnum &p){cerr << static_cast<T>(p);}
};
using mint = modnum<int32_t, mod>;
template <class T, class U> class ST{
private: int n, sz, lg;
    const T O = T();
    vector<T> seg; vector<U> lazy;
    T op(T x, T y){return x + y;}
    void pull(int p){seg[p] = op(seg[p << 1], seg[p << 1 | 1]);}
    void apply(int p, U u){
        seg[p].apply(u);
        if (p < sz) lazy[p] += u;
    }
    void push(int p){
        apply(p << 1, lazy[p]);
        apply(p << 1 | 1, lazy[p]);
        lazy[p] = U();
    }
public: ST(int _n) : n(_n), sz(2 << __lg(n == 1?: n - 1)), lg(__lg(sz)){seg.assign(sz << 1, O), lazy.assign(sz, U());}
    ST(vi &a) : ST(size(a)){
        for (int i = 0; i < n; i++) seg[sz + i] = T(a[i]);
        for (int i = sz - 1; i; i--) pull(i);
    }
    void update(int p, T val){
        p += sz - 1;
        for (int i = lg; i; i--) push(p >> i);
        seg[p] = val;
        for (int i = 1; i <= lg; i++) pull(p >> i);
    }
    T query(int p){
        p += sz - 1;
        for (int i = lg; i; i--) push(p >> i);
        return seg[p];
    }
    T query(int l, int r){
        l += sz - 1, r += sz;
        for (int i = lg; i; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        T ra = O, rb = O;
        for (; l < r; l >>= 1, r >>= 1){
            if (l & 1) ra = op(ra, seg[l++]);
            if (r & 1) rb = op(seg[--r], rb);
        }
        return op(ra, rb);
    } 
    void add(int p, U u) {
        p += sz - 1;
        for (int i = lg; i; i--) push(p >> i);
        seg[p].apply(u);
        for (int i = 1; i <= lg; i++) pull(p >> i);
    }
    void add(int l, int r, U u) {
        l += sz - 1, r += sz;
        for (int i = lg; i; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1){
            if (l & 1) apply(l++, u);
            if (r & 1) apply(--r, u);
        }
        l = l0, r = r0;
        for (int i = 1; i <= lg; i++) {
            if (((l >> i) << i) != l) pull(l >> i);
            if (((r >> i) << i) != r) pull((r - 1) >> i);
        }
    }
};
struct lazy{
    int u; bool v, done = false;
    lazy(int u = 0, bool v = false) : u(u), v(v){}
    lazy operator+=(lazy &a){
        if (v) u = 0;
        u += a.u;
        return *this;
    }
};
struct node{
    int val, sz;
    node(int val = 0, int sz = 0) : val(val), sz(sz){}
    node operator+(node &a){
        node res; res.val = val + a.val;
        res.sz = sz + a.sz;
        return res;
    }
    void apply(lazy &u){
        if (u.v) val = 0;
        val += sz * u.u;
        u.done = true;
    }
};
void solve(){
    int n, m; cin >> n >> m;
    ST<node, lazy> seg(n);
    rep(i, 0, n){
        int x; cin >> x;
        seg.update(i + 1, node(x, 1));
    }
    rep(i, 0, m){
        int t, l, r, v; cin >> t, --t;
        if (t){
            cin >> v;
            cout << seg.query(v).val << endl;
        }else{
            cin >> l >> r >> v;
            seg.add(l, r, lazy(v));
        }
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