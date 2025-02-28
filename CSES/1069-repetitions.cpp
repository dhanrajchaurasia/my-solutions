/* 
--------------------------------------------------------------------------------------------------------------------------
------------------------- This problem has been solved by coderdhanraj (Dhanraj Chaurasia) -------------------------------
--------------------------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define float long double
#define vi vector<int>
#define vvi vector<vi>
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii>
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
#define rep(i, a, b, c) for (int i = a; i < b; i += c)
#define bck(i, a, b, c) for (int i = a - 1; i >= b; i -= c)
#define mx(x) *max_element(all(x))
#define mn(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define ceils(x, y) x / y + (x % y != 0)
#define cins(x) for (auto &i : x) cin >> i
#define natural(x, y) iota(all(x), y * (1LL))
#define cond(x) cout << &("NO\0YES" [3 * x]) << endl
#define google(x) cout << "Case #" << x << ": "
#define ends(x) " \n"[x]
#define endl ends(1)
#define mod (int)(1e9 + 7)
#define mod2 998244353
#define pi acos(-1)
#define eps 1e-6
#define inf (int)1e18
#define inf2 (1LL << 60)
const int maxn = 2e5 + 10;

#ifndef coderdhanraj
#define debug(x) cerr << #x <<" :: "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(float t) {cerr << t;}

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

void IOS()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout.setf(ios::fixed);
    
    #ifndef coderdhanraj
    freopen("Error.txt", "w", stderr);
    #endif
}

int power(int x, int y, int Mod)
{
    int res = 1;
    x = x % Mod; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % Mod;
        y = y >> 1LL;
        x = (x * x) % Mod;
    }
    return res;
}

/*
--------------------------------------------------------------------------------------------------------------------------
------------------------------------------------- Solution Starts From Here ----------------------------------------------
--------------------------------------------------------------------------------------------------------------------------
*/ 

void solve()
{
    string s;
    cin >> s;
    int ans = 1, count = 1, n = size(s);
    rep(i, 0, n - 1, 1)
    {
        if (s[i] == s[i + 1])
            count++;
        else
            count = 1;
        ans = max(ans, count);
    }
    cout << ans << endl;
}

int32_t main()
{
    IOS();
    int ttc = 1;
    // cin >> ttc;
    while (ttc--)
    {
        auto start_time = chrono::high_resolution_clock::now();
        solve();
        cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << " ms." << endl;
    }

    return 0;
}