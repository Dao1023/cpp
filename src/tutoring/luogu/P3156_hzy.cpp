#include <bits/stdc++.h>
using namespace std;

// vector 获取用户输入要先声明空间大小
// 如果不声明，需要 cin 临时变量， 然后 push_back
int main(){
	vector<int> id;
	vector<int> ask;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>id[i];
	}
	for(int i=0;i<m;i++){
		cin>>ask[i];
	}
	for(int i=0;i<m;i++){
		cout<<id[ask[i]]<<endl;
	}
	return 0;
}
