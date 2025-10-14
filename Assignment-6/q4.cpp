// . Write a program to check if a doubly linked list of
//  characters is palindrome or not

//create a doubly linked list

#include<bits/stdc++.h>
using namespace std;
class node{
  public:
  char data;
  node* next;
  node* back;
  
  node(char data1){
    data = data1;
    next = nullptr;
    back=nullptr;
  }
  node(char data1,node* next1, node* back1){
    data = data1;
    next = next1;
    back = back1;
  }
  node(char data1){
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
bool isPalindrome(node* head){
    node* left = head;
    node* right = head;
    while(right->next!=NULL){
        right = right->next;
    }
    while(left!=right && left->next!=right){
        if(left->data != right->data){
            return false;
        }
        left = left->next;
        right = right->back;
    }
    return true;
}

int main() 
{
    vector<char> arr = {'l','e','v','e','l'};
    node* head = arrtoDLL(arr);
    print(head);
    cout<<"Is Palindrome: "<<(isPalindrome(head) ? "Yes" : "No")<<endl;
}

 