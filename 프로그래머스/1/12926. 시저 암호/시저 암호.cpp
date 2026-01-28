#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    //공백은 제외.
    
    //대문자 소문자 구분 해야됨.

    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == ' ')
            continue;
        
        int Temp = static_cast<int>(s[i]);
        
        bool IsUpper = 'a' <= Temp && Temp <= 'z' ? false : true;
        Temp += n;
        
        if(IsUpper)
        {
            if(Temp > 'Z')
                Temp -= 26;
        }
        else
        {
            if(Temp > 'z')
                Temp -= 26;
        }
        
        s[i] = static_cast<char>(Temp);
    }
    return s;
}