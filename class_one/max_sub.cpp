#include<iostream>
#include<vector>
using namespace std;
vector<int> ve;
int find_max(int a,int b,int c){
    if(a>b){
        if(a>c){return a;}
        else{return c;}
    }
    else{
        if(b>c){return b;}
        else{return c;}
    }
}

int findmax(vector<int>& ve,int left,int right){
    int max_left,max_right,max_value;
    if(left == right){
        if(ve[left]<0){return 0;}
        else{return ve[left];}
    }
    int center = (left+right)/2;
    max_left = findmax(ve,left,center);
    max_right = findmax(ve,center+1,right);
    int max_medium_left = 0,now_medium_left = 0;
    for(int i = center;i>=left;i--){
        now_medium_left += ve[i];
        if(now_medium_left > max_medium_left){max_medium_left = now_medium_left;}
    }
    int max_medium_right = 0,now_medium_right = 0;
    for(int i = center+1;i<=right;i++){
        now_medium_right += ve[i];
        if(now_medium_right > max_medium_right){max_medium_right = now_medium_right;}
    }

    int max_medium = max_medium_left+max_medium_right;
    max_value = find_max(max_left,max_right,max_medium);
    return max_value;
}

int main(){
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        ve.push_back(temp);
    }
    int max_value = findmax(ve,0,N-1);
    cout << max_value;
    return 0;
}