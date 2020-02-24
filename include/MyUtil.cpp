//
// Created by aqiu on 2019-10-20.
//

#include <assert.h>
#include <time.h>
#include "MyUtil.h"

namespace MyUtil{


int *MyUtil::GenerateRandomArray(int n, int rangeL, int rangeR)
{
    assert( n > 0 && rangeL <= rangeR );

    int *arr = new int[n];

    srand(time(NULL));

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }

    return arr;
}

int *MyUtil::GenerateOrderedArrary(int n, int rangeL, int rangeR)
{
    assert( n > 0 );

    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }

    return arr;
}


void TimeCost::StartMS()
{
    m_startTime = std::chrono::steady_clock::now();
}

double TimeCost::EndMS()
{
    m_endTime = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(m_endTime - m_startTime).count();
}



}// namespace MyUtil
