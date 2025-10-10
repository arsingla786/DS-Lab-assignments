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
  cout<<"given list : ";
  node* temp = head;
  while(temp!= NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

node* reverse(node* head){
  cout<<"reversed list : ";
  if(!head){
    return head;
}

  node* temp = head;
  node* front =NULL;
  node* back= NULL;
  
  while(temp!=NULL){
    front = temp->next;
    temp->next=back;
    back = temp;
    temp= front;
  }
  return back;
}

int main() 
{     
    vector<int> arr = {1,2,3,9,4};
    node* head = arrtoLL(arr);
    print(head);
    cout<<endl;
    
    head = reverse(head);
    print(head);
} 