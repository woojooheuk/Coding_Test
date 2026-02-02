#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> nums)
{
    int MaxNum = nums.size() / 2;
    
    sort(nums.begin(),nums.end());
    
    nums.erase(unique(nums.begin(),nums.end()), nums.end());
    int Size = nums.size();
    
    return min(MaxNum,Size);
}