#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include<iostream>''
using namespace std;

int solution(string s) {
    int answer = 0;
    
    map<string, int> TextMap;
    
    //z, o, tw, th, fo, fi, si, se, e, n 있으면 하면 되겠네.
    //대문자 고려.
    
    
    TextMap.emplace("zero",0);
    TextMap.emplace("one",1);
    TextMap.emplace("two",2);
    TextMap.emplace("three",3);
    TextMap.emplace("four",4);
    TextMap.emplace("five",5);
    TextMap.emplace("six",6);
    TextMap.emplace("seven",7);
    TextMap.emplace("eight",8);
    TextMap.emplace("nine",9);
    
    int Size = s.length();
    
    string TempText = "";

    for(int i = 0; i < Size; ++i)
    {
        //문자열 찾는 조건
        if('a' <= s[i] && s[i] <= 'z')
        {
            TempText.push_back(s[i]);
            
            auto iter = TextMap.find(TempText);

            if(iter != TextMap.end())
            {
                answer*=10;
                answer+= iter->second;
                TempText = "";
            }
        }
        else
        {
            if('0' <= s[i] && s[i] <= '9')
            { 
                answer *=10;
                answer += (s[i] - '0');
            }

        }
    }

    return answer;
}