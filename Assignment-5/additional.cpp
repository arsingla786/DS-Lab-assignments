//q1________________________________________________________________
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //USING HASHMAP____________________
        // if(headA==NULL || headB==NULL) return NULL;   
        // ListNode* temp1 =(headA);
        // ListNode* temp2 =(headB);

        // map<ListNode* , int> mp;

        // while(temp1!=NULL)
        // {
        //     mp[temp1] = 1;
        //     temp1 = temp1->next;
        // }
        // while(temp2!=NULL){
        //     if(mp[temp2]==1){
        //         return temp2;
        //     }
        //     temp2=temp2->next;
        // }
        // return NULL;
        //______________________COUNT BOTH LENGTH AND START FROM SAME POSITION
//          ListNode* temp11 =(headA);
//          ListNode* temp22 =(headB);

// int l1 = 0,l2= 0;
// while(temp11 != NULL){
//     l1++;
//     temp11= temp11->next;
// }
// while(temp22!=NULL){
//     l2++;
//     temp22 = temp22->next;
// }
//     ListNode* temp1 =(headA);
//     ListNode* temp2 =(headB);
// if(l1<l2){
//     for(int i=0;i<l2-l1;i++){
//         temp2 = temp2->next;
//     }
// }
// if(l1>l2){
//     for(int i=0;i<l1-l2;i++){
//         temp1 = temp1->next;
//     }
// }
// while(temp1 != temp2){
//     temp1=temp1->next;
//     temp2 = temp2->next;
// }
   
//     return temp1; //or temp2

//___________________________OPTIMAL
    ListNode* temp1 =(headA);
    ListNode* temp2 =(headB);
    if(headA==NULL || headB==NULL){
        return 0;
    }
    while(temp1 != temp2 || temp1==NULL && temp2 ==NULL){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2){
            return temp1; //or temp2
        }
        if(temp1==NULL){
            temp1= headA;
        }
        if(temp2==NULL){
            temp2= headB;
        }
    }
    return temp1;
}
};



//q2____________________________________________________________________
// Given a linked list and a positive number K, reverse the nodes in groups of K.
// All the remaining
// nodes after multiples of k should be left as it is.
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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* front = NULL;
        ListNode* prev = NULL;
        while(curr!=NULL){
            front = curr->next;
            curr->next = prev;
            prev= curr;
            curr = front;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp!=NULL){
            ListNode* kthNode = getKthNode(temp,k);
            if(kthNode==NULL){
                if(prevLast){
                    prevLast->next = temp;
                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if(temp==head){
                head = kthNode;
            }
            else{
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};

//q3____________________________________________________________________
//DELLETE LOOP IN LINKED LIST
/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

*/
class Solution {
  public:
    void removeLoop(Node* head) {
        if (!head || !head->next) return;
        // code here
        Node* slow= head;
        Node* fast= head;
         while (fast!=NULL && fast->next !=NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;  // loop detected
            }
        }
        if (slow != fast) return; //no loop
        
        slow=head; //take slow to the head
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        fast->next = NULL;
    }
};


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

 
