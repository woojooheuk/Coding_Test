#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<sstream>
#include <cmath>

using namespace std;

string Make_Bit(int n, int k)
{
    string Bit = "";
    
    while(n >= k)
    {
        //나머지
        int Temp = n % k;
        if(Temp == 0)
            Bit +=" ";
        else
            Bit += to_string(Temp);
        //몫
        n = n / k;
    }
    Bit += to_string(n);
    reverse(Bit.begin(),Bit.end());
    return Bit;
}

bool Find_Divide(long long Num)
{  
    for(long long i = 2; i <= sqrt(Num); ++i)
    {
        //소수가 아니면
        
        if(Num % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string Bit = Make_Bit(n,k); 
    // cout <<Bit<<endl;
    vector<long long> TT;
    stringstream SS(Bit);
    
    long long T;
    while(SS >> T)
    {
        if(T == 1)
            continue;
        if(Find_Divide(T))
            answer++;
    }
    
    return answer;
}