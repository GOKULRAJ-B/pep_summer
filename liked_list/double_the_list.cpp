//https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/?envType=problem-list-v2&envId=linked-list
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
    // ListNode* helper(ListNode* head, int count){
    //     if(head==NULL) return NULL;
    //     if(head->next == NULL){
    //         int num = head->val*2;
    //         head->val = num;
    //         if(head->val>9 && count==0){
    //             ListNode* newnode = new ListNode(head->val/10);
    //             head->val = head->val%10;
    //             newnode->next = head;
    //             return newnode;
    //         }
    //         return head;
    //     }
    //     ListNode* temp = helper(head->next,count+1);
    //     int carry = temp->val/10;
    //     temp->val = temp->val%10;
    //     int n = head->val*2 + carry;
    //     head->val = n;
    //     if(head->val>9 && count==0){
    //         ListNode* newnode = new ListNode(head->val/10);
    //         head->val = head->val%10;
    //         newnode->next = head;
    //         return newnode;
    //     }
    //     return head;
    // }
    ListNode* doubleIt(ListNode* head) {
        // return helper(head,0);
        if(head->val >= 5){
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            head = dummy;
        }
        ListNode* temp = head;
        while(temp!=NULL){
            temp->val = (temp->val*2) % 10;
            if(temp->next && temp->next->val >= 5){
                temp->val++;
            }
            temp = temp->next;
        }
        return head;
    }
};