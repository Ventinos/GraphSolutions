#include <iostream>
#include "Graph.hpp"

int main() {
  int n, m;
  std::vector<int> vet;
  std::cin >> n;
  for(int i = 0; i < n; i++){
    Graph* g = Graph::readGraph();
    vet.push_back(g->solve());
  }
  std::cin >> m;
  for(auto i : vet)
    std::cout << i <<std::endl;
}