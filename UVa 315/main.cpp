#include "Graph.hpp"
#include <iostream>

int main() {
  int n;
  std::string input;
  std::vector<int> cnt;;
  std::cin >> n;
  while(n!=0){
  std::getline(std::cin, input);
  Graph *g = Graph::readGraph(n);
  n = g->contaCritico();
  cnt.push_back(n);
  std::cin >> n;
  }
  for(auto i : cnt)
    std::cout << i << std::endl;
  return 0;
}