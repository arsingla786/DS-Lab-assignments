// Write a program to find size of
// i. Doubly Linked List.
// ii. Circular Linked List.

//creating a dll
#include<bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  node* next;
  node* back;
  
  node(int data1){
    data = data1;
    next = nullptr;
    back=nullptr;
  }
  node(int data1,node* next1, node* back1){
    data = data1;
    next = next1;
    back = back1;
  }
  node(int data1){
    data=data1;
    next=NULL;
    back=NULL;
  }
};

node* arrtoDLL(vector<int> &arr){
  node* head = new node(arr[0]);
  node* prev = head;
  for(int i=1;i<arr.size();i++){
    node* temp = new node(arr[i],nullptr,prev);
    prev->next= temp;
    prev= temp;
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
int size(node* head){
  int count =0;
  node* temp = head;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  return count;
}
int main() 
{
    vector<int> arr = {1,2,3,4};
    node* head = arrtoDLL(arr);
    print(head);
    cout<<"Size of DLL is: "<<size(head)<<endl;
    return 0;
}

//_________________________________________________________
//creating a circular linked list
#include<bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  node* next;
  
  node(int data1){
    data = data1;
    next = nullptr;
  }
};
node* arrtoCLL(vector<int> &arr){
  node* head = new node(arr[0]);
  node* prev = head;
  for(int i=1;i<arr.size();i++){
    node* temp = new node(arr[i]);
    prev->next= temp;
    prev= temp;
  }  
  prev->next=head; //making it circular
  return head;
}
void print(node* head){
  node* temp = head;
  if(head==NULL) return;
  do{
    cout<<temp->data<<" ";
    temp=temp->next;
  }while(temp!=head);
  cout<<endl;
}
int size(node* head){
    node* temp = head;
    node* x = head;
    int count = 0;
    while(temp->next!=x){
        count++;
        temp=temp->next;
    }
    return count;
}

int main(){
    vector<int> arr = {1,2,3,4};
    node* head = arrtoCLL(arr);
    print(head);
    cout<<"Size of CLL is: "<<size(head)+1<<endl; //+1 for last node
    return 0;
}
 