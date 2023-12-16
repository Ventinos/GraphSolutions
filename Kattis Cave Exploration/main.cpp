#include "Graph.hpp"
#include <iostream>
#include <stack>
/*Input:
9 10
0 1
0 2
1 3
2 3
2 8
3 4
4 5
4 6
5 7
6 7

*/
// saida esperada: 4
int main() {
  std::vector<std::pair<int, int>>
      pontes; // guarda todas as pontes encontradas no DFS esquisito
  int n = 0, u = 0, dfs_numbercounter = -1, dfsRoot = 0, rootChildren = 0,
      accumulator = 0, result;
  std::vector<int> dfs_num, dfs_low, dfs_parent;
  Graph *g = Graph::readGraph();
  n = g->getSize();

  for (int i = 0; i < n; i++) {
    dfs_num.push_back(-1);
    dfs_low.push_back(0);
    dfs_parent.push_back(-1);
  }

  for (int u = 0; u < n; u++) {
    if (dfs_num.at(u) == -1) {
      dfsRoot = u;
      rootChildren = 0;
      g->dfsBridges(u, &dfs_numbercounter, dfs_num, dfs_low, dfs_parent,
                    &dfsRoot, &rootChildren, &pontes);
    }
  }

  g->print();
  
  result = g->dfs(0, pontes);

  std::cout << result << std::endl;
  return 0;
}