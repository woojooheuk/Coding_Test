#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";

    int Card1Index = 0;
    int Card2Index = 0;
    bool IsMake = true;

    int Size = goal.size();
    
    //반례 : ["bcd"], ["b","c","d"];
    
    for(int i = 0; i < Size; ++i)
    {
        if(goal[i].find(cards1[Card1Index]) != string::npos &&
           goal[i] == cards1[Card1Index])
        {
            ++Card1Index;
            continue;
        }
        else if(goal[i].find(cards2[Card2Index]) != string::npos&&
           goal[i] == cards2[Card2Index])
        {
            ++Card2Index;
            continue;
        }
        else
        {
            IsMake = false;
            break;
        }
    }

    IsMake ? answer = "Yes" : answer = "No";
    
    return answer;
}