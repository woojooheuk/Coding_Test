#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    int Size = targets.size();
    int Max = 101;
    for(int i = 0; i < Size; ++i)
    {
        string Temp = targets[i];
        int StrLength = Temp.size();
        int Count = 0;
        
        for(int j = 0; j < StrLength; ++j)
        {
            int KeySize = keymap.size();
            int MinCount = Max;

            for(int k = 0; k < KeySize; ++k)
            {
                int Index = keymap[k].find_first_of(Temp[j]);
                
                if(Index != string::npos)
                {
                    MinCount = min(MinCount, Index + 1);
                }
            }
            
            if(MinCount == Max)
            {
                Count = 0;
                break;
            }
            
            Count += MinCount;
        }
        if(Count == 0)
            Count = -1;
        
        answer.push_back(Count);
    }
        
    
    
    return answer;
}