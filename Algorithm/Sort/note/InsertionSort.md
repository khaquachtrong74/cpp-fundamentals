
---

# Ý tưởng 

1. Bắt đầu với phần tử thứ 2 sau đó so sánh nó với các phần tử phía trước
2. Ta sẽ tìm vị trí thích hợp trong phần mảng đã sắp xếp và chè phần tử đang xét
3. Thoả điều kiện sẽ sắp xếp
4. Nới dần giới hạn, lặp lại cho đến khi tất cả phần tử đã sắp xếp

# Đánh giá

Xét về mặt thời gian thực thi thì mức độ phức tạp của nó có thể được xem là công thức tổng của cấp số cộng: O(n(n-1)/2) và ta có thể xem nó là O(n**2). Trong trường hợp _tốt nhất_ thì có thể đạt là O(n)