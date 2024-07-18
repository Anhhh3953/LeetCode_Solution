#include <iostream>
using namespace std;
struct Node
{ 
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node *next) : val(val), next(next) {}
};
Node *createlinkedlist() 
{
    int n; 
    cin >> n;
    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Node *newnode = new Node(val);
        if (!head)
        {
            head = newnode;
        }
        else
        {
            tail->next = newnode;
        }
        tail = newnode;
    }
    return head;
}
class Merge
{
public:
    Node *MergeLists(Node *l1, Node *l2)
    {
        /*C1:Node *mergehead = nullptr;
        Node *mergetail = nullptr;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                if (!mergehead)
                {
                    mergehead = l1;
                }
                else
                {
                    mergetail->next = l1;
                }
                mergetail = l1;
                l1 = l1->next;
            }
            else
            {
                if (!mergehead)
                {
                    mergehead = l2;
                }
                else
                {
                    mergetail->next = l2;
                }
                mergetail = l2;
                l2 = l2->next;
            }
        }
        if (l1)
        {
            mergetail->next = l1;
        }
        else
        {
            mergetail->next = l2;
        }
        return mergehead;*/

        
        /*C2:Node dummy(0);
        Node *tailmerge = &dummy;
        if (!l1 && !l2)
            return nullptr;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tailmerge->next = l1;
                l1 = l1->next;
            }
            else
            {
                tailmerge->next = l2;
                l2 = l2->next;
            }
            tailmerge = tailmerge->next;
        }
        tailmerge->next = l1 ? l1 : l2;
        return dummy.next; // dummy is a variable not a pointer -> do not use ->
        */

        if (l1->val <= l2->val)
        {
            l1->next = MergeLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = MergeLists(l1, l2->next);
            return l2;
        }
    }
};
int main()
{
    Merge merge;
    Node *l1 = createlinkedlist();
    Node *l2 = createlinkedlist();
    Node *result = merge.MergeLists(l1, l2);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    // release the memory
    while (l1)
    {
        Node *tmp = l1;
        l1 = l1->next;
        delete tmp;
    }
    while (l2)
    {
        Node *tmp = l2;
        l2 = l2->next;
        delete tmp;
    }
    return 0;
}