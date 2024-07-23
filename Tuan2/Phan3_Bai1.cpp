#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void TaoMang(int a[], int &n) {
	printf("Nhap so luong phan tu:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000;
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}
int KT_SNT(int a) {
	if (a < 2) return 0;
	int count = 0;
	for (int i = 2; i <= a; i++)
	{
		if (a % i == 0) count++;
	}
	if (count < 2) return 1; else return 0;
}
void XuatSNT_NhohonN(int a[],int n) {
	int count=0;
	for (int i = 0; i < n; i++)
	{
		if (KT_SNT(a[i]) == 1 && a[i] < n) { 
			count++;
		printf("%d\t", a[i]); }
	}
	if (count == 0) printf("\nMang khong co so nguyen to nao nho hon n");
}
int KTDauLe(int a) {
	while (a>=10)
	{
		a /= 10;
	}
	if (a % 2 == 1) return 1; else return 0;
}
int TinhTongPTDaule(int a[], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (KTDauLe(a[i]) == 1) tong = tong + a[i];
	}
	return tong;
}
int main() {
	int a[100];
	int n;
	TaoMang(a, n);
	XuatMang(a, n);
	printf("\n");
	XuatSNT_NhohonN(a, n);
	printf("\n%d",TinhTongPTDaule(a, n));
}