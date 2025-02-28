#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

#ifdef coderdhanraj
#include "debug.h"
#include "generator.h"
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
#define MSB(x) __lg(x)
#define LSB(x) (int)log2((x) & -(x))
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
template<typename T1, typename T2> 
istream& operator>>(istream &in, pair<T1, T2> &p){return (in >> p.first >> p.second);}
template<typename T> 
istream& operator>>(istream &in, vector<T> &v){for(auto &it: v) cin >> it; return in;}
template<typename T1, typename T2> 
ostream& operator<<(ostream &out, const pair<T1, T2> &p){return (out << p.first << " " << p.second); }
template<typename T> 
ostream& operator<<(ostream &out, const vector<T> &c){for (auto &it: c) cout << it << " "; return out;}

template <typename T1, typename T2> using gphash = gp_hash_table<T1, T2, custom_hash>;
template <typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec = vector<vector<T>>;
template <typename T1, int T2> using var = vector<array<T1, T2>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2, custom_hash>;
template <typename T1, typename T2> void amax(T1 &x, T2 y){if(x < y) x = y;}
template <typename T1, typename T2> void amin(T1 &x, T2 y){if(x > y) x = y;}
template<typename T> void unique(vector<T> &a){sort(all(a)); a.resize(a.end() - unique(all(a)));}

/* --------------------------------------------------------- UNIVERSAL CONSTANTS --------------------------------------------------- */

const double pi = acos((double)-1.0);
const double eps = 1e-9;
const int mod = 1e9 + 7;// 998244353LL;
const uint64_t inf = 2e18;
const uint64_t INF = 9e18;
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};

/* --------------------------------------------------------- USEFUL FUNCTIONS ---------------------------------------------------- */

int testcase;
int iseq(double x, double y){return abs(x - y) < eps;}
bool isSquare(int x){int y = sqrtl(x); return x == y * y;}
bool isOverflow(int x, int y){return (x > LLONG_MAX / y or y > LLONG_MAX / x);}
bool ispow2(int x){return (x ? !(x & (x - 1)) : 0);}
int ceill(int x, int y){return (x >= 0 ? (x + y - 1) / y : x / y);}
int floorr(int x, int y){return x / y - ((x ^ y) < 0 and x % y);}
int gcd(int x, int y){return (x ? gcd(y % x, x) : y);}
int lcm(int x, int y){return x / gcd(x, y) * y;}
bool google(){return cout << "Case #" << ++testcase << ": ", true;}
int expo(int x, int y, uint64_t m = INF){int res = 1; x = x % m; while (y > 0){if (y & 1) res = (res * x) % m; y = y >> 1LL, x = (x * x) % m;} return res;}
int inv(int n, int m = mod){return expo(n, m - 2, m);}
double bpow(double x, int y){double res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1LL, x *= x;} return res;}
int ncr(int n, int k){if (n < k){return 0;} k = min(k, n - k); int ans = 1; rep(i, 1, k + 1){ans *= (n - i + 1), ans /= i;} return ans;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int64_t uniform_gen(int64_t x, int64_t y){return uniform_int_distribution<int64_t>(x, y)(rng);}
int64_t gen(int64_t x = LLONG_MIN, int64_t y = LLONG_MAX){return x + rng() % static_cast<int64_t>(y - x + 1);}

/* --------------------------------------------------------- FAST INPUT/OUTPUT ----------------------------------------------------- */
void IOS(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);
    cout.setf(ios::fixed);
    /*  
        * find_by_order(K): Returns an iterator to the Kth largest element (counting from zero)
        * order_of_key (K): Returns the number of items that are strictly smaller than K
    */
}

/* ------------------------------------------------------- SOLUTION TO THE PROBLEM ------------------------------------------------- */

void solve(){
    /* JAI SHREE RAM */
    int n;
    cin >> n;
    vec<int> adj(n);
    rep(i, 1, n){
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    vec<int> dp(n, vi(2));
    function<void(int, int)> dfs = [&](int u, int p){
        for (auto &e : adj[u]){
            if (e == p) continue;
            dfs(e, u);
            dp[u][1] += dp[e][0];
        }
        for(auto &e : adj[u]){
            if (e == p) continue;
            amax(dp[u][0], 1 + dp[u][1] - dp[e][0] + dp[e][1]);
        }
    };
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << endl;
}  

int32_t main(){
    IOS();
#ifdef coderdhanraj
    auto start = high_resolution_clock::now();
    freopen("error.txt", "w", stderr);
#endif
    int ttc = 1; 
    // cin >> ttc;
    while (ttc--) solve();
#ifdef coderdhanraj
    auto time =  duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000;
    cerr << "Time: " << time << " ms!" << endl;
#endif
    return 0;
}