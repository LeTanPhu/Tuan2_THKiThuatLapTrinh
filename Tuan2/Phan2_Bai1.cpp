#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void TaoMang_PThon15(int a[], int &n) {
	printf("\nNhap so phan tu cua mang:");
	scanf("%d", &n);
	printf("\nCac phan tu ngau nhien lon hon >= 15\n");
	for (int i = 0; i < n; i++)
	{
		a[i] = 15 + rand() % 100;
		printf("%d\t",a[i] );
	}
}
void TaoMang_PTChan(int a[], int &n) {
	printf("\nNhap so phan tu cua mang:");
	scanf("%d", &n);
	printf("\nCac phan tu ngau nhien toan chan\n");
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%1000;
		if (a[i] % 2 == 0) printf("%d\t", a[i]);
	}
}
int LinearSearch(int a[], int n, int &x) {
	printf("\nNhap x can tim:");
	scanf("%d", &x);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) return 1;
	}
	return 0;
}
void DoiCho(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}
void InterchangeSort(int a[], int n) {

}
int main() {
	int n,x;
	int a[100],b[100];
	TaoMang_PThon15(a, n);
	//TaoMang_PTChan(b, n);
	if (LinearSearch(a, n, x) == 1) printf("\nCo tim thay!"); else printf("\nKhong tim thay!");
	getch();
}