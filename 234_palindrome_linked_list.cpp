class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if(!head->next)
            return true;
        ListNode* temp=head;
        stack<int> S;
        while(temp && temp->next)
        {
            S.push(head->val);
            head=head->next;
            temp=temp->next->next;
        }
        if(temp && !temp->next)
            head=head->next;
        while(head)
        {
            if(S.top() != head->val)
                return false;
            S.pop();
            head=head->next;
        }
        return true;
    }
};
