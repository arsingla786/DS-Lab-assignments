//find if a binary tree is BST or not
//Write program using functions for binary tree traversals: Pre-order, In-order
// and Post order using recursive approach

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 
class node{
  public:
  int val;
  node* left;
  node* right;
  
  public:
  node(int data1){
    val = data1;
    left = nullptr;
    right= nullptr;
  }
};

bool checkIfBST(node* root,int minVal,int maxVal){
      if(root==NULL) return true;
      if(root->val <=minVal || root->val >=maxVal)
        return false;
      
      
      return checkIfBST(root->left,minVal,root->val) && checkIfBST(root->right,root->val,maxVal);
}

node* createTree(){
  node* root = new node(15);
  root->left = new node(9);
  root->right = new node(17);
  root->left->left = new node(5);
  root->left->right = new node(10);
  root->right->right = new node(19);
    
    return root;
}

int main() 
{
  
  node* root = createTree();
  
  cout<<checkIfBST(root,INT_MIN,INT_MAX);
}

