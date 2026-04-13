#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;

int solution(string s) {
    int answer = 0;
    queue<char> QueueTemp;
    int Size = s.size();
    for(char S : s)
    {
        QueueTemp.push(S);
    }

    for(int i = 0; i < Size; ++i)
    {
        char QS = QueueTemp.front();
        stack<char> StackTemp;
        queue<char> Temp = QueueTemp;
        
        bool Test = false;        
        
        for(int j = 0; j < Size; ++j)
        {   
            char TT = Temp.front();
            
            if(StackTemp.empty() == false)
            {
                switch(TT)
                {
                    case ')': 
                        if(StackTemp.top() == '(')
                            StackTemp.pop();
                        break;
                        
                    case '}': 
                        if(StackTemp.top() == '{')
                            StackTemp.pop();
                        break;
                        
                    case ']': 
                        if(StackTemp.top() == '[')
                            StackTemp.pop();
                        break;
                    default:
                        StackTemp.push(TT);
                        break;
                }
            }
            else
                StackTemp.push(TT);
            Temp.pop();
            
            if(Temp.empty())
            {
                if(StackTemp.empty() == true)
                    Test = true;
                break;
            }
        }
        
        if(Test == true)
        {
            answer++;
        }
        QueueTemp.pop();
        QueueTemp.push(QS);
    }    
    
    return answer;
}