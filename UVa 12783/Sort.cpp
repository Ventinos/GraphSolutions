#include "Sort.hpp"

int Sort::comparePair(std::pair<int, int> a, std::pair<int, int> b) {
  if (a.first == b.first) {
    if (a.second > b.second) {
      return -1;
    } else
      return 1;
  }
  if (a.first < b.first) {
    return 1;
  }
  return -1;
}

void Sort::swapPair(std::vector<std::pair<int, int>> &v, int pivo, int i) {
  std::pair<int, int> aux = v.at(i);
  v.at(i) = v.at(pivo);
  v.at(pivo) = aux;
}

int Sort::partitionPair(std::vector<std::pair<int, int>> &v, int esq, int dir) {
  int i, fim;
  fim = esq;
  for (i = esq + 1; i <= dir; i++)
    if (comparePair(v.at(i), v.at(esq)) > 0) {
      fim++;
      swapPair(v, fim, i);
    }
  swapPair(v, esq, fim);
  return fim;
}

void Sort::quicksort(std::vector<std::pair<int, int>> &v, int esq, int dir) {
  int i;
  if (esq >= dir)
    return;
  i = partitionPair(v, esq, dir);
  quicksort(v, esq, i - 1);
  quicksort(v, i + 1, dir);
}