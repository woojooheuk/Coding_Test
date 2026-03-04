#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int Size = nums.size();
    
    for(int i = 0; i < Size - 2; ++i)
    {
        for(int j = i + 1; j < Size - 1; ++j)
        {
            for(int k = j + 1; k < Size; ++k)
            {
                int Num = nums[i] + nums[j] + nums[k];
                
                bool Divine = true;
                for(int R = 2; R < Num / 2; ++R)
                {
                    if(Num % R == 0)
                    {
                        Divine= false;
                        break;
                    }
                }
                if(Divine)
                    answer++;
            }   
        }
    }
    return answer;
}