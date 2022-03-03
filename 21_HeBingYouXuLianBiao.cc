#include <cstddef>
#include<iostream>
using namespace std;

#if 0
template <typename T>
void Swap(const T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

int main()
{
	// int a = 10;
	// int b = 20;
	// Swap(a, b);
	// double c = 2.3;
	// double d = 4.5;
	// Swap(c, d);
    //
	// float e = 2.1, f = 4.3;
	// Swap(e, f);

    // Swap(1.2, 3.4);   //为什么报错?

	return 0;
}
#endif


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() 
        : val(0), 
        next(nullptr) 
    {}

    ListNode(int x)
        : val(x), 
        next(nullptr) 
    {}

    ListNode(int x, ListNode *next)
        : val(x), 
        next(next) 
    {}
};

class Solution 
{
public:
    // 迭代
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        //创建合并后链表的头节点
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        // while (l1 != nullptr && l2 != nullptr)
        while(l1 && l2)
        {
            if (l1->val < l2->val) 
            {
                prev->next = l1;
                l1 = l1->next;
            } 
            else 
            {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }

    // 递归
    ListNode* mergeTwoLists_1(ListNode* l1, ListNode* l2) 
    {
        if(nullptr == l1)
            return l2;
        else if(nullptr == l2)
            return l1;
        else if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists_1(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists_1(l1, l2->next);
            return l2;
        }

    }
};

