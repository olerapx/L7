#ifndef TREE_H
#define TREE_H

#include "treenode.h"

template <typename T>
class Tree
{
private:
    TreeNode<T>* root;

public:
    Tree();


};

template <typename T>
Tree<T>::Tree()
{
    root=nullptr;
}



#endif // TREE_H
