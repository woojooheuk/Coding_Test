#include <string>
#include <vector>
#include<algorithm>
#include<set>
#include<map>
#include<iostream>
#include<iterator>

using namespace std;
    
vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    //9,10,11,12,13 시간 초과.
    map<string,int> Rank;
    
    //Rank의 second에 players의 등수를 넣어놓고 직접 접근해서 바꾸고 Rank도 바꾸기?
    int Size = players.size();
    
    for(int i = 0; i < Size; ++i)
    {
        Rank.emplace(players[i],i);
    }
    
    Size = callings.size();
    for(int i = 0; i < Size; ++i)
    {
        auto iter = Rank.find(callings[i]);
        
        if(iter == Rank.end())
            continue;
        int Rate = iter->second;
        iter->second-=1;
        iter = Rank.find(players[Rate - 1]);
        if(iter != Rank.end())
        {
            iter->second += 1;
        }
        
        swap(players[Rate],players[Rate - 1]);
        
    }
    answer = players;
    
    return answer;
}   