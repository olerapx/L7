#ifndef TREE_H
#define TREE_H

#include "treenode.h"
#include <iostream>

template <typename T>
class Tree
{
private:
    TreeNode<T>* root;

    void addTreeNode(TreeNode<T>*r, const T& element);
    void printTreeNode(TreeNode<T>* r, int u, std::ostream &oStream, void(*printFunc)(std::ostream& os, const T& value));
    size_t getHeightNode (TreeNode<T> *r);

public:
    Tree();
    void add (const T& element);

    void printTree(std::ostream& oStream, void(*printFunc)(std::ostream& os, const T& value));

    size_t getHeight();

};


template <typename T>
Tree<T>::Tree()
{
    root=nullptr;
}

template <typename T>
void Tree<T>::add(const T &element)
{
    addTreeNode(root, element);
}

template <typename T>
void Tree<T>::addTreeNode(TreeNode<T>*r, const T& element)
{
    if (r==nullptr)
    {
        r=new TreeNode<T>(element);
        if (root==nullptr) root=r;
        return;
    }
    if(element<=r->value)
    {
        if (r->left==nullptr)
        {
            r->left=new TreeNode<T>(element);
            return;
        }
        addTreeNode(r->left, element);
    }
   else if (element>r->value)
    {
        if (r->right==nullptr)
        {
            r->right=new TreeNode<T>(element);
            return;
        }
        addTreeNode(r->right, element);
    }
}

template <typename T>
void Tree<T>::printTree(std::ostream& oStream, void(*printFunc)(std::ostream& os, const T& value))
{
   Tree<T>::printTreeNode(this->root, 0, oStream, printFunc);
}

template <typename T>
void Tree<T>::printTreeNode(TreeNode<T>* r, int u, std::ostream &oStream, void(*printFunc)(std::ostream& os, const T& value))
{
   if (r==nullptr) return;

   printTreeNode(r->left, ++u, oStream, printFunc);
   for (int i=0;i<u;++i) oStream<<"|";
   printFunc(oStream, r->value);
   u--;
   printTreeNode(r->right, ++u, oStream, printFunc);
}

template <typename T>
size_t Tree<T>::getHeight()
{
    return getHeightNode(root);
}


template <typename T>
size_t Tree<T>::getHeightNode (TreeNode<T>* r)
{
    if (r==nullptr) return 0;

    size_t sizeLeft=getHeightNode(r->left);
    size_t sizeRight=getHeightNode(r->right);

    if (sizeLeft>=sizeRight) return (1+sizeLeft);
    return (1+sizeRight);
}


#endif // TREE_H
