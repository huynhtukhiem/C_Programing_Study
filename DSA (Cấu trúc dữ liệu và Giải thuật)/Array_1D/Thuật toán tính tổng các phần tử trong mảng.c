#include<stdio.h>
// Hàm nhập mảng
void Nhap_mang(int n, int a[]){
    for(int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &a[i]);
    }
}
// Hàm in mảng
void In_mang(int n, int a[]){
    for(int i =0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm tính tổng các phần tử trong mảng
int Tong(int n, int a[]){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    return sum;
}

int main(){
    int n;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &n);
    int a[n];
    Nhap_mang(n,a);
    In_mang(n,a);
    printf("Tong cac phan tu trong mang la: %d\n", Tong(n,a));
    return 0;
}
