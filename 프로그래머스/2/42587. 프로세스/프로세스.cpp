#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> Temp;
    
    int Size = priorities.size();
    for(int i = 0; i < Size; ++i)
    {
        Temp.push({ i, priorities[i] });
    }
    
    sort(priorities.rbegin(),priorities.rend());
    
    while(true)
    {
        pair<int,int> T = Temp.front();
        Temp.pop();
     
        if(priorities[answer] == T.second)
        {
            answer++;
            cout <<T.first<<endl;
            
            if(location == T.first)
                break;
        }
        Temp.push(T);
    }
    
    
    
    return answer;
}