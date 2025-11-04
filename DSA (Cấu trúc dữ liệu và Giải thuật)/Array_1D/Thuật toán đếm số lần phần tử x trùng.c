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

void Count(int n, int a[], int x){
    int count = 0;
    // Duyệt qua các phần tử trong mảng
    for(int i = 0; i < n; i++){
        if(x == a[i]){
            count++; // Nếu x mà bằng phần tử trong mảng => cộng thêm 1 giá trị cho biến count
        }
    }
    printf("Phần tử %d có số lần lặp lại là: %d\n",x,count);

}

int main(){
    SetConsoleOutputCP(65001); // Dùng để in ra tiếng việt ở màn hình console
    int n;
    printf("Nhập kích thước mảng: ");
    scanf("%d", &n);
    int a[n];
    Nhap_mang(n,a);
    In_mang(n,a);
    int x;
    printf("Nhập số cần xác định số lần lặp: ");
    scanf("%d", &x);
    Count(n,a,x);
    return 0;
}
