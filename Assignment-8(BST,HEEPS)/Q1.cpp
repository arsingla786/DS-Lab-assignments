//Write program using functions for binary tree traversals: Pre-order, In-order and Post
///order using recursive approach

#include <iostream>
#include<vector>
using namespace std;

class node{
  public:
  int data;
  node* left;
  node* right;
  
  public:
  node(int data1){
    data = data1;
    left = nullptr;
    right= nullptr;
  }
};


void preorder(node* root){
  if(root == NULL){
    return;
  } 
  
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(node* root){
 if(root==NULL){
   return;
 }
 
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void postorder(node* root){
  if(root==NULL){
    return;
  }
  
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}
node* createTree(){
    node* root = new node(1);
     root->left = new node(2);
     root->right = new node(3);
     root->left->left = new node(5);
     root->left->right = new node(4);
     root->left->right->left = new node(6);
     root->right->left = new node(7);
     root->right->right = new node(8);
     root->right->right->left = new node(9);
     root->right->right->right = new node(10);
    
    return root;
}

int main() 
{
  node* root = createTree();
  cout<<"preorder : ";
  preorder(root);
  cout<<endl;
  cout<<"inorder : ";
  inorder(root);
  cout<<endl;
  cout<<"postorder : ";
  postorder(root);
  cout<<endl;
  
}

