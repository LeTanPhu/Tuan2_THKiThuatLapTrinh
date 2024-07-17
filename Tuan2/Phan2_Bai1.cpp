//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//void TaoMang_PThon15(int a[], int &n) {
//	printf("\n1.Cac phan tu ngau nhien lon hon >= 15");
//	printf("\nNhap so phan tu cua mang:");
//	scanf("%d", &n);
//	printf("\nCac phan tu ngau nhien lon hon >= 15\n");
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = 15 + rand() % 100;
//		printf("%d\t",a[i] );
//	}
//}
//void XuatDSMang(int a[], int n) {
//	printf("\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d\t",a[i]);
//	}
//}
//void TaoMang_PTChan(int a[], int &n) {
//	printf("\n2.Cac phan tu ngau nhien chan");
//	printf("\n\nNhap so phan tu cua mang:");
//	scanf("%d", &n);
//	printf("\nCac phan tu ngau nhien toan chan\n");
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand()%1000;
//		if (a[i] % 2 == 0) printf("%d\t", a[i]);
//	}
//}
//int LinearSearch(int a[], int n, int &x) {
//	printf("\nNhap x can tim:");
//	scanf("%d", &x);
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == x) return 1;
//	}
//	return 0;
//}
//void InterchangeSortInCrease(int a[], int n) {
//	for (int i = 0; i < n-1; i++)
//	{
//		for (int j = i+1; j < n; j++)
//		{
//			if (a[i]>a[j]){
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//int BinarySearch(int a[], int n,int &y) {
//	printf("\nNhap y can tim:");
//	scanf("%d", &y);
//	int left = 0,right=n-1;
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (a[mid] == y) return 1;
//		else if (a[mid]<y)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//	return 0;
//}
//void SelectionSort(int a[], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		int min_index = i;
//		for (int j = i+1; j < n; j++)
//		{
//			if (a[j] < a[min_index])
//				min_index = j;
//		}
//		int temp = a[min_index];
//		a[min_index] = a[i];
//		a[i] = temp;
//	}
//}
//void DoiCho(int *a, int *b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int partition(int a[], int l, int r) {
//	int pivot = a[r];
//	int i = l - 1;
//	for (int j = l; j <= r-1; j++)
//	{
//		if (a[j] < pivot) {
//			i++;
//			DoiCho(&a[i], &a[j]);
//		}
//	}
//	DoiCho(&a[i + 1], &a[r]);
//	return (i + 1);
//}
//void QuickSort(int a[], int l,int r) {
//	if (l < r) {
//		int pi = partition(a, l, r);
//		QuickSort(a, l, pi - 1);
//		QuickSort(a, pi + 1, r);
//	}
//}
//int main() {
//	int n,x,y;
//	int a[100],b[100],c[100],d[100];
//	TaoMang_PThon15(a, n);
//	TaoMang_PTChan(b, n);
//	printf("\n3.Tim kiem x trong a theo giai thuat tim kiem tuyen tinh Linear Search");
//	if (LinearSearch(a, n, x) == 1) printf("\nCo tim thay!"); else printf("\nKhong tim thay!");
//	printf("\n4.Sap xep theo thuat toan InterChangeSort mang a");
//	InterchangeSortInCrease(a, n);
//	XuatDSMang(a, n);
//	printf("\n5.Tim kiem x trong a theo giai thuat tim kiem Binary Search");
//	if (BinarySearch(a, n, y) == 1) printf("\nCo tim thay!"); else printf("\nKhong tim thay!");
//	printf("\n6.Sap xep theo thuat toan Selection Sort");
//	TaoMang_PThon15(c, n);
//	SelectionSort(c, n);
//	printf("\nMang da duoc sap xep");
//	XuatDSMang(c, n);
//	printf("\n7.Sap xep theo thuat toan Quick Sort");
//	TaoMang_PThon15(d, n);
//	QuickSort(d, 0, n - 1);
//	printf("\nMang da duoc sap xep");
//	XuatDSMang(d, n);
//	getch();
//}