#include <iostream>
#include <iomanip>
using namespace std;
int a[9]={0},sum=0;
bool b[9]={0},c[17]={0},d[17]={0};

void print()
{
	sum++;
	for(int i=1;i<=8;i++)
		cout<<setw(4)<<a[i];
	cout<<endl;
}

void search(int i)
{
	for(int j=1;j<=8;j++)
		if((!b[j])&&((!c[i+j])&&(!d[i-j+7]))) //判断当前列，两个对角是否能放置皇后,d+7是因为下标不能为负数 
		{
			a[i]=j; //i是行，j是该行皇后在哪列	
			b[j]=1; //该列被占据
			c[i+j]=1;
			d[i-j+7]=1; //两对角线被占据
			if(i==8) print(); //八个皇后全部放完 
			else search(i+1); 
			b[j]=0;
			c[i+j]=0;
			d[i-j+7]=0; //回溯一步找下一种方案 
		} 
}

int main()
{
	search(1);
	cout<<"sum="<<sum<<endl;
	return 0;
}
