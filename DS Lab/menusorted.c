#include <stdio.h>
void display(int *arr, int n)
{
printf("The array elements are:\n");
for (int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}
int binarySearch(int *a, int key, int n)
{
int l = 0;
int h = n;
while (l <= h)
{
int mid = (l + h) / 2;
if (a[mid] == key)
return mid;
else if (key > a[mid])
l = mid + 1;
else if (key < a[mid])
h = mid - 1;
}
return -1;
}
int deleteFromArray(int *arr, int index, int n)
{
if (index >= n)
return -1;
for (int i = index; i < n - 1; i++)
arr[i] = arr[i + 1];
return 1;
}
void insertInArray(int *arr, int x, int n)
{
int i;

for (i = n - 1; (arr[i] > x) && i >= 0; i--)
{
arr[i + 1] = arr[i];
}
arr[i + 1] = x;
}
void menu(){
printf("\nMENU Options\n");
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Search\n");
printf("4.Display\n");
printf("5.EXIT\n");
}
int main()
{
int choice, n = 0;
int arr[1000];
do{
int x;
menu();
printf("Enter Your Choice:");
scanf("%d", &choice);
switch (choice){
case 1:
printf("Enter element to be inserted:");
scanf("%d", &x);
    insertInArray(arr, x, n);
    n++;
printf("Element inserted successfully!\n");
break;
case 2:
printf("Enter index to be deleted:");
scanf("%d", &x);
if (deleteFromArray(arr, x, n) == -1)
printf("Invalid Index\n");
else{
printf("Element Deleted Successfully!\n");
n--;
}
break;

case 3:
printf("Enter element to be searched:");
scanf("%d", &x);
if (binarySearch(arr, x, n) == -1)
printf("Element Not Found\n");
else
printf("Element found at %d index\n",

binarySearch(arr, x, n));
break;
case 4:
display(arr, n);
break;
default:
break;
}
} while (choice != 5);
return 0;
}