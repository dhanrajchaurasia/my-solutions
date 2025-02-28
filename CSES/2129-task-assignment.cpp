#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
#ifdef coderdhanraj
#include "libs/debug.h"
#else
#define debug(...) 
#endif
#define int long long
#define double long double
#define ff first
#define ss second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define FIND(x, y) binary_search(all(x), y)
#define MEM(x, y) memset(x, y, sizeof(x))
#define CNT(x) __builtin_popcountll(x)
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define bck(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define endl '\n' // remove for interactives
using i64 = int64_t; using u64 = uint64_t; using i128 = __int128_t; using u128 = __uint128_t;
using vi = vector<int>; using mii = map<int, int>; using phii = pair<int, int>; using vii = vector<phii>;
/* --------------------------------------------------------- TEMPLATES --------------------------------------------------- */
class custom_hash{public: static u64 splitmix64(u64 x){ x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);}
    size_t operator()(u64 x) const {static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}
    template<typename P, typename Q>
    size_t operator()(const pair<P, Q> &Y) const{static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);}
};
template<typename P, typename Q> istream& operator>>(istream &in, pair<P, Q> &p){return (in >> p.first >> p.second);}
template<typename P, typename Q> ostream& operator<<(ostream &out, const pair<P, Q> &p){return (out << p.first << " " << p.second); }
template<typename T> istream& operator>>(istream &in, vector<T> &a){for(auto &e : a) cin >> e; return in;}
template<typename T> ostream& operator<<(ostream &out, const vector<T> &a){for (auto &e : a) cout << e << " "; return out;}
template<typename T, size_t N> istream& operator>>(istream &in, array<T, N> &a){for(auto &e : a) cin >> e; return in;}
template<typename T, size_t N> ostream& operator<<(ostream &out, array<T, N> &a){for (auto &e : a) cout << e << " "; return out;}
template<typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vec = vector<vector<T>>;
template<typename P, size_t Q> using var = vector<array<P, Q>>;
template<typename P, typename Q> using indexed_map = tree<P, Q, less<P>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename P, typename Q> using gphash = gp_hash_table<P, Q, custom_hash>;
template<typename P, typename Q> using umap = unordered_map<P, Q, custom_hash>;
template<typename P, typename Q> void amax(P &x, Q y){if(x < y) x = y;}
template<typename P, typename Q> void amin(P &x, Q y){if(x > y) x = y;}
template<typename T> void unique(vector<T> &a){sort(all(a)); a.resize(unique(all(a)) - a.begin());}
template<typename T> T ceil(T x, T y){return (x >= 0 ? (x + y - 1) / y : x / y);}
template<typename T> T floor(T x, T y){return x / y - ((x ^ y) < 0 and x % y);}
template<typename T> T gcd(T x, T y){return (x ? gcd(y % x, x) : y);}
template<typename T> T lcm(T x, T y){return x / gcd(x, y) * y;}
template<typename T> T ncr(T n, T k){if (n < k){return 0;} k = min(k, n - k); T ans = 1; rep(i, 1, k + 1){ans *= (n - i + 1), ans /= i;} return ans;}
template<typename P, typename Q> P expo(P x, Q y, u64 m = LLONG_MAX){P res = 1; x = x % m; while (y > 0){if (y & 1) res = (u128)res * x % m; y = y >> 1, x = (u128)x * x % m;} return res;}
template<typename P, typename Q> P bpow(P x, Q y){P res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1, x *= x;} return res;}
template<typename P, typename Q> P inv(P n, Q m){return expo(n, m - 2, m);}
template<typename T> T sqr(T x){return x * x;}
/* --------------------------------------------------------- UNIVERSAL CONSTANTS --------------------------------------------------- */
const double eps = 1e-9;
const int mod = 1e9 + 7;  // 998244353LL; // 10000000069LL; // 3006703054056749LL;
const i64 inf = 1LL << 60;
const double pi = 3.14159265358979323846264338327950;
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};
/* --------------------------------------------------------- USEFUL FUNCTIONS ---------------------------------------------------- */
int testcase;
bool isOverflow(int x, int y){return (x > LLONG_MAX / y or y > LLONG_MAX / x);}
bool ispow2(int x){return (x ? !(x & (x - 1)) : 0);}
bool Case(){return cout << "Case #" << ++testcase << ": ", true;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
i64 rand(i64 x, i64 y){return uniform_int_distribution<i64>(x, y)(rng);}
#define JAI_SHREE_RAAM ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout.precision(20), cout.setf(ios::fixed);
/* ------------------------------------------------------- SOLUTION TO THE PROBLEM ------------------------------------------------- */
template <typename Cost = long, typename CostSum = Cost>
auto fast_dense_hungarian(const vector<vector<Cost>>& cost){
    static constexpr CostSum inf = numeric_limits<CostSum>::max() / 3;
    int V = size(cost);
    vector<int> row_mate(V, -1), col_mate(V, -1);
    vector<CostSum> phi(V, 0);
    auto residual = [&](int r, int c){return cost[r][c] - phi[c];};
    // column reduction, mate columns greedily
    vector<bool> transferrable(V, false);
    for (int col = 0; col < V; col++){
        int row = 0;
        for (int u = 1; u < V; u++) if (cost[row][col] > cost[u][col]) row = u;
        phi[col] = cost[row][col];
        if (row_mate[row] == -1){
            row_mate[row] = col, col_mate[col] = row;
            transferrable[row] = true;
        }else transferrable[row] = false;
    }
    // reduction transfer
    for (int row = 0; row < V; row++){
        if (transferrable[row]){
            int col = row_mate[row], c = -1;
            for (int v = 0; v < V; v++){
                if (v != col and (c == -1 or residual(row, c) > residual(row, v))) c = v;
            }
            phi[col] -= residual(row, c);
        }
    }
    // augmenting row reduction
    for (int it = 0; it < 2; it++){
        for (int row = 0; row < V; row++){
            if (~row_mate[row]) continue;
            auto u1 = residual(row, 0), u2 = inf;
            int c1 = 0;
            for (int c = 0; c < V; c++){
                auto u = residual(row, c);
                if (u < u1 or (u == u1 and ~col_mate[c1])) u2 = u1, u1 = u, c1 = c;
                else if (u < u2) u2 = u;
            }
            if (u1 < u2) phi[c1] -= u2 - u1;
            if (int r1 = col_mate[c1]; ~r1) row_mate[r1] = col_mate[c1] = -1;
            row_mate[row] = c1, col_mate[c1] = row;
        }
    }
    vector<int> cols(V);
    iota(begin(cols), end(cols), 0);
    for (int row = 0; row < V; row++){
        if (~row_mate[row]) continue;
        vector<CostSum> dist(V);
        for (int c = 0; c < V; c++) dist[c] = residual(row, c);
        vector<int> pred(V, row);
        int scanned = 0, labeled = 0, last = 0, col = -1;
        while (true){
            if (scanned == labeled){
                last = scanned;
                auto min = dist[cols[scanned]];
                for (int j = scanned; j < V; j++){
                    int c = cols[j];
                    if (dist[c] <= min){
                        if (dist[c] < min){
                            min = dist[c];
                            labeled = scanned;
                        }
                        swap(cols[j], cols[labeled++]);
                    }
                }
                for (int j = scanned; j < labeled; j++){
                    if (int c = cols[j]; col_mate[c] == -1){
                        col = c;
                        goto done;
                    }
                }
            }
            assert(scanned < labeled);
            int c1 = cols[scanned++];
            int r1 = col_mate[c1];
            for (int j = labeled; j < V; j++){
                int c2 = cols[j];
                auto len = residual(r1, c2) - residual(r1, c1);
                assert(len >= 0);
                if (dist[c2] > dist[c1] + len){
                    dist[c2] = dist[c1] + len;
                    pred[c2] = r1;
                    if (!len){
                        if (col_mate[c2] == -1){
                            col = c2;
                            goto done;
                        }
                        swap(cols[j], cols[labeled++]);
                    }
                }
            }
        }
        done:;
        for (int i = 0; i < last; i++){
            int c = cols[i];
            phi[c] += dist[c] - dist[col];
        }
        int t = col;
        while (~t){
            col = t; int r = pred[col];
            col_mate[col] = r;
            swap(row_mate[r], t);
        }
    }
    CostSum total = 0;
    for (int u = 0; u < V; u++) total += cost[u][row_mate[u]];
    return make_pair(total, move(row_mate));
}
void solve(){
    int n; cin >> n;
    vec<int> cost(n, vi(n)); cin >> cost;
    auto res = fast_dense_hungarian(cost);
    cout << res.ff << endl;
    rep(i, 0, n) cout << i + 1 << ' ' << res.ss[i] + 1 << endl;
}
int32_t main(){
#ifdef coderdhanraj
    auto start = high_resolution_clock::now();
    freopen("error.txt", "w", stderr);
#endif
    JAI_SHREE_RAAM
    int ttc = 1;
    // cin >> ttc;
    while (ttc--) solve();
#ifdef coderdhanraj
    auto time =  duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000;
    cerr << "Time: " << time << " ms!" << endl;
#endif
    return 0;
}