
//Q4____________________________________________________________________
//rotate left by k nodes

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateLeft(ListNode* head, int k) {
        if (!head || k == 0) return head;

        // Step 1: Find the size of the linked list
        ListNode* temp = head;
        int size = 1; // Start with 1 to count the head node
        while (temp->next != NULL) {
            size++;
            temp = temp->next;
        }

        // Step 2: If k is greater than size, take k modulo size
        k = k % size;
        if (k == 0) return head; // No rotation needed

        // Step 3: Find the kth node and the last node
        ListNode* kthNode = head;
        for (int i = 1; i < k; i++) {
            kthNode = kthNode->next;
        }
        ListNode* newHead = kthNode->next; // (k+1)th node will be the new head
        kthNode->next = NULL; // Break the link to form the new end of the list
        temp->next = head; // Connect the last node to the original head

        return newHead; // Return the new head of the rotated list
    }
};

//Q4___________________________________________________________________
#include <iostream>
#include<vector> 
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int data1){
      data=data1;
      next=nullptr;
    }
};

node* arrTOLL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* temp=head;
    for(int i=1;i<arr.size();i++){
      temp->next = new node(arr[i]);
      temp=temp->next;
    }
    return head;
}

void print(node* head){
    node* temp = head;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
}

int length(node* head){
  node* temp = head;
  int count = 0;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
    return count;
}

node* rotateLeft(node* head, int size, int k){
  node* temp = head;
  node* tail = head;
  node* mover = head;
  node* upcoming = NULL;
  node* prev = NULL;
  k = k % size;
  //find tail
  while(temp->next!=NULL){
    temp=temp->next;
    tail = temp;
  }
  int c= 1;
  while(c<=k){
    head = head->next;
    upcoming = mover->next;
    mover->next = NULL;
    tail->next = mover;
    tail = mover;
    mover = upcoming;
    c++;
  }
  return head;
}
int main() 
{
    vector<int> arr = {1,2,3,4,5};
    node* head = arrTOLL(arr);
    print(head);
    cout<<endl;
    int size= length(head);
    cout<<size;
    cout<<endl;
    node* newHead = rotateLeft(head,size,4);
    print(newHead);
}
