#include <string>
#include <vector>
#include<iostream>
#include<numeric>
#include<algorithm>

using namespace std;

vector<vector<int>> Replace_Vector(vector<vector<int>> Vector)
{
    int NumSize = Vector[0].size();
    
    vector<vector<int>> Temp;
    Temp.resize(NumSize);
    
    int CurNum = 0;
    while(CurNum < NumSize)
    {
        for(auto& Vector1 : Vector)
        {
            Temp[CurNum].push_back(Vector1[CurNum]);
        }
        CurNum++;
    }
    return Temp;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int ColSize = arr1.size();

    int NumSize = arr1[0].size();
    arr2 = move(Replace_Vector(arr2));
    int RowSize = arr2.size();

    //arr1
    for(int i = 0; i < ColSize; ++i)
    {
        vector<int> Temp;
        //arr2
        for(int j = 0; j < RowSize; ++j)
        {
        vector<int> Temp2;
          transform(arr1[i].begin(), arr1[i].end(), arr2[j].begin(), back_inserter(Temp2), multiplies<int>());

            Temp.push_back(accumulate(Temp2.begin(),Temp2.end(),0));
        }
        answer.push_back(Temp);
    }
    
    return answer;
}