
---

# Ý tưởng

1. Duyệt qua các phần tử, nhờ vào 2 vòng lặp lồng nhau
2. Xét điều kiện nhờ vòng lặp trong, nếu thoả sẽ chuyển đổi vị trí
3. Lặp lại cho tới khi mảng được sắp xếp
# Đánh giá

Độ phức tạp về thời gian sẽ lên tới O(n\*\*2) bởi vòng lặp ngoài mỗi lần di chuyển thì vòng lặp trong sẽ lặp (n-1) (n-2)... -> cấp số cộng (Số lần so sánh và có thể hoán đổi luôn luôn theo cấp số cộng do nó không phụ thuộc vào giá trị phần tử mà dựa vào số lượng phần tử có trong mảng).