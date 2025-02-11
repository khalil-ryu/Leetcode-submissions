class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* ans = head;
        
        while (head) {
            while (!st.empty() && head->val > st.top()->val) st.pop();            
            if (!st.empty()) st.top()->next = head; 
            else ans = head;

            st.push(head);
            head = head->next;
        }
        return ans;
    }
};
