#include<iostream>
using namespace std;
int m,n,k,ans[101][101],h[10001],x[10001],y[10001],a[101][101],maxx;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void qsort(int l,int r){
	if(l>r)return;
	int i=l,j=r,m=h[r],sw;
	while(i<=j){
		while(h[i]<m)i++;
		while(h[j]>m)j--;
		if(i<=j){
			sw=h[i];
			h[i]=h[j];
			h[j]=sw;
			sw=x[i];
			x[i]=x[j];
			x[j]=sw;
			sw=y[i];
			y[i]=y[j];
			y[j]=sw;
			i++;j--;
		}
	}
	qsort(l,j);
	qsort(i,r);
}
int main(){
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 	for(int j=1;j<=m;j++)
 	{
 	    cin>>a[i][j];
 	    k++;
 	    h[k]=a[i][j];
 	    x[k]=i;
 	    y[k]=j;
     }
     qsort(1,k);
     for(int i=1;i<=k;i++){
     	for(int i1=0;i1<4;i1++){
			int xx=x[i]+dx[i1],yy=y[i]+dy[i1];
		    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[x[i]][y[i]]<a[xx][yy]){
		    	if(ans[x[i]][y[i]]+1>ans[xx][yy]){
		    		ans[xx][yy]=ans[x[i]][y[i]]+1;
		    		if(ans[xx][yy]>maxx)maxx=ans[xx][yy];
		    	}
		    }
    	 }
     }
     cout<<maxx+1;
}

