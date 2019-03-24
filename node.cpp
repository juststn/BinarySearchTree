#include <iostream>
#include "node.h"
#include <string>

using namespace std;

// class of TreeNode
// constructor
TreeNode::TreeNode(){

  left = NULL;
  right = NULL;
  value = 0;
}

// destructor
TreeNode::~TreeNode(){
  
}

// set left node
void TreeNode::setLeft(TreeNode* newLeft){
  left = newLeft;
}

// set right node
void TreeNode::setRight(TreeNode* newRight){
  right = newRight;
}

//get left node
TreeNode* TreeNode::getLeft(){
  return left;
}

// get right node
TreeNode* TreeNode::getRight(){
  return right;
}

// get value
int TreeNode::getValue(){
  return value;
}

// ste value
void TreeNode::setValue(int newValue){
  value = newValue;
}
