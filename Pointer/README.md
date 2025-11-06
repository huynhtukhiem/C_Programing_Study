file này thể hiện các nội dung sau:
- Lý thuyết về con trỏ: Định nghĩa, khai báo, các toán tử
- Hàm trong lập trình C
- Mối liên hệ giữa hàm và con trỏ

# Lý thuyết cơ bản về con trỏ
Con trỏ là một biến lưu địa chỉ của một biến nằm ở trong bộ nhớ
```
int a = 10;
printf("%d", &a);// In ra địa chỉ của biến a, giả sử như 10000000
```
Khi ta viết int a = 10 thì biến a có giá trị là 10 và được lưu ở trong bộ nhớ tại một địa chỉ nào đó và ta có thể in ra bằng toán tử &
```
int a = 10;
printf("%d", &a); // In ra địa chỉ của a trong bộ nhớ, ví dụ 10000000
int *p;  // hoặc int* p ta khai bao con trỏ p
*p = &a; // Lúc này p đang lưu địa chỉ của biến a
printf("%d", p); // In ra địa chỉ của a cũng là giá trị của con trỏ p, 10000000
printf("%d", *p); // In ra giá trị của a cũng là giá trị tại địa chỉ của con trỏ p
```
Như vậy kết luận: Khi con trỏ trỏ tới một biến
  - Địa chỉ của biến = Giá trị con trỏ = 10000000
  - Giá trị của biến = Giá trị tại địa chỉ của con trỏ = 10
  
# Phân biệt các loại toán tử
| Biểu thức | Ý nghĩa |
|:----------| :--------| 
| a | 10 (Giá trị của a) |
| &a | Toán tử in ra địa chỉ của a, ví dụ 10000000 |
| int *p = &a | Khai báo con trỏ trỏ tới a, p mang giá trị là địa chỉ của a: 10000000 |
| *p | giá trị tại địa chỉ của p là giá trị của a = 10 |

# Ứng dụng của con trỏ
Con trỏ có rất nhiều ứng dụng khác nhau như cấp phát động, tối ưu hiệu năng, dùng trong các cấu trúc dữ liệu khác như linked list, tree,...

Tuy nhiên, một ứng dụng quan trọng nhất mà khi chúng ta đã nắm rõ được nó, ta đã nắm rõ 80% các bài toán phức tạp trong C, đó là: **Thay đổi giá trị của biến trong hàm**. Nó liên quan đến các khái niệm như sau:
  - Biến gốc và bản sao của biến
  - Truyền tham số và truyền địa chỉ
  - Truy cập vào địa chỉ của biến gốc

Đây là phần rất phức tạp nhưng khi đã hiểu và nắm rõ được thì cũng sẽ nắm rõ được các bài toán liên quan đến lập trình C

# Hàm trong lập trình C
Hàm là một khối lệnh được đặt tên và dùng để giải quyết một nhiệm vụ.

Ứng dụng lớn nhất của hàm là tái sử dụng, thay vì phải viết đi viết lại các đoạn code thì ta có thể gọi hàm để rút gọn đoạn code
```
<kiểu trả về> ten_ham(<danh sách tham số>) {
    // thân hàm
    return <giá trị>; // nếu hàm có kiểu trả về khác void
}
```
```
int cong(int a, int b) {
    return a + b;
}

int main() {
    int tong = cong(2, 3);
    printf("%d", tong); // 5
}
```
