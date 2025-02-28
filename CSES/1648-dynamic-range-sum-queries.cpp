#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

// BOOST IS THE SECRET OF MY ENERGY!
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

#ifdef coderdhanraj
#include "debug.h"
#else
#define debug(...)
#endif

using int64 = int64_t;
#define int int64
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
#define endl '\n'
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
#define LEFT(a, l, r, k) rotate(a.begin() + l, a.begin() + l + (k % (r - l + 1)), a.begin() + r + 1)
#define RIGHT(a, l, r, k) rotate(a.begin() + l, a.begin() + r + 1 - (k % (r - l + 1)), a.begin() + r + 1)

/* --------------------------------------------------------- TEMPLATES --------------------------------------------------- */

class custom_hash{public: static uint64_t splitmix64(uint64_t x){ x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);}
    size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}
};
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &in, pair<T1, T2> &p){ return (in >> p.first >> p.second);}
template<typename T> // cin >> vector<T>
istream& operator>>(istream &in, vector<T> &v){for(auto &it: v) cin >> it; return in;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &out, const pair<T1, T2> &p){return (out << p.first << " " << p.second); }
template<typename T> //cout << vector<T>
ostream& operator<<(ostream &out, const vector<T> &c){for (auto &it: c) cout << it << " "; return out;}

//template <typename T1, typename T2> using gphash = gp_hash_table<T1, T2, custom_hash>;
//template <typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec = vector<vector<T>>;
template <typename T1, int T2> using var = vector<array<T1, T2>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2, custom_hash>;
template <typename T1, typename T2> void amax(T1 &x, T2 y){if(x < y) x = y;}
template <typename T1, typename T2> void amin(T1 &x, T2 y){if(x > y) x = y;}

/* --------------------------------------------------------- UNIVERSAL CONSTANTS --------------------------------------------------- */

const double pi = acos((double)-1.0);
const double eps = 1e-9;
const int mod = 1e9 + 7;// 998244353LL;
const int64 inf = 2e18;
const int64 INF = 9e18;
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
int expo(int x, int y, int64 m = INF){int res = 1; x = x % m; while (y > 0){if (y & 1) res = (res * x) % m; y = y >> 1LL, x = (x * x) % m;} return res;}
int inv(int n, int m = mod){return expo(n, m - 2, m);}
double bpow(double x, int y){double res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1LL, x *= x;} return res;}
int ncr(int n, int k){if (n < k){return 0;} k = min(k, n - k); int ans = 1; rep(i, 1, k + 1){ans *= (n - i + 1), ans /= i;} return ans;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
int gen(int x, int y){return x + (int)rand() % (y - x + 1);}
int uniform_gen(int x, int y){return uniform_int_distribution<int>(x, y)(rng);}
int base_gen(int x, int y){int base = uniform_gen(x, y); return base - !(base & 1);}
int add(){return 0;} int mul(){return 1;}
template <typename T1, typename... T2> int add(T1 x, T2... y){return (x + add(y...) + mod) % mod;}
template <typename T1, typename... T2> int mul(T1 x, T2... y){return (x * mul(y...)) % mod;}
/* --------------------------------------------------------- FAST INPUT/OUTPUT ----------------------------------------------------- */

void IOS(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);
    cout.setf(ios::fixed);
    freopen("error.txt", "w", stderr);
    // #undef endl // remove for interactives
    /*  
        * find_by_order(K): Returns an iterator to the Kth largest element (counting from zero)
        * order_of_key (K): Returns the number of items that are strictly smaller than K
    */
}

/* ------------------------------------------------------- SOLUTION TO THE PROBLEM ------------------------------------------------- */
struct node{
public:
    int sum;
    node op(node x, node y){
        node z; z.sum = x.sum + y.sum;
        return z;
    }
};

class SegmentTree : public node{
private:
    int n;
    vector<node> seg;
    node nll = node({0}); 
public:
    void init(int _n){n = _n, seg.assign(2 * n, nll);}
    void pull(int p){seg[p >> 1] = node().op(seg[p], seg[p ^ 1]);}
    void update(int p, node val){for (seg[p += n - 1] = val; p > 1; p >>= 1) pull(p);}
    node query(int l, int r){
        node ra = nll, rb = nll;
        for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ra = node().op(ra, seg[l++]);
            if (r & 1) rb = node().op(rb, seg[--r]);
        }
        return op(ra, rb);
    }
};

void solve(){
    /* JAI SHREE RAM */
    int n, q;
    cin >> n >> q;
    SegmentTree f;
    f.init(n);
    rep(i, 0, n){
        int x;
        cin >> x;
        f.update(i + 1, node({x}));
    }
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1){
            f.update(x, node({y}));
        }else{
            cout << f.query(x, y).sum << endl;
        }
    }
}  
int32_t main(){
    IOS();
    int ttc = 1;
    // cin >> ttc;
    while (ttc--){
        solve();
    }
    return 0;
}