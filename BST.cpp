#include <iostream>
#include <fstream>

#include "node.h"
using namespace std;


/*Binary Search Tree: Input numbers to put it in a tree with each node having a left 
and right child. Nodes can be removed, added, and printed in any order. 
Tree is visually displayed
*/
void insertTree(TreeNode* &root, int input);
void printTree(TreeNode* root);
void deleteTree(TreeNode* &root, int input);
int getHeight(TreeNode* root);
void printRow1(int array[1000], int cnt);
void getPrintList(TreeNode* root, int k, int array[1000]);
int main(){

  TreeNode* root = NULL;
  int input = 0;
  
  cout<<"Binary Search Tree: choose whether to read from file or input [F, I]"<<endl;

  
  string in;
  cin>>in;

  //inputting from file
  if (in == "F"){
    cout<<"Input file name"<<endl;
    cin>>in;
    
     std::ifstream myfile(in);
     if (myfile.is_open()) {
       if (!myfile.eof())
       {
          while (myfile >> input) {
           insertTree(root, input); 
            }
       }
       myfile.close();
      }
     else {
        cout << "Can not open input file" << endl;
        return 0;
       }
   }
  //inputting from input
  else if (in == "I"){
    cout<<"Input numbers to add (separated with spaces, such as 1 4 3 34 2)"<<endl;
    while ( cin >> input) {
    
      // insert the number into heap
      insertTree(root, input);
      
      if ( cin.get() == '\n' ) break;
     }
  }
  else{
      cout<<"invalid input"<<endl;
      return 0;
  }

  
  // print the tree
  printTree(root);

  string cmd="";
  int  value;
  int loop=1;
  while (loop ==1) {
    cout << endl << "Enter command (add, delete, print, exit):" << endl;
    cin >> cmd;

    if (cmd == "delete") {
      cout << "Enter a number to delete from tree:" << endl;
      cin >> value;
      deleteTree(root, value);
      }

    if (cmd == "print") {
      printTree(root);
     }

    if (cmd == "add") {
      cout << "Enter a number to add to tree:" << endl;
      cin >> value;
      insertTree(root, value);
     }

    if (cmd == "exit") {
	  loop=0;
      }

  }
}

//inserting a number to BST
void insertTree(TreeNode* &root, int input){

  // if heap is empty, then add the first value to heap
  if(root == NULL){
    TreeNode* newNode = new TreeNode;
    newNode->setValue(input);
    root = newNode;
    return;
  }

  if(input>root->getValue()){
    TreeNode *temp = root->getRight();
    insertTree(temp, input);
    root->setRight(temp);
  }
  else{
    TreeNode *temp = root->getLeft();
    insertTree(temp, input);
    root->setLeft(temp);
  }
  
}


//delete the root of the he
void deleteTree(TreeNode* &root, int deletedNumber){

  //Nothing
  if(root == NULL){
    return;
  }

  //deleted Number is bigger than the root, recursive call for root right child
  if(deletedNumber > root->getValue()){
    TreeNode* temp = root->getRight();
    deleteTree(temp, deletedNumber);
    root->setRight(temp);
    return;
  }
  //deleted Number is less than the root, recursive call for root left child
  if(deletedNumber < root->getValue()){
    TreeNode* temp = root->getLeft();
    deleteTree(temp, deletedNumber);
    root->setLeft(temp);
    return;
  }

  //deleted Number is equal to root
  if(deletedNumber == root->getValue()){

    
    if(root->getLeft() == NULL && root->getRight() == NULL){
      delete root;
      root = NULL;
      return;
    }

    //If left and right child are not null or if left is null
    if (root->getRight() != NULL){
      TreeNode* temp;
      int v; 
      //set temp to right child value
      v = root->getRight()->getValue();
      //set right child to root value
      root->getRight()->setValue(root->getValue());
      //set root to right child value
      root->setValue(v);
      temp = root->getRight();
      deleteTree(temp, deletedNumber);
      root->setRight(temp);
      return;
    }

    //ifright child is null
    if(root->getRight() == NULL && root->getLeft() != NULL){
       TreeNode* temp;
       int v;
      //set temp to left child value
      v =root->getLeft()->getValue();
      //set left child to root value
      root->getLeft()->setValue(root->getValue());
      //set root to Left child value
      root->setValue(v);
      temp = root->getLeft();
      deleteTree(temp, deletedNumber);
      root->setLeft(temp);
    }
  }
}

//print tree
void printTree(TreeNode* root){

  
  /*
  cout<<"tree list:"<<endl;
  int x = 1;

  //switch to a new line when it encounters 2^x
  for(int i = 1; i<=heap_size; i++){
    // cout<<" "<<i<<"  1111 "<<x<<endl;
    if(i == pow(2,x)){
      cout<<endl;
	x++;
      }
      
    
    cout<<heap[i]<<" ";
  }
  cout<<endl;
 
  return;
  */
  
   int array[1000];
      // initialize the array
      for (int i=0; i< 1000; i++)
	array[i] =-999;  // -999 represent null tree node

      // put the tree node value into the array
      getPrintList(root, 0, array);
      
      int height = getHeight(root);
      //      cout << "Tree height: " << height << endl;
      
      int cnt=1;
      for (int i = 0 ; i < height; i ++) {
	// printRow(array, height, i, cnt);
	printRow1(array, cnt);
	cnt = cnt * 2; 
      }
  }

// get height of tree
int getHeight(TreeNode* root)
{
  if (root == NULL) {
    return 0;
  }

  int righth, lefth;
  righth = getHeight(root->getRight());
  lefth = getHeight(root->getLeft());

  if (righth > lefth) {
    return righth +1;
  }
  else
    {
      return lefth+1;
    }
}

// get the tree into an array for printing
void getPrintList(TreeNode* root, int k, int array[1000])
{
  if (root == NULL)
    return;

  array[k] = root->getValue();
  getPrintList(root->getLeft(), k*2+1, array);
  getPrintList(root->getRight(), k*2+2, array);
}

// print a row
void printRow1(int array[1000], int cnt)
{
  int startIndex = cnt-1;
  int endIndex = startIndex + cnt;

  for (int i = startIndex; i < endIndex; i++) {
    if (array[i] != -999)
    printf("%4d ", array[i]);
    else
      printf(" ___ ");
  }
  printf("\n");
}
