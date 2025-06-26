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
    int findLength(ListNode* head){
        int len =0;
        while(head && head->next){
            len++;
            head = head->next;
        }
        return head ? len+1 : len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        

        int listLength = findLength(head);
        k %= listLength;
        if(k == 0) return head;

        ListNode* breakPt = head;
        for(int i = 0; i < listLength - k - 1; i++){
            breakPt = breakPt->next;
        }
        
        ListNode* newHead = breakPt->next;
        breakPt->next = nullptr;
        ListNode* curr = newHead;

        while(curr->next){
            curr = curr->next;
        }

        curr->next = head;
        return newHead;
    }
};