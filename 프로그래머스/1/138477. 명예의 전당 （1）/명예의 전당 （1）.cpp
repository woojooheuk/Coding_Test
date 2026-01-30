#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
    
using namespace std;
    
vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    int Days = score.size();

    if(k > Days)
        k = Days;
    vector<int> Temp;
    Temp.reserve(k);
    for(int i = 0; i < k; ++i)
    {
        Temp.push_back(score[i]);
        auto iter = min_element(Temp.begin(),Temp.end());
        
        answer.push_back(*iter);
    }
    
    for(int i = k; i < Days; ++i)
    {
        auto iter = min_element(Temp.begin(),Temp.end());
        
        if(*iter < score[i])
        {
            *iter = score[i];
        }
        
        iter = min_element(Temp.begin(),Temp.end());
        
        answer.push_back(*iter);
    }
    //K가 score보다 클 때 
    return answer;
}