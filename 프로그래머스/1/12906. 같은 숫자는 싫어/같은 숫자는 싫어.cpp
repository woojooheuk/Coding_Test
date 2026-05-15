#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr.front());

    //배열에서 연속적으로 나타내는 숫자는 하나만 남기고 제거.
    int Size = arr.size();
    for(int i = 1; i < Size; ++i)
    {
        if(answer.back() == arr[i])
        {
            continue;
        }
        else
        {
            answer.push_back(arr[i]);
        }
    }
    
    
    
//     int Size = arr.size();
    
//     answer.push_back(arr[0]);
    
//     for(int i = 0; i < Size; ++i)
//     {
//         if(answer.back() == arr[i])
//             continue;
//         answer.push_back(arr[i]);
//     }
    
//     // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
//     cout << "Hello Cpp" << endl;

    return answer;
}