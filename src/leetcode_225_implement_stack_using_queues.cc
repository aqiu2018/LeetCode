/**
 * 
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tmp;
        while(!q.empty()){
            tmp.push(q.front());
            q.pop();
        }

        q.push(x);
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }


    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;

};


class Solution
{
public:
    int leetcode_225_implement_stack_using_queues(vector<int> &nums) {
        return 1;
    }
};

TEST(leetcode_225_implement_stack_using_queues, leetcode_225_implement_stack_using_queues_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_225_implement_stack_using_queues(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
