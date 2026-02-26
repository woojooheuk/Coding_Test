#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    //가려져서 안보이는 글자 = 0
    //lottos에 있는 숫자들 중 win_nums에서 몇 개 겹치나 확인.
    //몇 개 가려져있나 확인 후 제일 많이 겹쳤을 경우를 가정.
    //하나도 안맞췄으면 1 하나 늘어날 때마다 1 증가.
    //사실상 0의 개수는 정답의 수로 가정.
    int WinSize = win_nums.size();
    int Min = 7;
    //Min을 7으로 설정. 하나 맞을 때마다 -1. 하나도 못맞추면 6으로.
    
    for(int i = 0; i < WinSize; ++i)
    {
        auto iter = find_if(lottos.begin(),lottos.end(),[&](int A){
            return A == win_nums[i];
        });
        
        if(iter != lottos.end())
        {
            --Min;
        }
    }
    int Max = Min - count(lottos.begin(),lottos.end(), 0);
    
    if(Max > 6)
        Max = 6;
    else if(Max < 1)
        Max = 1;
    
    if(Min ==7)
        Min = 6;
    answer.push_back(Max);
    answer.push_back(Min);
    
    return answer;
}