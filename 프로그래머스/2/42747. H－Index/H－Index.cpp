#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.rbegin(),citations.rend());

    int Size = citations.size();
    
    for(int i = 0; i < Size; ++i)
    {
        //h번 이상의 h | 인용된 수 = citations[i]
        //h편 이상의 h | 나보다 큰 수 = i
        //citations[i]가 i보다 커야한다. ?
        
        if(citations[i] >= i + 1)
            answer = i + 1;
        else
            break;
        
    }
    
    return answer;
}