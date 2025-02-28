#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
// #include<bits/stdc++.h>
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cassert>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <bitset>
#include <chrono>
#include <random>
#include <fstream>
#include <iterator>
#include <complex>
 
#define ll  long long
#define INF 1e18
#define MOD 1000000007
#define nline "\n" 
// #define fr(i,a,b) for(ll i=a;i<(b);++i)
// #define rep(i,a,b) for(ll i i=a;i<=b;++i)
// #define per(i,a,b) for(ll i i=a;i>=b;i--)
using namespace std;
// #define int long long
  
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
 const int MAX_N=1e6;
 const int LOG=20;//CAN CHANGE ACCORDING TO THE CONSTRAINTS
 ll spt[MAX_N][LOG];//sparse table
 int bin_log[MAX_N];
 
 
 
 void solve(){
  //TAKE INPUT
  int n,q;cin>>n>>q; 
  ll v[n];
  for(int i=0;i<n;++i){cin>>v[i]; spt[i][0]=v[i];}
 
   bin_log[1]=0;
   for(int i=2;i<=n;++i){
    bin_log[i]=bin_log[i/2]+1; 
   } 
  //PRE-COMPUTING O(N*log(N)) 
   for(int i=1;i<LOG;++i){
      for(int j=0;j+(1<<i)-1<n;++j){
        spt[j][i]=min(spt[j][i-1],spt[j+(1<<(i-1))][i-1]);
      }
   }
 
 
  for(int i = 0; i < q; i++) {
     int l,r; cin>>l>>r; 
    //  l--;r--;
     int len=r-l+1;
     int qlimit=bin_log[len];
    //  debug(len,qlimit); 
     cout<<min(spt[l - 1][qlimit],spt[r-(1<<qlimit)][qlimit])<<nline; 
   }
 
 }
 
 
 
int32_t main(){
    std::ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);
  int t=1 ;
  // cin>>t;
 cout<<fixed<<setprecision(6);
 while(t--)
   solve();   
 
}