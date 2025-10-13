// 1. Develop a menu driven program for the following operations of on a Circular as well
// as a Doubly Linked List.
// (a) Insertion anywhere in the linked list (As a first node, as a last node, and
// after/before a specific node).
// (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
// deleted may appear as a head node, last node or a node in between.
// (c) Search for a node.

//doubly linked list 

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

node* deleteHead(node* head){
  if(head==NULL || head->next==NULL){
    return NULL;
  }
  node* prev = head;
  head = head->next;
  head->back = nullptr;
 // prev->next = nullptr;
  delete prev;
  return head;
  cout<<endl;
}

node* deleteTail(node* head){
  if(head==NULL || head->next==NULL){
    return NULL;
  }
  //reach the tail first
  node* tail = head;
  while(tail->next!=NULL){
    tail = tail->next;
  }
  node* prev = tail->back;
  prev->next = NULL;
  tail->back = NULL;
  delete tail;
  return head;
  cout<<endl;
}

//delete kth node
node* deleteK(node* head, int k){
  if(head == NULL){
    return NULL;
  }
  //reach the kth node first
  int count = 0;
  node* temp = head;
  while(temp!=NULL){
    count++;
    if(count== k ){
      break;
    }
    temp = temp->next;
  }
  //now temp is at kth node
  
  //if k is given out of bounds
  if(temp==NULL){
    return head;
  }
  if(temp==head){
    //we are at head
    node* prev = head;
    head = head->next;
    head->back = NULL;
    delete prev;
    return head;
  }
  //if temp is tail
  if(temp->next==NULL){
    temp->back->next = NULL;
    delete temp;
    return head;
  }
  temp->next->back = temp->back;
  temp->back->next = temp->next;
  delete temp;
  return head;
}

node* deleteVal(node* head, int val){
  if(head==NULL){
    return head;
  }
  //reach the node with given val
  node* temp =head;
  while(temp!=NULL){
    if(temp->data==val){
      break;
    }
    temp=temp->next;
  }
  //now we are at required node;
  //if val is at head
  if(temp==head){
    node* prev = head;
    head=head->next;
    head->back=NULL;
    delete prev;
    return head;
  }
  //if there is no val
  if(temp==NULL){
    return head;
  }
  
  //if val is at tail
  if(temp->next==NULL){
    temp->back->next = NULL;
    delete temp;
    return head;
  }
  //if val is in between
  temp->next->back = temp->back;
  temp->back->next= temp->next;
  temp->back = NULL;
  delete temp;
  return head;
}
// ___________________
//|    INSERTION      |
//|___________________|
// INSERTION IN A  DLL

//Insert at head
node* insertHead(node* head, int val){
  node* newNode = new node(val);
  head->back = newNode;
  newNode->next = head;
  head= newNode;
  newNode->back = NULL;
  return head;
}

//insert at tail
node* insertTail(node* head, int val){
  //firstly find the tail 
  if(head==NULL){
    return new node(val,head,NULL);
  }
  node* temp = head;
  node* newNode = new node(val);
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next = newNode;
  newNode->back=temp;
  newNode->next=NULL;
  return head;
}


//insert at position k 
//k should not be equal to head or tail
node* insertK(node* head,int val , int k){
  if(head==NULL){
    return head;
  }
  node* temp = head;
  int count = 1;
  //firstly go to kth position
  while(temp!=NULL){
    count++;
    temp=temp->next;
    if(count==k){
      break;
    }
  }
  if(temp==NULL){
    return head;
  }
  //now we are at position k
  node* newNode= new node(val);
  temp->back->next = newNode;
  newNode->next = temp;
  newNode->back = temp->back;
  temp->back = newNode;
  return head;
}


