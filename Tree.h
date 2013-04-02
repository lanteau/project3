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
#ifndef __TREE_H__
#define __TREE_H__

#include "bstnode.h"
#include <string>

class Tree {

private:
   bstnode *m_root;

public:
   Tree(bstnode* root=NULL) { m_root = root; }
   Tree(Tree &orig);
   ~Tree();
   bstnode *copyTree(bstnode *n);
   void treeDelete(bstnode *removedNode);
   void transplant(bstnode *removedNode, bstnode *replacementNode);
   void insert(bstnode *node);
   void inoTreeWalk(bstnode *n, int wins);
   bstnode *getSuccessor(bstnode *n);
   bstnode *getRoot();
   bstnode *search(bstnode *n, std::string name);
};

#endif
