
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

