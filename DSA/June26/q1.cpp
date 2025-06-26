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

    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* oldNext = nullptr;
        
        while(head){
            oldNext = head->next;
            head->next = prev;
            prev = head;
            head = oldNext;
        }

        return prev;

    }

    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* nextHead = slow->next;
        slow->next = nullptr;
        nextHead = reverseList(nextHead);

        while(head && nextHead){
            if(head->val != nextHead->val) return false;
            else{
                head = head->next;
                nextHead = nextHead->next;
            }
        }
        return true;
    }
};