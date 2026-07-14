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
    ListNode* reverse(ListNode* head) {
        // if(!head && !head->next) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        if (!head)
            return;

        ListNode* mid = head;
        ListNode* fastP = head;
        while (fastP && fastP->next) {
            mid = mid->next;
            fastP = fastP->next->next;
        }

        ListNode* firstH = head;
         stack<ListNode*> st;

        ListNode* newN = mid->next;
        mid->next = nullptr;

        while (newN) {
            st.push(newN);
            newN = newN->next;
        }


        while(!st.empty()){
            ListNode* temp=firstH->next;
            ListNode* curr=st.top();
            st.pop();
            curr->next=temp;
            firstH->next=curr;
            firstH=temp;
        }
       
        
        
    }
};