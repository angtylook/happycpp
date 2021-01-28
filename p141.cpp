#include "base/util.h"
#include <unordered_set>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        std::unordered_set<ListNode*> exists;
        while (head!=nullptr) {
            if (head->next) {
                if (exists.count(head->next) > 0) {
                    return true;
                } else {
                    exists.insert(head->next);
                }
            }
            head = head->next;
        }
        return false;
    }
};

int main() {
    return 0;
}
