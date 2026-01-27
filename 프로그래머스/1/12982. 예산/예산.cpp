#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    //일단 배열을 정렬시키기.
    sort(d.begin(),d.end());
    int Size = d.size();
    
    for(int i = 0; i < Size; ++i)
    {
        budget -= d[i];
        if(budget < 0)
            break;
        answer++;
    }
    
    
    return answer;
}