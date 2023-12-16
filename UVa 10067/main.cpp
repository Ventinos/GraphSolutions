#include "Graph.hpp"
#include "queue"
#include <iostream>

int main() {
  int n, m;
  int s[4], t[4], f[4];
  int mult=1, forbidden=0, T=0, S=0;
  std::queue<int> queue;
  //monta grafo:
  Graph *g = Graph::readGraph();
  
  //captura quantidade de casos de teste:
  std::cin >> n;
  //para cada caso:
  for(int i = 0; i < n; i++){
    //captura o start e o target:
    std::cin >> s[0] >> s[1] >> s[2] >> s[3];
    std::cin >> t[0] >> t[1] >> t[2] >> t[3];
    
    //concatena eles:
    for (int k = 3; k >= 0; k--) {
      T += t[k] * mult;
      S += s[k] * mult;
      mult *= 10;
    }
    
    //reseta mult:
    mult = 1;
    
    //captura quantidade de forbidden:
    std::cin >> m;
    
    //pra cada forbidden:
    for(int j = 0; j < m; j++){
      //captura o forbidden:
      std::cin >> f[0] >> f[1] >> f[2] >> f[3];
      
      //concatena:
      for (int k = 3; k >= 0; k--) {
        forbidden += f[k] * mult;
        mult *= 10;
      }
      
      //marca como visitado pra n passar por ele no bfs:
      g->vertices.at(forbidden)->mark= true;
      
      //reseta mult e forbidden:
      forbidden=0;
      mult = 1;
    }
    //mede a distancia:
    g->bfs(S);
    
    //salva na fila de resultados:
    queue.push(g->vertices.at(T)->dist);
      

    //reseta o S e T:
    S=0;
    T=0;

    //reseta marcacoes do grafo:
    g->resetMarks();
  }
  
  //printa os resultados:
  while(!queue.empty()){
    //if(queue.front() == 0) std::cout << -1 << std::endl;    //else 

    std::cout << queue.front() << std::endl;
    queue.pop();
  }
}
