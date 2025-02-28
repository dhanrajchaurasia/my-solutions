#include <bits/stdc++.h>
using namespace std;

const int mod=998244353;
int k;

pair<int,int> solve(int mask,vector<pair<int,int>>&dp,vector<int>&people)
{
    int n=people.size();
    if(mask==(1<<n)-1)
        return {1,0};
    
    auto &val=dp[mask];
    if(val.first!=-1)
        return val;
    
    val={1e9,1e9};

    for(int i=0;i<n;i++)
    {
        if( (mask&(1<<i)) == 0 )
        {
            auto bestPossibleVal=solve(mask+(1<<i),dp,people);
            if( bestPossibleVal.second + people[i] <= k)
                bestPossibleVal.second+=people[i];
            else
            {
                bestPossibleVal.second=std::min(bestPossibleVal.second,people[i]);
                bestPossibleVal.first++;
            };

            if(val.first > bestPossibleVal.first)
                val=bestPossibleVal;
            else if(val.first==bestPossibleVal.first)
                val.second=std::min(val.second,bestPossibleVal.second);
        }
    }

    return val;
}

int main(){
    
    int n;
    cin >> n;

    cin >> k;

    vector<int> people(n);
    for(int i=0;i<n;i++)
        cin >> people[i];
    
    vector< pair<int,int> > bitmask((1<<n),{-1,-1});

    auto result=solve(0,bitmask,people);
    cout << result.first << endl;
}

//tree
//nodes with different colour
//add an edge between nodes of distance 2

//    1 c1
//   / \
//  2 c1  3 c1
// /     \
//4 c1      5 c1

// 4={4}
// 2={2,24}
//now while merging we

//if I have the count of nodes connected to me and valid then using that can we work
//at 4=> 1
// at 5-> 1
//at 2->2
//at 3->2
//ok so let us consider a dp
// = nodes not connected to the LCA

//bottom up
//so suppose we hve 2 different parts then how to merge those
//same colour first
//


//  14   23 15 
//  1,2,3,4,5,  12 ,13, 14, 15, 124, 135, 45 
