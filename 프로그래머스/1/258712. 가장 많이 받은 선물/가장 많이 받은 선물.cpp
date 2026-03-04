#include <string>
#include <vector>
#include<map>
#include<iostream>
#include<sstream>
    
using namespace std;
    
map<string,int> Rating(vector<string> gifts)
{   
    map<string,int> GiftRate;
    int Size = gifts.size();
    
    for(int i = 0; i < Size; ++i)
    {
        stringstream ss(gifts[i]);
        string give;
        string gave;
        
        ss >> give;
        ss >> gave;
        
        GiftRate[give]++;
        GiftRate[gave]--;
    }   
    return GiftRate;
}   
    
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string,int> GiftRate = Rating(gifts);
    map<string,map<string,int>> RelateCount;
    int Size = friends.size();
    
    for(string Name : friends)
    {
        RelateCount[Name];
        for(string Name2 : friends)
        {
            if(Name == Name2)
                continue;
            RelateCount[Name][Name2];
        }
    }
    
    for(string Names : gifts)
    {
        stringstream ss(Names);
        string give;
        string gave;
        
        ss >> give;
        ss >> gave;
        
        auto iter = RelateCount.find(give);
        
        if(iter == RelateCount.end())
            continue;
        
        iter->second[gave]++;
        
        iter = RelateCount.find(gave);
        
        if(iter == RelateCount.end())
            continue;
        iter->second[give]--;
    }
    
    for(auto iter : RelateCount)
    {
        cout << iter.first <<" -- "<<endl;
        for(auto iter2 : iter.second)
        {
            cout << iter2.first <<" "<<iter2.second<<endl;
        }
    }
    
    for(auto iter : RelateCount)
    {
        int Gifted=0;
        for(auto iter2 : iter.second)
        {
            if(iter2.second > 0)
                Gifted++;
            else if(iter2.second == 0)
            {
                int MyRate = GiftRate.find(iter.first)->second;
                int OtherRate = GiftRate.find(iter2.first)->second;
                
                if(MyRate > OtherRate)
                    Gifted++;
            }
        }
        answer = max(answer,Gifted);
    }
    //17, 20
    //friends엔 있지만 gift엔 없는 놈.
    return answer;
}   