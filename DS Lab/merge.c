#include<stdio.h>

void merge(int *a, int n, int *b, int m, int *c){
	int i=0;
	int j=0;
	int k =0;
	while(i<n && j<m){
		if(a[i]<b[j]){
			c[k++]=a[i++];
		}
		else if(b[j]<a[i]){
			c[k++]=b[j++];	
		}
		else{
		
			c[k++]=a[i++];
			c[k++]=b[j++];
		}
	}
	
	while(i<n){
		c[k++]=a[i++];
	}
	
	while(j<m){
		c[k++]=b[j++];
	}
}

int main(){
	int n=10;
	int a[]={1,3,5,7,9,11,13,15,17,19};
	int m=5;
	int b[]={0,2,4,6,8};
	int c[15];
	merge(a,n,b,m,c);
	for(int i = 0  ; i < m+n ; i++){
		printf("%d ", c[i]);
	}
}