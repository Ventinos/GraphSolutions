#include "Graph.hpp"
#include "Sort.hpp"
#include <iostream>
#include <queue>
/*
Input:
8 4
0 4
1 2
2 3
2 4
3 5
3 6
3 7
6 7
-1 -1
0 0

Output:
2 3
3 3
4 2
0 1
*/

int main() {
  int n = 0, m = 0;
  std::queue<std::vector<std::pair<int,int>>> queue;
  std::vector<std::pair<int,int>> components;
  std::queue<int> queuem;
  while(true){
      //Leitura do nº de vertices e quantidade de candidatos para destruição
    std::cin >> n;
    std::cin >> m;
    if(n == 0 || m == 0) break;
    Graph *g = Graph::readGraph(n,m);
    // preenchendo os vetores com seus valores iniciais:
    for (int i = 0; i < n; i++) {
      components.push_back(std::make_pair(i,0));
    }
    //Verifica nº de componentes se "retirar o vertice"
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++){
        if(j != i && (!g->getVertex(j)->getMark())){
          components.at(i).second++;
          g->dfs_qtd(j,i);
        }
       }
      for(int j = 0; j < n; j++){
        g->getVertex(j)->setMark(false);
      }
    }
  
    Sort::quicksort(components,0,n-1);
    queuem.push(m);
    queue.push(components);
    components.clear();
  }

  while(!queue.empty()){
    components = queue.front();
    m = queuem.front();
    for(int i = 0; i < m; i++){
      std::cout << components.at(i).first << " " << components.at(i).second << std::endl;
      }
    std::cout << std::endl;
    queue.pop();
    queuem.pop();
  }

  return 0;
}
