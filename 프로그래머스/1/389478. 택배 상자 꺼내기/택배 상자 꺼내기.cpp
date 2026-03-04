#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<vector<int>> Boxes;
    
    int OutSize = n / w;
    if(n % w != 0)
        OutSize++;
    
    Boxes.resize(OutSize);
    
    for(int i = 0 ; i < OutSize; ++i)
    {
        Boxes[i].reserve(w);
        
        for(int j = 1; j <= w; ++j)
        {
            int Temp = i * w + j;
            if(Temp > n)
                Temp = -1;
            Boxes[i].push_back(Temp);
        }
        
        if(i % 2 != 0)
            reverse(Boxes[i].begin(),Boxes[i].end());
        
    }
    reverse(Boxes.begin(),Boxes.end());
    
    int Index = 0;
    for(int i = 0; i < OutSize; ++i)
    {
        bool Find = false;
        for(int j = 0; j < w; ++j)
        {
            if(Boxes[i][j] == num)
            {
                Index = j;   
                Find=true;
                break;
            }
        }
        if(Find)
            break;
    }

    for(int i = 0; i < OutSize; ++i)
    {
        int FindIndex = Index;
        
        if(Boxes[i][FindIndex] != -1)
        {
            answer++;
        }
        
        if(Boxes[i][FindIndex] == num)
            break;
    }

    
    return answer;
}