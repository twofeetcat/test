#include <iostream>
#include <cstdio>
using namespace std;
char a[21][21];
int u[4]={1,0,0,-1},v[4]={0,1,0,-1},maxl=0,m,n;
bool b[21][21]={0},c[27]={0};
void search(int x,int y,int o)
{
	int p,q;
	if(o>maxl) maxl=o;
	for(int i=0;i<4;i++)
	{
		p=x+u[i];
		q=y+v[i];
		int letter = (int)a[p][q]-65;
		if(p>=1 && p<=m && q>=1 && q<=n && (!b[p][q]) && (!c[letter])){
			b[p][q]=1;
			c[letter]=1;
			search(p,q,o+1);
			b[p][q]=0;
			c[letter]=0;
		}
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
		getchar();
	}
	b[1][1]=1;
	c[a[1][1]-65]=1;	
	search(1,1,2);	
	cout<<maxl-1<<endl;
	return 0;
}
