#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {

    int answer = 0;
    
    int Size1 = sizes.size();

    int Long = 0;
    int Short = 0;

    for(int i = 0; i < Size1; ++i)
    {
        Long = max(Long,max(sizes[i][0],sizes[i][1]));
        Short = max(Short,min(sizes[i][0],sizes[i][1]));
    }

    answer = Long * Short;
    return answer;
}
