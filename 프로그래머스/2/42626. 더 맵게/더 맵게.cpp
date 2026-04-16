#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    multiset<int> Temp(scoville.begin(),scoville.end());    

    while(true)
    {
        int First = *Temp.begin();
        
        if(First >= K)
            break;
        else if(First < K && Temp.size() == 1)
            return -1;
    
        Temp.erase(Temp.begin());
        
        int Second = *Temp.begin();
        Temp.erase(Temp.begin());
        
        int New = First + Second * 2;
        Temp.insert(New);
        answer++;
    }
    
    return answer;
}