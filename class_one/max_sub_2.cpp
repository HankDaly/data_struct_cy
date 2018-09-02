#include<iostream>
#include<vector>
using namespace std;


int main(){
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int N; cin >> N;
    int sqe_first,sqe_last,first = 0,last = 0,sub_first = 0;
    int max_value = 0;
    int sub_value = 0;
    int ok = 0;
    int flag = 2;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        // 
        if(temp >= 0){ok = 1;}
        if(i == 0){sqe_first = temp;}
        if(i+1 == N){sqe_last = temp;}
        //
        if(flag == 2||flag == 1){sub_first = temp;}
        sub_value += temp;
        if(sub_value < 0){sub_value = 0;flag = 1;} //重置后子列开头也重置
        else{flag = 0;}
        if(sub_value > max_value){max_value = sub_value;first = sub_first;last = temp;}
    }
    if(ok == 0){cout << 0 <<" "<< sqe_first << " " << sqe_last;}
    else{cout << max_value << " " << first << " " << last;}
    return 0;
}