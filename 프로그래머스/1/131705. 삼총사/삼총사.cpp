#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

bool Compare(int a, int b)
{
    if(abs(a) == abs(b))
        return a < b;
    
    return abs(a) < abs(b);
}

int solution(vector<int> number) {
    int answer = 0;
    vector<int> Temp;
    
    Temp.resize(number.size());
    
    copy(number.begin(),number.end(),Temp.begin());
    sort(Temp.begin(),Temp.end(),Compare);
    

    for(int i = 0; i < Temp.size() - 2; ++i)
    {
        for(int j = i + 1; j < Temp.size(); ++j)
        {
            for(int k = j + 1; k < Temp.size(); ++k)
            {
                if(Temp[i] + Temp[j] + Temp[k] == 0)
                    answer++;
            }
        }
    }
    
    
    for(int i = 0; i < Temp.size(); ++i)
        cout << Temp[i]<<" ";
    cout << endl;
    //세 수의 합이 0이 되는 조건?
    //절대값으로 정렬?
    
    
    
    
    return answer;
}