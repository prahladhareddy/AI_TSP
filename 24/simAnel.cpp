#include <bits/stdc++.h>
using namespace std;
#include "graph.h"

void graph::simAne(){
    vector<int> v = curr_tour;
    double cc = cost;
    long long  count = 0;
    int a = 9, b = 9;
    double T = pow(10,a);
    double mult = 1 - pow(10,(-1)*b);
   // cout<<mult<<"\n";
    time(&end);
    double st = double(end-start);
    double tim = 300 - st;
    
    double least = (tim-1)/pow(10,a+b);
    //cout<<"least ="<<least<<"\n";
    while(1){
        double init = 0;
        // double T = 300 - double(end - start);
        int p1 = rand()%n;
        int p2 = rand()%n;
        while(p1 == p2){
            p2 = rand()%n;
        }
        double diff = 0;
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
            init = am[v11][v1] + am[v1][v12] + am[v21][v2] + am[v2][v22];
            diff += init;
            diff -= am[v11][v2] + am[v2][v12] + am[v21][v1] + am[v1][v22];
        } else if(p2-p1 == 1){
            int v1 = v[p1];
            int v2 = v[p2];
            int v0 = v[(p1+n-1)%n];
            int v3 = v[(p2+1)%n];
            init = am[v0][v1] + am[v1][v2] + am[v2][v3];;
            diff += init;
            diff -= am[v0][v2] + am[v2][v1] + am[v1][v3];
        } else if(p2-p1 == n-1){
            int t = p1;
            p1 = p2;
            p2 = t;
            int v1 = v[p1];
            int v2 = v[p2];
            int v0 = v[(p1+n-1)%n];
            int v3 = v[(p2+1)%n];
            init = am[v0][v1] + am[v1][v2] + am[v2][v3];
            diff += init;
            diff -= am[v0][v2] + am[v2][v1] + am[v1][v3];
        }
        if(diff > 0){
            // cout<<cc<<" "<<diff<<" "<<cost<<"\n";
            // cout<<(cc-diff)<<" "<<cost<<'\n';
            // cout.flush();
            if( (cc-diff) < cost){
                double t=v[p1];
                v[p1] = v[p2];
                v[p2] = t;
                cc = cc - diff;
                curr_tour = v;
                cost=cc;
                print_current();
                continue;
            }
        }


        double prob = 0;

        if(T<=0.0000001){
            // cout<<"YESSSSSSS\n";
            // cout<<T;
            break;
            prob = double(1.0/n);
        } else {
            if (init == 0){
                init = 1;
            }
            double x = (diff)/(init*T);
            if(x>=32){
                prob = 1;
            } else if(x <= -32){
                prob = 0;
            } else {
                double po = pow(2,(-1)*x);
                prob = 1.0/(1+po);
            }
        }

        double prob2 = (double) rand()/RAND_MAX;

        if(prob2<prob){
            double t=v[p1];
            v[p1] = v[p2];
            v[p2] = t;
            cc = cc - diff;
        }

        // time(&end);
        // tim = double(end-start) -st;
        // cout<<"ratio= "<<(tim/least)<<" T= "<<T<<"\n";
        // while(count<tim/least){
        //     T*=mult;
        //     count++;
        // }
        
        T*=mult;
    
    }
    
}