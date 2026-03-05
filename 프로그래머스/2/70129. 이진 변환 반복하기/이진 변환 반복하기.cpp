#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.resize(2);
    
//     while (s.size() != 1) {  // s가 "1"이 될 때까지 반복
//         int zeroCount = 0;   // 이번 루프에서 제거할 0의 개수

//         // 현재 문자열에서 0의 개수를 센다
//         for (char ch : s) {
//             if (ch == '0') zeroCount++;
//         }

//         int i = s.size() - zeroCount;  // 1의 개수만 남겼을 때의 길이
//         s = "";  // 문자열 초기화

//         // 길이를 2진수 문자열로 바꿔서 다시 s에 저장
//         while (i > 0) {
//             s = (i % 2 == 0 ? "0" : "1") + s;  // 맨 앞에 붙이기
//             i /= 2;
//         }

//         answer[0]++;           // 변환 횟수 증가
//         answer[1] += zeroCount; // 제거한 0의 개수 누적
//     }


    
    //"0"만 있을 경우
    while(s != "1")
    {
        answer[0]++;
        int Size = s.size();
        
        int Count = count(s.begin(),s.end(),'0');
        
        int Length = Size - Count;

        answer[1]+=Count;
        int Temp = 0;
        int i = 0;
        s="";
        if(Length != 0)
        {
            
            while (Length > 0)
            {
                s = (Length % 2 == 0 ? "0" : "1") + s;  // 맨 앞에 붙이기
                Length /= 2;
            }
            
//             while(Length > 0)
//             {
//                 Temp += Length % 2 * pow(10,i++);

//                 if(Size <= 2)
//                 {
//                     Temp += Length / 2 * pow(10,i++);
//                     break;
//                 }
//                 Length = Length / 2;
//             }
            // s=to_string(Temp);
        }
        else
            break;
    }
    
    return answer;
}