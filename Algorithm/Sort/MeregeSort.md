# Ý tưởng thuật toán

1. Dãy số không quá 1 phần tử
2. Dãy số nhiều hơn 1 phần tử thì chia ra 2 phần bằng nhau
3. Sắp xếp 2 dãy con này
4. Gộp 2 dãy có thứ tự thành dãy có kích thước ban đầu.

## Triển khai với [Đệ quy]

Công đoạn ta chia ra làm 2 phần.

1. Chia ra 2 phần bằng nhau, đồng thời sắp xếp
2. Sau đó là gộp lại về.

# Đánh giá

Độ phức tập là O(N*logN) với bất kể dãy số với thứ tự như nào đi nữa.
Đảm bảo được tính ổn định
Tốn bộ nhớ do phải lưu mảng tạm

