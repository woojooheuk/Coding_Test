#include <string>
#include <vector>
#include<cctype>
#include<iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    //공백을 만날 때까지 순회하다가 공백 만나면 그 이전 애들 변환. -> 반복?
    
    int Split = 0;
    
    for(int i =0; i < s.length(); ++i)
    {
        if(s[i] == ' ')
        {
            Split = i+1;
            cout << Split<< endl;
            continue;
        }
        
        if((i - Split) % 2 == 0)
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);

    }
    
    // for(int i = 0; i < s.length(); ++i)
    // {
    //     if(s[i] == ' ')
    //     {
    //         for(int j = Split; j < i;++j)
    //         {
    //             if(j % 2 == 0)
    //                 s[j] = toupper(s[j]);
    //             else
    //                 s[j] = tolower(s[j]);
    //         }
    //         Split = i;
    //         cout << Split<<endl;
    //     }
    // }
    //글자 하나씩 다 보기. Split을 빼서.
    
    return answer = s;
    //공백 처리를 해야한다.
    //짝수는 대문자 홀수는 소문자
}