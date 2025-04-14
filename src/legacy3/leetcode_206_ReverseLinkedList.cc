/**
 * 
 * Copyright (c) 2018
 * 
 * @file
 * @author   qzc (1457615966@qq.com)
 * @date     2019-11
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-11-20
 * Modified By:    qzc (1457615966@qq.com)
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "headers.h"

class Solution
{
public:
    ListNode* leetcode_206_ReverseLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode *pre = nullptr, *next = nullptr;
        while(head->next){
            next = head->next;
            head->next = pre;

            pre = head;
            head = next;
        }
        head->next = pre;

        return head;
    }
};

TEST(leetcode_206_ReverseLinkedList, leetcode_206_ReverseLinkedList_1)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.insert(3);
    l.insert(2);
    l.insert(4);
    l.print();

    rstList.insert(4);
    rstList.insert(2);
    rstList.insert(3);
    rstList.insert(1);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_206_ReverseLinkedList(l.head), rstList.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
