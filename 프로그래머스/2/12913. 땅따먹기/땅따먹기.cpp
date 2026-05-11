#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;

    int ColSize = land[0].size();
    int RowSize = land.size();
    
    vector<int> DPPoints(RowSize, 0);
    
    DPPoints = land[0];

    int PrevCol = -1;
    int Max1 = 0;
    int Max2 = 0;
    
    for(int i = 1; i < RowSize; ++i)
    {
        vector<int> Temp = land[i];
        
        for(int j = 0; j < ColSize; ++j)
        {
            int PrevNum = DPPoints[j];
            if(Max1 <= PrevNum)
            {
                Max2 = Max1;
                Max1 = PrevNum;
                PrevCol = j;
            }
            else
            {
                Max2 = max(PrevNum, Max2);
            }
        }
        
        for(int j = 0; j < ColSize; ++j)
        {
            if(PrevCol == j)
                DPPoints[j] = Max2 + Temp[j];
            else
                DPPoints[j] = Max1 + Temp[j];
        }
    }
   
    answer = *max_element(DPPoints.begin(),DPPoints.end());
    
    return answer;
}