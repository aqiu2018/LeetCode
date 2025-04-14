/**
 * 
公司共有 n 个项目和  m 个小组，每个项目要不没有归属，要不就由其中的一个小组负责。
我们用 group[i] 代表第 i 个项目所属的小组，如果这个项目目前无人接手，那么 group[i] 就等于 -1。（项目和小组都是从零开始编号的）

 请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：
同一小组的项目，排序后在列表中彼此相邻。
项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，其中 beforeItems[i] 表示在进行第 i 个项目前（位于第 i 个项目左侧）应该完成的所有项目。

 结果要求：
如果存在多个解决方案，只需要返回其中任意一个即可。
如果没有合适的解决方案，就请返回一个 空列表。

 

示例 1：
输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
输出：[6,3,4,1,5,2,0,7]

 示例 2：
输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
输出：[]
解释：与示例 1 大致相同，但是在排序后的列表中，4 必须放在 6 的前面。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"
struct CmpByValue{
    bool operator()(pair<int, pair<int, vector<int>>> &a, pair<int, pair<int, vector<int>>> &b){
        return a.second.first<b.second.first;
    }
};
class Solution
{
public:
    vector<int> leetcode_1203_sort_items_by_groups_respecting_dependencies(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        // n 项目个数  m 小组个数
        for(int &groupIndex : group){//1 没有分组的归为一组，组号为m
            if(groupIndex == -1) groupIndex = m;
        }
        m += 1;

        vector<int> ans;
        vector<int> groupInDegree(m, 0); // 小组入度
        vector<vector<int>> groupItems(m, vector<int>()); //groupItems[j][i]存在表示项目i属于j组

        vector<int> itemInDegree(n, 0); // 项目入度
        vector<vector<int>> graph(n); // 项目出边

        for (int i = 0; i < n; ++i) {
            int currentGroup = group[i];
            groupItems[currentGroup].push_back(i);//groupItems[j][i]存在表示项目i属于j组
            for(int before : beforeItems[i]){
                graph[before].push_back(i); // 项目出边

                int beforeGroup = group[before];
                if(beforeGroup != currentGroup){
                    groupInDegree[currentGroup] += 1; // 小组入度
                }
            }
            itemInDegree[i] = beforeItems[i].size();// 项目入度
        }


        queue<int> groupQueue;
        queue<int> itemQueue;
        for (int j = 0; j < m; ++j) {
            if(groupInDegree[j] == 0) groupQueue.push(j); // 3 组入度为0的入队列
        }

        while(!groupQueue.empty()) {
            int currentGroup = groupQueue.front(); groupQueue.pop();
            for (auto itemIndex : groupItems[currentGroup]) { //找到当前组入度为0的项目
                if(itemInDegree[itemIndex] == 0) itemQueue.push(itemIndex);
            }

            while(!itemQueue.empty()){
                int currentItem = itemQueue.front(); itemQueue.pop();
                ans.push_back(currentItem);
                for (auto next : graph[currentItem]) {
                    itemInDegree[next]--; // 出边节点的入度-1
                    //后继项目入度为0，且后继项目与当前项目在同一组
                    if(itemInDegree[next] == 0 && group[next] == group[currentItem])
                        itemQueue.push(next);

                    groupInDegree[group[next]]--;
                    //后继项目与当前项目不在同一组，后继项目所在组入度-1，如果-1后 组入度0，投入组队列
                    if(groupInDegree[group[next]] == 0 && group[next] != group[currentItem])
                        groupQueue.push(group[next]);
                }
            }

        }

        return ans.size() == n ? ans : vector<int>();

/*
        vector<int> ans;
        vector// 小组入度<int> inDegree(n, 0);
        vector<vector<int>> graph(n);

        // 1 初始化入度和出边
        for (int i = 0; i < beforeItems.size(); i++) {
            inDegree[i] = beforeItems[i].size();// 入度
            for (auto j : beforeItems[i]) {
                graph[j].push_back(i); // 出边
            }
        }
        // 2 先按照 依赖组的个数 大到小排序
//        map<int, pair<int, vector<int>>> mm;//group[i], cnt, i
//        for (int k = 0; k < group.size(); ++k) {
//            if(mm.count(group[k]) == 0) mm.insert(make_pair(group[k], make_pair(1, vector<int>{k})));
//            else {
//                mm[group[k]].first++;
//                mm[group[k]].second.push_back(k);
//            }
//        }
//
//        vector< pair<int, pair<int, vector<int>>> > vv(mm.begin(), mm.end());
//        sort(vv.begin(), vv.end(), CmpByValue());
//
//        deque<int> dq;
//        for (int l = 0; l < vv.size(); ++l) {
//            for (auto j : vv[l].second.second) {
//                if(inDegree[j] == 0 && group[j] == -1) dq.push_back(j);
//                else if(inDegree[j] == 0) dq.push_back(j);
//
//                if(!dq.empty()) cout<< " top " << dq.front() << endl;
//            }
//        }


        deque<int> dq;
        for (int j = 0; j < n; ++j) {
            if(inDegree[j] == 0 && group[j] == -1) dq.push_back(j);
            else if(inDegree[j] == 0) dq.push_front(j);

            if(!dq.empty()) cout<< " top " << dq.front() << endl;
        }


        int cnt = 0;
        while(!dq.empty()){
            int index = dq.front();
            dq.pop_front();
            ans.push_back(index);
            cnt++;

            for (int i = 0; i < graph[index].size(); ++i) {
                inDegree[ graph[index][i] ]--;
                if(inDegree[graph[index][i]] == 0) dq.push_front(graph[index][i]);
            }
        }

        if(cnt == n) return ans;
        else return vector<int>{};
*/
    }
};

TEST(leetcode_1203_sort_items_by_groups_respecting_dependencies, leetcode_1203_sort_items_by_groups_respecting_dependencies_3)
{
    Solution s;
    int in1 = 5, in2 = 5;
    vector<int> group = {2,0,-1,3,0};
    vector<vector<int>> in3 = {
            {2,1,3},{2,4},{},{},{}
    };
    vector<int> ans{3,2,4,1,0};
    EXPECT_EQ(s.leetcode_1203_sort_items_by_groups_respecting_dependencies(in1, in2, group, in3), ans);
}

TEST(leetcode_1203_sort_items_by_groups_respecting_dependencies, leetcode_1203_sort_items_by_groups_respecting_dependencies_1)
{
    Solution s;
    int in1 = 8, in2 = 2;
    vector<int> group = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> in3 = {
            {},{6},{5},{6},{3},{},{4},{}
    };
    vector<int> ans;
    EXPECT_EQ(s.leetcode_1203_sort_items_by_groups_respecting_dependencies(in1, in2, group, in3), ans);
}

TEST(leetcode_1203_sort_items_by_groups_respecting_dependencies, leetcode_1203_sort_items_by_groups_respecting_dependencies_2)
{
    Solution s;
    int in1 = 8, in2 = 2;
    vector<int> group = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> in3 = {
            {},{6},{5},{6},{3,6},{},{},{}
    };
    vector<int> ans{6,3,4,1,5,2,0,7};
    EXPECT_EQ(s.leetcode_1203_sort_items_by_groups_respecting_dependencies(in1, in2, group, in3), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
