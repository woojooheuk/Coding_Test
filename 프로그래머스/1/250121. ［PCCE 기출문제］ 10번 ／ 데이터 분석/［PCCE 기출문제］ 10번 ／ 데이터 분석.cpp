#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int Selecte(string Word)
{
    int Num = 0;
    if(Word =="code")
        Num = 0;
    else if(Word =="date")
        Num = 1;
    else if(Word =="maximum")
        Num = 2;
    else if(Word =="remain")
        Num = 3;
    
    return Num;
}
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int Standard = Selecte(ext);
    sort(data.begin(),data.end(),[&](auto iter, auto iter2){
        return iter[Standard] < iter2[Standard];
    });
    
    for(auto iter : data)
        cout << iter[Standard] << endl;
    
    auto iter = find_if(data.begin(),data.end(),[&](auto iter){
        return iter[Standard] > val_ext;
    });
    
    vector<vector<int>> Temp(data.begin(),iter);
    move(data.begin(),iter,back_inserter(answer));
    
    Standard = Selecte(sort_by);
    sort(answer.begin(),answer.end(),[&](auto iter, auto iter2){
        return iter[Standard] < iter2[Standard];
    });
    return answer;
}