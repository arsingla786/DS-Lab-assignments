#include <iostream>
#include<vector>

using namespace std;

class node{
  public:
  int data;
  node* next;
  node(int data1){
    data = data1;
    next = NULL;
  }
};

node* arrtocll(vector<int> &arr){
       node* head = new node(arr[0]);
       node* temp = head;
        for(int i=1;i<arr.size();i++){
          temp->next = new node(arr[i]);
          temp = temp->next;
        }
        temp->next = head;
        return head;
}

void split(node* head){
  //count length 
  node* temp = head;
  int count = 1;
  while(temp->next!=head){
    count++;
    temp=temp->next;
  }
  int k=1;
  if(count%2==0){
    node* t = head;
    node* front = NULL;
    while(k <= count/2){
      cout<<t->data<<" ";
      front = t->next;
      t = t->next;
      k++;
    }
    cout<<" | ";
    while(front!=head){
      
      cout<<front->data<<" ";
      front= front->next;
    }
  }
  else{
     node* t = head;
    node* front = NULL;
    while(k <= (count/2)+1){
      cout<<t->data<<" ";
      front = t->next;
      t = t->next;
      k++;
  }
  cout<<" | ";
  while(front!=head){
    
    cout<<front->data<<" ";
    front = front->next;
  }
}
}
int main() 
{
    vector<int> arr = {1,2,3,4,5,6,7};
    node* head = arrtocll(arr);
    split(head);
    
}

//_______________________________________________________

 





