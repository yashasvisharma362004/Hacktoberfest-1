#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Create a dummy head to simplify edge cases
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Merge while both lists have nodes
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Attach remaining nodes (if any)
        tail->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
};

int main() {
    // Example: creating two sorted lists manually
    ListNode* l1 = new ListNode(1, new ListNode(3, new ListNode(5)));
    ListNode* l2 = new ListNode(2, new ListNode(4, new ListNode(6)));

    Solution s;
    ListNode* merged = s.mergeTwoLists(l1, l2);

    while (merged) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    
    // Note: In production code, you should free the allocated memory
    // to avoid memory leaks
    
    return 0;
}