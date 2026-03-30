#include <string>
#include <vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    int Size = phone_book.size();
    
    for(int i = 0; i < Size - 1; ++i)
    {
        int StringSize = phone_book[i].size();
        if(phone_book[i + 1].compare(0,StringSize, phone_book[i]) == false)
            return false;
    }
    return answer;
}