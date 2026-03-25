#include <string>
#include <vector>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    map<string, int> Temp;
    for(auto string : clothes)
    {
        Temp[string[1]]++;
    }
    int Size= Temp.size();

    int Num = 1;
    for(auto Pair : Temp)
        Num *= (Pair.second + 1);
    Num -= 1;
    answer = Num;
    return answer;
}