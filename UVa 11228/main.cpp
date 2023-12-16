#include "Graph.hpp"
#include <cmath>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int main() {
  Graph *g, *k;
  std::vector<Graph *> grafos;
  std::vector<Graph *> kruskal;
  std::vector<int> rr;
  // usados para o input:
  int casos, n, r;
  // usados para o output:
  double roads = 0, rails = 0;
  double states = 1;
  std::queue<std::tuple<int, int, int>> saida;

  // captura:
  std::cin >> casos;
  for (int i = 0; i < casos; i++) {
    std::cin >> n;
    std::cin >> r;
    rr.push_back(r);
    g = Graph::readGraph(n);
    grafos.push_back(g);

    // solução:
    k = g->kruskal();
    kruskal.push_back(k);
  }

  // montando a saida:
  int i = 0;
  for (Graph *g : kruskal) {
    std::tuple<double, double, double> tripla;
    for (int j = 0; j < g->arestas.size(); j++) {
      Edges *e = g->arestas[j];
      if (e->peso <= rr[i])
        roads += e->peso;
      else {
        states++;
        rails += e->peso;
      }
    }
    // montando saida:
    tripla = {states, (int)round(roads), (int)round(rails)};
    saida.push(tripla);
    // resetando valores:
    states = 1;
    roads = 0;
    rails = 0;
    i++;
  }

  // printando saida:
  for (int i = 1; !saida.empty(); i++) {
    std::cout << "Case #" << i << ": ";
    std::cout << std::get<0>(saida.front()) << " ";
    std::cout << std::get<1>(saida.front()) << " ";
    std::cout << std::get<2>(saida.front()) << std::endl;
    saida.pop();
  }

  return 0;
}
