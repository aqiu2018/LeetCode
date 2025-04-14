/**
 *
请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。它应该支持以下操作：get 和 put。

get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) - 如果键不存在，请设置或插入值。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最近 最少使用的键。
「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。

 

进阶：
你是否可以在 O(1) 时间复杂度内执行两项操作？

 

示例：

LFUCache cache = new LFUCache( 2 capacity (缓存容量) );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回 1
cache.put(3, 3);    // 去除 key 2
cache.get(2);       // 返回 -1 (未找到key 2)
cache.get(3);       // 返回 3
cache.put(4, 4);    // 去除 key 1
cache.get(1);       // 返回 -1 (未找到 key 1)
cache.get(3);       // 返回 3
cache.get(4);       // 返回 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lfu-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处
 *
 */
#include "headers.h"
class LFUCache {
public:
    LFUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        if(m.count(key) == 0) return -1;

        m_freq[m[key].second].erase(m_freqIterator[key]); // 从m_freq中删除对应 key
        m[key].second++; // m的freq增加
        m_freq[m[key].second].push_back(key); // 将key值，添加到新freq的列表中
        m_freqIterator[key] = --m_freq[m[key].second].end(); // 保存key值对应freq在list的位置

        if(m_freq[m_minFreq].size() == 0) m_minFreq++;// 如果最小频率已经删除，应该增加1

        return m[key].first;

    }

    void put(int key, int value) {
        if(m_capacity <= 0) return;

        if(get(key) != -1) {
            m[key].first = value;
            return;
        }

        if(m.size() >= m_capacity) {
            m.erase(m_freq[m_minFreq].front());
            m_freqIterator.erase(m_freq[m_minFreq].front());
            m_freq[m_minFreq].pop_front();
        }

        m[key] = {value, 1};
        m_freq[1].push_back(key);
        m_freqIterator[key] = --m_freq[1].end();
        m_minFreq = 1;
    }

    unordered_map<int, pair<int, int>> m; // key, value, freq
    unordered_map<int, list<int>> m_freq; // freq, <key>
    unordered_map<int, list<int>::iterator > m_freqIterator; // key, m_freq iterator

    int m_capacity;
    int m_minFreq;
};

class Solution
{
public:
    int leetcode_460_lfu_cache(vector<int> &nums) {
        LFUCache* obj = new LFUCache(3);
        obj->put(5,1);
        int param_1 = obj->get(5);
        obj->put(6,2);
        param_1 = obj->get(6);
        obj->put(7,3);
        obj->put(8,4);


        return 1;
    }
};

TEST(leetcode_460_lfu_cache, leetcode_460_lfu_cache_1)
{
    Solution s;
    int i = INT_MAX;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_460_lfu_cache(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
