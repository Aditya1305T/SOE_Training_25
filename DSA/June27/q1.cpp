class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        
        int carry = 0;
        while(curr1->next && l2->next){
            int total = curr1->val + l2->val + carry;
            carry = total/10;
            curr1->val = total%10;
            curr1 = curr1->next;
            l2 = l2->next;
        }

        ListNode* nextNode = (l2->next? l2->next : curr1->next);

        int sum = curr1->val + l2->val + carry;
        carry = sum/10;
        curr1->val = sum%10;
        curr1->next = nextNode;

        while(carry && curr1->next){
            curr1 = curr1->next;
            curr1->val += carry;
            carry = curr1->val / 10;
            curr1->val %= 10;
        }
        
        if(carry == 0) return l1;
        else{
            curr1->next = new ListNode(carry);
        }

        return l1;


    }
};