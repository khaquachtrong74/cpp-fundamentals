# Tính chất

Là một kỹ thuật sắp xếp dựa trên cấu trúc dữ liệu [Binary_Heap]

# Lý thuyết sắp xếp từ nhỏ tới lớn
1. Tạo Max Heap chứa toàn bộ phần tử cần sắp xếp
2. Phần tử lớn nhất nằm ở root của Heap, đổi chỗ với cuối mảng
3. Giảm size đi 1 và sắp xếp lại Heap
4. Lặp lại cho tới khi xong.

# Đánh giá

Heap sort là một thuật toán sắp xếp tại chỗ
Độ phức tạp của heapify là O(logN) và độ phức tạp tạo và build heap là O(n). Vậy nên độ phức tạp của heap sort là O(nlogN)
