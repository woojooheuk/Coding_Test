#include <string>
#include <vector>
#include<bitset>
#include<iostream>

using namespace std;

int Count_One(int n)
{
    int Count = 0;
    while(n > 0)
    {
        if(n % 2 != 0)
            Count++;
        n /=2;
    }
    return Count;
}

int solution(int n) {
    int answer = 0;
    int Temp = n + 1;
    
    int CountOne = Count_One(n);
    while(true)
    {
        
        if(CountOne == Count_One(Temp))
        {
            answer = Temp;
            break;
        }
        ++Temp;
    }
    return answer;
}