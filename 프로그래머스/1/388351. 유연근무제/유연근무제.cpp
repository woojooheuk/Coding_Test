#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    int Num = schedules.size();
    
    for(int i =0; i < Num; ++i)
    {
        int Limit = schedules[i] + 10;
        if(Limit % 100 >= 60)
        {
            Limit += 100;
            Limit -= 60;
        }
        bool IsOk = true;
        for(int j = 0; j < 7; ++j)
        {
            if(!IsOk)
                break;
            int Weekend = j + startday;
            if(Weekend > 7)
                Weekend -= 7;
            if(Weekend == 6 || Weekend == 7)
            {
                continue;
            }
            int Time = timelogs[i][j];
            
            if(Limit < Time)
            {
                IsOk = false;
                cout << Limit <<" " <<Time<<endl;
            }    
        }
        
        if(IsOk)
        {
            answer++;
        }
    }
    
    return answer;
}