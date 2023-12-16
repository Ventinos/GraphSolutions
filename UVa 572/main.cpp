#include <iostream>
#include "Graph.hpp"

int main()
{
  std::vector<int> vet;
  int cnt, j, k;
  std::cin >> j; //linhas
  std::cin >> k; //colunas
  while((k!=0)&&(j!=0)){
  Graph* graph = Graph::readGraph(j, k);
  cnt = graph->busca();
    vet.push_back(cnt);
  std::cin >> j;
  std::cin >> k;
  }
  for(auto i : vet)
    std::cout << i << std::endl;
  return 0;
}