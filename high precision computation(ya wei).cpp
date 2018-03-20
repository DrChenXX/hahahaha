#include<bits/stdc++.h>
using namespace std;
const int MAXN=80005;
char a[MAXN],b[MAXN];
long long shu1[MAXN],shu2[MAXN],ans[MAXN];
int main()
{
	scanf("%s",a);
	scanf("%s",b);
	int la=strlen(a),
		lb=strlen(b);
	int wei1=0,x=0;
	for(int i=la-1; i>=0; i--)
	{
		x++;
		shu1[wei1]/=10;
		shu1[wei1]+=(a[i]-'0')*10000000;
		if(x==8){
			wei1++;
			x=0;
		}
	}
	while(x%8){
		shu1[wei1]/=10;
		x++;
	}
	int wei2=0;
	x=0;
	for(int i=lb-1; i>=0; i--)
	{
		x++;
		shu2[wei2]/=10;
		shu2[wei2]+=(b[i]-'0')*10000000;
		if(x==8){
			wei2++;
			x=0;
		}
	}
	while(x%8){
		shu2[wei2]/=10;
		x++;
	}
	for(int i=0;i<=wei1;i++)
		for(int j=0;j<=wei2;j++){
			ans[i+j]+=shu1[i]*shu2[j];
			long long rest=ans[i+j]/100000000;
			ans[i+j]%=100000000;
			int wei=1;
			while(rest){
				ans[i+j+wei]+=rest;
				rest=ans[i+j+wei]/100000000;
				ans[i+j+wei]%=100000000;
				wei++;
			}
		}
	bool flag1=false,
		 flag2=false;
	for(int i=MAXN; i>=0; i--){
		if(ans[i]!=0) flag1=true;
		if(flag2){
			printf("%08lld",ans[i]);
		}
		else if(flag1){
			printf("%lld",ans[i]);
			flag2=true;
		}
	}
	return 0;
} 
