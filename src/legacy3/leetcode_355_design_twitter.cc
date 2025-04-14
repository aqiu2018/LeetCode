/**
 * 
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：

postTweet(userId, tweetId): 创建一条新的推文
getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
follow(followerId, followeeId): 关注一个用户
unfollow(followerId, followeeId): 取消关注一个用户
示例:

Twitter twitter = new Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);

// 用户1关注了用户2.
twitter.follow(1, 2);

// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);

// 用户1取消关注了用户2.
twitter.unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-twitter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Twitter {
public:
    int m_index = 0;
    map<int, set<int>> m_subscibe; // followerId, followeeId
    map<int, list<pair<int, int>>> m_tweet; // followerId, <index, tweetId>
    priority_queue<pair<int, int>> m_priorityQueue; // <index, tweetId>
    /** Initialize your data structure here. */
    Twitter() {}

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (m_tweet.find(userId) == m_tweet.end())
            m_tweet[userId] = list<pair<int, int>>{{m_index++, tweetId}};
        else {
            m_tweet[userId].insert(m_tweet[userId].begin(), make_pair(m_index++, tweetId));
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {

        while (!m_priorityQueue.empty()) m_priorityQueue.pop();
        if (m_subscibe.find(userId) != m_subscibe.end()) {
            for (auto followee : m_subscibe[userId]) {
                list<pair<int, int>>::iterator iter =  m_tweet[followee].begin();
                for (int j = 0; j < m_tweet[followee].size() && j < 10; ++j) {
                    m_priorityQueue.push(*iter);
                    iter++;
                }
            }
        }

        if(m_tweet.find(userId) != m_tweet.end()){
            list<pair<int, int>>::iterator iter =  m_tweet[userId].begin();
            for (int j = 0; j < m_tweet[userId].size() && j < 10; ++j) {
                m_priorityQueue.push(*iter);
                iter++;
            }
        }


        vector<int> ans;
        int size = m_priorityQueue.size();
        for (int i = 0; i < size && i < 10; ++i) {
            pair<int, int> temp = m_priorityQueue.top(); m_priorityQueue.pop();
            ans.push_back(temp.second);
        }

        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        if (m_subscibe.find(followerId) == m_subscibe.end()) m_subscibe[followerId] = set<int>{followeeId};
        else m_subscibe[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto iter = m_subscibe.find(followerId);
        if (iter != m_subscibe.end()) {
            auto iter2 = m_subscibe[followerId].find(followeeId);
            if (iter2 != m_subscibe[followerId].end()) m_subscibe[followerId].erase(iter2);
        }
    }


};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

class Solution
{
public:
    int leetcode_355_design_twitter(vector<int> &nums) {

        int userId = 1;
        int followerId = userId, followeeId = 2;
        Twitter* obj1 = new Twitter();

        obj1->postTweet(1,5);
        vector<int> param_2 = obj1->getNewsFeed(1);

        log(INFO_) << "useid " << userId << " ";
        copy(param_2.begin(), param_2.end(), log(" "));
        log() << endl;

        obj1->follow(1,1);
        param_2 = obj1->getNewsFeed(1);
        log(INFO_) << "useid " << userId << " ";
        copy(param_2.begin(), param_2.end(), log(" "));
        log() << endl;




        Twitter* obj = new Twitter();
        obj->postTweet(1,1);
        param_2 = obj->getNewsFeed(1);

        log(INFO_) << "useid " << userId << " ";
        copy(param_2.begin(), param_2.end(), log(" "));
        log() << endl;

        obj->follow(2,1);
        param_2 = obj->getNewsFeed(2);
        log(INFO_) << "useid " << userId << " ";
        copy(param_2.begin(), param_2.end(), log(" "));
        log() << endl;


        obj->unfollow(2,1);
        param_2 = obj->getNewsFeed(2);
        log(INFO_) << "useid " << userId << " ";
        copy(param_2.begin(), param_2.end(), log(" "));
        log() << endl;

//        obj->postTweet(userId,5);
//        vector<int> param_2 = obj->getNewsFeed(userId);
//
//        log(INFO_) << "useid " << userId << " ";
//        copy(param_2.begin(), param_2.end(), log(" "));
//        log() << endl;
//
//        obj->follow(followerId,followeeId);
//        obj->postTweet(followeeId,6);
//        param_2 = obj->getNewsFeed(userId);
//        log(INFO_) << "useid " << userId << " ";
//        copy(param_2.begin(), param_2.end(), log(" "));
//        log() << endl;
//
//
//        obj->unfollow(followerId,followeeId);
//        param_2 = obj->getNewsFeed(userId);
//        log(INFO_) << "useid " << userId << " ";
//        copy(param_2.begin(), param_2.end(), log(" "));
//        log() << endl;

        return 1;
    }
};

TEST(leetcode_355_design_twitter, leetcode_355_design_twitter_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_355_design_twitter(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
