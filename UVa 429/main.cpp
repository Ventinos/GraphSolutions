#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
  int nroCasos = 0;
  std::queue<std::pair<std::string, std::string>> casos;
  std::pair<std::string, std::string> *novoCaso = NULL;
  std::string str, startWord, endWord;
  std::queue<int> queue;
  std::cin >> nroCasos;
  int print[nroCasos+1];
  for (int i = 0; i < nroCasos; i++) {
    std::vector<std::string> dictionary;

    // captura dos termos do dicionario
    for (int i = 0; i < 200; i++) {
      std::cin >> str;
      if (str == "*")
        break;
      dictionary.push_back(str);
    }

    // montando o grafo a partir do dicionario
    Graph *g = Graph::connect(dictionary);

    print[i] = 0;
    // buscando resposta:
    while (true) {
      int space = 0;
      std::getline(std::cin, str);

      if (str == "\n")
        break;

      for (int j = 0; j < str.size(); j++) {
        if (str[j] == ' ')
          space = j;
      }

      if (std::cin.peek() == '\n')
        break;

      std::cin >> startWord;
      std::cin >> endWord;
      std::pair<std::string, std::string> novoCaso =
          std::make_pair(startWord, endWord);
      casos.push(novoCaso);
      queue.push(g->solve(startWord, endWord));
      g->resetMarks();
      print[i] ++;
    }
  }
  int j =0;
  int i=0;
  while (!queue.empty()) {
    std::cout << casos.front().first << " " << casos.front().second << " "
              << queue.front() << std::endl;
    queue.pop();
    casos.pop();
    j++;
    if(print[i] == j && !queue.empty()){
      i++;
      std::cout << '\n';
      j = 0;
    }
  }
}