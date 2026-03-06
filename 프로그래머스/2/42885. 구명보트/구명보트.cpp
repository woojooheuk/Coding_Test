#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(),people.end(),greater<int>());
    
    auto light = people.end() - 1;
    auto heavy = people.begin();
    
    while(true)
    {
        if(*light + *heavy > limit)
        {
            heavy++;
        }
        else
        {
            heavy++;
            light--;
        }
        answer++;
        if(heavy > light)
            break;
    }
    
    return answer;
}