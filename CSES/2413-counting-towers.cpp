#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define double long double
     
#define vi vector<int>
#define vvi vector<vi>
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
#define cins(x) for (auto &i : x) cin >> i
#define ceils(x, y) (x + y - 1) / y
#define pow2(x) (1LL << x)
#define endl "\n"
#define gcd __gcd
#define srt is_sorted
#define nxtpm next_permutation
#define prvpm prev_permutation

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: TEMPLATES ::::::::::::::::::::::::::::::::::::::::::::::::::: */

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec = vector<vector<T>>;
template <typename T> using uset = unordered_set<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;

// find_by_order(K): Returns an iterator to the Kth largest element (counting from zero)
// order_of_key (K): Returns the number of items that are strictly smaller than K

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: UNIVERSAL CONSTANTS ::::::::::::::::::::::::::::::::::::::::::::::::::: */

const double pi = acos(-1.0);
const double eps = 1e-9;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 2e18;
const int inf2 = (1LL << 60);
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

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MODULUS OPERATIONS :::::::::::::::::::::::::::::::::::::::::::::::::::: */

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

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::: MOIVATION-TRICKS-TIPS ::::::::::::::::::::::::::::::::::::::::::::::::: 

    1) RATING IS F*CK, YOU ARE HERE JUST FOR FUN!, RATING MAY DECREASES BUT NOT EXPERIENCE.
    2) NEVER SUBMIT A DUMB CODE! YOU DO EVERYTIME REMIND IT!
    3) FIND ALL POSSIBLES (SEE EDGE CASES)
    4) IF YOU'R AT A QUE FOR MORE THAN 20 MIN AND GETTING NOTHING THEN GO FOR NEXT QUE!
    DON'T SEE YOUR FRIENDS HAVE DONE BUT YOU'RE STILL NOT GETTING, JUST LEAVE IT!
    5) MAX-MIN SHOWS YOU TO GO FOR EITHER DP OR BINARY SEARCH
    6) FOR INTERACTIVE PROBLEMS REMOVE CIN.PTR ALWAYS
    7) IF CONSTRAINS ARE LOW (EXCEPT PROBLEM A) GO FOR BRUTE FORCE, DP, BINARY SEARCH ALWAYS
    8) FOR BINARY SEARCH, ALWAYS SEE TWICE THE SEARCH SPACE BEFORE MAKING SUBMISSION
    9) DON'T IMPLEMENT TOO MUCH FOR PROBLEM A AND B (THEY MIGHT HAVE EASY SOLUTION)

*/

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::: SOLUTION TO THE PROBLEM ::::::::::::::::::::::::::::::::::::::::::::::::: */
int dp[maxx][2];

void pre()
{
    dp[1][0] = dp[1][1] = 1;
    rep(i, 2, maxx)
    {
        dp[i][0] = mod_add(dp[i][0], 2 * dp[i - 1][0], mod);
        dp[i][0] = mod_add(dp[i][0], dp[i - 1][1], mod);
        dp[i][1] = mod_add(dp[i][1], 4 * dp[i - 1][1], mod);
        dp[i][1] = mod_add(dp[i][1], dp[i - 1][0], mod);
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << mod_add(dp[n][0], dp[n][1], mod) << endl;
}  

int32_t main()
{
    pre();
    IOS();
    int ttc = 1;
    cin >> ttc;
    while (ttc--)
        solve();
    return 0;
}