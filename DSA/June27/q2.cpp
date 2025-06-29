ListNode* reverseList(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* oldNext = nullptr;

    while(curr){
        oldNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = oldNext;
    }

    return prev;
}


class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseList(slow);
        int maxi = 0;
        while(head && newHead){
            maxi = max(maxi, head->val + newHead->val);
            head = head->next;
            newHead = newHead->next;
        }

        return maxi;
    }
};