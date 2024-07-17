#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct HS
{
	int phannguyen;
	int tu, mau;
};
void TaoMangChuaHonSo(HS a[], int &n) {
	printf("\nNhap so luong phan tu:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i].tu = rand() % 100;
		a[i].mau = rand() % 100;
		a[i].phannguyen = rand() % 100;
		if (a[i].mau == 0) return;
	}
}
void XuatMang(HS a[], int n){
	printf("\nDanh sach hon so la: ");
	for (int i = 0; i < n; i++)
	{
		printf("(%d)%d/%d\t",a[i].phannguyen,a[i].tu,a[i].mau);
	}
}
int UCLN(int a, int b) {
	if (a == b) return 1;
	while (a!=b)
	{
		if (a>b) a -= b; else
		{
			b -= a;
		}
	}
	return a;
}
int ChuyenHSvePS(HS a) {
	return a.tu = a.phannguyen*a.mau + a.tu;
}
void SoSanh2HS(HS a, HS b) {
	ChuyenHSvePS(a);
	ChuyenHSvePS(b);
	int temp=UCLN(a.mau, b.mau);
	if (a.tu*temp > b.tu*temp) printf("\nHon so 1 > hon so 2"); else if (a.tu*temp==b.tu*temp) 
	{
		printf("\nHai hon so bang nhau"); 
	}
	else
	{
		printf("\nHon so 1 < hon so 2");
	}
}
int main(){
	HS a[100];
	int n;
	TaoMangChuaHonSo(a, n);
	XuatMang(a, n);
	HS b,c;
	/*b.tu = 1;
	b.mau = 2;
	b.phannguyen = 1;
	c.tu = 1;
	c.mau = 2;
	c.phannguyen = 2;
	SoSanh2HS(b, c);*/
	getch();
}