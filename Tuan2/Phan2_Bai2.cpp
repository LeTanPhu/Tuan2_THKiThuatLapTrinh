#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct HS
{
	int phannguyen;
	int tu, mau;
};
void TaoMangChuaHonSo(HS a[], int& n) {
	printf("\nNhap so luong phan tu:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i].tu = rand() % 100;
		a[i].mau = (rand() % 100)+1;
		a[i].phannguyen = rand() % 100;
	}
}
void XuatMangHS(HS a[], int n) {
	printf("\nDanh sach hon so la: ");
	for (int i = 0; i < n; i++)
	{
		printf("(%d)%d/%d\t", a[i].phannguyen, a[i].tu, a[i].mau);
	}
}
int SoSanh2HS(HS a, HS b) {
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
void ChuyenHSthanhPS(HS a[], int n) {
	int tumoi, maumoi;
	for (int i = 0; i < n; i++)
	{
		tumoi = a[i].phannguyen * a[i].mau + a[i].tu;
		maumoi = a[i].mau;
		printf("\nChuyen doi hon so thu %d thanh phan so:%d/%d", i+1, tumoi, maumoi);
	}
}
void ChuyenPSthanhHS(int tu, int mau) {
	int nguyen = tu / mau;
	int tusomoi = tu % mau;
	printf("\nKet qua:(%d)%d/%d",nguyen,tusomoi,mau);
}
void Tinh2HS(HS a, HS b) {
	float hs1 = (float)(a.phannguyen * a.mau + a.tu) / a.mau;
	float hs2 = (float)(b.phannguyen * b.mau + b.tu) / b.mau;
	float tong = hs1 + hs2;
	float hieu = hs1 - hs2;
	float tich = hs1 * hs2;
	float thuong = hs1 / hs2;
	printf("\nTong cua 2 hs:%.2f", tong);
	printf("\nHieu cua 2 hs:%.2f", hieu);
	printf("\nTich cua 2 hs:%.2f", tich);
	printf("\nThuong cua 2 hs:%.2f", thuong);
}
void InterchangeSort(HS a[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (SoSanh2HS(a[i],a[j])==1) {
				HS temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void SelectionSort(HS a[], int n) {
	int min;
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for (int j = i+1; j < n; j++)
		{
			if (SoSanh2HS(a[min], a[j]) == 1) {
				min = j;
			}
		}
		HS temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}
void DoiCho(HS& a, HS& b) {
	HS temp = a;
	a = b;
	b = temp;
}
int partition(HS a[], int low, int high)
{
	HS pivot = a[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (SoSanh2HS(a[j], pivot) == -1)
		{
			i++;
			DoiCho(a[i], a[j]);
		}
	}
	DoiCho(a[i + 1], a[high]);
	return (i + 1);
}
void QuickSort(HS a[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(a, low, high);
		QuickSort(a, low, pi - 1);
		QuickSort(a, pi + 1, high);
	}
}
int main() {
	HS a[100],b[100],c[100];
	int n;
	printf("\n1.Tao mang chua hon so");
	TaoMangChuaHonSo(a, n);
	printf("\n\n2.Xuat mang chua hon so");
	XuatMangHS(a, n);
	printf("\n\n3.So sanh 2 hon so a[1] va a[2]");
	HS b1 = a[1];
	HS b2 = a[2];
	int SS = SoSanh2HS(b1, b2);
	if (SS == 1) printf("\nHS 1 lon hon HS 2"); else if(SS==-1)
	{
		printf("\nHS 1 be hon HS 2"); 
	}
	else
	{
		printf("\n2 HS bang nhau");
	}
	printf("\n\n4.Chuyen hon so thanh phan so");
	ChuyenHSthanhPS(a, n);
	printf("\n\n5.Chuyen phan so thanh hon so");
	int c1 = rand() % 100;
	int c2 = (rand() % 100) + 1;
	printf("\nPhan so la:%d/%d", c1, c2);
	ChuyenPSthanhHS(c1, c2);
	printf("\n\n6.Tinh 2 hon so a[1] va a[2]");
	Tinh2HS(b1, b2);
	printf("\n\n7.Sap xep mang theo InterchangeSort");
	InterchangeSort(a, n);
	XuatMangHS(a, n);
	printf("\n\n8.Sap xep mang theo SelectionSort");
	TaoMangChuaHonSo(b, n);
	SelectionSort(b, n);
	XuatMangHS(b, n);
	printf("\n\n9.Sap xep mang theo QuickSort");
	TaoMangChuaHonSo(c, n);
	QuickSort(c, 0,n-1);
	XuatMangHS(c, n);
	getch();
}
