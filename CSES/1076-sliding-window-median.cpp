#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define double long double
     
#define vi vector<int>
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii>

#define ff first
#define ss second
#define pf push_front
#define pb push_back
#define ppf pop_front()
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
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define bck(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define mem(x, y) memset(x, y, sizeof(x))
#define CNT(x) __builtin_popcountll(x)
#define MSB(x) __lg(x)
#define LSB(x) (int)log2((x) & -(x))
#define srt(x) is_sorted(all(x))
#define endl '\n'
#define rtn exit(0)

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: TEMPLATES ::::::::::::::::::::::::::::::::::::::::::::::::::: */

class custom_hash 
{
    public:
    static uint64_t splitmix64(uint64_t x) 
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const 
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &in, pair<T1, T2> &p){ return (in >> p.first >> p.second);}
template<typename T> // cin >> vector<T>
istream& operator>>(istream &in, vector<T> &v){for(auto &it: v) cin >> it; return in;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &out, const pair<T1, T2> &p){return (out << p.first << " " << p.second); }
template<typename T> //cout << vector<T>
ostream& operator<<(ostream &out, const vector<T> &c){for (auto &it: c) cout << it << " "; return out;}

template<class T1, class T2 = vector<T1>, class T3 = less<T1>> 
ostream& operator<<(ostream& out, priority_queue<T1, T2, T3> const& pq){
    static priority_queue<T1, T2, T3> a = pq;
    out << "{"; string sep;
    while(!a.empty()){out << sep << a.top(); sep = ", "; a.pop();}
    return (out << "}");
}
template<class T> 
ostream& operator<<(ostream& out, queue<T> const& q){
    static queue<T> a = q;
    out << "{"; string sep;
    while(!a.empty()){out << sep << a.front(); sep = ", "; a.pop();}
    return (out << "}");
}
template<class T> 
ostream& operator<<(ostream& out, stack<T> const& s){
    static stack<T> a = s;
    out << "{"; string sep;
    while(!a.empty()){out << sep << a.top(); sep = ", "; a.pop();}
    return (out << "}");
}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec = vector<vector<T>>;
template <typename T1, int T2> using var = vector<array<T1, T2>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2, custom_hash>;
template <typename T1, typename T2> using gphash = gp_hash_table<T1, T2, custom_hash>;
template <typename T1, typename T2> void amax(T1 &x, T2 y) {if(x < y) x = y;}
template <typename T1, typename T2> void amin(T1 &x, T2 y) {if(x > y) x = y;}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: DEBUGGING AREA :::::::::::::::::::::::::::::::::::::::::::::::::::::: */

void __print(int x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void _print() {cerr << "]\n";}

template <typename T1, typename T2> void __print(const pair<T1, T2> &x) {cerr << '{'; __print(x.ff); cerr << ','; __print(x.ss); cerr << '}';}
template <typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
template <typename T1, typename... T2> void _print(T1 t, T2... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef coderdhanraj
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: UNIVERSAL CONSTANTS ::::::::::::::::::::::::::::::::::::::::::::::::::: */

const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 2e18;
const int INF = 9e18;
const int maxn = 2e5 + 10;
const int maxx = 2e6 + 10;
const int mod = 1e9 + 7;
const int mod2 = 998244353LL;
const string dir[8] = {"D", "L", "R", "U", "DL", "DR", "UL", "UR"};
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: USEFUL FUNCTIONS :::::::::::::::::::::::::::::::::::::::::::::::::::: */
int testcase;
int iseq(double x, double y) {return abs(x - y) < eps;}
bool isSquare(int x) {int y = sqrtl(x); return x == y * y;}
bool ispow2(int x) {return (x ? !(x & (x - 1)) : 0);}
int ceill(int x, int y) {return (x >= 0 ? (x + y - 1) / y : x / y);}
int gcd(int x, int y) {return (x ? gcd(y % x, x) : y);}
int lcm(int x, int y) {return x / gcd(x, y) * y;}
void google() {cout << "Case #" << ++testcase << ": ";}
int expo(int x, int y, int m = INF) {int res = 1; x = x % m; while (y > 0){if (y & 1) res = (res * x) % m; y = y >> 1LL, x = (x * x) % m;} return res;}
int gen(int x, int y) {srand(time(0)); return x + rand() % (y - x + 1);}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MODULUS OPERATIONS :::::::::::::::::::::::::::::::::::::::::::::::::::: */

int mod_inv(int n, int m) {return expo(n, m - 2, m);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m));}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: FAST INPUT/OUTPUT ::::::::::::::::::::::::::::::::::::::::::::::::::::: */

void IOS()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);
    cout.setf(ios::fixed);
    // #undef endl // uncomment for interactives
    // #undef int // uncomment for MLEs or TLEs
    // find_by_order(K): Returns an iterator to the Kth largest element (counting from zero)
    // order_of_key (K): Returns the number of items that are strictly smaller than K
}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::: SOLUTION TO THE PROBLEM ::::::::::::::::::::::::::::::::::::::::::::::::: */

int median(ordered_mset<pii> &s){
    return s.find_by_order((size(s) - 1) / 2)->ff;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vi v(n);
    cin >> v;
    ordered_mset<pii> s;
    rep(i, 0, k)
        s.in({v[i], i});
    cout << median(s) << " ";
    rep(i, k, n)
    {
        s.erase(s.lb({v[i - k], i - k - 1}));
        s.in({v[i], i});
        cout << median(s) << " ";
    }
    cout << endl;
}  

int32_t main()
{
    IOS();
    int ttc = 1;
    // cin >> ttc;
    while (ttc--)
        solve();
    return 0;
}