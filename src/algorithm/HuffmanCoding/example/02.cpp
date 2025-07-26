/*
	Author: Az1r 
	Date: 2022/10/14
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <limits>
#include <queue>
#include <map>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#define MAX_LENTH 100


// 哈夫曼树
struct TreeNode{
	int weight;
	char ch;

	TreeNode* left;
	TreeNode* right;
};
typedef TreeNode* Huff;

// 小根堆
struct HeapNode{
	Huff* data;
	int size;// 堆的大小 
	int cap; //容量 
};
typedef HeapNode* Heap;
Huff T = NULL;

//编码表 
const int N = 128;
int cnt[N];
map<int, string> mp;

Huff CreateNode(char ch, int weight);	//创建一个哈夫曼树的节点 
Heap CreateHeap();						//创建一个小根堆 
void InitHeap(Heap H);					//初始化堆 
void SetHeap(Heap H, int p);			//向下调整堆 
bool IsFull(Heap H);					//判满 
bool IsEmpty(Heap H);					//判空 
bool InsertHeap(Heap H,Huff tree);		//向堆中插入插入 
Huff Pop(Heap H);						//弹出堆中根节点 
void LoadTreeByInput();					//通过输入初始化哈夫曼树 
Huff BuildHuffmanTree(Heap H);			//建立哈夫曼树 
void PrintTree(Huff tree);				//打印哈夫曼树 
void Menu();							//打印菜单 
void CreateDict(Huff tree, string temp);//创建哈夫曼编码表 
void PrintCode();						//打印编码表 
void LoadTreeByFile();					//文件输入哈夫曼树 
void CodeFile();						//编码文本文件 
void Caulcute();						//计算压缩率 
void DecodeFile(Huff tree);				//解码文本文件 

/* 
	test.txt 		英文文本测试文件 
	test_Copy.txt 	英文文本解码文件
	code.txt		哈夫曼编码文件
	huffman.txt		哈夫曼树的结构文件 	
*/ 
int main()
{
	int select = -1;
	while(select)
	{
		system("pause");
		system("cls");
		Menu();
		printf("input your choose: ");
		scanf("%d", &select);
		
		switch(select)
		{
			case 1:
			{
				PrintTree(T);
				break;
			}
			case 2:
			{
				DecodeFile(T);
				break;
			}	
			case 3:
			{
				CodeFile();
				break;
			}
			case 4:
			{
				PrintCode();
			}
			case 5:
			{
				Caulcute();
				break;
			}
			case 0:
			{
				break;
			}
			default:
			{
				break;
			}		 
		}
	}
	return 0;
}

