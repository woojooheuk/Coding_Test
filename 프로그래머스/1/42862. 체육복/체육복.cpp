#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int Size = lost.size();

    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    
    
    vector<int> Test;
    set_intersection(lost.begin(),lost.end(),reserve.begin(),reserve.end(),
                    back_inserter(Test));
    
    int TestSize = Test.size();
    for(int i = 0; i <TestSize; ++i)
    {
        auto Iter = find_if(reserve.begin(),reserve.end(),[&](int A){
            return Test[i] == A;
        });
        
        if(Iter != reserve.end())
            reserve.erase(Iter);
    }
    
    for(int i = 0; i < Size; ++i)
    {
        auto iter1 = find_if(Test.begin(),Test.end(),[&](int A){
            return lost[i] == A;
        });
        
        if(iter1 != Test.end())
            continue;
        
        auto iter2 = find_if(reserve.begin(),reserve.end(),[&](int A){
            return abs(lost[i] - A) <= 1;
        });
        
        if(iter2 == reserve.end())
        {
            --n;
        }
        else
        {
            reserve.erase(iter2);
        }
    }
    return n;
}