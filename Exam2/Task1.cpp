#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//the function wrote on the exam
ListNode* delete_elements(ListNode* head, int x) {
    if (!head) {
        return head;
    }

    ListNode* newHead = nullptr;
    ListNode* iter = new ListNode(0, head);
    
    bool isNewHeadFound = false;
    while (iter && iter->next) {
        if (iter->next->val % x == 0) {
            iter->next = iter->next->next;
        }
        else {
            iter = iter->next;
            if (isNewHeadFound == false) {
                newHead = iter;
                isNewHeadFound = true;
            }
        }
    }

    return newHead;
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
    int K = 3;

    std::cout << "Initial List: ";
    printList(head);

    head = delete_elements(head, K);

    std::cout << "\nResult: ";
    printList(head);

    return 0;
}
