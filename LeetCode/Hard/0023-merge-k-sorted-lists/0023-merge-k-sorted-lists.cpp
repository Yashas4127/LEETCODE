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
    struct cmp {
        bool operator()(ListNode* first, ListNode* second) {
            return first->val > second->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;

        for (ListNode* head : lists) {
            if (head)
                minHeap.push(head);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!minHeap.empty()) {
            ListNode* curr = minHeap.top();
            minHeap.pop();

            temp->next = curr;
            temp = curr;

            if (curr->next)
                minHeap.push(curr->next);
        }

        return dummy->next;
    }
};