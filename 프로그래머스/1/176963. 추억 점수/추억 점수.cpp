#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    //photo에서 name을 찾고, 그 name이 yearning에 해당하는 점수.
    
    map<string, int> nameyearning;
    int Size = name.size();
    for(int i = 0; i < Size; ++i)
        nameyearning.emplace(name[i],yearning[i]);
    Size = photo.size();
    
    
    //그리움 값의 총합.
    for(int i = 0; i < Size; ++i)
    {
        auto Photo = photo[i];
        
        int Size2 = Photo.size();
        
        int score = 0;
        
        for(int j = 0; j < Size2; ++j)
        {
            auto iter = nameyearning.find(Photo[j]);
             
            //이 람다식이 똑같이 맨 앞에 있는 놈만 계속 찾음.

            if(iter == nameyearning.end())
                continue;
            
            score += iter->second;
        }
        
        answer.push_back(score);
    }
    return answer;
}