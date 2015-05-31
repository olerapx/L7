#include "tree.h"

void printInt(std::ostream& os, const int& value)
{
    os<<value<<'\n';
}

int main (int argc, char* argv[])
{
    Tree<int> tree;

  tree.add(10);
  tree.add(1);
  tree.add(11);
  tree.add(0);
  tree.add(3);
  tree.add(10);
  tree.add(12);

    tree.printTree(std::cout, printInt);

    std::cout <<tree.getHeight();
    std::cin.get();
    return 0;
}
