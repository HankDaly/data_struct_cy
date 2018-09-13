#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int ch_ori[105];
int ch_now[105];
int main(){
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        ch_ori[i] = temp;
    }
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        ch_now[i] = temp;
    }
    int i,j;
    for(i = 0;i<N-1 && ch_now[i]<=ch_now[i+1];i++);
    for(j = i+1;j<N && ch_now[j] == ch_ori[j];j++);
    if(j == N){
        cout << "Insertion Sort" << endl;
        sort(ch_ori,ch_ori+i+2);
    }
    else{
        cout << "Merge Sort" << endl;
        int kase = 1,flag = 1;
        while(flag){
            flag = 0;
            for(int k = 0;k<N;k++){
                if(ch_now[k] != ch_ori[k]){flag = 1;}
            }
            kase = kase*2;
            for(i = 0;i<(N/kase);i++){
                sort(ch_ori+i*kase,ch_ori+(i+1)*kase);
            }
            sort(ch_ori + N/kase*kase,ch_ori+N);
        }
    }
    for(j = 0;j<N;j++){
        if(j!=0){cout << " ";};
        cout << ch_ori[j];
    }
    return 0;
}