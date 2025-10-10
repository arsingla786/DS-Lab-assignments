#include <iostream> 
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data1){
      data=data1;
      next = nullptr;
    }
};

node* arrtoLL(vector<int> &arr){
  node* head = new node(arr[0]);
  node* temp= head;
  for(int i=1;i<arr.size();i++){
    temp->next = new node(arr[i]);
    temp=temp->next;
  }
  return head;
}

void print(node* head){
  node* temp = head;
  while(temp!= NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

void middle(node* head){
  node* slow= head;
  node* fast = head;
  
  while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
  }
  cout<<"middle node :"<< slow->data;
}

int main() 
{     
    vector<int> arr = {1,2,3,9,4};
    node* head = arrtoLL(arr);
    print(head);
    cout<<endl;
    middle(head);
    
}


 