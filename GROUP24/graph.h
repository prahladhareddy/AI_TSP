class graph{
  public:
  int n;
  bool iseu;
  vector<vector<float>> am;
  vector<pair<float,float>> coord;
  void input();
  void print();
  void print_current();
  void TSPNearestNeighbourHurestic();
  vector<int> curr_tour;
  float cost;
  void simAne();
};