
---

# Ý tưởng

1. Duyệt tất cả phần tử
	1. Vòng lặp ngoài - Duyệt từng vị trí trong mảng (xem phần tử đầu là chưa được sắp xếp)
	2. Vòng lặp trong - Duyệt ngay sau vị trí đầu của phần mảng chưa được **sắp xếp**
2. Duyệt từ phần tử **sau** phần tử đang xét đến cuối, tìm phần tử **nhỏ nhất**
3. Chuyển vị trí giữa 2 phần tử nếu chúng khác nhau
4. Lặp lại cho tới khi sắp xếp xong

# Đánh giá

Độ phức tạp luôn là O(n\*\*2) do mỗi lần duyệt và thì sẽ kiểm tra từ vị trí phần tử sau phần tử đang xét đến hết.