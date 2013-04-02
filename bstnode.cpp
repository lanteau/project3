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

#include "bstnode.h"

bstnode::bstnode(BasketballTeam *key, bstnode *left, bstnode *right, bstnode *parent)
{
   m_key = key;
   m_left = left;
   m_right = right;
   m_parent = parent;
}

bstnode::~bstnode()
{
   delete m_left;
   delete m_right;
   m_left = NULL;
   m_right = NULL;
   m_parent = NULL;
   delete m_key;
   m_key = NULL;
}

bstnode* bstnode::getRight() { return m_right; }
bstnode* bstnode::getLeft() { return m_left; }
bstnode *bstnode::getParent() { return m_parent; }

BasketballTeam* bstnode::getKey() { return m_key; }

void bstnode::setKey(BasketballTeam* key) { m_key = key; }
void bstnode::setLeft(bstnode* left) { m_left = left; }
void bstnode::setRight(bstnode* right) { m_right = right; }
void bstnode::setParent(bstnode* parent) { m_parent = parent; }

