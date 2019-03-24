#ifndef TREENODE_H
#define TREENODE_H
#include <string>
using namespace std;

// definition of TreeNode class
class TreeNode{
 public:
  TreeNode();
  ~TreeNode();
  TreeNode* getRight();
  TreeNode* getLeft();

  void setLeft(TreeNode* newLeft);
  void setRight(TreeNode* newRight);
  int getValue();
  void setValue(int newValue);
 private:
  
  TreeNode* left;
  TreeNode* right;
  int value;
  
};

#endif
