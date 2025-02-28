/* 
----------------------------------------------------------------------------------------------------------------------------
----------------------------- This problem has been solved by coderdhanraj (Dhanraj Chaurasia) -----------------------------
----------------------------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define float long double
#define vi vector<int>
#define vvi vector<vi>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define usi unordered_set<int>
#define msi multiset<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define gi greater<int>
#define gpii greater<pii>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ppb pop_back()
#define lb lower_bound
#define ub upper_bound
#define fr front()
#define bk back()
#define cr clear()
#define emp empty()
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mx(x) *max_element(all(x))
#define mn(x) *min_element(all(x))
#define maxs(x, y) (x < y ? y : x)
#define mins(x, y) (x > y ? y : x)
#define sum(x) accumulate(all(x), 0LL)
#define unique(x) (x).erase(unique(all(x)), (x).end())
#define index(x, y) find(all(x), y) - (x).begin()
#define search(x, y) binary_search(all(x), y)
#define debug(x) cout << #x << " = " << x << endl
#define cins(x) for (auto &i : x) cin >> i
#define cins2(x) for (auto &i : x) cin >> i.ff >> i.ss
#define endl "\n"
#define mod 1000000007
#define mod2 998244353
#define inf (1LL << 60)
#define umap(x) (x).reserve(1 << 10); (x).max_load_factor(0.25)
#define cond(x) cout << &("NO\0YES" [3 * x]) << endl
#define google(x) cout << "Case #" << x << ": "

//	Prerequisite functions : 

//	Calculates gcd of x and y.
int gcd(int x, int y)
{
    return (y == 0) ? x : gcd(y, x % y);
}

//	Check a number is a prime or not.
bool checkPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

//	Calculates x raise to power y.
int power(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1LL;
    }
    return res;
}

//	Calculates nCr.
int Combination(int n, int r)
{
    int res = 1;
    if (r > n - r)
        r = n - r;
    for (int i = 1; i <= r; i++)
    {
        res *= n - r + i;
        res /= i;
    }
    return res;
}

/*
----------------------------------------------------------------------------------------------------------------------------
------------------------------------------------ Solution Starts From Here------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------
*/

void solve()
{
    int n, k;
    cin >> n >> k;
    vpii v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].ff;
        v[i].ss = i + 1;
    }
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        if (v[i].ff > k)
            break;
        for (int j = i + 1; j < n; j++)
        {
            int sums = k - (v[i].ff + v[j].ff);
            if (sums > k)
                break;
            int lo = 0, hi = n - 1;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if (v[mid].ff == sums)
                {
                    if (v[mid].ss == v[i].ss or v[mid].ss == v[j].ss)
                        break;
                    cout << v[i].ss << " " << v[j].ss << " " << v[mid].ss << endl;
                    return;
                }
                else if (v[mid].ff > sums)
                    hi = mid - 1;
                else if (v[mid].ff < sums)
                    lo = mid + 1;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout.setf(ios::fixed);
    
    int ttc = 1;
    while (ttc--)
        solve();
    
    return 0;
}