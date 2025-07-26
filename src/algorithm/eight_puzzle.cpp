#include<iostream>
#include<time.h>
#include<windows.h>
#include<vector>
#include<cmath>
using namespace std;

struct node{
	int a[3][3];           //存放矩阵
	int father;            //父节点的位置 
	int gone;             //是否遍历过,1为是,0为否
	int fn;               //评价函数的值
	int x,y;              //空格的坐标
	int deep;            //节点深度 
};

vector<node> store;        //存放路径节点

int mx[4]={-1,0,1,0};
int my[4]={0,-1,0,1};      //上下左右移动数组

int top;                  //当前节点在store中的位置

bool check(int num)       //判断store[num]节点与目标节点是否相同,目标节点储存在store[0]中 
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(store[num].a[i][j]!=store[0].a[i][j])
				return false;
		}
	}
	return true;
}        

bool search(int num)        //判断store[num]节点是否已经扩展过 ,没有扩展返回true 
{
	int pre=store[num].father;       //pre指向store[num]的父节点位置 
	bool test=true;
	while(!pre){                     //循环直到pre为0,既初始节点 
		for(int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				if(store[pre].a[i][j]!=store[num].a[i][j]){
					test=false;
					break;
				}
			}
			if(test==false) break;
		}
		if(test==true) return false;
		pre=store[pre].father;          //pre继续指向store[pre]父节点位置 
	}
	return true;
}

void print(int num)                //打印路径,store[num]为目标节点 
{
	vector<int> temp;             //存放路径 
	int pre=store[num].father;
	temp.push_back(num);
	while(pre!=0){                  //从目标节点回溯到初始节点 
		temp.push_back(pre);
		pre=store[pre].father;
	}
	cout<<endl;
	cout<<"*********数码移动步骤*********"<<endl; 
	int mm=1; //步数
	for(int m=temp.size()-1;m>=0;m--){

		cout<<"---第"<<mm<<"步---："<<endl;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cout<<store[temp[m]].a[i][j]<<" ";
			}
			cout<<endl;
		}
		mm++;
		cout<<endl;
	}
	cout<<"所需步数为: "<<store[num].deep<<endl; 
	return;
}

int get_fn(int num)             //返回store[num]的评价函数值 
{
	int fn_temp=0;              //评价函数值 
	bool test=true;
	for(int i=0;i<3;i++){      //当找到一个值后,计算这个值位置与目标位置的距离差,test置为false后继续寻找下一个值 
		for(int j=0;j<3;j++){
			test=true;
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					if((store[num].x!=i||store[num].y!=j)&&store[num].a[i][j]==store[0].a[k][l]){    //寻值时排除空格位 
						fn_temp=fn_temp+abs(i-k)+abs(j-l);
						test=false;
					}
					if(test==false) break;
				}
				if(test==false) break;
			}
		}
	}
	fn_temp=fn_temp+store[num].deep;    //加上节点深度 
	return fn_temp;
}

void kongxy(int num)                   //获得空格坐标 
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(store[num].a[i][j]==0){
				store[num].x=i;
				store[num].y=j;
			}
		}

	}
	return;
}

