/**
 * 
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。
 * 
 */
#include "headers.h"

class Solution
{
public:
    ListNode* leetcode_19_Remove_Nth_Node_From_End_of_List(ListNode* head, int n) {
        ListNode* nAhead = head, *cur = head;

        for (int i = 0; i < n; ++i) {
            nAhead = nAhead->next;
        }

        if (nAhead == nullptr) {
            head = head->next;

            ListNode *delNode = cur;
            delete delNode;
            delNode = nullptr;
        }else{
            while (nAhead->next != nullptr){
                cur = cur->next;
                nAhead = nAhead->next;
            }

            // delete nth node from end of list
            ListNode *delNode = cur->next;
            cur->next = delNode->next;
            delete delNode;
            delNode = nullptr;
        }


        // avoid Wild pointer
        nAhead = nullptr;
        cur = nullptr;

        return head;

    }
};

TEST(leetcode_19_Remove_Nth_Node_From_End_of_List, leetcode_19_Remove_Nth_Node_From_End_of_List_1)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.print();

    rstList.insert(1);
    rstList.insert(2);
    rstList.insert(3);
    rstList.insert(5);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_19_Remove_Nth_Node_From_End_of_List(l.head, 2), rstList.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
