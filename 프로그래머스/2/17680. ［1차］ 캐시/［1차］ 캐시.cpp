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
    if(cacheSize == 0)
        return answer = cities.size() * 5;
    
    vector<string> Cache;
    
    int Size = cities.size();
    
    //캐시 적중 하면 순서 바꾸기?
    //차라리 map으로 바꿔서 find하고, erase 이런 식은?
    //second를 int로 LifeTime을 설정.
    //second가 0이면 
    //swap으로 합시다.
    
    for(int i = 0; i < Size; ++i)
    {
        string SmallString = cities[i];
        ToLower(SmallString);
        // cout << "Cur : "<<SmallString<<" | ";
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
            // cout << *iter2 <<" ";
            // cout << *(iter2+1)<<endl;
            iter_swap(iter2, iter2+1);
        }
        // for(string T : Cache)
            // cout <<T<<" ";
        // cout<<endl;
    }
    

    
    return answer;
}