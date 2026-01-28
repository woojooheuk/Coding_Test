#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    vector<int> Temp;
    
    for(auto& iter : food)
    {
        if(iter % 2 != 0)
            iter -= 1;
    }
    
    int Size = food.size();
    for(int i = 0; i < Size; ++i)
    {
        int Count = food[i] / 2;
        for(int j = 0; j < Count; ++j)
        Temp.push_back(i);
    }
    vector<int> Temp2(Temp);
    
    Temp.push_back(0);
    reverse(Temp2.begin(),Temp2.end());
    Temp.insert(Temp.end(),Temp2.begin(),Temp2.end());
    
    for(int i = 0; i < Temp.size(); ++i)
    {
         cout << Temp[i]<< " ";
        answer+=to_string(Temp[i]);        
    }
    
    return answer;
}