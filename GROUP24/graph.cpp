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
      float a,b;
      cin>>a>>b;
      coord.push_back(pair<float,float>(a,b));
    }
    for(int i=0;i<n;i++){
      vector<float> v;
      for(int j=0;j<n;j++){
        float d;
        cin>>d;
        v.push_back(d);
      }
      am.push_back(v);
    }

    curr_tour = vector<int>(n,0);
    cost = 0;
    for(int i=0;i<n;i++){
      curr_tour[i]=i;
      if(i!=0){
        cost+=am[i-1][i];
      } else {
        cost+=am[n-1][0];
      }
    }

  }

  void graph::print(){
      cout<<"....OK....\n";
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
    for(int i=0;i<n;i++){
      cout<<curr_tour[i]<<" ";
    }
    // cout<<cost;
    // cout<<"\n";
  }