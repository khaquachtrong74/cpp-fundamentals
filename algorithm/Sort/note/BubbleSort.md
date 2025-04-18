
---

# Ý tưởng

1. Duyệt phần tử
	1. Vòng lặp ngoài - Quyết định số lần nổi bọt
	2. Vòng lặp trong - Thực hiện việc so sánh và đổi chỗ cho các **Cặp phần tử liền kề** và sau lần lặp của vòng ngoài.
2. So sánh điều kiện và chuyển đổi vị trí nếu thoả mãn
3. Lặp lại làm cho các phần tử **nổi** dần

# Đánh giá

Trường hợp tốt nhất có thể là O(n) xảy ra khi mảng đã được sắp xếp, -> Trong vòng lặp không hoán đổi và thuật toán dừng sớm -> duyệt 1 lần -> Chỉ chạy vòng lặp ngoài
Trường hợp tệ nhất là O(n\*\*2)  Khi thứ tự mảng không có sắp xếp thì vòng lặp ngoài chạy n-1 lần và vòng lặp trong chạy theo cấp số cộng n*(n-1)/2.