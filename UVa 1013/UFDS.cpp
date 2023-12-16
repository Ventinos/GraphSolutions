#include "UFDS.hpp"

UFDS::UFDS() {}

UFDS::UFDS(int size) {
  for (int i = 0; i < 3 * size; i++)
    marked.push_back(i);
}

bool UFDS::isConnected(int i, int j) {
  int r1 = findRoot(i);
  int r2 = findRoot(j);
  return r1 == r2;
}

void UFDS::setRoot(int i, int j, int caminho[], int hab[]) {
  if (isConnected(i, j))
    return;
  int x = findRoot(i), y = findRoot(j);
  if (caminho[x] > caminho[y]) {
    marked[y] = x;
    caminho[x] += caminho[y];
    hab[x] += hab[y];
  } else {
    marked[x] = y;
    caminho[y] += caminho[x];
    hab[y] += hab[x];
  }
}

int UFDS::findRoot(int i) {
  if (i == marked[i])
    return i;
  marked[i] = findRoot(marked[i]);
  return marked[i];
}
