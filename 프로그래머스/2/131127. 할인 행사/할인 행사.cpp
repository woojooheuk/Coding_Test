#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    //10일 연속으로 원하는 품목이 있어야함.
    int NumSize = number.size();
    vector<string> Temp;
    for(int i = 0; i < NumSize; ++i)
    {
        int Count = number[i];
        string Name = want[i];
        for(int i = 0; i < Count; ++i)
        {
            Temp.push_back(Name);
        }
    }

    want = move(Temp);
    int WantSize = want.size();
    sort(want.begin(),want.end());
    bool Test = false;
    for(auto iter = discount.begin(); iter != discount.end() - WantSize + 1; ++iter)
    {
        vector<string> TT(iter,iter + WantSize);
        vector<string> Temp;
        sort(TT.begin(),TT.end());
        
        set_intersection(TT.begin(),TT.end(),want.begin(),want.end(),
                         back_inserter(Temp));

        if(Temp.size() == WantSize)
        {
            answer++;
        }
    }

    return answer;
}