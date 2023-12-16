#include "Graph.hpp"
#include <iostream>
#include <queue>

int main() {
  int n,v;
  std::string city = "";
  std::queue <std::string> cities;
  std::queue<bool> results;
  std::ifstream file("Input.txt");
  if(file.is_open()){
    file >> n;
    //std::cin >> n;
    Graph* g = Graph::readGraph(n, &file);
    g->verificaSafe();
    while(!file.eof()){
      //std::cin >> city;
      file >> city;
      if(g->verifyCity(city, &v)){
        cities.push(city);
        results.push(g->getVertex(v)->getSafe());
      }
    }
    file.close();
    while(!results.empty()){
      std::cout << cities.front();
      if(results.front())
        std::cout << " safe\n";
      else
        std::cout << " trapped\n";
      results.pop();
      cities.pop();
    }
  }  
  //g->print();
}