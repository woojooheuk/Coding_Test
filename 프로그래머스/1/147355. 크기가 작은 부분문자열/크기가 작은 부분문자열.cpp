#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    //p가 3글자면 t에서 3글자씩 떼서 비교해야함
    
    
    int StrSize = p.length();
    int Size = t.length();

    for(int i = 0; i < Size; ++i)
    {
        if(i + StrSize > Size)
            break;

        unsigned long long tNum = stoull(t.substr(i, StrSize));
        unsigned long long pNum = stoull(p);
        
        if(tNum <= pNum)
        {
            answer++;
            cout << tNum <<endl;
        }
    
    }
    
    
    return answer;
}