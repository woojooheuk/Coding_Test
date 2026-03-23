#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for(long long i = left; i <= right; ++i)
    {
        int col = i / n;
        int row = i % n;
        int Num = max(col,row)+1;
        answer.push_back(Num);
    }
    
    return answer;
}