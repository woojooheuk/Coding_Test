#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    
    int Size = s.size();
    
    vector<int> SortVector;
    for(int i=0; i<Size; ++i)
    {
        int Num = s[i];
        SortVector.push_back(Num);
    }

    sort(SortVector.begin(),SortVector.end());
    reverse(SortVector.begin(), SortVector.end());
    for(int i=0; i<Size; ++i)
    {
        answer += static_cast<char>(SortVector[i]);
    }
    
    return answer;
}