#include "tree.h"

void printInt(std::ostream& os, const int& value)
{
    os<<value<<'\n';
}

int main (int argc, char* argv[])
{
    Tree<int> tree;
    tree.add(10);
    tree.add(5);
    tree.printTree(std::cout, printInt);

    std::cin.get();
    return 0;
}
