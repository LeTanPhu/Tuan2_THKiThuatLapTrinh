#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
struct HS
{
	int phannguyen;
	int tu, mau;
};
struct PS {
	int tu, mau;
};
void TaoMangChuaHonSo(HS a[], int& n) {
	printf("\nNhap so luong phan tu:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i].tu = rand() % 100;
		a[i].mau = (rand() % 100) + 1;
		a[i].phannguyen = rand() % 100;
	}
}
void XuatMangHS(HS a[], int n) {
	printf("\nDanh sach hon so la: ");
	for (int i = 0; i < n; i++)
	{
		printf("(%d)%d/%d\t", a[i].phannguyen, a[i].tu, a[i].mau);
	}
}int SoSanh2HS(HS a, HS b) {
	if (a.phannguyen > b.phannguyen) { return 1; }
	else if (a.phannguyen < b.phannguyen) {
		return -1;
	}
	else
	{
		int PSa = a.tu * a.mau;
		int PSb = b.tu * b.mau;
		if (PSa > PSb) { return 1; }
		else if (PSa < PSb) { return -1; }
		else return 0;
	}
}
int LinearSearch(HS a[], int n,HS x) {
	for (int i = 0; i < n; i++)
	{
		if (SoSanh2HS(a[i], x) == 0) { return i; }
	}
	return -1;
}
void DoiCho(HS& a, HS& b) {
	HS temp = a;
	a = b;
	b = temp;
}
void SapXep_NguyenChanDau_LeNguyenCuoi(HS a[], int n) {
	int l = 0;
	int r = n - 1;
	while (l<r)
	{
		if (a[l].phannguyen % 2 == 0) l++;
		if (a[r].phannguyen % 2 != 0) r--;
		if (l < r) {
			DoiCho(a[l], a[r]);
			l++;
			r--;
		}
	}
}
void SapXepTang(HS a[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (SoSanh2HS(a[i], a[j]) == 1) {
				DoiCho(a[i], a[j]);
			}
		}
	}
}
int BinarySearch(HS a[], int n,HS x) {
	int l = 0;
	int r = n - 1;
	while (l<=r)
	{
		int mid = (l + r) / 2;
		if(SoSanh2HS(a[mid],x)==0) return mid;
		else if (SoSanh2HS(a[mid], x) == 1) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}
void XoaPTThuK(HS a[], int n, int k) {
	for (int i = k; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void ThemPTThuK(HS a[], int n, int k,HS &x) {
	printf("\nNhap hon so can them:");
	scanf("%d%d%d", &a->phannguyen, &a->tu, &a->mau);
	for (int i = n; i > k; i--)
	{
		a[i] = a[i - 1];
	}
	a[k] = x;
	n++;
}
void ChuyenHSthanhPS(HS a[], int n,PS c[]) {
	for (int i = 0; i < n; i++)
	{
		c[i].tu = a[i].phannguyen * a[i].mau + a[i].tu;
		c[i].mau = a[i].mau;
	}
}
void MangClaPS(PS c[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("Phan so thu %d: %d/%d\n", i + 1, c[i].tu, c[i].mau);
	}
}
float TongCacPT(HS a[], int n) {
	float tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong = tong + ((float)(a[i].phannguyen * a[i].mau + a[i].tu)/a[i].mau);
	}
	return tong;
}
void XuatPTNguyenChan(HS a[], int n) {
	for (int i = 0; i < n; i++)
	{
		if (a[i].phannguyen % 2 == 0) printf("\nVi tri la %d", i);
	}
}
int main() {
	HS a[1000];
	PS b[1000];
	int n;
	HS x,y;
	x.phannguyen = rand() % 100;
	x.tu = rand() % 100;
	x.mau = 1+(rand() % 100);
	TaoMangChuaHonSo(a, n);
	XuatMangHS(a, n);
	printf("\n1.Tim kiem hon so x trong mang theo LinearSearch\n");
	if (LinearSearch(a, n, x) == 1) printf("\nTim thay x\n"); else printf("\nKhong tim thay\n");
	printf("\n2.Sap xep phan nguyen chan len dau, phan nguyen le cuoi");
	SapXep_NguyenChanDau_LeNguyenCuoi(a, n);
	XuatMangHS(a, n);
	printf("\n3.Tim kiem x theo thuat toan Binary");
	if (BinarySearch(a, n, x) == 1) printf("\nTim thay x\n"); else printf("\nKhong tim thay\n");
	printf("\n4.Xoa phan tu thu k");
	XoaPTThuK(a, n, 3);
	XuatMangHS(a, n);
	printf("\n5.Them phan tu thu k");
	ThemPTThuK(a, n, 5, y);
	XuatMangHS(a, n);
	printf("\n6.Mang C chua cac phan tu la phan so duoc doi tu mang b\n");
	ChuyenHSthanhPS(a, n, b);
	MangClaPS(b, n);
	printf("\n7.Tinh tong cac phan tu trong mang b:%.2f", TongCacPT(a, n));
	printf("\n8.Xuat vi tri phan tu nguyen chan");
	XuatPTNguyenChan(a, n);
}