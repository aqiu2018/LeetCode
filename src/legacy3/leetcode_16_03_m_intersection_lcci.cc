/**
 * 
给定两条线段（表示为起点start = {X1, Y1}和终点end = {X2, Y2}），如果它们有交点，请计算其交点，没有交点则返回空值。

要求浮点型误差不超过10^-6。若有多个交点（线段重叠）则返回 X 值最小的点，X 坐标相同则返回 Y 值最小的点。

 

示例 1：

输入：
line1 = {0, 0}, {1, 0}
line2 = {1, 1}, {0, -1}
输出： {0.5, 0}
示例 2：

输入：
line1 = {0, 0}, {3, 3}
line2 = {1, 1}, {2, 2}
输出： {1, 1}
示例 3：

输入：
line1 = {0, 0}, {1, 1}
line2 = {1, 0}, {2, 1}
输出： {}，两条线段没有交点
 

提示：

坐标绝对值不会超过 2^7
输入的坐标均是有效的二维坐标

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<double> leetcode_16_03_m_intersection_lcci(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {

        // https://blog.csdn.net/yangtrees/article/details/7965983
        /**
         * 两条线段的斜率和与y轴的交点 分别位 a1、a2、b1、b2
         *  1 平行
         *      1 b1 != b2 ===> 空解
         *      2 b1 == b2 ===> 取重叠区域的最小值
         *
         *  2 不平行
         *      固定a1， 分别从a2线的两个端点，按a1的斜率，找到与y轴的两个交点 b3和b4
         *      1 (b3 > b1 && b4 > b1) || (b3 < b1 && b4 < b1) ===> 空解
         *      2 计算交点 ===>
         * */

        /**
         * Ax + By + C = 0
         * */
        int A1 = end1[1] - start1[1]; // Y2 - Y1
        int B1 = start1[0] - end1[0]; // X1 - X2
        int C1 = end1[0]*start1[1] - start1[0]*end1[1]; // X2*Y1 - X1*Y2

        int A2 = end2[1] - start2[1]; // Y2 - Y1
        int B2 = start2[0] - end2[0]; // X1 - X2
        int C2 = end2[0]*start2[1] - start2[0]*end2[1]; // X2*Y1 - X1*Y2

        int C3 = - (A1 * start2[0] + B1 * start2[1]);
        int C4 = - (A1 * end2[0] + B1 * end2[1]);

        double eps = 1e-6;
        // 1 平行
        double D = A1 * B2 - A2 * B1; // D为0时，表示两直线重合; 斜率相等 double(B1/A1) - double(B2/A2) = 0

        // 1.1 平行，但是与y轴交点不相等，或者两线段没有重叠区域
        // if(D < eps && double(C1/A1) - double(C2/A2) >  eps) return vector<double>();
        if((abs(D) < eps) && ((abs(double(C1*A2 - C2*A1)) > eps) ||
                min(start1[0], end1[0]) > max(start2[0], end2[0]) ||
                max(start1[0], end1[0]) < min(start2[0], end2[0]) ||
                min(start1[1], end1[1]) > max(start2[1], end2[1]) ||
                max(start1[1], end1[1]) < min(start2[1], end2[1])
                )) return vector<double>();

        // 1.2 平行，排序后取第二个点即为解
        if(abs(D) < eps) {
            vector<vector<int>> points;
            points.push_back(start1);
            points.push_back(end1);
            points.push_back(start2);
            points.push_back(end2);
            sort(points.begin(), points.end());
            return vector<double>{double(points[1][0]), double(points[1][1])};
        }

        // 2 不平行
        if((C3 < C1 && C4 < C1) || (C3 > C1 && C4 > C1)) return vector<double>();
        /**
         * x = (b1*c2 – b2*c1)/D
         * y = (a2*c1 – a1*c2)/D
         * D = a1*b2 – a2*b1， (D为0时，表示两直线重合)
         * */
        //double D = A1 * B2 - A2 * B1;
        double x = (B1*C2 - B2*C1)/D;
        double y = (A2*C1 - A1*C2)/D;

        // 2.1 相交却不在线段范围中
        if((x-start1[0])*(x-end1[0])>0 || (y-start1[1])*(y-end1[1])>0 ||
            (x-start2[0])*(x-end2[0])>0 || (y-start2[1])*(y-end2[1])>0)
            return vector<double>();

        // 2.2 相交点满足条件
        return vector<double>{x, y};
    }
};

TEST(leetcode_16_03_m_intersection_lcci, leetcode_16_03_m_intersection_lcci_5)
{
    Solution s;
    vector<int> start1 = {11,28};
    vector<int> end1 = {30,15};

    vector<int> start2 = {35,7};
    vector<int> end2 = {93,-1};

    vector<double> ans = {};
    EXPECT_EQ(s.leetcode_16_03_m_intersection_lcci(start1, end1, start2, end2), ans);
}

TEST(leetcode_16_03_m_intersection_lcci, leetcode_16_03_m_intersection_lcci_4)
{
    Solution s;
    vector<int> start1 = {0, 0};
    vector<int> end1 = {0, 1};

    vector<int> start2 = {0, 2};
    vector<int> end2 = {0, 3};

    vector<double> ans = {};
    EXPECT_EQ(s.leetcode_16_03_m_intersection_lcci(start1, end1, start2, end2), ans);
}

TEST(leetcode_16_03_m_intersection_lcci, leetcode_16_03_m_intersection_lcci_3)
{
    Solution s;
    vector<int> start1 = {0, 0};
    vector<int> end1 = {1, 1};

    vector<int> start2 = {1, 0};
    vector<int> end2 = {2, 1};

    vector<double> ans = {};
    EXPECT_EQ(s.leetcode_16_03_m_intersection_lcci(start1, end1, start2, end2), ans);
}

TEST(leetcode_16_03_m_intersection_lcci, leetcode_16_03_m_intersection_lcci_2)
{
    Solution s;
    vector<int> start1 = {0, 0};
    vector<int> end1 = {3, 3};

    vector<int> start2 = {1, 1};
    vector<int> end2 = {2, 2};

    vector<double> ans = {1, 1};
    EXPECT_EQ(s.leetcode_16_03_m_intersection_lcci(start1, end1, start2, end2), ans);
}

TEST(leetcode_16_03_m_intersection_lcci, leetcode_16_03_m_intersection_lcci_1)
{
    Solution s;
    vector<int> start1 = {0, 0};
    vector<int> end1 = {1, 0};

    vector<int> start2 = {1, 1};
    vector<int> end2 = {0, -1};

    vector<double> ans = {0.5, 0};
    EXPECT_EQ(s.leetcode_16_03_m_intersection_lcci(start1, end1, start2, end2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
