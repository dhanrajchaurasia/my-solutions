/* 
--------------------------------------------------------------------------------------------------------------------------
------------------------- [This problem has been solved by coderdhanraj (Dhanraj Chaurasia)] ----------------------------
--------------------------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define double long double

#define vi vector<int>
#define vvi vector<vi>
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii>
#define viii vector<tuple<int, int, int>>

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
#define mem0(x) memset(x, 0, sizeof(x))
#define mem1(x) memset(x, -1, sizeof(x))
#define count_1(x) __builtin_popcountll(x)
#define count_0(x) __builtin_ctzll(x)
#define gcd __gcd
#define ceils(x, y) (x + y - 1) / y
#define cins(x) for (auto &i : x) cin >> i
#define endl "\n"

/* ---------------------------- [Universal Constants] ----------------------------- */

const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 2e18;
const int inf2 = (1LL << 60);
const int maxn = 2e5 + 10;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

/* ------------------------------ [Debugging Area] -------------------------------- */

#ifndef coderdhanraj
#define debug(x) cerr << #x <<" :: "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(float t) {cerr << t;}
void google(int t) {cout << "Case #" << t << ": ";}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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

/* ------------------------------ [Modulus Operations] -------------------------------- */

int inverse(int n, int m) {return power(n, m - 2, m);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, inverse(b, m), m));}

/* ------------------------------ [FAST INPUT/OUTPUT] ---------------------------------- */

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

/* ----------------------------- [Solution Of The Problem] ---------------------------- */

void solve()
{
    int a, b;
    cin >> a >> b;
    cout << power(a, b, mod) << endl;
}

int32_t main()
{
    IOS();
    int ttc = 1;
    cin >> ttc;
    while (ttc--)
    {
        auto start_time = chrono::high_resolution_clock::now();
        solve();
        cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms." << endl;
    }

    return 0;
}