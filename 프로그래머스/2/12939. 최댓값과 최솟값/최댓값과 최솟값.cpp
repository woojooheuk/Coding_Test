#include <string>
#include <vector>
#include<sstream>
#include<algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> Nums;
    
    stringstream ss(s);
    
    int Num= 0;
    while(ss >> Num)
    {
        Nums.push_back(Num);
    }
    sort(Nums.begin(),Nums.end());
    answer += to_string(*(min_element(Nums.begin(),Nums.end())));
    answer += " ";
    answer += to_string(*(max_element(Nums.begin(),Nums.end())));
    return answer;
}