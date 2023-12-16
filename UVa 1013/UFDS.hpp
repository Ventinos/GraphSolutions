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
  void setRoot(int i, int j,int w1[], int w2[]);
  int findRoot(int i);
};

