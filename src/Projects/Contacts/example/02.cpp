//在这里插入代码片/*信息录入系统*/

#include<iostream>
#include<string>

#define  Person_Max  1000   //不加分号
using  namespace std;

struct Person                          //联系人结构体
{
	string name;
	int sex;
	int age;
	string telephone_number;
	string adress;
};
struct  Adress_Book               //联系人通讯录结构体（套娃的方法很方便）
{
	int Person_i;
	struct Person Contact_Person_Array[Person_Max];
};



int Exit_Address_Book();                               //退出系统子函数。
void Add_Person(Adress_Book* p);                       //添加联系人。
void Show_Person(Adress_Book*p);                       //显示联系人。
void Delete_Person(Adress_Book*p);                     //删除联系人。
void Find_Person(Adress_Book*p);                       //查找联系人。 
void Change_Person(Adress_Book*p);                     //修改联系人。  
void Clear_All_Person(Adress_Book*p);                  //清空联系人。  

int main()
{
	Adress_Book Book1;
	Book1.Person_i = 0;
	
	
	
	Book1.Person_i = 11; 
	Book1.Contact_Person_Array[1] = { "张三",1,23,"15972506833","湖北省咸宁市通山县" };
	Book1.Contact_Person_Array[2] = { "陈攀",1,33,"15962506852","湖北省咸宁市崇阳县" };
	Book1.Contact_Person_Array[3] = { "李妞",2,43,"13662545832","湖北省咸宁市赤壁县" };
	Book1.Contact_Person_Array[4] = { "陈盼",2,23,"13662545832","湖北省咸宁市通成县" }; 
	Book1.Contact_Person_Array[5] = { "陈盼",2,18,"13662545532","湖北省咸宁市通山县" }; 
	Book1.Contact_Person_Array[6] = { "李大兆",1,43,"15662545832","湖北省咸宁市通山县" };
	Book1.Contact_Person_Array[7] = { "小布",1,33,"13662545892","湖北省咸宁市通山县" };
	Book1.Contact_Person_Array[8] = { "吴哥",1,23,"13662545532","湖北省咸宁市通山县" };
	Book1.Contact_Person_Array[9] = { "陈盼",1,18,"13462545532","湖北省咸宁市崇阳县" };
	Book1.Contact_Person_Array[10] = { "陈希",2,18,"13462545902","湖北省咸宁市崇阳县" };
	Book1.Contact_Person_Array[11] = { "张三",1,24,"15972406833","湖北省咸宁市通山县" };
	

	while (1)
	{
		cout << "\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "\t$$$$$$$$$ 1、添加联系人 $$$$$$$$$" << endl;
		cout << "\t$$$$$$$$$ 2、显示联系人 $$$$$$$$$" << endl;
		cout << "\t$$$$$$$$$ 3、删除联系人 $$$$$$$$$" << endl;
		cout << "\t$$$$$$$$$ 4、查找联系人 $$$$$$$$$" << endl;
		cout << "\t$$$$$$$$$ 5、修改联系人 $$$$$$$$$" << endl;
		cout << "\t$$$$$$$$$ 6、清空联系人 $$$$$$$$$" << endl;
		cout << "\t$$$$$$$$  7、退出通讯录 $$$$$$$$$" << endl;
		cout << "\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "温馨提示：不同的数字选项对应不同的操作，请开始你的操作：" << endl;

		int select ;
		int flag1;     //用于退出系统的标志。
		cout << "请输入你的选择：" ;
		cin >> select;

		switch (select)
		{
		case 1:                                       //1、添加联系人
			Add_Person(&Book1);
			break;
		case 2:                                       //2、显示联系人  
			Show_Person(&Book1);                    
			break;
		case 3:                                       //3、删除联系人
			Delete_Person(&Book1);                    
			break;
		case 4:                                       //4、查找联系人
			Find_Person(&Book1);
			break;
		case 5:                                       //5、修改联系人
			Change_Person(&Book1);                    
			break;
		case 6:                                       //5、清空联系人                  
			Clear_All_Person(&Book1);
			break;
		case 7:
			flag1 = Exit_Address_Book();
			if (flag1 == 1) { system("pause"); return 0; }
			break;
		default:
			cout << "没有此项操作吗，请重新选择。" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}

//退出系统。
int Exit_Address_Book()                                  
{
	int flag;
	cout << "是否确定退出系统：" << endl;
	cout << "\t1、是，选择退出。" << endl;
	cout << "\t2、否，返回菜单。" << endl;
	cout << "请输入你的选择：";
loop:cin >> flag;
	if (flag == 1)
	{
		return flag;
	}
	else if (flag == 2)
	{
		system("cls");
	}
	else
	{
		cout << "没有此项操作吗，请重新选择: ";
		goto loop;
	}
}  //   //tuichu

//添加联系人函数。
void Add_Person(Adress_Book*p)
{
	if (p->Person_i >= Person_Max)                                           //先做个个判断防止存储人员爆满，可通过define修改最大值
	{
		cout << "联系人存储已经到达上限，无法继续添加联系人。" << endl;
		return;
	}
	else 
	{
		loop2:p->Person_i++;                                                 //每加一个人员，计数值加一，结构体素组第一个元素不存储数据（Person_i为0的时候）
		string name;
		cout << "请添加人员姓名：" ;
		cin >> name;
		cout << endl;
		p->Contact_Person_Array[p->Person_i].name = name;
		
		int  sex;
		cout << "请添加人性别：" << endl << "\t1、男" << "\t2、女" << endl;
		loop3: cout << "你的选择是：";
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			cout << endl;
			p->Contact_Person_Array[p->Person_i].sex = sex;
		}
		else
		{
			cout << "您输入有误，请重新选择..." << endl;
			goto loop3;
		}

		int  age;
	    loop1: cout << "年龄范围0-125，请添加人员年龄：" ;
	    cin >> age;
		cout << endl;
		if (age > 200 || age < 0)
		{
			cout << "您输入有误，请重新输入..." << endl;
			goto loop1;
		}
		else
		{
			p->Contact_Person_Array[p->Person_i].age = age;
		}

		string telephone_number;
		cout << "请添加人员联系电话：" ;
		cin >> telephone_number;
		cout << endl;
		p->Contact_Person_Array[p->Person_i].telephone_number = telephone_number;

		string adress;
		cout << "请添加人员家庭住址：" ;
		cin >> adress;
		cout << endl;
		p->Contact_Person_Array[p->Person_i].adress = adress;

		cout << "是否继续添加联系人：" << endl << "\t1、是，继续添加。" << endl << "\t2、否，返回菜单。" << endl<<"你的选择是：";
		int flag2;
		cin >> flag2;
		if (flag2 == 1)
		{
			goto loop2;
		}
		system("cls");
		return;
	}
}

//显示联系人
void Show_Person(Adress_Book*p)
{
	string man = "男";
	string woman = "女";
	if (p->Person_i == 0)
	{
		cout << "通讯录暂时无存储联系人..." << endl;
		cout << "按任意键返回主菜单" << endl;
		system("pause");
		system("cls");
		return;

	}
	else
	{
		for (int i = 1; i <= p->Person_i; i++)                    //通过通讯录结构体中的Person_i;计数值挨个显示
		{
			cout << "\t序号" << i<< "\t姓名：" << p->Contact_Person_Array[i].name << "\t性别: " << (p->Contact_Person_Array[i].sex == 1 ? man : woman)
				<< "\t电话： " << p->Contact_Person_Array[i].telephone_number << "\t家庭住址： " << p->Contact_Person_Array[i].adress << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

//删除联系人
void Delete_Person(Adress_Book*p)
{
	string name;
	int D_Array[Person_Max] = {0};                                 //用来存储相同名字的序号即Person_i的值
	cout << "请输入你要删除的联系人： " << endl;
	cin >> name;
	int j = 0;                                 
	for (int i = 1; i <= p->Person_i; i++)                           //遍历数组查是否有相同的名字
	{
		if (name == p->Contact_Person_Array[i].name)              
		{
			cout << "序号：" << (i) << "\t姓名：" << p->Contact_Person_Array[i].name << "\t性别: " << (p->Contact_Person_Array[i].sex == 1 ? "男" : "女")
				<< "\t电话： " << p->Contact_Person_Array[i].telephone_number << "\t家庭住址： " << p->Contact_Person_Array[i].adress << endl;
			j++;                                    //每有一个重复名字，D_Array[Person_Max] 编号加一
			D_Array[j] = i;                        //记录查到名字的序号，就是该联系人在结构体数组中的位置。
		}
	}
	if (j != 0)
	{
		cout << "一共查找到联系人信息：" << j << "条" << endl;
		cout << "受否确定删除联系人：" << endl << "\t1、是，确定删除。" << endl << "\t2、否，我在想想。" << endl;
		int D_flag1;
		D_loop2: cout << "您的选择是：" << endl;
		cin >> D_flag1;
		if (D_flag1 == 1)
		{
			for (j; j >= 1; j--)
			{
				for (int i = D_Array[j]; i <= p->Person_i; i++)
				{
					p->Contact_Person_Array[i] = p->Contact_Person_Array[i + 1];              //通过覆盖来删除
				}
				p->Person_i--;
			}			
				cout << "删除完毕！"<<endl;
				system("pause");
				system("cls");
			
		}
		else if (D_flag1 == 2)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请您重新选择..." << endl;
			goto D_loop2;
		}


	}
	else
	{
		cout << "查无此人..." << endl;
		system("pause");
		system("cls");
		return;
	}
}

//查找联系人
void Find_Person(Adress_Book*p)
{
	string name;
	Find_Person_loop:cout << "请输入你查找的联系人： " << endl;
	cin >> name;
	int j = 0;
	for (int i = 1; i <= p->Person_i; i++)
	{
		if (name == p->Contact_Person_Array[i].name)
		{
			cout << "序号：" << (i) << "\t姓名：" << p->Contact_Person_Array[i].name << "\t性别: " << (p->Contact_Person_Array[i].sex == 1 ? "男" : "女")
				<< "\t电话： " << p->Contact_Person_Array[i].telephone_number << "\t家庭住址： " << p->Contact_Person_Array[i].adress << endl;
			j++;
		}
	}
	if (j != 0)
	{
		int Find_Person_Flag1;
		cout << "一共查找到联系人信息：" << j << "条" << endl;
		cout << "是否继续查找联系人：" << endl << "\t1、是，继续查找。" << endl << "\t2、否，返回菜单。" << endl;
		Find_Person_loop1:cout << "你的选择是：";
		cin >> Find_Person_Flag1;
		if (Find_Person_Flag1 == 1)
		{
			goto Find_Person_loop;
		}
		else if (Find_Person_Flag1 == 2)
		{
			system("cls");
			return;
		}
		else 
		{
			cout << "输入错误，请您重选择..." << endl;
			goto Find_Person_loop1;
		}
	}
	else
	{
		int Find_Person_Flag2;
		cout << "查无此人..." << endl;
		cout << "是否继续查找联系人：" << endl << "\t1、是，继续查找。" << endl << "\t2、否，返回菜单。" << endl;
		Find_Person_loop2:cout << "你的选择是：";
		cin >> Find_Person_Flag2;
		if (Find_Person_Flag2 == 1)
		{
			goto Find_Person_loop;
		}
		else if (Find_Person_Flag2 == 2)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请您重选择..." << endl;
			goto Find_Person_loop2;
		}
	}

}

//修改联系人
void Change_Person(Adress_Book*p)                     //修改联系人。
{
	string C_name;
	int C_Array[Person_Max] = { 0 };
	cout << "请输入您将要修改的联系人名字: ";
	cin >> C_name;
	int C_j = 0;
	for (int i = 1; i <= p->Person_i; i++)
	{
		if (C_name == p->Contact_Person_Array[i].name)
		{
			C_j++;
			cout << "序号：" << (i) << "\t姓名：" << p->Contact_Person_Array[i].name << "\t性别: " << (p->Contact_Person_Array[i].sex == 1 ? "男" : "女")
				<< "\t电话： " << p->Contact_Person_Array[i].telephone_number << "\t家庭住址： " << p->Contact_Person_Array[i].adress << endl;
			C_Array[C_j] = i;
		}
	}
	if (C_j >= 1)
	{
		string C_name;
		int C_sex;
		int C_age;
		string C_telephone_number;
		string C_adress;
		if (C_j != 1)
		{
			cout << "你所查找的人不只一个，请选择你需要修改第几个联系人的信息（由上到下数）：";
			int C_temp;
		C_loop3:cin >> C_temp;
			cout << "你选择的是序号为“" << C_Array[C_temp] << "”的联系人"<<endl;
			if (C_temp == 0 || C_temp > C_j)
			{
				"输入错误，请重新输入：";
				goto C_loop3;
			}
			C_j = C_temp;
		}
		cout << "姓名修改为：";
		cin >> C_name;
		p->Contact_Person_Array[C_Array[C_j]].name = C_name;
		cout << "性别修改为：" << endl << "\t1、男" << "\t2、女" << endl;
	C_loop: cout << "你的选择是：";
		cin >> C_sex;
		if (C_sex == 1 || C_sex == 2)
		{
			cout << endl;
			p->Contact_Person_Array[C_Array[C_j]].sex = C_sex;
		}
		else
		{
			cout << "您输入有误，请重新选择..." << endl;
			goto C_loop;
		}
	C_loop1: cout << "年龄范围0-125，年龄修改为：";
		cin >> C_age;
		cout << endl;
		if (C_age > 200 || C_age < 0)
		{
			cout << "您输入有误，请重新输入..." << endl;
			goto C_loop1;
		}
		else
		{
			p->Contact_Person_Array[C_Array[C_j]].age = C_age;
		}
		cout << "联系人电话修改为：";
		cin >> C_telephone_number;
		cout << endl;
		p->Contact_Person_Array[C_Array[C_j]].telephone_number = C_telephone_number;
		cout << "人员家庭住址修改为：";
		cin >> C_adress;
		cout << endl;
		p->Contact_Person_Array[C_Array[C_j]].adress = C_adress;
		cout << "修改后人员信息为：" <<endl<< "\t姓名：" << p->Contact_Person_Array[C_Array[C_j]].name << "\t性别: " << (p->Contact_Person_Array[C_Array[C_j]].sex == 1 ? "男" : "女")
			<< "\t电话： " << p->Contact_Person_Array[C_Array[C_j]].telephone_number << "\t家庭住址： " << p->Contact_Person_Array[C_Array[C_j]].adress << endl;
		system("pause");
		system("cls");


	}
	else
	{
		cout << "查无此人..." << endl;
		system("pause");
		system("cls");
		return;
	}

}

//清空联系人
void Clear_All_Person(Adress_Book*p)
{
	int flag;
	cout << "再次确定是否清空所有联系人：" << endl << "\t1、是，确定清空。" << endl << "\t2、否，返回菜单。" << endl;
	loop:Clear_loop1:cout << "你的选择是：";
	cin >> flag;
	if (flag == 1)
	{
		p->Person_i = 0;                                  //逻辑清空，将计数元素Person_i置零。
		cout << "已经清空所有联系人..." << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (flag == 2)
	{
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "输入错误，请您重新选择" << endl;
		goto loop;
	}

}
