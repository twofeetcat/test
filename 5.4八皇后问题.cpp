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
		if((!b[j])&&((!c[i+j])&&(!d[i-j+7]))) //�жϵ�ǰ�У������Խ��Ƿ��ܷ��ûʺ�,d+7����Ϊ�±겻��Ϊ���� 
		{
			a[i]=j; //i���У�j�Ǹ��лʺ�������	
			b[j]=1; //���б�ռ��
			c[i+j]=1;
			d[i-j+7]=1; //���Խ��߱�ռ��
			if(i==8) print(); //�˸��ʺ�ȫ������ 
			else search(i+1); 
			b[j]=0;
			c[i+j]=0;
			d[i-j+7]=0; //����һ������һ�ַ��� 
		} 
}

int main()
{
	search(1);
	cout<<"sum="<<sum<<endl;
	return 0;
}
