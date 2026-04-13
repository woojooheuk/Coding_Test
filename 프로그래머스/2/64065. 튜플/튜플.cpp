#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

vector<vector<int>> Parser(string s)
{
    vector<vector<int>> Temp;
    vector<int> TempVector;
    string C;
    
    for(char S : s)
    {
        if(isdigit(S))
            C+=S;
        else
        {
            if(C.empty()== false)
            {
                TempVector.push_back(stoi(C));
                C="";
            }
            
            if(S == '}')
            {
                Temp.push_back(TempVector);
                TempVector.clear();
            }
        }
        
    }
    return Temp;
}


vector<int> solution(string s) {
    vector<int> answer;
    s = s.substr(1,s.size() - 2);
    vector<vector<int>>Temp = Parser(s);
    //튜플이 여러개면 순서대로 나온다.
    //2,1 |1,3 | 4,2 이런 식이면 튜플의 순서는
    //4, 2, 1, 3 이런 식.
    //한 튜플 내에서는 원소의 순서가 바뀌어도 됨.
    
    //1, 2 | 1, 3| 4, 2 이런 식이어도 가능.
    
    sort(Temp.begin(),Temp.end(),[&](auto Vector1, auto Vector2){
        bool Return;
        Vector1.size() < Vector2.size() ? Return = true : Return = false;
        return Return;
    });
    
    // for(auto T : Temp)
    // {
        // for(int A : T)
            // cout <<A<<" ";
        // cout<<endl;
    // }
    int OutSize = Temp.size();
    for(int i = 0; i < OutSize; ++i)
    {
        int InSize = Temp[i].size();
        
        for(int j =0; j <InSize; ++j)
        {
            int CurInt = Temp[i][j];
            auto iter = find(answer.begin(),answer.end(), CurInt);
            
            if(iter == answer.end())
            {
                answer.push_back(CurInt);
            }
            
        }
    }
    
    return answer;
}