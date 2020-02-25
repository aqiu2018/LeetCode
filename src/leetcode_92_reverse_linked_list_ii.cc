/**
 * 
 * Copyright (c) 2018
 * 
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    ListNode* leetcode_92_reverse_linked_list_ii(ListNode* head, int m, int n) {

        ListNode* m_pre=head, *m_cur=head, *n_cur=head, *n_next= nullptr;
        for (int i = 0; i < n; ++i) {
            if(i<m-2) m_pre = m_pre->next;
            if(i<m-1) m_cur = m_cur->next;
            if(i<n-1) n_cur = n_cur->next;
            if(i==n-1 && n_cur->next != nullptr) n_next = n_cur->next;
        }

        ListNode *pre = n_next, *next = nullptr;
        while(m_cur != n_cur && m_cur->next != nullptr){
            next = m_cur->next;
            m_cur->next = pre;

            pre = m_cur;
            m_cur = next;
        }
        m_cur->next = pre;
        if(m==1) return m_cur;

        m_pre->next= m_cur;
        return head;
    }
};
//        cout << "3!!!"<<endl;
//        print_list(head);

TEST(leetcode_92_reverse_linked_list_ii, leetcode_92_reverse_linked_list_ii_1)
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
    rstList.insert(4);
    rstList.insert(3);
    rstList.insert(2);
    rstList.insert(5);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_92_reverse_linked_list_ii(l.head, 2, 4), rstList.head), true);
}

TEST(leetcode_92_reverse_linked_list_ii, leetcode_92_reverse_linked_list_ii_2)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.print();

    rstList.insert(5);
    rstList.insert(4);
    rstList.insert(3);
    rstList.insert(2);
    rstList.insert(1);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_92_reverse_linked_list_ii(l.head, 1, 5), rstList.head), true);
}


TEST(leetcode_92_reverse_linked_list_ii, leetcode_92_reverse_linked_list_ii_3)
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
    rstList.insert(4);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_92_reverse_linked_list_ii(l.head, 4, 5), rstList.head), true);
}



TEST(leetcode_92_reverse_linked_list_ii, leetcode_92_reverse_linked_list_ii_4)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.print();

    rstList.insert(1);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_92_reverse_linked_list_ii(l.head, 1, 1), rstList.head), true);
}


TEST(leetcode_92_reverse_linked_list_ii, leetcode_92_reverse_linked_list_ii_5)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.print();

    rstList.insert(1);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_92_reverse_linked_list_ii(l.head, 1, 1), rstList.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
