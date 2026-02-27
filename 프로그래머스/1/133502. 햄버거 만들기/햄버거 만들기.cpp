#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<stack>

using namespace std;

int System(stack<int>& Check, string& Temp)
{
    int Size = Check.size();
    Temp += to_string(Check.top());
    
    if(Size >= 4)
    {
        int Range = Size - 4;
        int Index = Temp.find("1231", Range);
        
        if(Index != string::npos)
        {
            for(int i = 0; i < 4; ++i)
                Check.pop();
            
            Temp = Temp.substr(0, Range);
            return 1;
        }
    }
    return 0;
}

int solution(vector<int> ingredient) {
    int answer = 0;
    int Size = ingredient.size();
    
    stack<int> Check;
    string Temp="";
    
    for(int i = 0; i < Size; ++i)
    {
        Check.push(ingredient[i]);
        answer += System(Check,Temp);
    }
    
    return answer;
}