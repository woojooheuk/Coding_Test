#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<cctype>

using namespace std;

void ToLower(string& Temp)
{
    transform(Temp.begin(),Temp.end(),Temp.begin(),[&](unsigned char T){
        return tolower(T);
    });
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int Size = cities.size();
    if(cacheSize == 0)
        return answer = Size * 5;
    
    vector<string> Cache;
    
    for(int i = 0; i < Size; ++i)
    {
        string SmallString = cities[i];
        ToLower(SmallString);
        auto iter = find_if(Cache.begin(),Cache.end(), [&](string Temp){
            return Temp == SmallString;
            });
        
        if(iter == Cache.end())
        {
            if(Cache.size() < cacheSize)
            {
                Cache.push_back(SmallString);
                iter = Cache.end()-1;
            }
            else
            {
                Cache[0] = SmallString;
                iter = Cache.begin();
            }
            answer+=5;
        }
        else
            answer++;

        for(auto& iter2 = iter; iter2 != Cache.end()-1; ++iter2)
        {
            iter_swap(iter2, iter2+1);
        }
    }
    

    
    return answer;
}