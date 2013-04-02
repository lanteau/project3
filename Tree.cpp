/******************************************************************************
*******************************************************************************
*                           EECS 1580 - 001                                   *
*                        Project #3 Binary Tree                               *
*                                                                             *
*                      Written by: Logan Anteau                               *
*                          March 24, 2013                                     *
*******************************************************************************
*******************************************************************************
*/

#include "Tree.h"
#include <string>

using namespace std;

Tree::Tree(Tree &orig) 
{
   if (orig.m_root == NULL)
      m_root = NULL;
   else
   {
      m_root = copyTree(orig.m_root);
      m_root->setParent(NULL);
   }
}

Tree::~Tree()
{
   delete m_root;
}

bstnode *Tree::copyTree(bstnode *n)
{
   bstnode *copy = NULL;
   if (n == NULL) 
      return copy;
   copy = new bstnode (*n);
   copy->setLeft(copyTree(n->getLeft()));
   copy->setRight(copyTree(n->getRight()));
   if (copy->getLeft() != NULL)
      copy->getLeft()->setParent(copy);
   
   if (copy->getRight() != NULL)
      copy->getRight()->setParent(copy);
   
   return copy;
}

void Tree::insert(bstnode *node)
{
   if (m_root == NULL)        // If the current tree is empty
   {
      m_root = node;
      m_root->setParent(NULL);
   }
   else
   {
      bstnode *current;

      current = m_root;
      while ((*(current->getKey()) <= *(node->getKey()) && current->getRight() != NULL) ||
         (*(current->getKey()) > *(node->getKey()) && current->getLeft() != NULL))
      {
            if (*(current->getKey()) > *(node->getKey()))
               current = current->getLeft();
            else
               current = current->getRight();
      }
      if (*(current->getKey()) > *(node->getKey()))
      {
         current->setLeft(node);
         node->setParent(current);
      }
      else
      {
         current->setRight(node);
         node->setParent(current);
      }
   }
   return;
}

void Tree::inoTreeWalk(bstnode *n, int wins = 0)
{
   if(n != NULL)
   {
      inoTreeWalk(n->getLeft(), wins);
      if (n->getKey()->getWins() >= wins)
         cout << *(n->getKey());
      inoTreeWalk(n->getRight(), wins);
   }
   
   return;
}

bstnode *Tree::getRoot() { return m_root; }

bstnode *Tree::getSuccessor(bstnode *n)
{
   bstnode *successor;

   successor = n->getRight();
   if (successor == NULL)
      return successor;
   
   while (successor->getLeft() != NULL)
      successor = successor->getLeft();

   return successor;
}

void Tree::transplant (bstnode *removedNode, bstnode *replacementNode)
{
   if (removedNode->getParent() == NULL)      // It's the root
      m_root = replacementNode;
   else if ((removedNode->getParent())->getLeft() == removedNode)  // It's a left child...
      (removedNode->getParent())->setLeft(replacementNode);
   else
      (removedNode->getParent())->setRight(replacementNode);      // It's a right child...
   
   if (replacementNode != NULL)
      replacementNode->setParent(removedNode->getParent());
   
}

void Tree::treeDelete(bstnode *removedNode)
{
   bstnode *y;

   if (removedNode->getLeft() == NULL)
      transplant(removedNode, removedNode->getRight());
   else if (removedNode->getRight() ==NULL)
      transplant(removedNode, removedNode->getLeft());
   else
   {
      y = getSuccessor(removedNode);
      if (y->getParent() != removedNode)
      {
         transplant (y, y->getRight());
         y->setRight(removedNode->getRight());
         y->getRight()->setParent(y);
      }
      transplant (removedNode, y);
      y->setLeft(removedNode->getLeft());
      (y->getLeft())->setParent(y);
   }
}

bstnode *Tree::search(bstnode *n, string name)
{
   if(n == NULL || n->getKey()->getName() == name)
      return n;
   if (name < n->getKey()->getName())
      return this->search(n->getLeft(), name);
   else
      return this->search(n->getRight(), name);

}