//insert before a given node value ,gurantee not at head 
node* insertBeforeVal(node* head, int givenVal, int insertVal){
    if(head==NULL){
      return head;
    }
    //firstly go to the given node
    node* temp = head;
    while(temp!=NULL){
      if(temp->data == givenVal){
        break;
      }
      temp=temp->next;
    }
    if(temp==NULL){
      cout<<"no such node found"<<endl;
      return head;
    }
    //now we are at the given node 
    node* newNode = new node(insertVal);
    temp->back->next = newNode;
    newNode->next = temp;
    newNode->back = temp->back;
    temp->back = newNode;
    return head;
}

int main() 
{
  vector<int> arr = {1,2,3,4};
  node* head = arrToDLL(arr);
  print(head);
  //head= deleteHead(head);
  //print(head);
  head = deleteK(head,2);
  print(head);
  head = deleteVal(head,4);
  print(head);
  head = insertHead(head,17);
  print(head);
  head= insertTail(head,19);
  print(head);
  head=insertK(head,100,4);
  print(head);
  head=insertBeforeVal(head,3,200);
  print(head);
}
//_
//_________________________________________________________________
//REVERSE A DLL
//doubly linked list 

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
//reverse a DLL
//we can use a stack  ;

//push all in stack first then pop one by one to reverse
node* reverseDLL(node* head){
  if(head==NULL){
    return head;
  }
  stack<int> st;
  node* temp = head;
  while(temp!=NULL){
    st.push(temp->data);
    temp=temp->next;
  }
  node* temp1 = head;
  
  while(!st.empty()){
    temp1->data = st.top();
    st.pop();
    temp1=temp1->next;
  }
  return head;
}

int main() 
{ 
  vector<int> arr = {1,2,3,4};
  node* head = arrToDLL(arr);
  print(head);
  head= reverseDLL(head);
  print(head);
}
//__________________________________________________________________
//REVERSE A DLL OPTIMAL SOLUTION 
#include <bits/stdc++.h>

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

void  print(node* head){
  node* temp=head;
  
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

node* reverseDLL(node* head){
  node* current = head;
  node* last=NULL;
  while(current!=NULL){
    last = current->back;
    current->back = current->next;
    current->next= last;
    current=current->back;
  }
  head = last->back;
  return head;
}
int main() 
{
    vector<int> arr = {1,2,3,4};
    node* head = arrtoDLL(arr);
    print(head);
    head= reverseDLL(head);
    print(head);
    
}

//ADD TWO INTEGRERS USING SINGLY LINKED LIST
#include <bits/stdc++.h>

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

void  print(node* head){
  node* temp=head;
  
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

node* reverseDLL(node* head){
  node* current = head;
  node* last=NULL;
  while(current!=NULL){
    last = current->back;
    current->back = current->next;
    current->next= last;
    current=current->back;
  }
  head = last->back;
  return head;
}

node* add(node* head, node* head1,vector<int> &ans){
  
  node* t = head;
  node* t1 = head1;
  node* dummy = new node(-1);
  node* current = dummy;
  int carry = 0;
  while(t!=NULL || t1 != NULL){
    int sum = carry;
    if(t){
      sum = sum+t->data;
    }
    if(t1){
      sum= sum+ t1->data;
    }
    node* newNode = new node(sum%10);
    ans.push_back(newNode->data);
    carry = sum/10;
    current->next=newNode;
    current = current->next;
    
    if(t) t=t->next;
    if(t1) t1=t1->next;
    
  }
  if(carry){
    node* newNode = new node(carry);
    current->next = newNode;
    current=current->next;
    ans.push_back(carry);
  }
  
  return dummy->next; //head of answer
}

int main() 
{
    vector<int> arr = {1,2,3,4};
    vector<int> brr =  {7,8,9,2};
    vector<int> ans;
    node* head = arrtoDLL(arr);
    node* head1 = arrtoDLL(brr);
     cout<<"given numbers : "<<endl;
    print(head);
    print(head1);
    head = reverseDLL(head);
    head1= reverseDLL(head1);
    node* head2 = add(head,head1,ans);
    head2 = arrtoDLL(ans);
    head2 = reverseDLL(head2);
     cout << "Final sum :" << endl;
    print(head2);  
}



