#include <iostream>
#include <vector>

class Sort
{
  public:
    int static comparePair(std::pair<int,int> a,std::pair<int,int> b);
 
    void static swapPair(std::vector<std::pair<int,int>> &v, int pivo, int i);

    int static partitionPair(std::vector<std::pair<int,int>> &v, int esq, int dir);

    void static quicksort(std::vector<std::pair<int,int>> &v, int esq, int dir);
};

