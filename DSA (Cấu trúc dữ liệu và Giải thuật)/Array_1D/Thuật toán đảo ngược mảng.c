#include<stdio.h>
#include<windows.h>
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
// Hàm đảo ngược mảng
void Dao_nguoc(int n, int a[]){
    // In từ cuối về đầu
    for(int i = n-1; i >= 0; i--){
        printf("%d ", a[i]);
    }
// Kích thước của mảng là 5, bắt đầu từ vị trí 0 -=> phần tử cuối có vị trí 4 => in từ số 5-1 = 4 về 0
}

int main(){
    SetConsoleOutputCP(65001); // Dùng để in ra tiếng việt ở màn hình console
    int n;
    printf("Nhập kích thước mảng: ");
    scanf("%d", &n);
    int a[n];
    Nhap_mang(n,a);
    Dao_nguoc(n,a);
    return 0;
}
