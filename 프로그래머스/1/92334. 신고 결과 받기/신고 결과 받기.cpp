#include <string>
#include <vector>
#include<unordered_map>
#include<set>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    set<string> Newreport(report.begin(),report.end());
    unordered_map<string,int> Result;
    unordered_map<string, vector<string>> ReportInfo;
    vector<pair<string,int>> Names;

    for(string Name : id_list)
    {
        Result.emplace(Name,0);
        Names.push_back({Name, {}});
    }
    
    for(auto iter = Newreport.begin(); iter != Newreport.end(); ++iter)
    {
        string Reporter;
        string Reported;
        
        stringstream ss(*iter);
        
        ss >> Reporter;
        ss >> Reported;
        ReportInfo[Reporter].push_back(Reported);
        Result[Reported]++;
    }

    for(auto iter : ReportInfo)
    {
        auto iterVector = iter.second;

        for(string Name : iterVector)
        {
            auto iter2 = Result.find(Name);
            
            if(iter2 == Result.end())
                continue;
            
            if(k <= iter2->second)
            {
                auto iter3 = find_if(Names.begin(),Names.end(),[&](auto TT){
                    return TT.first == iter.first;
                });
                
                if(iter3 != Names.end())
                    iter3->second++;
            }
        }
    }
    
    for(auto iter : Names)
        answer.push_back(iter.second);
    return answer;
}