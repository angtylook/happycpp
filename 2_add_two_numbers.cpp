#include <vector>
#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(0);
    ListNode* tail = result;
    int quotient = 0;
    
    while (l1 || l2) {
      int val1 = 0;
      if(l1) {
        val1 = l1->val;
        l1 = l1->next;
      }
      int val2 = 0;
      if(l2) {
        val2 = l2->val;
        l2 = l2->next;
      }
      
      int remainder = (val1 + val2 + quotient) % 10;
      quotient = (val1 + val2 + quotient) / 10;
      
      tail->val = remainder;
      if(l1 || l2) {
        tail->next = new ListNode(0);
        tail = tail->next;
      } else if(quotient != 0) {
        tail->next = new ListNode(quotient);
      }
    }
    return result;
  }
  
  void test() {
    ListNode* l1 = new ListNode(6);
    l1->next = new ListNode(7);
    l1->next->next = new ListNode(8);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    ListNode* result = addTwoNumbers(l1, l2);
    print(result);
    
    dellist(l1);
    dellist(l2);
    dellist(result);
  }
  
  void print(ListNode* l) {
    while (l) {
      std::cout << l->val << " ";
      l = l->next;
    }
  }
  
  void dellist(ListNode* l) {
    while (l) {
      ListNode* d = l;
      l = l->next;
      delete d;
    }
  }
};

int main(int argc, const char* argv[]) {
  Solution solution;
  solution.test();
  return 0;
}


