#include <bits/stdc++.h>
using namespace std;
#include "graph.h"
void graph::TSPNearestNeighbourHurestic(){
    vector<int> ans(n,0);
    vector<int> vis(n,0);
    float tot_cost = 0;
    int s = 0;
    vis[s] = 1;
    for(int i=1;i<n;i++){
        float min = FLT_MAX;
        int s2 = 0;
        for(int j=0;j<n;j++){
            if(vis[j] != 1 && j !=s){
                if(am[s][j] < min){
                    s2 = j;
                    min = am[s][j];
                }
            }
        }
        tot_cost+=am[s][s2];
        ans[i]=s2;
        vis[s2] =1;
        s = s2;
    }
    tot_cost+=am[s][0];
    if(cost>tot_cost){
        cost = tot_cost;
        curr_tour = ans; 
        print_current();
    }
}