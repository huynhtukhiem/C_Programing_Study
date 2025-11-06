#include<stdio.h>
void Tang(int x){
    x = x + 1;
}
int main(){
    int a = 10;
    Tang(a); // Tôi muốn tăng a lên 1 đơn vị
    printf("%d", a);
    return 0;
}
// Kết quả vẫn là 10
// Vì sao? Ở đây, a trong main và x trong tang là hai biến độc lập, chỉ giống giá trị thôi.
// Khi x++, nó chỉ thay đổi bản sao, không ảnh hưởng a.
// Đây là truyền tham số

#include<stdio.h>
void Tang(int x){
    x = x + 1;
    printf("%d\n", x);
}
int main(){
    int a = 10;
    Tang(a); // Truyền 10 vào gán cho x
    printf("%d", a);
    return 0;
}
// Kết quả: 11 10, 11 mà chúng ta thấy ở đây là giá trị của x trong hàm, a trong main vẫn mang giá trị là 10
// Câu hỏi: Làm sao mà khi truyền a vào hàm, sau đó trong main nó tăng lên 1
// => Truyền địa chỉ

#include<stdio.h>
void Tang(int* x){
    *x = *x + 1;
}

int main(){
    int a = 10;
    Tang(&a); // Truyền địa chỉ của a vào gán cho x
    printf("%d", a);
    return 0;
}
// Kết quả: 11, ta thấy a trong main đã được tăng lên 1 đơn vị
