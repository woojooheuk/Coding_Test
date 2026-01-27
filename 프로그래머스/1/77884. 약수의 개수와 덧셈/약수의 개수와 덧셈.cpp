#include <string>
#include <vector>
#include <iostream>
using namespace std;

int Divisor(int Num)
{
    int Sum = 0;
    for(int i=1; i <= Num; ++i)
    {
        if(Num % i == 0)
            ++Sum;
    }
    return Sum;
}


int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; ++i)
    {
        int Num = Divisor(i);
        
        if(Num % 2 ==0)
            answer += i;
        else
            answer -= i;
    }
    
    return answer;
}