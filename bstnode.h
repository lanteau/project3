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
#ifndef __BSTNODE_H__
#define __BSTNODE_H__

#include <iostream>
#include <string>
#include "BasketballTeam.h"

class bstnode {
private:
   BasketballTeam *m_key;
   bstnode *m_left, *m_right, *m_parent;

public:
   bstnode(BasketballTeam *key, bstnode* left=NULL, bstnode* right=NULL, bstnode *parent=NULL);
   ~bstnode();
   BasketballTeam* getKey();
   bstnode *getLeft();
   bstnode *getRight();
   bstnode *getParent();
   void setKey(BasketballTeam *key);
   void setLeft(bstnode *left);
   void setRight(bstnode *right);
   void setParent(bstnode *parent);
};
#endif