void Menu()
{
	printf("----         Menu         ----");	printf("\n");
	printf("----    1.PrintTree  	  ----");	printf("\n");
	printf("----    2.Decode          ----");	printf("\n");
	printf("----    3.Code            ----");	printf("\n");
	printf("----    4.PrintDictCode   ----");	printf("\n");
	printf("----    5.Caulcute        ----");	printf("\n");
	printf("----    0.Exit            ----");	printf("\n");

}
void Caulcute()
{
	int chTotal = 0;
	int hfmTotal = 0;
	for(int i = 0; i < N; i ++ )
	{
		chTotal += cnt[i];
		hfmTotal += cnt[i] * mp[i].length();
	}
	
	double rate = hfmTotal * 1.0 / ( 8 * chTotal ) * 100; //1个字符占8位 
	cout << "Code rate: " << rate << "%" << "\n"; 
}
void DecodeFile(Huff tree)
{
	ifstream infile;
	infile.open("code.txt");
	
	ofstream outfile;
	outfile.open("test_Copy.txt");
	
	if(infile == NULL || outfile == NULL)
	{
		printf("File open error!\n");
		return;
	}
	
	char temp;
	Huff x = tree;
	
	while(!infile.eof())
	{
		infile >> temp;
		if(infile.fail())//防止读到最后一个字符 
		{
			break;
		}
		if(temp == '0') // 左为 0，右为 1 
		{
			x = x->left;
		}else
		{
			x = x->right;
		}
			
		if(x->left == NULL && x->right == NULL) // 左右儿子都无，那就是叶子节点，即保存字符的节点 
		{
			outfile << x->ch;
			x = tree;
		}
	}
	
	infile.close();
	outfile.close();
	printf("Succeeful decode file!");
}
void CodeFile()
{
	for(int i = 0; i < N; i ++ )
	{
		cnt[i] = 0;
	}
	ifstream infile;
	infile.open("test.txt");
	
	infile >> noskipws; //  控制符，可以读取空格回车 
	
	char ch;
	while(!infile.eof())
	{
		infile >> ch;
		
		if(infile.fail())//防止读到最后一个字符 
		{
			break;
		}
		cnt[(int)ch] ++;
	}
	infile.close();
	
	ofstream outfile;
	outfile.open("huffman.txt");
	
	for(int i = 0; i < N; i ++ )
	{
		if(cnt[i])
		{
			ch = i;
			outfile << ch << cnt[i] << "\n"; //输出到哈夫曼树结构文件中 
		}
	}
	outfile.close();
	
	LoadTreeByFile();
	CreateDict(T, "");
	
	infile.open("test.txt");
	infile >> noskipws;
	outfile.open("code.txt");
	while(!infile.eof())
	{
		infile >> ch;
		if(infile.fail())//防止读到最后一个字符 
		{
			break;
		}
		outfile << mp[(int)ch];
	}
	
	infile.close();
	outfile.close();
	
	printf("Succeeful code file!");
}
void PrintCode()
{
	int total = 0;
	for(int i = 0; i < N; i ++ )
	{
		total += cnt[i];
	}
	for(int i = 0; i < N; i ++ )  // 输出字符,频率,编码 
	{
	
		if(cnt[i])
		{
			float f = cnt[i] * 1.0 / total;
			if(i == 10)
			{
				cout << setw(3) << i << "---- " << "\\n" << "      ---- " << fixed << setprecision(3) << f << "  " << mp[i] << "\n" ; 
			}else if (i == 32)
			{
				cout << setw(3) << i << "---- " << "<space>" << " ---- " << fixed << setprecision(3) << f << "  " << mp[i] << "\n" ; 
			}else
			{
				cout << setw(3)  << i << "---- " << (char)i << "       ---- " << fixed << setprecision(3) << f << "  " << mp[i] << "\n" ; 
			}
		}
	}
}
void CreateDict(Huff tree, string temp)
{
	if(tree)
	{
		if(tree->left == NULL && tree->right == NULL)
		{
			int idx = tree->ch;
			mp[idx] = temp;
		}else
		{
			CreateDict(tree->left, temp + "0");//左 0 
			CreateDict(tree->right, temp + "1");//右 1 
		}
	}
}


Huff CreateNode(char ch, int weight)
{
	Huff Node = (Huff)malloc(sizeof (TreeNode));

	Node->ch = ch;
	Node->weight = weight;
	Node->left = Node->right = NULL;
	return Node;
}
// 堆的构建
Heap CreateHeap()
{
	Heap Node = (Heap)malloc(sizeof (HeapNode));
	
	Node->data = (Huff *)malloc((MAX_LENTH + 1) * sizeof (Huff));
	Node->size = 0;
	Node->cap = MAX_LENTH;
	Node->data[0] = CreateNode('\0',INT_MIN);

	return Node;
}

// 堆的向下调整
void SetHeap(Heap H, int p)
{
	int parent, child;
	int lenth = H->size;

	Huff root = H->data[p];

	for(parent = p; parent * 2 <= lenth; parent = child)
	{
		// 将Child指向Parent的左右子节点中最小者 
		child = parent * 2;
		if((child < lenth) && H->data[child]->weight > H->data[child + 1]->weight){
			child++;
		}
		// 如果child的权重不再小于parent,调整完毕,否则继续进行调整
		if(root->weight <= H->data[child]->weight)
		{
			break;
		}else
		{
			H->data[parent] = H->data[child];
		}
	}
	H->data[parent] = root;

}
// 初始化最小堆
void InitHeap(Heap H)
{
	// 从最后一个节点的父节点开始,一直到根节点1 (0是哨兵节点) 
	for(int i = H->size / 2; i > 0; i --)
	{	
		SetHeap(H,i);
	}
}
// 判空，判满
bool IsFull(Heap H)
{
	return (H->size == H->cap);
}
bool IsEmpty(Heap H)
{
	return (H->size == 0);
}

