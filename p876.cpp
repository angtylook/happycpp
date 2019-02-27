#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* one = head;
        ListNode* two = head;
        while (two && two->next != nullptr) {
            one = one->next;
            two = two->next;
            if (two)
                two = two->next;
        }
        return one;
    }
};

int main() {
    ListNode node6(6);
    ListNode node5(5);
    node5.next = &node6;
    ListNode node4(4);
    node4.next = &node5;
    ListNode node3(3);
    node3.next = &node4;
    ListNode node2(2);
    node2.next = &node3;
    ListNode node1(1);
    node1.next = &node2;

    Solution sol;
    auto node = sol.middleNode(&node1);
    std::cout << node->val << std::endl;

    node5.next = nullptr;
    node = sol.middleNode(&node1);
    std::cout << node->val << std::endl;
    return 0;
}
