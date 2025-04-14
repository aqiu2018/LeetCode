/**
 * 
你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

示例 1:
输入: 2, [[1,0]]
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。

 示例 2:
输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。

 提示：
输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
1 <= numCourses <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Graph{
public:
    int m_vertexNum;
    list<int> *m_adj;
    void topologicalSortUtil(int v, bool visited[], stack<int>& stack);

    Graph(int vertexNum);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int vertexNum)
{
    this->m_vertexNum = vertexNum;
    m_adj = new list<int>[vertexNum];
}

void Graph::addEdge(int v, int w)
{
    m_adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool *visited, stack<int> &stack)
{
    visited[v] = true;
    
    list<int>::iterator i;
    for (i = m_adj[v].begin(); i != m_adj[v].end(); ++i) {
        if (visited[*i] == false) {
            topologicalSortUtil(*i, visited, stack);
        }
    }

    stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> s;

    bool *visited = new bool[m_vertexNum];
    for (int i = 0; i < m_vertexNum; ++i) {
        visited[i] = false;
    }
    // vector<bool> visited(m_vertexNum, false);

    for (int j = 0; j < m_vertexNum; ++j) {
        if (visited[j] == false) {
            topologicalSortUtil(j, visited, s);
        }
    }

    while (s.empty() == false) {
        cout << s.top() << " ";
        s.pop();
    }
}

class Solution
{
public:
    bool leetcode_207_course_schedule(int numCourses, vector<vector<int>>& prerequisites) {

        /*
        // Create a graph given in the above diagram
        Graph g(6);
        g.addEdge(5, 2);
        g.addEdge(5, 0);
        g.addEdge(4, 0);
        g.addEdge(4, 1);
        g.addEdge(2, 3);
        g.addEdge(3, 1);

        cout << "Following is a Topological Sort of the given graph \n";
        g.topologicalSort();
        cout << endl;
        */

        unordered_map<int, vector<int>> graph; // course, adj
        vector<int> indegree(numCourses, 0); // indegreee
        stack<int> s;
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) s.push(i);
        }
        
        while (!s.empty()) {
            int index = s.top(); s.pop();
            numCourses--;
            for (int i = 0; i < graph[index].size(); ++i) {
                indegree[graph[index][i]]--;
                if(indegree[graph[index][i]] == 0) s.push(graph[index][i]);
            }
        }

        return numCourses==0;
    }
};


TEST(leetcode_207_course_schedule, leetcode_207_course_schedule_2)
{
    Solution s;
    vector<vector<int>> in2 = {{1,0}, {0,1}};
    int in1 = 2;
    bool ans2 = false;
    EXPECT_EQ(s.leetcode_207_course_schedule(in1, in2), ans2);

}

TEST(leetcode_207_course_schedule, leetcode_207_course_schedule_1)
{
    Solution s;
    vector<vector<int>> in2 = {{1,0}};
    int in1 = 2;
    bool ans2 = true;
    EXPECT_EQ(s.leetcode_207_course_schedule(in1, in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
