#include <stdio.h>
void merge(int*a,int lo,int mid,int hi){
    int b[hi+1];
    int i=lo,j=mid+1,k=lo;
    while(i<=mid && j<=hi)
    {
        if(a[i]<a[j])
        b[k++]=a[i++];
        else
        b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=hi)
        b[k++]=a[j++];
    for(int q=lo;q<=hi;q++)
        a[q]=b[q];
}
void sort(int *a, int n)
{
    int p;
    for( p=2;p<=n;p=p*2)
    {
        for(int i=0;i+p-1<n;i+=p)
        {
            merge(a,i,i+(p-1)/2,i+p-1);
        }
    }
    if(p/2<n)
    {
        merge(a,0,(p-1)/2,n-1);
    }
}


int main()
{
    int n;
    int a[1000];
    printf("Enter number of elements in array:\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
}
sort(a,n);
printf("Sorted array is:")
for(int k=0;k<n;k++)
printf("%d ",a[k]);
return 0;