#include <iostream>
#include <vector>

class UFDS{
public:
  //ATRIBUTOS:
  std::vector<int> marked;
  //METODOS:
  UFDS();
  UFDS(int size);
  bool isConnected(int i, int j);
  void setRoot(int i, int j);
  int findRoot(int i);
};

