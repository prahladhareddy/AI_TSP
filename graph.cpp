#include <bits/stdc++.h>
using namespace std;
#include "graph.h"

void graph::input(){

    string s;
    cin>>s;
    if(s=="euclidean"){
      iseu = true;
    } else {
      iseu = false;
      cin>>s;
    }

    cin>>n;
    for(int i=0;i<n;i++){
      double a,b;
      cin>>a>>b;
      coord.push_back(pair<double,double>(a,b));
    }

    for(int i=0;i<n;i++){
      vector<double> v;
      for(int j=0;j<n;j++){
        double d;
        cin>>d;
        v.push_back(d);
      }
      am.push_back(v);
    }

    curr_tour = vector<int>(n,0);
    cost = am[n-1][0];
    for(int i=0;i<n;i++){
      curr_tour[i]=i;
      if(i!=0){
        cost+=am[i-1][i];
      }
    }

  }

  void graph::print(){
      cout<<" printing graph \n";
      for(int i=0;i<n;i++){
          cout<<coord[i].first<<" "<<coord[i].second<<"\n";
      }
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              cout<<am[i][j]<<" ";
          }
          cout<<"\n";
      }
  }

  void graph::print_current(){
    // for(int i=0;i<n;i++){
    //   cout<<curr_tour[i]<<" ";
    // }

    cout<<"approx cost = " << cost;
    double atc_cost = am[curr_tour[n-1]][curr_tour[0]];
    for(int i=1;i<n;i++){
      atc_cost += am[curr_tour[i-1]][curr_tour[i]];
    }
    cout<<" atchual_cost = " << atc_cost;

    cout.flush();
    cout<<"\n";
  }

  void graph::run(){
    if(n<10000){
      TSPNearestNeighbourHurestic();
    }
    simAne();
  }