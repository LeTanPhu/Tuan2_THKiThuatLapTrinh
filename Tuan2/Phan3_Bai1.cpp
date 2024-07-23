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
void LietKetPT(int a[], int n) {
	int max = 1000;
	int dem[1000] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int j = a[i];
		dem[j]++;
	}
	for (int j = 0; j < max; j++)
	{
		if (dem[j] > 0)
		{
			printf("So lan xuat hien cua phan tu %d : %d\n", j, dem[j]);
		}
	}
}
void DoiCho(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void SapXepTangDan(int a[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				DoiCho(a[i], a[j]);
			}
		}
	}
}
void TimSoNhoT2(int a[], int n) {
	SapXepTangDan(a, n);
	printf("Phan tu nho thu 2 la:%d", a[1]);
}
void SapXepChanTang(int a[],int n) {
	for (int i = 0; i < n + 1; i++)
	{
		if (a[i] % 2 == 0) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j] && a[j] % 2 == 0) {
					DoiCho(a[i], a[j]);
				}
			}
		}
	}
}
void SXLeDauChanCuoi(int a[], int n) {
	int l = 0;
	int r = n - 1;
	while (l<r)
	{
		while (a[l] % 2 == 1) l++;
		while (a[r]%2==0)
		{
			r--;
		}
		if (l < r) {
			DoiCho(a[l], a[r]);
			l++;
			r--;
		}
	}
}
int main() {
	int a[100],b[100],c[100];
	int n;
	TaoMang(a, n);
	XuatMang(a, n);
	printf("\n1.Nhap vao so nguyen n và liet ke cac so nguyen to nho hon n");
	XuatSNT_NhohonN(a, n);
	printf("\n\n2.Tong cac phan tu co chu so dau le:%d", TinhTongPTDaule(a, n)); 
	printf("\n3.Liet ke so lan xuat hien cua cac phan tu trong mang\n");
	LietKetPT(a, n);
	printf("\n4.Tim so nho thu 2 trong mang\n");
	TimSoNhoT2(a, n);
	printf("\n\n5.Sap xep phan tu chan tang, phan tu le giu nguyen\n");
	TaoMang(b, n);
	SapXepChanTang(b, n);
	XuatMang(b, n);
	printf("\n\n6.Sap xep so le dau mang, so chan dau mang\n");
	TaoMang(c, n);
	SXLeDauChanCuoi(c, n);
	XuatMang(a, n);
}
