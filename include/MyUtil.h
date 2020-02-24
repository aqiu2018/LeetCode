//
// Created by aqiu on 2019-10-20.
//

#ifndef LEETCODE_MYUTIL_H
#define LEETCODE_MYUTIL_H

#include <chrono>

namespace MyUtil {
    int *GenerateRandomArray(int n, int rangeL, int rangeR);
    int *GenerateOrderedArrary(int n, int rangeL, int rangeR);

    /*----------------- TimeCost start -----------------*/
    class TimeCost
    {
    public:
        void StartMS();
        double EndMS();

    private:
        std::chrono::steady_clock::time_point m_startTime;
        std::chrono::steady_clock::time_point m_endTime;
    };

    // get global standard logger, with sink std::clog
    inline TimeCost& SingleTimeCost() {
        static TimeCost timeCost;
        return timeCost;
    }

    inline void StartMS() { SingleTimeCost().StartMS(); }
    inline double EndMS() { return SingleTimeCost().EndMS(); }

    /*----------------- TimeCost end -----------------*/


}

#endif //LEETCODE_MYUTIL_H
