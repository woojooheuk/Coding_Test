#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> Percent;
    
    int Num = 0;
    sort(stages.begin(), stages.end());
    
    if(stages.back() > N)
    {
        Num += count(stages.begin(), stages.end(), stages.back());
        for(int i = 0; i < Num; ++i)
            stages.pop_back();
    }
    //가장 큰 인원
    for(int i = N; i > 0; --i)
    {
        //14,26
        auto iter = find_if(stages.begin(),stages.end(),[&](int A){
           return i == A; 
        });
        
        if(iter == stages.end())
        {
            Percent.push_back({i, 0});
            continue;
        }
        
        int Count = count(stages.begin(), stages.end(), i);
        Num += Count;
        
        Percent.push_back({i, static_cast<float>(Count) / Num});

    }

    sort(Percent.begin(),Percent.end(),[&](auto& A, auto& B){
        if(A.second == B.second)
            return A.first<B.first;
        else
            return A.second>B.second;
    });
    
    for(auto& iter : Percent)
    {
        cout << iter.second <<": " << iter.first<<endl;
        answer.push_back(iter.first);
    }
    
    //사람이 없으면 실패율 0. 
    
    
    return answer;
}