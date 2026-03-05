#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    int Pair = 0;
    
    int Size = s.size();
    if(s[0] == ')' || s[Size] == '(')
        return answer;
    for(char Word : s)
    {
        switch(Word)
        {
            case '(':
                Pair++;
                break;
            case ')':
                Pair--;
                break;
        }
        if(Pair <0)
            return answer;
    }
    if(Pair == 0)
        answer = true;
    return answer;
}