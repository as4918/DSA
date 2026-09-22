void reorderList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return;

    // Find middle
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode* second = slow->next;
    slow->next = NULL;

    struct ListNode* prev = NULL;

    while (second != NULL)
    {
        struct ListNode* next = second->next;
        second->next = prev;
        prev = second;
        second = next;
    }

    second = prev;

    // Merge two halves
    struct ListNode* first = head;

    while (second != NULL)
    {
        struct ListNode* temp1 = first->next;
        struct ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}