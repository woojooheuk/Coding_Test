#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    
    //괄호 맞추기.
    //string에 (면 더하고 )면 빼기?
    string Temp = "";

    int Pair = 0;
    
    for(char Word : s)
    {
        if(Word == '(')
            Pair++;
        else if(Word == ')')
        {
            Pair--;
            if(Pair < 0)
                break;
        }
    }
    if(Pair == 0)
        answer = true; 
    
    
    
    
    
    
    
//     int Pair = 0;
    
//     int Size = s.size();
//     if(s[0] == ')' || s[Size] == '(')
//         return answer;
//     for(char Word : s)
//     {
//         switch(Word)
//         {
//             case '(':
//                 Pair++;
//                 break;
//             case ')':
//                 Pair--;
//                 break;
//         }
//         if(Pair <0)
//             return answer;
//     }
//     if(Pair == 0)
//         answer = true;
    return answer;
}