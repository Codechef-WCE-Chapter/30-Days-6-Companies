#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode *> hash;
        int sum = 0;
        for (ListNode *p = dummy; p; p = p->next)
        {
            sum += p->val;
            hash[sum] = p;
        }
        sum = 0;
        for (ListNode *p = dummy; p; p = p->next)
        {
            sum += p->val;
            p->next = hash[sum]->next;
        }
        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(32);
    ListNode *node1 = new ListNode(25);
    ListNode *node2 = new ListNode(12);
    ListNode *node3 = new ListNode(50);
    ListNode *node4 = new ListNode(40);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    ListNode *node = s.removeZeroSumSublists(head);
    cout << "ListNode value:" << node->val << endl;
}