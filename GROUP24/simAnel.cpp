#include <bits/stdc++.h>
using namespace std;
#include "graph.h"

void graph::simAne(){
    vector<int> v = curr_tour;
    float cc = cost;
    while(1){
        for(int i=0;i<INT_MAX;i++){
            int p1 = rand()%n;
            int p2 = rand()%n;
            while(p1 == p2){
                p2 = rand()%n;
            }
            float diff = 0;
            if(p1>p2){
                int t = p1;
                p1 = p2;
                p2 = t;
            }
            if(p2-p1 != 1 && p2-p1 != n-1){
                int v1 = v[p1];
                int v2 = v[p2];
                int v11 = v[(p1+n-1)%n];
                int v12 = v[(p1+1)%n];
                int v21 = v[(p2+n-1)%n];
                int v22 = v[(p2+1)%n];
                diff += am[v11][v1] + am[v1][v12] + am[v21][v2] + am[v2][v22];
                diff -= am[v11][v2] + am[v2][v12] + am[v21][v1] + am[v1][v22];
            } else if(p2-p1 == 1){
                int v1 = v[p1];
                int v2 = v[p2];
                int v0 = v[(p1+n-1)%n];
                int v3 = v[(p2+1)%n];
                diff += am[v0][v1] + am[v1][v2] + am[v2][v3];
                diff -= am[v0][v2] + am[v2][v1] + am[v1][v3];
            } else if(p2-p1 == n-1){
                int t = p1;
                p1 = p2;
                p2 = t;
                int v1 = v[p1];
                int v2 = v[p2];
                int v0 = v[(p1+n-1)%n];
                int v3 = v[(p2+1)%n];
                diff += am[v0][v1] + am[v1][v2] + am[v2][v3];
                diff -= am[v0][v2] + am[v2][v1] + am[v1][v3];
            }
            if(diff > 0){
                if(cc-diff < cost){
                    curr_tour = v;
                    float t = curr_tour[p1];
                    curr_tour[p1] = curr_tour[p2];
                    curr_tour[p2] = t;
                    cost = cc - diff;
                    print_current();
                }
            }
            float prob = 1.0/(1+pow(2,-((diff*1.0)/(INT_MAX-i))));
            float prob2 = (float) rand()/RAND_MAX;
            if(prob2<prob){
                float t=v[p1];
                v[p1] = v[p2];
                v[p2] = t;
                cc = cc - diff;
            }
        }
        // break;
    }
    
}