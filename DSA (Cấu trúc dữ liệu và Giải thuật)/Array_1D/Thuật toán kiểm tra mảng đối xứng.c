#include<stdio.h>
#include<windows.h>
void Nhap_mang(int n, int a[]){
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử thứ %d: ", i+1);
        scanf("%d", &a[i]);
    }
}
void In_mang(int n, int a[]){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Doi_xung(int n, int a[]){
    // Duyệt từ đầu đến giữa mảng
    for(int i = 0; i < n/2; i++){
        // Kiểm tra cặp (đầu;cuối) (hai;áp cuối) (...)
        if(a[i] != a[n-1-i]){
            printf("Mảng không đối xứng\n");
            return; // Thoát hàm luôn khi phát hiện ra
        }
    }
    printf("Mảng đối xứng\n");
}

int main(){
    SetConsoleOutputCP(65001);
    int n;
    printf("Nhập kích thước mảng: "); scanf("%d", &n);
    int a[n];
    Nhap_mang(n,a);
    In_mang(n,a);
    Doi_xung(n,a);
    return 0;
    
}
