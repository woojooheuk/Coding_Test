#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<numeric>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    string Temp = "";
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    set_intersection(X.begin(),X.end(),Y.begin(),Y.end(),back_inserter(Temp));
    
    vector<int> Intanswer(Temp.begin(),Temp.end());

    if(Intanswer.size() == 0)
    {
        answer = "-1";
    }
    else
    {
        sort(Intanswer.begin(),Intanswer.end(), greater<int>());
    
        int Sum = accumulate(Intanswer.begin(),Intanswer.end(),0) % 48 ;
        
        if(Sum == 0)
            answer = "0";
        else
        {
            for(int Num : Intanswer)
                answer += Num;
        }
        
    }
    return answer;
}