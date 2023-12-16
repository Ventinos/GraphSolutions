#include "Graph.hpp"
#include "Sort.hpp"
#include <iostream>
#include <stack>
int main() {
  // guarda todas as pontes encontradas no DFS esquisito
  std::vector<std::pair<int, int>> pontes;
  // guarda todos os conjuntosde pontes
  std::vector<std::vector<std::pair<int, int>>> respostas;
  int n, m, k = 0, dfs_numbercounter = -1, dfsRoot = 0, rootChildren = 0;

  std::vector<int> dfs_num, dfs_low, dfs_parent, articulacao;

  std::cin >> n;
  std::cin >> m;
  while (n != 0 || m != 0) {
    std::cout << n << m << "\n";
    //realiza leitura do grafo
    Graph *g = Graph::readGraph(n, m);

    //prepara o grafo para o dfs
    for (int i = 0; i < n; i++) {
      dfs_num.push_back(-1);
      dfs_low.push_back(0);
      dfs_parent.push_back(-1);
      articulacao.push_back(0);
    }
    //realiza o dfs e armazena as pontes
    for (int u = 0; u < n; u++) {
      if (dfs_num.at(u) == -1) {
        dfsRoot = u;
        rootChildren = 0;
        g->dfsBridges(u, &dfs_numbercounter, dfs_num, dfs_low, dfs_parent,
                      articulacao, &dfsRoot, &rootChildren, &pontes);
        articulacao.at(u) = (rootChildren > 1);
      }
    }
    //ordena a lista de pontes e armazena em um vetor de lista de pontes
    Sort::quicksort(pontes, 0, pontes.size() - 1);
    respostas.push_back(pontes);

    //limpa os vetores para a leitura do próximo grafo
    pontes.clear();
    dfs_num.clear();
    dfs_low.clear();
    dfs_parent.clear();
    articulacao.clear();

    std::cin >> n;
    std::cin >> m;
  }

  //printa todos os dados do vetor de listas de pontes
  for (int i = 0; i < respostas.size(); i++) {
    std::cout << "\n" << respostas[i].size() << " ";
    for (int j = 0; j < respostas[i].size(); j++) {
      std::cout << respostas[i][j].first << " " << respostas[i][j].second
                << " ";
    }
  }

  return 0;
}

