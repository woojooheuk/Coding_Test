using namespace std;
#include<iostream>

long long solution(int price, int money, int count)
{

    long long answer = -1;
    
    long long Num =0;
    
    for(int i = 1; i <= count; ++i)
    {
        Num -= price * i;
    }
    cout << Num << endl;
    
    Num = Num + money;
    if(Num > 0)
        answer = 0;
    else
        answer = abs(Num);
    return answer;
}