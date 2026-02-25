#include <string>
#include <vector>
#include<iostream>
#include<cstring>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    int Size = s.size();

    int RepSize = skip.size();
    for(int i = 0; i < Size; ++i)
    {
        for(int j = 0; j < index; ++j)
        {
            ++s[i];
            
            if(s[i] > 'z')
                s[i] -= 26;
            
            for(int k = 0; k < RepSize; ++k)
            {
                if(s[i] == skip[k])
                {
                    --j;
                    break;
                }
            }
            
        }
    }
    answer = s;
    return answer;
}