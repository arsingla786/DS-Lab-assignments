//convert a 2d matrix to linked list (left, right , up , down pointers)

#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int data;
  node* left;
  node* right;
  node* up;
  node* down;
  node(int data){
    this->data=data;
    left = right = up=down =NULL;
  }
};

node* ConvertToDLL(vector<vector<int>>& matrix){
  int rows = matrix.size();
  int cols = matrix[0].size();
   vector<vector<node*>> nodes(rows, vector<node*>(cols, nullptr));
  for(int i = 0;i<rows;i++){
    for(int j=0;i<cols;j++){
      nodes[i][j] = new node(matrix[i][j]);
    }
  }
  //link nodes
  for(int i=0;i<rows;i++){
    for(int j =0;j<cols;j++){
      //for right
      if(j<cols-1){nodes[i][j]->right = nodes[i][j+1]};
      //for up
      if(i>0){nodes[i][j]->up = nodes[i-1][j]};
      //for down
      if(i<rows-1){nodes[i][j]->down = nodes[i+1][j]};
      //for left
      if(j>0){nodes[i][j]->left = nodes[i][j-1]};
    }
  }
  return nodes[0][0];
}

int main(){
  vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
  
}





