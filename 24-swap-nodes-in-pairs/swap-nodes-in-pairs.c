struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;

    while (prev->next && prev->next->next) {
        struct ListNode* first = prev->next;
        struct ListNode* second = prev->next->next;

        // Swap
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // Move pointer
        prev = first;
    }

    return dummy.next;
}