#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> Temp;
    int Num = n;
    while(true)
    {
        
        if(Num / 3 == 0)
        {
            Temp.push_back(Num);
            break;
        }
        else
        Temp.push_back(Num % 3);

        Num = Num / 3;
    }
    
    int Size = Temp.size();    

    for(int i = 0;i < Size; ++i)
    {
        answer += pow(3, Size -(i + 1)) * Temp[i];
        cout << answer << endl;
    }
    
    return answer;
}