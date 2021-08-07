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
	int n;
	int a[100];
	int m;
	int b[100];
	int c[200];
	printf("Enter number of elements in array 1:\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(int i =0; i<n; i++){
		scanf("%d",&a[i]);
	}
	printf("Enter number of elements in array 2:\n");
	scanf("%d",&m);
	printf("Enter the elements\n");
	for(int i =0; i<m; i++){
		scanf("%d",&b[i]);
	}
	merge(a,n,b,m,c);
	for(int i = 0  ; i < m+n ; i++){
		printf("%d ", c[i]);
	}
}