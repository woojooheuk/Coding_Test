#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int Size = s.size();
    string First = "";
    int Count = 0;
    
    for(int i = 0; i < Size; ++i)
    {
        if(First == "")
            First = s[i];
        
        if(First[0] - s[i] == 0)
            Count++;
        else
            Count--;
        
        if(Count == 0)
        {
            ++answer;
            First = "";
        }
    }
    
    if(First != "")
        ++answer;
    
    return answer;
}