// 插入堆的操作
bool InsertHeap(Heap H,Huff tree)
{
	if(IsFull(H))
	{
		printf("Full Heap!\n");
		return false; 
	}

	H->size ++;
	int i= H->size;
	// i为最后一个位置，然后一层一层向上过滤 
	for(; H->data[i / 2]->weight > tree->weight; i /= 2)
	{
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = tree;

	return true;
}
// 从堆中取出最小元素的实现
Huff Pop(Heap H)
{
	if(IsEmpty(H))
	{
		printf("Empty Heap!\n");
		return NULL;
	}
	int parent,child;
	int lenth = H->size;
	// 取出根节点
	Huff rootTree = H->data[1];
	// xTree为最后一个元素，同时size-1（因为取出了根节点） 
	Huff xTree = H->data[H->size --];
	// 从根节点下面找出最小的替换上来
	for(parent = 1;parent * 2 <= lenth; parent = child)
	{
		child = parent * 2;
		if((child < lenth) && (H->data[child]->weight > H->data[child+1]->weight))
		{
			child ++;
		}
		if(xTree->weight <= H->data[child]->weight)
		{
			break;
		}else
		{
			H->data[parent] = H->data[child];
		}
	}
	H->data[parent] = xTree;

	return rootTree;
}

// 哈夫曼树的构造
Huff BuildHuffmanTree(Heap H)
{
	// 假设已经无序的将节点保存在堆的data中,
	// 首先要将堆调整为最小堆
	Huff tree;
	InitHeap(H);
	int size = H->size;
	for(int i = 1;i < size; i ++)
	{
		tree = (Huff)malloc(sizeof (TreeNode));
		// 取出两个最小节点，作为这个节点的左右分支
		tree->ch = '\0';
		tree->left = Pop(H);
		tree->right = Pop(H);
		// 计算新的权值
		tree->weight = tree->left->weight + tree->right->weight;
		// 将这个节点再插入最小堆
		InsertHeap(H,tree); 
		
		/* test
		
		*/
	}
	// 取出哈夫曼树根节点(也就是堆顶节点)
	tree = Pop(H);
	return tree; 
}
// 先序遍历哈夫曼树
void PrintTree(Huff tree)
{
	if(tree)
	{
		if((tree->left == NULL) && (tree->right == NULL))
		{
			char ch = tree->ch;
			if(ch == '\n')
			{
				cout << "Leaf  " << setw(3) << tree->weight << " ---- " << "\\n" << "\n" ; 
			}else if(ch == ' ')
			{
				cout << "Leaf  " << setw(3) << tree->weight << " ---- " << "<space>" << "\n" ; 
			}else
			{
				cout << "Leaf  " << setw(3) << tree->weight << " ---- " << ch << "\n" ; 
			}
		}else
		{
			cout << "Node  " << setw(3) << tree->weight << "\n" ; 
		}
		PrintTree(tree->left);
		PrintTree(tree->right); 
	}
}
void LoadTreeByFile()
{
	ifstream infile;
	infile.open("huffman.txt");
	if(infile == NULL)
	{
		printf("load file error!\n");
		return; 
	}
	int weight;
	char ch;
	char temp[20];
	
	Heap heap = CreateHeap();
	
	infile >> noskipws; //  控制符，可以读取空格回车 
	while(!infile.eof())
	{
		infile >> ch;
		infile.getline(temp, 20);
		weight = atoi(temp);
		
		heap->data[++ heap->size] = CreateNode(ch, weight);
	}
	infile.close();
   	T = BuildHuffmanTree(heap);
}
// 哈夫曼树从用户输入
void LoadTreeByInput()
{
	printf("please input your haffman:\n");
	int weight,count;
	char ch;
	char temp[10];

	Heap heap = CreateHeap();
	printf("input data num :");
	scanf("%d", &count); 
	cout << "( data+weight ):" <<endl; 
	for(int i = 1;i <= count; i ++)
	{
		scanf("%s", temp);
		ch = temp[0];
		weight = atoi(temp + 1);
		
		cnt[(int)ch] = weight;
		
		heap->data[i] = CreateNode(ch, weight);
		heap->size ++;
	}
	T = BuildHuffmanTree(heap);
}