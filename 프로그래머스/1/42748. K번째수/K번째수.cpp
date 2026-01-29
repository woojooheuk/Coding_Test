#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int Size1 =  commands.size();
    
    for(int i = 0; i < Size1; ++i)
    {
        int a = commands[i][1] - commands[i][0] + 1;
        vector<int> Temp(a);

        copy(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1],
             Temp.begin()); 
        
        sort(Temp.begin(),Temp.end());
        
        answer.push_back(Temp[commands[i][2]-1]);
    }
    
    
    
    return answer;
}