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
// Hàm tìm số max và min trong mảng
void Max_Min(int n, int a[]){
    int max = a[0]; // Tạm thời gán cho phần tử đầu tiên là lớn nhất tạm thời
    int min = a[0]; // Tạm thời gán cho phần tử đầu tiên là nhỏ nhất tạm thời
    // Chạy qua hết các phần tử trong mảng
    for(int i = 0; i < n; i++){
        // Nếu phần tử nào mà lớn hơn phần tử đầu tiên thì nó là phần tử lớn nhất tạm thời
        if(a[i] > max){
            max = a[i];
        }
        if(a[i] < min){
            min = a[i];
        }
    }
    printf("Phan tu lon nhat trong mang la: %d\n", max);
    printf("Phan tu nho nhat trong mang la: %d\n", min);
}


int main(){
    int n;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &n);
    int a[n];
    Nhap_mang(n,a);
    In_mang(n,a);
    Max_Min(n,a);

    return 0;
}
