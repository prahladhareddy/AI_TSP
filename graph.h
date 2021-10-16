class graph{
  public:
  int n;
  bool iseu;
  vector<vector<double>> am;
  vector<pair<double,double>> coord;
  void input();
  void print();
  void print_current();
  void TSPNearestNeighbourHurestic();
  vector<int> curr_tour;
  double cost;
  void simAne();
  time_t start,end;
};