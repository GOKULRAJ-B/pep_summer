//https://leetcode.com/problems/merge-in-between-linked-lists/?envType=problem-list-v2&envId=linked-list
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = 0;
        ListNode* temp=list1;
        ListNode* a_end;
        ListNode* b_end;
        while(count<=b+1){
            if(count==a-1){
                a_end = temp;
            }
            if(count==b+1){
                b_end = temp;
                break;
            }
            count++;
            temp = temp->next;
        }
        a_end->next = list2;
        temp = list2;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = b_end;
        return list1;
    }
};