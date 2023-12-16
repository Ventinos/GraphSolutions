#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, m, max;
  int i = 1;
  std::queue<std::queue<std::string>> queue;
  std::queue<std::string> s;
  while (true) {
    std::cin >> n;
    std::cin >> m;
    if (n == 0 && m == 0)
      break;
    std::pair<Graph *, Graph *> g = Graph::readGraph(m);
    queue.push(Graph::verificaCirculo(g.first,g.second));
    //g.first->print();
  }
  // Imprimir solução
  while(!queue.empty()){
    std::cout << "\nCalling circles for data set " << i << ":\n";
    s = queue.front();
    //Este pop serve para tirar uma string vazia presente no primeiro elemento da fila
    s.pop();
    while(!s.empty()){
      std::cout << s.front() << std::endl;
      s.pop();
    }
    queue.pop();
    i++;
  }
}