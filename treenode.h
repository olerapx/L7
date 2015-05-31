#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
class TreeNode
{     
public:
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* root;

    TreeNode(const T& element);
};

template <typename T>
TreeNode<T>::TreeNode(const T &element)
{
    left=nullptr;
    right=nullptr;
    root=nullptr;
    value=element;
}



#endif // TREENODE_H
