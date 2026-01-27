#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    //행과 열의 크기가 같은지 확인해야함.
    
    int Size1 =arr1.size();
    answer.resize(Size1);
    
    for(int i = 0; i < Size1; ++i)
    {
        int Size2 = arr1[i].size();
        answer[i].resize(Size2);
        
        for(int j = 0; j < Size2; ++j)
        {
            int Num = arr1[i][j] + arr2[i][j];
            
            answer[i][j] = (Num);
        }
    }
    
    return answer;
}