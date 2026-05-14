#include <string>
#include <vector>
#include<map>
#include<iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> Temp;
    
    int Num = 1;

    for(int i = 0; i < 26; ++i)
    {
        Temp.emplace(string(1, ('A'+i)), Num++);
    }
    
    int Size = msg.size();
    int CurIndex = 0;
    string Text = "";
    string TempText = "";
    
    while(CurIndex < Size)
    {
        Text = "";
        TempText = "";
        
        for(int i = CurIndex; i < Size; ++i)
        {
            auto iter = Temp.find(Text + msg[i]);
            
            if(iter == Temp.end())
            {
                TempText = Text + msg[i];
                break;
            }
            Text += msg[i];
        }
        
        Temp.emplace(TempText, Num++);
        answer.push_back(Temp[Text]);
        CurIndex += Text.size();
    } 
    
    return answer;
}