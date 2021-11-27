#include <stdlib.h>
struct SparseMat {
int row, col, val;
struct SparseMat *next;
};
struct SparseMat *InsertAtLast(struct SparseMat *s, int row, int col, int
value){
struct SparseMat *p, *q;
p = (struct SparseMat*)malloc(sizeof(struct SparseMat));
p->row = row;
p->col = col;
p->val = value;
p->next = NULL;
if(s == NULL){ //At head
p->next = s;
s = p;
}
else{
q = s;
while (q->next != NULL) {
q = q->next;
}
p->next = q->next;
q->next = p;
}
return s;
}
struct SparseMat *Read(struct SparseMat *s){
int n;
int i;
int row, col, val;
printf("Enter the number of terms: ");
scanf("%d",&n);
for (i=0; i<n; i++) {
printf("Enter the row and col of term %d: ",i+1);
scanf("%d %d",&row, &col);
printf("Enter the value of term %d: ",i+1);
scanf("%d",&val);
s = InsertAtLast(s, row, col, val);
}
return s;
}
void display(struct SparseMat *s, int row, int col){
if (s == NULL) {
printf("Matrix is empty\n");
return;
}
else{
struct SparseMat *q;
q = s;
for (int i=0; i<=row; i++) {
for (int j=0; j<=col; j++) {
if (q != NULL && (q->row == i && q->col == j)) {
printf(" %d ",q->val);
q = q->next;
}
else{
printf(" %d ",0);
}
}
printf("\n");
}
}
}
struct SparseMat *add(struct SparseMat *s1, struct SparseMat *s2){
struct SparseMat *s = NULL;
struct SparseMat *p = s1;
struct SparseMat *q = s2;
while (p != NULL && q !=NULL) {
if (p->row == q->row) {
if (p->col == q->col) {
s = InsertAtLast(s, p->row, p->col, (p->val + q->val));
p = p->next;
q = q->next;
}
else{
if (p->col < q->col) {
s = InsertAtLast(s, p->row, p->col, p->val);
p = p->next;
}
else{
s = InsertAtLast(s, q->row, q->col, q->val);
q = q->next;
}
}
}
else{
if (p->row < q->row) {
s = InsertAtLast(s, p->row, p->col, p->val);
p = p->next;
}
else{
s = InsertAtLast(s, q->row, q->col, q->val);
q = q->next;
}
}
}
while (p != NULL) {
s = InsertAtLast(s, p->row, p->col, p->val);
p = p->next;
}
while (q != NULL) {
s = InsertAtLast(s, q->row, q->col, q->val);
q = q->next;
}
return s;
}
int main(){
printf("For addition dimensions of S1 and S2 must be same\n\n");
printf("Indexing starts from 0 [means 3rows ~ row=2]\n\n");
struct SparseMat *s1 = NULL;
printf("* Enter the first Sparse Matrix *\n");
int r1,c1;
printf("Enter no of rows for S1: ");
scanf("%d",&r1);
printf("Enter no of columns for S1: ");
scanf("%d",&c1);
s1 = Read(s1);
struct SparseMat *s2 = NULL;
printf("\n** Enter the second Sparse Matrix **\n");
int r2,c2;
printf("Enter no of rows for S2: ");
scanf("%d",&r2);
printf("Enter no of columns for S2: ");
scanf("%d",&c2);
s2 = Read(s2);
struct SparseMat *s = NULL;
s = add(s1, s2);
printf("Sparse Matrix S1-\n");
display(s1,r1,c1);
printf("\nSparse Matrix S2-\n");
display(s2,r2,c2);
printf("\n\nS1 + S2 = \n");
if (r1 == r2 && c1 == c2) {
display(s,r1,c1);
}
else{
printf("Dimensions of S1 and S2 are different\n");
}
return 0;
}