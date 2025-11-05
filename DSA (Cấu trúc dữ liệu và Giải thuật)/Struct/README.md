# Lý thuyết và cách dùng cơ bản struct - Một dạng cấu trúc dữ liệu
struct là một kiểu dữ liệu giống với int, float, bool, long long,... và dùng để tập hợp các phần tử/ biến lại với nhau thành một tổ chức. Các dữ liệu trong struct có thể khác nhau về kiểu dữ liệu

VD: trong mảng, các biến/ phần tử phải có cùng một kiểu giá trị: int a[5] = {1,2,3,4,5} 1,2,3,4,5 đều là số nguyên hoặc {"Huynh", "Tu", "Khiem"} đều là các chuỗi kí tự

Trong struct các kiểu dữ liệu có thể là struct Sinhvien = {int tuoi, float diem, char gender}

# Ứng dụng của struct
Mục đích quan trọng nhất của struct là nó giúp ta tổ chức dữ liệu có liên quan hơn, giúp ta dễ dàng quản lí các biến có liên quan đến nhau hơn là khai báo các biến rời rạc

Ví dụ thay vì phải khai báo như sau:
```
int tuoi_A;
in tuoi_B;
int tuoi_C;
float diem_A;
float diem_B;
float diem_C;
char name_A[10];
char name_B[10];
char name_C[10];
```
Ta có thể thay thế bằng struct như sau:
```
struct Sinhvien{
  int tuoi;
  float diem;
  char name[10]
};
int main(){
  struct Sinhvien sv_A = {19, 9.0, "Khiem"};
  struct Sinhvien sv_B = {20, 10, "Khoi"};
  struct Sinhvien sv_C = {18, 8.3, "Khoa"};
}
```
# Cách khai báo struct
Đầu tiên ta sẽ định nghĩa kiểu dữ liệu mới ở ngoài hàm main, kiểu dữ liệu này chứa các kiểu dữ liệu khác. Việc định nghĩa diễn ra ở ngoài hàm main giống với cách chúng ta định nghĩa một giá trị nào đó: `#define MAX 100 // Định nghĩa biến MAX có giá trị 100`

```
struct Sinhvien{
  ...
};
```
Lúc này ta có thể hiểu (struct Sinhvien) là một kiểu dữ liệu, nó giống với int, float, char, bool,..... đều là kiểu dữ liệu

Sau khi đã định nghĩa ngoài hàm main, bên trong hàm main ta phải khai báo biến, biến có kiểu dữ liệu struct
```
int main(){
  struct Sinhvien sv_A;
  // Hoặc có thể gán luôn giá trị
  struct Sinhvien_B = {19, 10.0, "Khiem"};
}
```
Lúc này ta hiểu `sv_A` là tên biến, `struct Sinh_vien` là kiểu dữ liệu của biến giống như sau:

(int) (a) đồng nghĩa với (struct Sinhvien) (sv_A) đều là (kiểu dữ liệu) (tên biến) 

# Cách truy cập vào phần tử trong struct
Như đã nói ở trên, ban đầu t có thể gán giá trị cho struct bằng cách sau
```
struct Sinhvien sv_B = {19,10.0,"Khiem"};
```
Tuy nhiên nếu chúng ta muốn tự nhập các giá trị của phần tử có thể làm như sau:

Cách 1: Gán trực tiếp bằng code
```
// Dùng toán tử . để truy cập các biến con nằm bên trong sstruct
sv_B.tuoi = 19;
sv.diem = 10.0;
strcpy(sv_B.name, "Khiem"); // Không gán được vì "Khiem" là một mảng mà phải sao chép từng kí tự
```
Cách 2: Nhập từ bàn phím
```
printf("Nhập tuổi sinh viên: ");
scanf("%d", &sv_B.tuoi);

printf("Nhập điểm sinh viên: );
scanf("%f", &sv_B.diem);

getchar(); // ăn kí tự xuống dòng của phần nhập điểm
printf("Nhập tên sinh viên: );
fgets(sv.ten, sizeof(sv.ten), stdin); // nhập chuỗi có khoảng trắng
sv.ten[strcspn(sv.ten, "\n")] = '\0';  // xóa ký tự xuống dòng '\n'
```
