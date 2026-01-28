#include <string>
#include <vector>
#include<map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    map<char, int> Temp;
    
    for(int i = 0; i < s.length(); ++i)
    {
        auto iter =  Temp.find(s[i]);
        
        if(iter == Temp.end())
        {
            Temp.emplace(s[i], i);
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - iter->second);
            iter->second = i;
        }
    }
    
    return answer;
}