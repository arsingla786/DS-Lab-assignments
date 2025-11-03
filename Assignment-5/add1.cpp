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