int main()
{
	cout<<"-----------A*算法解决8数码问题------------"<<endl;
	while(true){
		store.clear();              //清空store 
		vector<int> open;           //建立open表 
		int i,j,m,n,f;
		int min;                    //store[min]储存fn值最小的节点 
		int temp;
		bool test;
		top=1;                     //当前节点在store的位置,初始节点在store[1] 

		int target[9];               
		int begin[9];              //储存初始状态和目标状态,用于判断奇偶 

		int t1=0,t2=0;             //初始状态和目标状态的奇偶序数 

		node node_temp;            

		store.push_back(node_temp);
		store.push_back(node_temp); //用于创建store[0]和store[1],以便下面使用 

		cout<<"请输入初始数码棋盘状态,0代表空格："<<endl; //输入初始状态,储存在store[1]中 
		test=false;
		while(test==false){
			f=0;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					cin>>temp;
					store[1].a[i][j]=temp;
					begin[f++]=temp;
				}
			}
			test=true;
			for(i=0;i<8;i++){             //检查是否有重复输入,若有则重新输入 
				for(j=i+1;j<9;j++){
					if(begin[i]==begin[j]){
						test=false;
						break;
					}
				} 
				if(test==false) break;
			}
			if(test==false) cout<<"输入重复,请重新输入:"<<endl;
		}                   


		kongxy(1); //找出空格的坐标 

		cout<<"请输入目标数码棋盘状态,0代表空格： "<<endl;  //输入目标状态,储存在store[0]中 
		test=false;
		while(test==false){
			f=0;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					cin>>temp;
					store[0].a[i][j]=temp;
					target[f++]=temp;
				}
			}
			test=true;
			for(i=0;i<8;i++){             //检查是否有重复输入,若有则重新输入 
				for(j=i+1;j<9;j++){
					if(target[i]==target[j]){
						test=false;
						break;
					}
				} 
				if(test==false) break;
			}
			if(test==false){
				cout<<"输入重复,请重新输入:"<<endl;
				continue;              //若重复,重新输入 
			}


			for(i=0;i<9;i++){            //检查目标状态与初始状态是否匹配 
				test=false;
				for(j=0;j<9;j++){
					if(begin[i]==target[j]){
						test=true;
						break;
					}
				} 
				if(test==false) break;
			}
			if(test==false) cout<<"输入与初始状态不匹配,请重新输入:"<<endl;
		} 


		for(i=1;i<9;i++){               //判断奇偶序数是否相同,若不相同则无法找到路径 
			for(j=1;i-j>=0;j++){
				if(begin[i]>begin[i-j]){
					if(begin[i-j]!=0) t1++;
				}
			}
		}
		for(i=1;i<9;i++){
			for(j=1;i-j>=0;j++){
				if(target[i]>target[i-j]){
					if(target[i-j]!=0) t2++;
				}
			}
		}
		if(!(t1%2==t2%2)){
			cout<<"无法找到路径."<<endl;
			cout<<endl;
			//system("pause");
			//return 0;
			continue;
		}

		LARGE_INTEGER Freg;
		LARGE_INTEGER Count1,Count2;
		QueryPerformanceFrequency(&Freg);
		QueryPerformanceCounter(&Count1);//获取时间Count1
		double d;

		store[1].father=0;           //初始化参数 
		store[1].gone=0;
		store[1].deep=0;             //初始节点的父节点为0 
		store[1].fn=get_fn(1);

		if(check(1)){               //判断初始状态与目标状态是否相同 
			print(1);
			//system("pause");
			//return 0;
			cout<<endl;
			continue;
		}

		open.push_back(1);         //把初始状态在store中的位置数压入open表中 

		while(!open.empty()){     //当open表不为空时,开始寻找路径 
			if(check(top)) break;
			min=top;
			int i_min=0;

			for(i=0;i<open.size();i++){     //遍历open表中元素,找出store中fn值最小的节点 
				if(store[open[i]].fn<=store[min].fn&&store[open[i]].gone==0){
					min=open[i];
					i_min=i;
				}
			}
			store[min].gone=1;    
			open.erase(open.begin()+i_min);  //把最小节点标记遍历过,并从open表中删除

			m=store[min].x;              
			n=store[min].y;                 //空格坐标 

			for(f=0;f<4;f++){               //上下左右移动空格 
				i=m+mx[f];
				j=n+my[f];

				if(i>=0&&i<=2&&j>=0&&j<=2){      //当变换后的空格坐标在矩阵中时,开始移动 
					top++;
					store.push_back(store[min]);   //把store[min]压入store中成为新增节点,位置为store[top] 
					store[top].father=min;         //新增节点的父节点为min 
					store[top].gone=0;             //新增节点未被访问 
					store[top].deep=store[min].deep+1;  //新增节点的深度为父节点深度+1 

					temp=store[top].a[m][n];           //交换空格与相邻数字 
					store[top].a[m][n]=store[top].a[i][j];
					store[top].a[i][j]=temp;

					store[top].x=i;                //移动后的空格坐标 
					store[top].y=j;
					store[top].fn=get_fn(top);     //移动后的fn值 

					open.push_back(top);           //把top压入open表中 
					if(check(top)){                //检查是否到达目标 
						print(top);
						//system("pause");
						//return 0;
						break;
					}

					if(search(top)==false){     //检查新增节点是否被访问过,若访问过,则删除此节点 
						top--;
						store.pop_back();
						open.pop_back();

					}
				}
			}
		}

		QueryPerformanceCounter(&Count2);//获取时间Count2
		d=(double)(Count2.QuadPart-Count1.QuadPart)/(double)Freg.QuadPart*1000.0;//计算时间差，d的单位为ms.
		cout<<"算法时间为为"<<d<<" ms."<<endl;

		cout<<endl;
	}

	return 0;
	system("pause");
}
