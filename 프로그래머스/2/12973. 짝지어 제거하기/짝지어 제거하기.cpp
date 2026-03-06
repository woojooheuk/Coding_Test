#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> Temp;
    stack<char> ss;
    
    char CurChar;
    for(char C : s)
        ss.push(C);
    
    while(!ss.empty())
    {
        CurChar = ss.top();
        ss.pop();
        
        if(!ss.empty() && Temp.empty() && CurChar == ss.top())
        {
            ss.pop();
        }
        else if(!Temp.empty() && CurChar == Temp.top())
        {
            Temp.pop();
        }
        else
        {
            Temp.push(CurChar);
        }
    }
    if(Temp.empty())
        answer = 1;

    return answer;
}