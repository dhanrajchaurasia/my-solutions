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
#define make make_pair
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define repp(i, a, b, c) for (int i = a; i < b; i += c)
#define bckk(i, a, b, c) for (int i = a - 1; i >= b; i -= c)
#define rep(i, a, b) repp(i, a, b, 1)
#define bck(i, a, b) bckk(i, a, b, 1)
#define mx(x) *max_element(all(x))
#define mn(x) *min_element(all(x))
#define summ(x) accumulate(all(x), 0LL)
#define mem(x, y) memset(x, y, sizeof(x))
#define count_1(x) __builtin_popcountll(x)
#define lmb(x) __lg(x)
#define rmb(x) (int)log2(x & -x)
#define srt(x) is_sorted(all(x))
#define endl '\n';

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: TEMPLATES ::::::::::::::::::::::::::::::::::::::::::::::::::: */

class custom_hash {
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

// find_by_order(K): Returns an iterator to the Kth largest element (counting from zero)
// order_of_key (K): Returns the number of items that are strictly smaller than K

template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec = vector<vector<T>>;
template <typename T> using uset = unordered_set<T, custom_hash>;
template <typename T1, int T2> using var = vector<array<T1, T2>>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2, custom_hash>;
template <typename T1, typename T2> using hash = gp_hash_table<T1, T2, custom_hash>;
template <typename T1, typename T2> void amax(T1 &x, T2 y) {if(x < y) x = y;}
template <typename T1, typename T2> void amin(T1 &x, T2 y) {if(x > y) x = y;}


// Read 
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1,T2> &p){ return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){
  for(auto &it: v) cin >> it;
  return istream;
}
// Write 
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p){ return (ostream << p.first << " " << p.second); }
template<typename T> //cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c){ for (auto &it: c) cout << it << " "; return ostream;}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: UNIVERSAL CONSTANTS ::::::::::::::::::::::::::::::::::::::::::::::::::: */

const double pi = acos(-1.0);
const double eps = 1e-9;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 2e18;
const int maxn = 2e5 + 10;
const int maxx = 2e6 + 10;
char dir[] = {'D', 'L', 'R', 'U'};
const int dx[] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};

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

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: USEFUL FUNCTIONS :::::::::::::::::::::::::::::::::::::::::::::::::::: */

bool isSquare(int x) {int y = sqrtl(x); return x == y * y;}
bool ispow2(int x) {return (x ? !(x & (x - 1)) : 0);}
int ceils(int x, int y) {return (x >= 0 ? (x + y - 1) / y : x / y);}
int gcd(int x, int y) {return (y ? gcd(y % x, x) : x);}
int lcm(int x, int y) {return x / gcd(x, y) * y;}

int power(int a, int y, int m = inf)
{
    int res = 1;
    a = a % m; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * a) % m;
        y = y >> 1LL;
        a = (a * a) % m;
    }
    return res;
}

bool isPrime(int n) 
{   
    if (n < 2)
        return false;
    if (n <= 3) 
        return true; 
    if (!(n % 2) or !(n % 3)) 
        return false; 
    for (int i = 5; i * i <= n; i += 6) 
        if (!(n % i) or !(n % (i + 2))) 
            return false;
    return true; 
}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MODULUS OPERATIONS :::::::::::::::::::::::::::::::::::::::::::::::::::: */

int mod_inv(int n, int m = mod) {return power(n, m - 2, m);}
int mod_add(int a, int b, int m = mod) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m = mod) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m = mod) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m = mod) {a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m));}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: FAST INPUT/OUTPUT ::::::::::::::::::::::::::::::::::::::::::::::::::::: */

void IOS()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);
    cout.setf(ios::fixed);
    
    #ifndef coderdhanraj
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("Error.txt", "w", stderr);
    #endif
}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::: SOLUTION TO THE PROBLEM ::::::::::::::::::::::::::::::::::::::::::::::::: */
class SegTree
{
    private:
        int n;
        vector<int> segtree, arr;
    public:
        SegTree(vector<int> v)
        {
             this->n = size(v);
             segtree.resize(4 * n + 1);
             arr.resize(n + 1);
             rep(i, 0, n)
                arr[i + 1] = v[i];
             build(1, 1, n);
        }
        void build(int x, int l, int r)
        {
            if (l == r)
            {
                segtree[x] = arr[l];
                return;
            }
            int mid = (l + r) / 2LL;
            build(2 * x, l, mid);
            build(2 * x + 1, mid + 1, r);
            segtree[x] = max(segtree[2 * x], segtree[2 * x + 1]);
        }
        void updateIt(int x, int l, int r, int idx, int delta)
        {
            if (l > idx or r < idx)
                return;
            if (l == r)
            {
                segtree[x] = arr[l];
                return;
            }
            int mid = (l + r) / 2LL;
            updateIt(2 * x, l, mid, idx, delta);
            updateIt(2 * x + 1, mid + 1, r, idx, delta);
            segtree[x] = max(segtree[2 * x], segtree[2 * x + 1]);
        }
        void update(int idx, int delta)
        {
            arr[idx] += delta;
            return updateIt(1, 1, n, idx, delta);
        }
        int maxIs(int x, int l, int r, int L, int R)
        {
            if (L <= l and R >= r)
                return segtree[x];
            if (L > r or R < l)
                return 0;
            int mid = (l + r) / 2LL;
            return max(maxIs(2 * x, l, mid, L, R), maxIs(2 * x + 1, mid + 1, r, L, R));
        }
        int query(int l,int r)
        {
            return maxIs(1, 1, n, l, r);
        }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vi v(n);
    cin >> v;
    SegTree Tree(v);
    rep(i, 0, k)
    {
        int x;
        cin >> x;
        int lo = 1, hi = n;
        int ans = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2LL;
            if (Tree.query(1, mid) >= x)
            {
                hi = mid - 1;
                ans = mid;
            }
            else
                lo = mid + 1;
        }
        if (ans == -1)
        {
            cout << 0 << " ";
            continue;
        }
        cout << ans << " ";
        Tree.update(ans, -x);
    }
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