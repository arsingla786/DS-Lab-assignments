// Display all the node values in a circular linked list, repeating value of head node at the
// end too.
// Input: 20 → 100 → 40 → 80 → 60,
// Output: 20 100 40 80 60 20.

#include <bits/stdc++.h>
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
node* arrToCLL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* temp= head;
    node* prev = NULL;
    for(int i=1;i<arr.size();i++){
        temp->next = new node(arr[i]);
        temp = temp->next;
    }
    temp->next = head; //making it circular
    return head;
}
void print(node* head){
    if(head==NULL){
        return;
    }
    node* temp = head;
    node* x = head;
    cout<<temp->data<<" ";
    while(temp->next!=x){
        temp = temp->next;
        cout<<temp->data<<" ";
    }
    cout<<x->data<<" ";
}
int main(){ 
    vector<int> arr = {20,100,40,80,60};
    node* head = arrToCLL(arr);
    print(head);
}

 

