
//check if a linked list is cuircular or not 

#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  public:
  node(int data){
    this->data=data;
    next = NULL;
  }
};

bool isCircular(node* head){
  if (head==NULL) return true;
  node* temp = head->next;
  while(temp!=NULL && temp!=head){
    temp =temp->next;    
  }
  return temp==head;
}

int main() 
{
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next = head;
    
    cout<<isCircular(head);
    
    
}
