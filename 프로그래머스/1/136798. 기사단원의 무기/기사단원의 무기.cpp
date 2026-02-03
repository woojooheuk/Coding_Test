#include <string>
#include <vector>
#include<iostream>
#include<cmath>
#include<numeric>

using namespace std;

int Get_Prime(int Num, int Limit, int Power)
{
    vector<int> Temp;
    
    for(int i = 1; i <= Num; ++i)
    {
        int half = i / 2;
        int NumTemp = 0;

        for(int j = 1; j <= half; ++j)
        {
            if(i % j == 0)
            {
                ++NumTemp;
            }
        }
        
        if(++NumTemp > Limit)
        {
            NumTemp = Power;
        }
        
        Temp.push_back(NumTemp);
    }
    
    cout << endl;
    
    return accumulate(Temp.begin(),Temp.end(),0);
}

int solution(int number, int limit, int power) {
    int answer = 0;

    return Get_Prime(number, limit, power);
}