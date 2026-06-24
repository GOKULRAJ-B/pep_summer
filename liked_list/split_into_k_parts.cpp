/**
 * https://leetcode.com/problems/split-linked-list-in-parts/?envType=problem-list-v2&envId=linked-list
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
    void splitter(ListNode* head, int count,int k, int rem, vector<ListNode*>&v){
        if(v.size()==k) return;
        if(head==NULL){
            while(v.size()<k){
                v.push_back(nullptr);
            }
            return;
        }
        int curr = count;
        if(rem>0){
            rem--;
            curr++;
        }
        ListNode* temp = head;
        for(int i=1;i<curr;i++){
            temp = temp->next;
        }
        ListNode* newhead = nullptr;
        if(temp!=NULL){
            newhead=temp->next;
            temp->next = NULL;
        }
        v.push_back(head);
        splitter(newhead,count,k,rem,v);

    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        ListNode* temp = head;
        int count=0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        int r = count%k;
        int e = count/k;
                                                               
        splitter(head,e,k,r,v);
        return v;
        
    }
};