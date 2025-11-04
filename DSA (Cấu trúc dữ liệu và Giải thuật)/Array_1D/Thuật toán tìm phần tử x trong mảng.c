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
// Hàm tìm kiếm phần tử trong mảng (Có vị trí trùng nhau)
void Search(int n, int a[], int x){
    int index = 0; // Phần tử cần tìm ban đầu là duy nhất trong mảng 
    for(int i = 0; i < n; i++){
        if(x == a[i]){
            printf("Phần tử %d nằm ở vị trí %d trong mảng\n",x,i);
            index++;// Tìm được là cộng thêm một đơn vị
        }
    }
    if(!index){ // Nếu index = 0 thì đồng nghĩa là ko có trong mảng
        printf("Không tìm thấy phần tử %d trong mảng", x);
    }
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
    printf("Nhập phần tử cần tìm: ");
    scanf("%d", &x);
    Search(n,a,x);
    return 0;
}
