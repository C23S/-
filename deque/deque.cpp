#include<iostream>
#include<deque>

using namespace std;

const int N = 1e6 + 10;
int a[N], n, k;

int main(){
    cin >> n >> k;
    
    for(int i = 1; i <= n; i ++) cin >> a[i];
    
    deque<int> q;  //存储数组下标
    
    //升序//最小值
    for(int i = 1; i <= n; i ++){
        while(!q.empty() && a[i] < a[q.back()]) {
            q.pop_back();  //删掉队列中大于a[i]的数
        }
        q.push_back(i);
        
        //队列元素超过窗口大小，删掉队头元素
        while(!q.empty() && q.front() <= i - k){
            q.pop_front();
        }
        
        if(i >= k){
            cout << a[q.front()] << ' ';
        }
    }
    
    cout << endl;
    
    q.clear();
    
    //降序//最大值
    for(int i = 1; i <= n; i ++){
        while(!q.empty() && a[i] > a[q.back()]) {
            q.pop_back();  //删掉队列中小于a[i]的数
        }
        q.push_back(i);
        
        //队列元素超过窗口大小，删掉队头元素
        while(!q.empty() && q.front() <= i - k){
            q.pop_front();
        }
        
        if(i >= k){
            cout << a[q.front()] << ' ';
        }
    }
    
    return 0;
}
