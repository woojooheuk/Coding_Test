#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    //for문 2개?
    
    int Size = numbers.size();
    for(int i = 0; i < Size - 1; ++i)
    {
        for(int j = i + 1; j < Size; ++j)
        {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(), answer.end()),answer.end());
    
    return answer;
}