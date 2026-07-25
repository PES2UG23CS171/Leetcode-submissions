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
    ListNode* merge(ListNode* L, ListNode* R) {
        if(L==NULL && R==NULL)  return NULL;
        else if(L==NULL && R!=NULL) return R;
        else if(R==NULL && L!=NULL) return L;
        
        if(L->val > R->val)
            swap(L, R);
        ListNode* head=L;
        while(R!=NULL && L->next!=NULL) {
            if(L->next->val > R->val) {
                ListNode* temp=R;
                R=R->next;
                temp->next=L->next;
                L->next=temp;
            }
            L=L->next;
        }
        if(L->next==NULL && R!=NULL)
            L->next=R;
        return head;
    }
    ListNode* mergeSort(int l, int r, vector<ListNode*>& lists) {
        if(r-l<=1)  return lists[l];
        int mid=l+(r-l)/2;
        ListNode* L=mergeSort(l, mid, lists);
        ListNode* R=mergeSort(mid, r, lists);
        return merge(L, R);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        return mergeSort(0, lists.size(), lists);
    }
};
