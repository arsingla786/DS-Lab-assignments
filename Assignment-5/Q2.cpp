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

node* deleteVal(node* head, int val){
  if(head->data==val){
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  
    node* prev = head;
    node* curr = head->next;

    while (curr != NULL) {
        if (curr->data == val) {
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

node* deleteK(node* head, int key){
  node* temp = head;
  while(temp!=NULL){
    if(temp->data==key){
      head = deleteVal(head,key);
      temp=head;
    }
    temp=temp->next;
  }
  return head;
}

int main() 
{     
    vector<int> arr = {1,2,3,9,4,1,5,1,8};
    node* head = arrtoLL(arr);
    print(head);
    cout<<endl;
    node* newHead = deleteK(head,1); 
    print(newHead);
}
