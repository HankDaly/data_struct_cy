/*
02-线性结构4 Pop Sequence（25 分）
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:
YES
NO
NO
YES
NO
*/
/*
总结:
规律有两个.1是不得超过当前循环次数加上M。
2.就是如果当前pop的数字比上一个小的话，那么当前pop的数字必须是上一个的邻位，但是中间
有一些已经被pop出去了，那么就开一个hash表格来表示pop的情况。
。
每次需要循环一下，可能有更好的方法。自下而上看看。
*/

#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<cctype>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int ch[1005];

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int M,N,K; cin >> M >> N >> K;
    for(int i = 0;i<K;i++){
        memset(ch,0,sizeof(ch));
        int temp = 0;
        int ok = 1;
        for(int z = 0;z<N;z++){
            int now; cin >> now;
            if(now>M+z){ok = 0;}
            if(z == 0){ch[now] = 1;temp = now;}
            else{
                if(now<temp){
                    for(int q = temp-1;q>=1;q--){
                        if(ch[q] == 0){
                            if(q != now){ok = 0;}
                            break;
                        }
                    }
                }
                ch[now] = 1;
                temp = now;
            }
        }
        if(ok == 0){cout << "NO" << endl;}
        else{cout << "YES" << endl;}
    }

    return 0;
}