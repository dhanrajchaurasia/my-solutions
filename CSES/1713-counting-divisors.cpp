#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

// BOOST IS THE SECRET OF MY ENERGY!
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

#ifdef coderdhanraj
#include "debug.h"
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
};
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &in, pair<T1, T2> &p){ return (in >> p.first >> p.second);}
template<typename T> // cin >> vector<T>
istream& operator>>(istream &in, vector<T> &v){for(auto &it: v) cin >> it; return in;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &out, const pair<T1, T2> &p){return (out << p.first << " " << p.second); }
template<typename T> //cout << vector<T>
ostream& operator<<(ostream &out, const vector<T> &c){for (auto &it: c) cout << it << " "; return out;}

template <typename T1, typename T2> using gphash = gp_hash_table<T1, T2, custom_hash>;
template <typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define rand rng
int gen(int x, int y){return x + rand() % static_cast<int>(y - x + 1);}
int uniform_gen(int x, int y){return uniform_int_distribution<int>(x, y)(rng);}

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
class Seive{
private: int N;
public: vector<int> spf, phi, mu, pr;
    Seive(int n) : N(n){spf.assign(n, 0), phi.assign(n, 0), mu.assign(n, 1);
        spf[1] = phi[1] = mu[1];
        for (int i = 2; i < N; i++){
            if (!spf[i]) spf[i] = i, phi[i] = i - 1, mu[i] = -mu[i / spf[i]], pr.push_back(i);
            else{
                if (spf[i] == spf[i / spf[i]]) phi[i] = phi[i / spf[i]] * spf[i], mu[i] = 0;
                else phi[i] = phi[i / spf[i]] * (spf[i] - 1), mu[i] = -mu[i / spf[i]];
            }
            for (int j = 0; j < size(pr) and pr[j] <= spf[i] and pr[j] < (N + i - 1) / i; j++) spf[i * pr[j]] = pr[j];
        }
    }
    bool isPrime(int x) {assert(x >= 0 and x < N); return spf[x] == x;}
    vector<int> divisors(int x){
        assert(x >= 0 and x < N);
        vector<int> ans(1, 1);
        while(x > 1){
            int p = spf[x], c = 0;
            while(spf[x] == spf[p]) x /= p, ++c;
            c *= size(ans);
            for (int i = 0; i < c; i++) ans.push_back(ans[i] * p);
        }
        return ans;
    }
    vector<pair<int, int>> primeFactors(int x){
        assert(x >= 0 and x < N);
        vector<pair<int, int>> ans;
        while (x > 1){
            int p = spf[x], c = 0;
            while (spf[x] == spf[p]) x /= p, ++c;
            ans.push_back({p, c});
        }
        return ans;
    }
};
const int SZ = 1e6 + 1;
Seive ps(SZ);

void solve(){
    /* JAI SHREE RAM */
    int n;
    cin >> n;
    cout << size(ps.divisors(n)) << endl;    
}  

int32_t main(){
    IOS();
#ifdef coderdhanraj
    auto start = high_resolution_clock::now();
    freopen("error.txt", "w", stderr);
#endif
    int ttc = 1; 
    cin >> ttc;
    while (ttc--) solve();
#ifdef coderdhanraj
    auto time =  duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000;
    cerr << "Time: " << time << " ms!" << endl;
#endif
    return 0;
}