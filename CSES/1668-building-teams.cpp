 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
#define int long long int
#define double long double
     
#define vi vector<int>
#define vvi vector<vi>
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii>
#define max_heap priority_queue<int>
#define min_heap priority_queue<int, vi, greater<int>>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ff first
#define ss second
#define pb push_back
#define ppb pop_back()
#define lb lower_bound
#define ub upper_bound
#define fr front()
#define bk back()
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define bck(i, a, b) for (int i = a - 1; i >= b; i--)
#define mx(x) *max_element(all(x))
#define mn(x) *min_element(all(x))
#define sumof(x) accumulate(all(x), 0LL)
#define IndexOf(x, y) (x).order_of_key(y)
#define ValAt(x, y) *(x).find_by_order(y)
#define mem0(x) memset(x, 0, sizeof(x))
#define mem1(x) memset(x, -1, sizeof(x))
#define count_1(x) __builtin_popcountll(x)
#define count_0(x) __builtin_ctzll(x)
#define gcd __gcd
#define ceils(x, y) (x + y - 1) / y
#define cins(x) for (auto &i : x) cin >> i
#define endl "\n"

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: Universal Constants ::::::::::::::::::::::::::::::::::::::::::::::::::: */

const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 2e18;
const int inf2 = (1LL << 60);
const int maxn = 2e5 + 10;
const int dir_X[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dir_Y[] = {0, 1, 0, -1, -1, 1, -1, 1};

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: Debugging Area :::::::::::::::::::::::::::::::::::::::::::::::::::::: */

void google(int t){cout << "Case: #" << t;}
void __print(int x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.ff); cerr << ','; __print(x.ss); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef coderdhanraj
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int power(int a, int y, int m)
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
 
void printBin(int n)
{
    bck(i, 64, 0)
        cout << (n & (1LL << i) ? 1 : 0);
    cout << endl;
}

bool prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: Modulus Operations :::::::::::::::::::::::::::::::::::::::::::::::::::: */

int inverse(int n, int m) {return power(n, m - 2, m);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, inverse(b, m), m));}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: FAST INPUT/OUTPUT ::::::::::::::::::::::::::::::::::::::::::::::::::::: */

void IOS()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);
    cout.setf(ios::fixed);
    
    #ifndef coderdhanraj
    freopen("Error.txt", "w", stderr);
    #endif
}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::: SOLUTION TO THE PROBLEM ::::::::::::::::::::::::::::::::::::::::::::::::: */

bool possible = true;

vi adj[maxn];
int pupil[maxn];
bool vis[maxn];

void dfs(int src)
{
    vis[src] = true;
    for (auto &node : adj[src])
    {
        if (!vis[node])
        {
            pupil[node] = (pupil[src] == 1 ? 2 : 1);
            dfs(node);
        }
        else if (pupil[node] == pupil[src])
        {
            possible = false;
            return;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    rep(i, 1, n + 1)
    {
        if (!vis[i])
        {
            pupil[i] = 1;
            dfs(i);
            if (!possible)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    rep(i, 1, n + 1)
        cout << pupil[i] << ' ';
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