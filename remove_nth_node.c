#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    res->val = 0;
    res->next = head;

    struct ListNode* dummy = res;
    struct ListNode* temp = head;

    for (int i = 0; i < n; i++) {
        temp = temp->next;
    }

    while (temp != NULL) {
        temp = temp->next;
        dummy = dummy->next;
    }

    struct ListNode* toDelete = dummy->next;
    dummy->next = dummy->next->next;
    free(toDelete);

    struct ListNode* ans = res->next;
    free(res);
    return ans;
}
