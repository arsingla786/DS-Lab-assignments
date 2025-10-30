/*2. Implement following functions for Binary Search Trees
(a) Search a given item (Recursive & Non-Recursive)
(b) Maximum element of the BST
(c) Minimum element of the BST
(d) In-order successor of a given node the BST
(e) In-order predecessor of a given node the BST 
*/

#include <iostream>
using namespace std;

class node{
  public:
  node* left;
  node* right;
  int val;
  
  node(int val){
    this->val=val;
    left=NULL;
    right=NULL;
  }
};

//(a)//recursive search
bool search(node* root, int k){
  if(root==NULL){
    return false;
  }
  if(root->val == k){
    return true;
  }
  
  if(k<root->val){
    return search(root->left,k);
  }
  else{
    return search(root->right,k);
  }
  
}
//iterative search
bool itsearch(node* root, int k){ 
  while(root!=NULL){
    if(k==root->val){
      return true;
    }
    else if(k<root->val){
      root = root->left;
    }
    
    else{
      root = root->right;
    }
  }
  
  return false;
}

//(b)//MINIMUM NODE-> LEFTMOST
int minNode(node* root){
  while(root->left!=NULL){
    root=root->left;
  }
  return root->val;
}

//(c)//MAXNODE -> RIGHTMOST
int maxNode(node* root){
  while(root->right!=NULL){
    root = root->right;
  }
  return root->val;
}
//(d)//inorder successor -> smallest element in right subtree
int successor(node* root, int val){
    
}

int main() 
{
  node* root = new node(15);
  root->left = new node(9);
  root->right = new node(17);
  root->left->left = new node(5);
  root->left->right = new node(10);
  root->right->right = new node(19);

  cout<<search(root,5)<<endl;
  cout<<itsearch(root,100)<<endl;
  
  cout<<"min node = "<<minNode(root)<<endl;
  cout<<"max node = "<<maxNode(root)<<endl;


}


