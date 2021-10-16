#include <bits/stdc++.h>
using namespace std;
#include "graph.h"


int main(){

  graph g;
  g.input();
  // g.print();
  g.print_current();
  g.TSPNearestNeighbourHurestic();
  g.simAne();
  return 0;

}
