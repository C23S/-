#include<iostream>
#include<deque>

using namespace std;

const int N = 1e6 + 10;
int a[N], n, k;

int main(){
    cin >> n >> k;
    
    for(int i = 1; i <= n; i ++) cin >> a[i];
    
    deque<int> q;  //�洢�����±�
    
    //����//��Сֵ
    for(int i = 1; i <= n; i ++){
        while(!q.empty() && a[i] < a[q.back()]) {
            q.pop_back();  //ɾ�������д���a[i]����
        }
        q.push_back(i);
        
        //����Ԫ�س������ڴ�С��ɾ����ͷԪ��
        while(!q.empty() && q.front() <= i - k){
            q.pop_front();
        }
        
        if(i >= k){
            cout << a[q.front()] << ' ';
        }
    }
    
    cout << endl;
    
    q.clear();
    
    //����//���ֵ
    for(int i = 1; i <= n; i ++){
        while(!q.empty() && a[i] > a[q.back()]) {
            q.pop_back();  //ɾ��������С��a[i]����
        }
        q.push_back(i);
        
        //����Ԫ�س������ڴ�С��ɾ����ͷԪ��
        while(!q.empty() && q.front() <= i - k){
            q.pop_front();
        }
        
        if(i >= k){
            cout << a[q.front()] << ' ';
        }
    }
    
    return 0;
}
