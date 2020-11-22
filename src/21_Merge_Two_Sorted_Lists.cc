// things to remember:
// 1)
// new does not need parentheses
// like ListNode* dummy = new ListNode;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ----- first try -----
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode;
        ListNode* head = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                dummy->next = l1;
                l1 = l1->next;
                dummy = dummy->next;
            } else {
                dummy->next = l2; 
                l2 = l2->next;
                dummy = dummy->next;
            }
        } 
        if (l1 != nullptr) {
            dummy->next = l1;
        } else {
            dummy->next = l2;
        } 
        return head->next;
    }
};

// recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};

// alloc on the stack
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* head = &dummy;    
        while(l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) {
                swap(l1, l2);
            }
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        if (l1 != nullptr) {
            head->next = l1;
        } else {
            head->next = l2;
        }
        return dummy.next;
    }
};
