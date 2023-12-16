#include <iostream>
#include "Graph.hpp"

int main() {
  int t = 0;
  std::queue<int> queue;
  std::cin >> t;
  for(int i = 0; i < t; i++){
    Graph* g = Graph::readGraph();

    g->markUnsafePlaces();

    g->bfs(g->reinoA);
    
    if(g->vertices.at(g->reinoB)->dist==0)
    {
      queue.push(-1);
    }
    else
    {
      queue.push(g->vertices.at(g->reinoB)->dist);
    }
  }
  while(!queue.empty()){
    if(queue.front() == -1) std::cout << "King Peter, you can’t go now!\n";
    else std::cout << "Minimal possible length of a trip is " << queue.front() << std::endl;
    queue.pop();
  }
}