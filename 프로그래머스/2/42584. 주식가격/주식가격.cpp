#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.reserve(prices.size());
    //가격이 떨어지지 않은 시간이 몇초인지?
    //배열 기준 내 뒤에 나보다 작은 숫자가 몇 개의 인덱스 이후에 나오는 지 쓰는 것.
    
    //min_element로?
    
    int Num = 0;
    for(auto iter = prices.begin(); iter != prices.end(); ++iter)
    {
        auto Target = find_if(iter, prices.end(), [&](int A){
            return *iter > A;
        });
        //나보다 작은 애 찾기
        
        if(Target == prices.end())
            Num = distance(iter, Target) - 1;
        else
            Num = distance(iter, Target);
        
        answer.push_back(Num);
    }
    
    
    return answer;
}