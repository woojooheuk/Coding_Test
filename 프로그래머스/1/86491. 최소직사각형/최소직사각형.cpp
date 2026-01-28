#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {

    int answer = 0;
    
    int Size1 = sizes.size();
    int Size2 = 2;
    
    int Long = 0;

    vector<int> Shorts;
    
    for(int i = 0; i < Size1; ++i)
    {
        Long = max(Long,max(sizes[i][0],sizes[i][1]));
        Shorts.push_back(min(sizes[i][0],sizes[i][1]));
    }

    int Short = 0;
    int Size3 = Shorts.size();
    for(int i = 0; i < Size3; ++i)
    {
        Short = max(Short, Shorts[i]);
    }
    answer = Long * Short;
    return answer;
}