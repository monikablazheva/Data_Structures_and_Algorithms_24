#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverse_between(ListNode* head, int start, int end) {
    if (!head || !head->next) {
        return head;
    }

    ListNode* dummy = new ListNode(0, head);

    //Трябва да е:
    //ListNode* prev = dummy;
    //Написала съм на изпита:
    ListNode* prev = dummy; 
    //(само едничка грешка от бързане, но логиката надолу е правилна)
    //така не работи при left = 1

    for (int i = 0; i < start - 1; i++) {
        if (!prev) {
            return head;
        }
        prev = prev->next;
    }

    ListNode* curr = prev->next;

    for (int i = 0; i < end - start; i++) {
        ListNode* next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return dummy->next;
}

int size(ListNode* head) {
    if (!head) {
        return 0;
    }

    ListNode* iter = head;
    int size = 0;
    while (iter) {
        size++;
        iter = iter->next;
    }

    return size;
}

ListNode* reverseOnHalf(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    int size_ = size(head);
    int mid;
    if (size_ % 2 == 0) {
        mid = size_ / 2;
    }
    else {
        mid = size_ / 2 + 1;
    }

    ListNode* copy = head;
    copy = reverse_between(head, 1, mid);
    copy = reverse_between(copy, mid + 1, size_);

    return copy;
}

void printList(ListNode* head)
{
    ListNode* copy = head;
    while (copy) {
        std::cout << copy->val << " ";
        copy = copy->next;
    }
}

int main()
{
    // Create list: 12->15->9->11->5->6->7
    ListNode* head = new ListNode(12);
    head->next = new ListNode(15);
    head->next->next = new ListNode(9);
    head->next->next->next = new ListNode(11);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    std::cout << "Initial List: ";
    printList(head);
    
    head = reverseOnHalf(head);
    
    std::cout << "\nResult: ";
    printList(head);

    return 0;
}
