// Merge two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

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

    tail->next = (l1) ? l1 : l2;
    return dummy.next;
}

// Main function
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    // Keep merging pairs of lists
    while (listsSize > 1) {
        int i = 0, j = 0;

        while (i < listsSize) {
            if (i + 1 < listsSize) {
                lists[j++] = mergeTwoLists(lists[i], lists[i + 1]);
            } else {
                lists[j++] = lists[i];
            }
            i += 2;
        }

        listsSize = j; // reduce size
    }

    return lists[0];
}