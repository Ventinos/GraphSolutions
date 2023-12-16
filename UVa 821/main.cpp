#include <iostream>
#include <iomanip>
#include "Graph.hpp"

int main() {
  int a, b, cnt = 0;
  std::queue<float> queue;
  std::cin >> a;
  std::cin >> b;
  while(a != 0 && b != 0){
    Graph* g = Graph::readGraph(a,b);
    queue.push(g->solve());
    std::cin >> a;
    std::cin >> b;
  }
  while(!queue.empty()){
    cnt++;
    std::cout << "Case " << cnt << ": average length between pages = " << std::fixed << std::setprecision(3) << queue.front() << " clicks" <<std::endl;
    queue.pop();
  }
}

//1 2 2 4 1 3 3 1 4 3 0 0
//1 2 1 4 4 2 2 7 7 1 0 0
//0 0
