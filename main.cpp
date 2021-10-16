#include <bits/stdc++.h>
using namespace std;
#include "graph.h"


int main(){

  graph g;
  time(&g.start);
  g.input();
  // g.print();
  g.print_current();
  g.TSPNearestNeighbourHurestic();
  // while(1){
    // cout<<"in\n";
    g.simAne();
  // }
  
  
  return 0;

}
