//_______________________________________________________
//q4
// Given a doubly linked list having exactly one of 
// the node pointing to a random node in the
// list, the task is to correct this 
// random pointer in the doubly linked list, such that it points to
//the expected node.

#include <bits/stdc++.h>
using namespace std;

class node{
  public:
int data;
node* next;
node* back;

public:
  node(int data1, node* next1, node* back1){
    data=data1;
    next=next1;
    back=back1;
}
  node(int data1){
    data=data1;
    next=NULL;
    back=NULL;
  }
};
 
node* arrToDLL(vector<int> &arr){
  node* head = new node(arr[0]); //create first node
  node* prev = head;
  for(int i=1;i<arr.size();i++){
    node* temp = new node(arr[i],nullptr,prev);//next points to NULL and back points to prev
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void print(node* head){
  node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

node* correctedDLL(node* head){
  //detecting the incorect node
  node* temp = head;
  while(temp!=NULL && temp->next!=NULL){
    // Fix forward direction
        if (temp->next != NULL && temp->next->back != temp) {
            temp->next->back = temp;
        }

        // Fix backward direction
        if (temp->back != NULL && temp->back->next != temp) {
            temp->back->next = temp;
        }
    temp =temp->next;
  }
  return head;
}

int main(){
  vector<int> arr = {1,2,3,4,5};
  node* head = arrToDLL(arr);
  head->next->back = head->next->next; // corrupt the back pointer
  node* newhead = correctedDLL(head);
  print(newhead);
}