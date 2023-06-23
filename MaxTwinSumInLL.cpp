/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        int sum = 0;
        if (head->next->next == NULL)
        {
            sum += head->val;
            head = head->next;
            sum += head->val;
            return sum;
        }

        stack<int> s;
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        while (slow != NULL)
        {
            s.push(slow->val);
            slow = slow->next;
        }
        slow = head;
        while (slow != fast)
        {
            cout << slow->val << " " << s.top() << endl;
            sum = max(sum, slow->val + s.top());
            slow = slow->next;
            s.pop();
        }
        sum = max(sum, slow->val + s.top());
        return sum;
    }
};