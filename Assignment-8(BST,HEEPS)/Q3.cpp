/*3. Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
(b) Delete an existing element,
(c) Maximum depth of BST
(d) Minimum depth of 
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
//(a) insert
node* insert(node* root,int val){
    if(root==NULL) return new node(val);
node* parent = root;
    while(true){
        if(val>root->val){
            if(root->right==NULL){
                root->right = new node(val);
                break;
            }
            else{
                root = root->right;
            }
        }
        else{
            if(root->left==NULL){
                root->left=new node(val);
                break;
            }
            else{
                root = root->left;
            }
        }
    }
    return parent;
}

//(b) delete
node* deleteNode(node* root,int val){
    if(root==NULL) return NULL;

}

//(c) max depth // it is equivalent to the height of BST
int maxDepth(node* root){
    if(root==NULL) return ;
    
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return max(lh,rh)+1;

}

int main() 
{
  node* root = new node(15);
  root->left = new node(9);
  root->right = new node(17);
  root->left->left = new node(5);
  root->left->right = new node(10);
  root->right->right = new node(19);

  node* root2 = insert(root,4);

  int maxdepth = maxDepth(root);
  cout<<"maxdepth = "<<maxdepth;
}
