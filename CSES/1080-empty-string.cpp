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
using i64 = int64_t; using u64 = uint64_t; using i128 = __int128_t; using u128 = __uint128_t;
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
const int mod = 1e9 + 7;// 998244353LL; // 10000000069LL; // 3006703054056749LL;
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
template <int mod> struct mod_int{
    long long x;
    mod_int() : x(0){}
    mod_int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod){}
    static long long get_mod(){return mod;}
    mod_int &operator+=(const mod_int &p){return (x += p.x) >= mod ? x -= mod : 0, *this;}
    mod_int &operator-=(const mod_int &p){return (x += mod - p.x) >= mod ? x -= mod : 0, *this;}
    mod_int &operator*=(const mod_int &p){return x = (long long)((__uint128_t)x * p.x % mod), *this;}
    mod_int &operator/=(const mod_int &p){return *this *= p.inv();}
    mod_int &operator++(){return *this += mod_int(1);} 
    mod_int &operator--(){return *this -= mod_int(1);}
    mod_int operator++(int32_t){mod_int tmp = *this; ++*this; return tmp;}
    mod_int operator--(int32_t){mod_int tmp = *this; --*this; return tmp;}
    mod_int operator+(const mod_int &p)const{return mod_int(*this) += p;}
    mod_int operator-(const mod_int &p)const{return mod_int(*this) -= p;}
    mod_int operator*(const mod_int &p)const{return mod_int(*this) *= p;}
    mod_int operator/(const mod_int &p)const{return mod_int(*this) /= p;}
    mod_int operator-()const{return mod_int(-x);}
    bool operator!()const{return !x;}
    bool operator~()const{return ~x;}
    bool operator==(const mod_int &p)const{return x == p.x;}
    bool operator!=(const mod_int &p)const{return x != p.x;} 
    mod_int inv()const{assert(*this != mod_int(0)); return pow(mod - 2);}
    mod_int pow(long long k)const{mod_int now = *this, ret = 1; for (; k > 0; k >>= 1, now *= now) if (k & 1) ret *= now; return ret;}
    friend istream &operator>>(istream &is, mod_int &p){long long a; is >> a; p = mod_int<mod>(a); return is;}
    friend ostream &operator<<(ostream &os, const mod_int &p){return os << p.x;}
};
using mint = mod_int<mod>;
void __print(mint x) {cerr << x;}
class combinatorics{
private: vector<mint> Fact, iFact;
public: combinatorics(int n){
        Fact.resize(n + 1), iFact.resize(n + 1); Fact[0] = 1;
        for (int i = 1; i <= n; i++) Fact[i] = (Fact[i - 1] * i);
        iFact[n] = Fact[n].inv();
        for (int i = n; i >= 1; i--) iFact[i - 1] = (iFact[i] * i);
    }
    mint fact(int n){return Fact[n];}
    mint ifact(int n){return iFact[n];}
    mint nPr(int n, int m){return (m < 0 or n < m ? 0 : (fact(n) * ifact(n - m)));}
    mint nCr(int n, int m){return (m < 0 or n < m ? 0 : (nPr(n, m) * ifact(m)));}
    mint Cn(int n){return (nCr(2 * n, n) - nCr(2 * n, n - 1));}
    mint Cn(int n, int k){return (nCr(2 * n + k, n) - nCr(2 * n + k, n - 1));}
    // More about Catalan, Stirling, Bell Numbers: https://p.ip.fi/ztXa
};
const int N = 500;
int dp[N][N];
string s;
combinatorics f(N);
int rec(int l, int r){
    if ((r - l + 1) & 1) return 0;
    if (l > r) return 1;
    int &ans = dp[l][r];
    if (~ans) return ans;
    ans = 0;
    rep(i, l + 1, r + 1) if (s[i] == s[l]){
        mint way = rec(l + 1, i - 1) * rec(i + 1, r);
        way *= f.nCr((r - l + 1) / 2, (i - l + 1) / 2);
        ans = (ans + way.x) % mod;
    }
    return ans;
}
void solve(){
    MEM(dp, -1);
    cin >> s;
    int n = size(s);
    cout << rec(0, n - 1) << endl;
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