#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
        
int solution(vector<int> topping) {
    int answer = 0;
    //토핑의 수보다 토핑의 종류가 중요.
    //자르고 앞과 뒤 벡터를 정렬 후 unique처리해서 size검사? 아니면 set으로 넣기
        
    //앞과 뒤에서 동시 접근?
    int Size = topping.size();
    
    map<int,int> T1;
    map<int,int> T2;
    
    for(int i =0; i < Size; ++i)
    {
        T1[topping[i]]++;
    }
    
    for(int i =0; i < Size; ++i)
    {
        T1[topping[i]]--;
        T2[topping[i]]++;
        
        
        if(T1[topping[i]] <= 0)
        {
            T1.erase(topping[i]);
        }
        
        if(T1.size() == T2.size())
            answer++;
    }

    return answer;
}       