#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    //둘 다 정렬 후 index가 다른 걸 찾아?
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    int Size = completion.size();
    
    for(int i = 0; i < Size; ++i)
    {
        if(participant[i] !=completion[i])
            return participant[i];
    }
    
    
    return participant.back();
}