/**
 * 
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。

示例 1：
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

示例 2：
输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
 

提示：

给定链表的结点数介于 1 和 100 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/middle-of-the-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
//    int leetcode_876_middle_of_the_linked_list(vector<int> &nums) {
    ListNode* leetcode_876_middle_of_the_linked_list(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;

//        int n = 1;
//        ListNode* ite = head;
//        while(ite!= nullptr && ite->next != nullptr) {
//            n++;
//            ite = ite->next;
//        }
//
//        int i = 1;
//        ite = head;
//        while(i++ <= n/2){
//            ite = ite->next;
//        }
//        return ite;
    }
};

TEST(leetcode_876_middle_of_the_linked_list, leetcode_876_middle_of_the_linked_list_1)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.insert(3);
    l.insert(2);
    l.insert(4);
    l.print();

    rstList.insert(2);
    rstList.insert(4);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_876_middle_of_the_linked_list(l.head), rstList.head), true);

}

TEST(leetcode_876_middle_of_the_linked_list, leetcode_876_middle_of_the_linked_list_2)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.print();

    rstList.insert(1);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_876_middle_of_the_linked_list(l.head), rstList.head), true);

}

TEST(leetcode_876_middle_of_the_linked_list, leetcode_876_middle_of_the_linked_list_3)
{
    Solution s;
    List l, rstList;
    l.print();

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_876_middle_of_the_linked_list(l.head), rstList.head), true);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
