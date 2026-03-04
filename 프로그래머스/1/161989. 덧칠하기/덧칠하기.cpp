#include <string>
#include <vector>
#include <iostream>
#include<map>
#include<algorithm>
#include<iterator>

using namespace std;
    
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    map<int, bool> Painted;
    for(int N : section)
        Painted[N] = false;

    int Size = section.size();
    
    for(int i = 0; i < Size; ++i)
    {
        auto iter = Painted.find(section[i]);
        
        if(iter == Painted.end())
            break;

        if(iter->second == true)
            continue;
        
        answer++;
        for(int j = section[i]; j < section[i] + m; ++j)
        {
            auto iter2 = Painted.find(j);
            
            if(iter2 == Painted.end())
                continue;
            iter2->second = true;
        }
    }
    
    return answer;
}