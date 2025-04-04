/**
 * 
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 缓存容量 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
 * 
 */
#include "headers.h"

class LRUCache {
public:
    // typedef std::tuple<int, int, int> Mytuple;
    list<pair<int, int> > m_list;
    unordered_map<int, list<pair<int, int> >::iterator > m_map;
    int m_capacity;

    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        auto it = m_map.find(key);
        if(it == m_map.end()) return -1;

        m_list.splice(m_list.begin(), m_list, it->second);

        return it->second->second;
    }

    void put(int key, int value) {
        auto it = m_map.find(key);
        if(it != m_map.end()) m_list.erase(it->second);

        m_list.push_front(make_pair(key, value));
        m_map[key] = m_list.begin();

        if(m_map.size() > m_capacity) {
            int n = m_list.rbegin()->first;
            m_list.pop_back();
            m_map.erase(n);
        }
    }
};

class Solution
{
public:
    int leetcode_146_lru_cache(vector<int> &nums) {
        return 1;
    }
};

TEST(leetcode_146_lru_cache, leetcode_146_lru_cache_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_146_lru_cache(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
