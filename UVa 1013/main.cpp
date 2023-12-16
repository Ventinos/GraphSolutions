#include "Graph.hpp"
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  Graph *g, *k;
  std::vector<Graph *> grafos;
  std::vector<Graph *> kruskal;
  // usados para o input:
  int n;
  // usados para o output:

  std::queue<double> saida;
  double resultado;

  // captura:

  std::cin >> n;
  while (n != 0) {
    resultado = 0;
    g = Graph::readGraph(n);
    grafos.push_back(g);
    // solução:
    k = g->kruskal(&resultado);
    kruskal.push_back(k);
    saida.push(resultado);
    std::cin >> n;
  }

  // montando a saida:

  // printando saida:
  for (int i = 1; !saida.empty(); i++) {
    std::cout << "Island Group: " << i << " Average: ";
    printf("%0.2lf\n", saida.front());
    saida.pop();
  }

  return 0;
}
