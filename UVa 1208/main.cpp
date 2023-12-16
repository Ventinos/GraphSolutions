#include <iostream>
#include "Graph.hpp"


int main() {
  int n,m,cnt=0;
  std::vector<Graph*> vet;
  std::cin >> n;
  for(int i = 0; i < n; i++){
    std::cin >> m;
    Graph* g = Graph::readGraph(m);
    g->print();
    Graph* g2 = g->solve();
    vet.push_back(g2);
  }
  for(auto i : vet){
    cnt++;
    std::cout << "Case " << cnt << ":" <<std::endl;
    i->printResul();
  }
}