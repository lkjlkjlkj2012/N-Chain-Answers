#include <iostream>
#include <conio.h>
using namespace std;
const int N=10005;
int n,now[N],to[N],num=0;
string oper_to[3]={"push off","unknow","push on"};
void pause(string i="push any key to continue...")
{
	/*cout<<i;
	getch();
	cout<<"\n";*/
}
void push(int c,int oper)
{
	if(now[c]==0&&oper==-1||now[c]==1&&oper==1)
		return;
	if(c<n)
	{
		push(c+1,1);
		for(int i=c+2;i<=n;i++)
			push(i,-1);
	}
	cout<<oper_to[oper+1]<<" number "<<c<<"\n";
	pause();
	now[c]+=oper;
	num++;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>now[i];
	for(int i=1;i<=n;i++)
		cin>>to[i];
	for(int i=1;i<=n;i++)
		if(now[i]!=to[i])
			push(i,to[i]-now[i]);
	cout<<"You are finish "<<n<<"chain!You do "<<num<<" steps.";
	pause();
	return 0;
}
