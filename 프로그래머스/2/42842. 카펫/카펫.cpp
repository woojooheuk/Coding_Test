#include <string>
#include <vector>
#include <iostream>
#include<map>


using namespace std;

void Multi_Least(vector<int>& answer,int N, int Max)
{
    for(int i = 1; i <= N; ++i)
    {
        bool IsOver = false;
        for(int j = 1; j <= N; ++j)
        {
            if(i * j > N)
            {
                IsOver = true;
                break;
            }
            else if(i * j == N && (i + 2 + j)*2 == Max )
            {
                answer.push_back(max(i,j) + 2);
                answer.push_back(min(i,j) + 2);
                return;
            }
        }
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    Multi_Least(answer, yellow,brown);

    return answer;
}