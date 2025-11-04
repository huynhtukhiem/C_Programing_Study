# Lý thuyết về mảng, mảng 1 chiều trong lập trình C
- Mảng là tập hợp các biến (các phần tử) có cùng một kiểu dữ liệu, VD: 1,2,3,4,5 đều có kiểu dữ liệu là số nguyên hoặc VD: "Huynh", "Tu", "Khiem" đều có kiểu dữ liệu là chuỗi.
```
int a[5] = {1,2,3,4,5}; // Đều có kiểu dữ liệu số nguyên (int)
char *a[] = {"Huynh", "Tu", "Khiem"};// Đều có kiểu dữ liệu là chuỗi kí tự (cách khai báo bằng con trỏ)
```
- Các phần tử có thể được truy cập trực tiếp thông qua chỉ số của chúng <=> mỗi phần tử có một chỉ số. Phần tử đầu tiên trong mảng có chỉ số là 0
- Các phần tử trong mảng được lưu liên tiếp nhau trong bộ nhớ. VD:  
```
int a[5] = {1,2,3,4,5};
for(int i = 0; i < 5; i++){
  printf("%d\n", &a[i]); // in ra địa chỉ của các phần tử trong mảng a ở dạng thập phân
}
```
Kết quả
```
308279344
308279348
308279352
308279356
308279360
```
- Kích thước của mảng tĩnh và mảng biến thiên là cố định sau khi khai báo, không thể thay đổi trong khi chương trình đang chạy, việc chúng ta nhìn thấy sự thay đổi phần tử của mảng khi đang chạy chẳng qua là nhờ một biện pháp khác, một kỹ thuật lập trình chứ không trực tiếp thay đổi kích thước của mảng đó. Ví dụ như sau:
```
int n;
int a[3] = {1,2,3}
printf("Thêm 1 phần tử vào mảng: );
scanf("%d", &n);
int b[4];
b[0] = 1; b[1] = 2; b[2] = 3;
b[4] = n;
for(int i = 0; i < 4; i++){
  printf("%d ", b[i]);
}
```
Chúng ta chỉ có thể thay đổi kích thước của mảng trong khi đang chạy chương trình bằng mảng động (mảng khai báo bằng cấp phát động)
```
    int *a = malloc(3 * sizeof(int));  // Cấp phát mảng 3 phần tử
    a[0] = 1; a[1] = 2; a[2] = 3;
    // Tăng kích thước mảng lên 5 phần tử:
    a = realloc(a, 5 * sizeof(int));
    a[3] = 4; a[4] = 5;
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    free(a);
```


# Phân biệt mảng biến thiên và mảng động
Trước hết chúng ta có thể khai bao một mảng bằng cách đơn giản như sau: `int a[3] = {1,2,3};` đây gọi là mảng tĩnh với kích thước và phần tử được biết trước khi compile

Chúng ta có thể tùy chọn kích thước và phần tử của mảng trong quá trình compile (chương trình đang chạy) bằng cách khai báo mảng biến thiên (Variable Length Array - VLA) như sau:
```
int n;
printf("Nhập kích thước cuả mảng");
scanf("%d", &n);
int a[n];
for(int i = 0; i < n; i++){
  printf("Nhập phần tử thứ %d của mảng: ", i);
  scanf("%d", &a[i]);
}
```
Tuy nhiên chúng ta nhận thấy rằng, không thể thay đổi trực tiếp kích thước của mảng trong khi đang chạy mà thay vào đó phải tạo ra một mảng mới có kích thước lớn hơn như đề cập ở trên. Vì vậy mảng động ra đời để giải quyết bài toán này.
```
    int *a = malloc(3 * sizeof(int));  // Cấp phát mảng 3 phần tử
    a[0] = 1; a[1] = 2; a[2] = 3;
    // Tăng kích thước mảng lên 5 phần tử:
    a = realloc(a, 5 * sizeof(int));
    a[3] = 4; a[4] = 5;
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    free(a);
```
Một số đặc điểm của mảng động:
 - Dữ  được lưu trên heap thay vì trên stack như mảng động
 - Phải tự giải phóng bộ nhớ để tránh rò 
 - Thay đổi được kích thước: Cấp phát dữ liệu vùng mới -> sao chép dữ liệu -> xóa vùng

Bảng so sánh sự khác nhau giữa mảng biến thiên và mảng động

| Tiêu chí | Mảng Biến Thiên (VLA) | Mảng Động (Dynamic Array) |
|----------|---------------------|--------------------------|
| **Cấp phát bộ nhớ** | Tự động trên **stack** | Thủ công trên **heap** (malloc, calloc, realloc) |
| **Giải phóng bộ nhớ** | Tự động khi ra khỏi scope | Cần **free()** thủ công |
| **Thay đổi kích thước** | Không thể thay đổi sau khi tạo; muốn thay đổi phải tạo VLA mới và copy dữ liệu | Có thể thay đổi bằng **realloc()** |
| **Tốc độ truy cập** | Nhanh, O(1) | Nhanh, O(1) nhưng `realloc` có overhead khi mở rộng |
| **Thời gian tồn tại** | Chỉ trong phạm vi scope | Cho đến khi **free()** hoặc chương trình kết thúc |
| **Kích thước** | Giới hạn bởi stack | Lớn hơn, giới hạn bởi heap |
| **Ưu điểm** | Dễ dùng, tự động quản lý | Linh hoạt, thay đổi kích thước, lưu trữ dữ liệu lớn |
| **Nhược điểm** | Không linh hoạt, stack nhỏ | Cần quản lý thủ công, dễ rò rỉ bộ nhớ |
| **Ví dụ khai báo** | `int arr[n];` | `int *arr = malloc(n * sizeof(int));` |

# Các bài tập giải thuật liên quan đến mảng
Cơ bản:
 - Tính tổng, tích, hiệu, trung bình  các phần tử trong mảng
 - Tìm số nhỏ nhất và lớn nhất trong mảng
 - Tìm số nguyên tố, số chính phương, số hoàn hảo,... trong mảng
 - Đếm số lần phần tử x có trong mảng
 - Tìm kiếm phần tử x có trong mảng (phần tử trùng)
 - Tìm kiếm bằng vị trí
 - Đảo ngược mảng
 - Kiểm tra mảng đối xứng

Trung cấp:
 - Thống kê phần tử trong mảng: Xuất hiện nhiều nhất, ít nhất, 
 - Sắp xếp mảng bằng các thuật toán sắp xếp khác nhau
 - Thêm phần tử và sắp xếp
 - Gộp 2 mảng thành 1 và sắp xếp
 - Tách 1 mảng thành 2 mảng con theo đặc điểm (chẳn, lẻ,..)
 - Loại bỏ phần tử bị trùng và sắp xếp

Cao cấp:
 - Gộp n mảng thành 1 và sắp xếp
 - Tách 1 mảng thành n mảng con
 - Tính toán 2 mảng: 2 mảng cộng nhau có cùng kích thước, 2 mảng cộng nhau khác kích thước
 - Tìm dãy con thỏa điều kiện: có tổng, tích lớn, tổng số chẳn lớn nhất,...




