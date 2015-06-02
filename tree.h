#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "treenode.h"
#include "nullelementexception.h"

template <typename T>
class Tree
{
private:
    TreeNode<T>* root;

    void addTreeNode(TreeNode<T>*r, const T& element);
    void printTreeNode(TreeNode<T>* r, int u, std::ostream &oStream, void(*printFunc)(std::ostream& os, const T& value));

    TreeNode<T>* _findMaxLeaf(TreeNode<T>*r);

public:
    Tree();
    void add (const T& element);

    void printTree(std::ostream& oStream, void(*printFunc)(std::ostream& os, const T& value));

    //type T must have an overloaded operator >
    T *findMaxLeaf();

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

   printTreeNode(r->left, u+1, oStream, printFunc);

   for (int i=0;i<u;++i) oStream<<"*";
   printFunc(oStream, r->value);

   printTreeNode(r->right,u+1, oStream, printFunc);
}


template <typename T>
T* Tree<T>::findMaxLeaf()
{
    return &_findMaxLeaf(root)->value;
}

template <typename T>
TreeNode<T>*Tree<T>::_findMaxLeaf(TreeNode<T> *r)
{

    if (r==nullptr)
    {
        if (root==r) throw NullElementException("Tree is empty");
        return nullptr;
    }

    if (r->left==nullptr && r->right==nullptr) return r;
    if (r->left==nullptr) return _findMaxLeaf(r->right);
    if (r->right==nullptr) return _findMaxLeaf(r->left);

    TreeNode<T>* maxLeft=_findMaxLeaf(r->left);
    TreeNode<T>* maxRight=_findMaxLeaf(r->right);


    return (maxLeft->value > maxRight->value)? maxLeft : maxRight;
}


#endif // TREE_H
