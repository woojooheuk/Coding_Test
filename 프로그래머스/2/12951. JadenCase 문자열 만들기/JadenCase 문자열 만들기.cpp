#include <string>
#include <vector>
#include<sstream>
#include<cctype>
    
using namespace std;
    
string solution(string s) {
    string answer = "";
    int FrontIndex = 0;
    while(true)
    {
        FrontIndex = s.find_first_not_of(" ", FrontIndex);
        
        if(FrontIndex == string::npos)
            break;

        int BackIndex = s.find_first_of(" ", FrontIndex);
        
        if(BackIndex == string::npos)
            BackIndex = s.size();
        
        
        for(int i = FrontIndex; i <= BackIndex; ++i)
            s[i] = tolower(s[i]);
            
        s[FrontIndex] = toupper(s[FrontIndex]);

        FrontIndex = BackIndex;
    }
    answer = s;
    
    return answer;
}