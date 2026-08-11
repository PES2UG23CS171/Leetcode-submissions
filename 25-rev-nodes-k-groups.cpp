class Solution {
public:
    ListNode* reverser(ListNode* head, ListNode* endd) {
        ListNode *t1=head, *t2=endd;
        while(head != endd) {
            t1=head;
            head=head->next;
            t1->next=t2;
            t2=t1;
        }
        return t1;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
            return head;
        ListNode *s=head, *e=head;
        for(int n=1; n<k && e->next!=NULL; n++)
            e=e->next;
        head=reverser(s, e->next);
        e= s->next;
        while(1) {
            int n=1;
            for(; n<k && e!=NULL && e->next!=NULL; n++)
                e=e->next;
            if(n!=k)    break;
            ListNode* b=s->next;
            s->next=reverser(b, e->next);
            s=b;
            e= s->next;
        }
        return head;
    }
};
