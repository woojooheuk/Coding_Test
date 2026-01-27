#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    //각 성분마다 검사 해서 아스키 코드 A부터 z까지 검사해야할듯?
    //길이도 검사해야함.
    
    int Size = s.size();
    
    if(!(4 == Size || Size == 6))
        return false;
    
    int Small = static_cast<int>('A');
    int Big = static_cast<int>('z');
    
    
    for(int i = 0; i < Size; ++i)
    {
        int Num =  static_cast<int>(s[i]);
        
        if(Small <= Num && Num <= Big)
            return false;
    }
    
    
    return answer;
}