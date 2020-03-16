/**
 * 
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetecode_42_trapping_rain_water(vector<int>& height) {

        stack<int> st;
        int l = 0, res = 0, r = height.size();
        while(l < r){
            if(st.empty() || height[l] <= height[st.top()]){
                st.push(l++);
            }else{
                int t = st.top();st.pop();
                if(st.empty()) continue;
                res += (min(height[l], height[st.top()]) - height[t]) * (l-st.top() - 1);
            }
        }
        return res;

        int ans = 0;
        stack<int> s_height;
        for (int i = 0; i < height.size(); ++i) {
            if(s_height.empty()) {
                s_height.push(i);
                continue;
            }

            if(height[i] > height[s_height.top()]) {
                int max_index = i;
                int small_index;
                int mid_value;


                while(!s_height.empty()) {
                    small_index = s_height.top();

                    s_height.pop();
                    if (s_height.empty()) {

                        mid_value = height[small_index];
                        for (int j = small_index+1; j < max_index; ++j) {
                            ans += (mid_value - height[j]);
                            height[j] = mid_value;
                        }

                        s_height.push(max_index);
                        break;

                    } else {
                        if (height[i] > height[s_height.top()]) mid_value = height[s_height.top()];
                        else mid_value = height[max_index];

                        for (int j = s_height.top() + 1; j < max_index; ++j) {
                            ans += (mid_value - height[j]);
                            height[j] = mid_value;
                        }

                        if(mid_value==height[max_index]) {
                            s_height.push(max_index);
                            break;
                        }
                    }
                }


            }else{
                s_height.push(i);
            }

        }


        return ans;
    }
};

TEST(leetecode_42_trapping_rain_water, leetecode_42_trapping_rain_water_2)
{
    Solution s;
    vector<int> in1 = {0,7,1,4,6};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 7;
    EXPECT_EQ(s.leetecode_42_trapping_rain_water(in1), ans);
}

TEST(leetecode_42_trapping_rain_water, leetecode_42_trapping_rain_water_1)
{
    Solution s;
    vector<int> in1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 6;
    EXPECT_EQ(s.leetecode_42_trapping_rain_water(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
