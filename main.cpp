#include "tree.h"

int main (int argc, char* argv[])
{
    Tree<int> tree;

    int number=0, max=0;

    std::cout <<"Input number of elements: ";
    std::cin >>number;
    std::cout <<"Input max element: ";
    std::cin >>max;

    srand (time_t(0));

    for (int i=0;i<number;i++)
      tree.add(rand()%(max+1));

    tree.printTree(std::cout, printInt);
    try
    {
         std::cout <<"Max leaf = " <<*tree.findMaxLeaf();
    }
    catch (NullElementException e)
    {
        std::cerr<<e.getError()<<"\n";
    }

    std::cin.get();
    return 0;
}
