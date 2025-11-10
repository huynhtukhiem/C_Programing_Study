# Khái niệm về single linked list
Danh sách liên kết đơn (single linked list) là một cấu trúc dữ liệu tuyến tính động, nó được tạo thành từ nhiều node nối với nhau bằng con trỏ. Trong mỗi node chứa 2 thành phần:
 - Giá trị của node đó, int, float, double, struct,....
 - Con trỏ trỏ tới node tiếp theo, node cuối trỏ đến NULL

Node đầu tiên là head, node cuối là. Nếu danh sách rỗng thì `head = NULL`

Trong C, NULL là con trỏ rỗng, nghĩa là nó không trỏ đến node nào nữa, hoặc là thông báo thất bại.

#Cách lưu trữ dữ liệu
Khác với Array khi mà các phần tử được lưu trong bộ nhớ theo thứ tự (nằm kế nhau). Linked list được lưu ở những "ô bộ nhớ" bất kì những ô này sẽ được nối với nhau bằng con trỏ. Điều này làm cho linked list dễ mở rộng hơn. Đây cũng là đặc điểm quan trọng nhất của linked list.

# Khi nào dùng single linked list
- Không biết trước số lượng phần tử.
- Thêm/xóa nhiều hơn truy cập ngẫu nhiên.
- Cần dữ liệu linh hoạt trong bộ nhớ, tránh cấp phát mảng quá lớn.

