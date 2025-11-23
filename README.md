
# Đăng ký tài khoản (User Registration)

## 1. Mô tả chức năng
Cho phép người dùng tạo tài khoản mới bằng cách nhập thông tin cá nhân hợp lệ và đồng ý với Chính sách Quyền riêng tư.  
Người dùng truy cập trang **Register**, điền các trường thông tin bắt buộc và gửi biểu mẫu.  
Hệ thống sẽ kiểm tra tính hợp lệ của từng trường, kiểm tra sự trùng khớp mật khẩu, và yêu cầu người dùng phải chấp nhận **Privacy Policy** trước khi tạo tài khoản.

---

## 1.1 Use Case Testing
- **Test 1:** Flow đi từ điểm đầu đến *“Required field missing”*
- **Test 2:** Flow đi từ điểm đầu đến *“Invalid field”*
- **Test 3:** Flow đi từ điểm đầu đến *“Passwords do not match”*
- **Test 4:** Flow đi từ điểm đầu đến *“Privacy must be accepted”*
- **Test 5:** Flow đi từ điểm đầu đến *“Registration Successful”*

Mỗi flow đại diện cho một đường đi duy nhất trên activity diagram dẫn đến một kết quả khác nhau.

---
### Use Case: User Registration (UC-REG)

| **Field** | **Content** | **Field** | **Content** |
|----------|-------------|-----------|-------------|
| **Use Case ID:** | UC-REG | | |
| **Use Case Name:** | User Registration | | |
| **Created By:** | Huy Truong | **Last Updated By:** | Huy Truong |
| **Date Created:** | 21/11/2025 | **Date Last Updated:** | 21/11/2025 |
| **Actors:** | User (Customer) | | |
| **Description:** | Người dùng điền vào các trường đăng ký; hệ thống xác nhận các trường bắt buộc, định dạng, mật khẩu trùng khớp và chấp nhận quyền riêng tư. | | |
| **Trigger:** | User clicks Register button. | | |
| **Preconditions:** | User is on Register Page. | | |
| **Postconditions:** | Thành công: Tài khoản được tạo.<br>Thất bại: Đăng ký chưa hoàn tất. | | |
| **Normal Flow:** | 1. Người dùng điền đầy đủ thông tin hợp lệ.<br>2. Nhấp Đăng ký.<br>3. Hệ thống xác thực các trường bắt buộc.<br>4. Xác thực mật khẩu trùng khớp.<br>5. Xác nhận Privacy Policy.<br>6. Hiển thị thông báo thành công. | | |
| **Alternative Flow 1:** | Missing field — Hệ thống hiển thị “Thiếu trường bắt buộc”. | | |
| **Alternative Flow 2:** | Invalid field — Hệ thống hiển thị “Trường không hợp lệ”. | | |
| **Alternative Flow 3:** | Password mismatch — Hệ thống hiển thị “Mật khẩu không khớp”. | | |
| **Alternative Flow 4:** | Privacy not accepted — Hệ thống hiển thị “Phải chấp nhận Quyền riêng tư”. | | |
| **Exceptions:** | Lỗi hệ thống trong quá trình xác thực hoặc gửi → Đăng ký bị hủy. | | |
| **Notes & Issues:** | Môi trường demo có thể không hiển thị đầy đủ thông báo xác thực. | | |

---
<img width="814" height="716" alt="image" src="https://github.com/user-attachments/assets/dd06529c-c0da-4eee-9916-c31cd7231173" />
---

## 2. Decision Table – Register Function

Đối với chức năng **Register**, ta có 4 điều kiện kiểm tra:

- **C1:** Có trường bắt buộc nào bị thiếu hay không?  
- **C2:** Có trường nào sai định dạng hay không?  
- **C3:** Password và Confirm Password có trùng nhau không?  
- **C4:** Người dùng có chấp nhận Privacy Policy không?

Vì có 4 điều kiện, một decision table đầy đủ (complete, non-redundant, consistent) sẽ tạo ra **16 rule** (2⁴ = 16).

Tuy nhiên, trong thực tế một số rule **không thể xảy ra** vì hệ thống sẽ dừng ngay khi điều kiện sai ở mức ưu tiên cao hơn xuất hiện.

### Quy tắc phân nhóm rule
- **Rule 1–8:** C1 = True → *Required field missing*  
- **Rule 9–12:** C1 = False, C2 = True → *Invalid field*  
- **Rule 13–14:** C1 = False, C2 = False, C3 = False → *Passwords do not match*  
- **Rule 15:** C1 = False, C2 = False, C3 = True, C4 = False → *Privacy must be accepted*  
- **Rule 16:** Tất cả hợp lệ → *Registration successful*

→ Sau khi gộp rule theo kết quả đầu ra, ta có 5 nhóm rule test:

- **Rule 1–8:** Required field missing  
- **Rule 9–12:** Invalid field  
- **Rule 13–14:** Password mismatch  
- **Rule 15:** Privacy must be accepted  
- **Rule 16:** Registration successful  

---

## Decision Table (Grouped Rules)

| **Conditions / Rule Groups** | **1–8** | **9–12** | **13–14** | **15** | **16** |
|------------------------------|---------|----------|-----------|--------|--------|
| **C1: Missing field?**       | T       | F        | F         | F      | F      |
| **C2: Invalid field?**       | –       | T        | F         | F      | F      |
| **C3: Passwords match?**     | –       | –        | F         | T      | T      |
| **C4: Privacy accepted?**    | –       | –        | –         | F      | T      |
| **A1: Required field missing** | X     |          |           |        |        |
| **A2: Invalid field**        |         | X        |           |        |        |
| **A3: Password mismatch**    |         |          | X         |        |        |
| **A4: Privacy must be accepted** |     |          |           | X      |        |
| **A5: Registration successful** |    |          |           |        | X      |

## 3. Robust Boundary Value Analysis (Register Form)

Để áp dụng kỹ thuật **Robust Boundary Value Analysis** cho trang Register, mỗi trường dữ liệu được kiểm thử tại **6 giá trị biên**:

- min − 1  
- min  
- min + 1  
- max − 1  
- max  
- max + 1  

Thêm 1 **giá trị trung vị (mid)** theo lý thuyết, nhằm giữ các biến khác ở nominal value → đảm bảo *single fault assumption*.

- Giá trị **min−1** và **max+1** kiểm tra tính robustness (hệ thống phải báo lỗi).  
- Các giá trị **min+1**, **mid**, **max−1** kiểm tra xử lý dữ liệu hợp lệ trong biên.

---

### **Boundary Values cho từng trường**

#### **1. First Name (1–32 ký tự)**
- 0 ký tự (min−1)  
- 1 ký tự (min)  
- 2 ký tự (min+1)  
- 16 ký tự (mid)  
- 31 ký tự (max−1)  
- 32 ký tự (max)  
- 33 ký tự (max+1)  

#### **2. Last Name (1–32 ký tự)**
- 0 ký tự  
- 1 ký tự  
- 2 ký tự  
- 16 ký tự  
- 31 ký tự  
- 32 ký tự  
- 33 ký tự  

#### **3. Telephone (3–32 ký tự)**
- 2 ký tự  
- 3 ký tự  
- 4 ký tự  
- 17 ký tự  
- 31 ký tự  
- 32 ký tự  
- 33 ký tự  

#### **4. Password (4–20 ký tự)**
- 3 ký tự  
- 4 ký tự  
- 5 ký tự  
- 12 ký tự  
- 19 ký tự  
- 20 ký tự  
- 21 ký tự  

## 4. Robust Testing Equivalence Partitioning

Chọn giá trị từ mỗi lớp tương đương hợp lệ và thêm giá trị từ các lớp không hợp lệ nhưng chỉ 1 lỗi tại một thời điểm.

Trong kỹ thuật **Weak Robust Equivalence Class Testing**, mỗi điều kiện đầu vào được chia thành các lớp tương đương hợp lệ và không hợp lệ. Mỗi test case chỉ chọn một giá trị đại diện từ một lớp invalid, trong khi các đầu vào khác giữ ở giá trị hợp lệ, nhằm tuân thủ nguyên tắc **single fault assumption**.

Đối với tính năng **Register**, các lớp invalid bao gồm:  
- First Name rỗng  
- Last Name rỗng  
- Email sai định dạng  
- Telephone quá ngắn hoặc sai format  
- Password quá ngắn  
- Password và Confirm Password không trùng  
- Privacy Policy không được chấp nhận  

Mỗi test case Weak Robust tương ứng với một lớp tương đương invalid kể trên. Việc lựa chọn đúng một giá trị đại diện cho mỗi lớp đảm bảo phạm vi kiểm thử bao phủ đầy đủ tất cả lỗi có thể xảy ra nhưng vẫn giữ số lượng test tối thiểu theo lý thuyết.

Dựa vào yêu cầu của form đăng ký:
- First Name bắt buộc  
- Last Name bắt buộc  
- Email đúng định dạng  
- Telephone phải hợp lệ  
- Password phải đủ độ dài  
- Confirm Password phải trùng Password  
- Privacy Policy phải được chấp nhận  

Cuối cùng có ít nhất một test thuộc tất cả lớp tương đương hợp lệ (**valid EC**).  
Mỗi một điều kiện tạo ra một lớp tương đương invalid, đúng theo lý thuyết **Weak Robust**.

**=> Mỗi test trong sheet “Weak Robust” đại diện cho 1 invalid EC.**

---

## Các Equivalence Class (Robust)

Dựa theo đặc tả của hệ thống, ta sử dụng kỹ thuật **Equivalence Class Partitioning (Robust)** để chia các giá trị đầu vào thành các lớp tương đương hợp lệ (valid) và không hợp lệ (invalid), đồng thời bao gồm cả các lớp **robust invalid** nằm ngoài miền giá trị cho phép.

### **First Name (Tên) – độ dài ký tự**
- length < 1  
- 1 ≤ length ≤ 32  
- length > 32  
→ Class thứ 2 là **valid**, hai lớp còn lại là **invalid**

### **Last Name (Họ) – độ dài ký tự**
- length < 1  
- 1 ≤ length ≤ 32  
- length > 32  
→ Class thứ 2 là **valid**, các class còn lại là **invalid**

### **Email – định dạng email**
- Không đúng định dạng email  
- Đúng định dạng email  
→ Class thứ 2 là **valid**, class thứ nhất là **invalid**

### **Telephone – độ dài ký tự**
- length < 3  
- 3 ≤ length ≤ 32  
- length > 32  
→ Class thứ 2 là **valid**, các class còn lại là **invalid**

### **Password – độ dài ký tự**
- length < 4  
- 4 ≤ length ≤ 20  
- length > 20  
→ Class thứ 2 là **valid**, các class còn lại là **invalid**

### **Confirm Password – quan hệ với Password**
- Confirm Password ≠ Password  
- Confirm Password = Password  
→ Class thứ 2 là **valid**, class thứ nhất là **invalid**

### **Privacy Policy – điều kiện chấp nhận**
- Không tick chọn Privacy Policy  
- Tick chọn Privacy Policy  
→ Class thứ 2 là **valid**, class thứ nhất là **invalid**


# Add to Cart – Decision Table

## 1. Mô tả chức năng
Chức năng **“Thêm sản phẩm vào giỏ hàng”** cho phép người dùng nhập số lượng và đưa sản phẩm vào giỏ hàng để chuẩn bị thanh toán.  
Khi người dùng nhập Quantity và nhấn nút **“Add to Cart”**, hệ thống sẽ kiểm tra tính hợp lệ của số lượng rồi mới xử lý thêm sản phẩm.

---

## 2. Điều kiện kiểm tra (Conditions)
- **C1:** Quantity là số nguyên và ≥ 1  
- **C2:** Quantity có bị để trống hay không  
- **C3:** Quantity có phải là số (numeric) hay không  

## 3. Kết quả mong đợi (Actions)
- **A1:** Hệ thống thêm sản phẩm thành công → Popup:  
  *“Success: You have added … to your shopping cart!”*
- **A2:** Không thêm sản phẩm → Hiển thị lỗi (Quantity < 1, rỗng, hoặc không phải số)

Vì có 3 điều kiện (C1–C3) → decision table đầy đủ gồm **8 rule**.  
Sau khi gộp thành nhóm rule theo kết quả:

- **Rule 1–4:** Quantity ≥ 1, không rỗng, là số → **A1: Add success**  
- **Rule 5–6:** Quantity < 1 (ví dụ 0, −1) → **A2: No item added**  
- **Rule 7–8:** Quantity rỗng hoặc không phải số → **A2: No item added**

⟹ Còn lại **3 rule group** tương ứng **3 test case** cần kiểm thử.

---

## Decision Table (Grouped Rules)

| **Conditions / Rule Groups** | **1–4** | **5–6** | **7–8** |
|------------------------------|---------|---------|---------|
| **C1: Quantity ≥ 1?**        | T       | F       | F       |
| **C2: Quantity empty?**      | F       | –       | –       |
| **C3: Quantity not numeric?**| F       | F       | –       |
| **A1: Add success**          | X       |         |         |
| **A2: No item added**        |         | X       | X       |

# Add to Cart – Use Case Specification

## 1. Mô tả chức năng
- Hệ thống kiểm tra định dạng số lượng: xác minh giá trị nhập có phải số (numeric) hay không.  
- Nếu người dùng nhập ký tự chữ, ký tự đặc biệt hoặc giá trị 0 → hệ thống không thêm sản phẩm.  
- Nếu để trống trường số lượng → hệ thống xem là dữ liệu không hợp lệ.  
- Nếu số lượng < 1 (0 hoặc âm) → vi phạm nghiệp vụ → không thêm sản phẩm.  
- Chỉ khi số lượng là số hợp lệ, không rỗng và ≥ 1 → hệ thống mới thêm sản phẩm vào giỏ hàng và hiển thị thông báo thành công.

### Use Case: Add to Cart – Thêm sản phẩm vào giỏ hàng

| **Mục** | **Nội dung** |
|--------|--------------|
| **Mã Use Case:** | UC-ADD |
| **Tên Use Case:** | Thêm sản phẩm vào giỏ hàng |
| **Người tạo:** | Huy Trương |
| **Người cập nhật:** | Huy Trương |
| **Ngày tạo:** | 21/11/2025 |
| **Ngày cập nhật:** | 21/11/2025 |
| **Tác nhân:** | Người dùng (Khách hàng) |
| **Mô tả:** | Người dùng nhập số lượng và nhấn nút Thêm vào giỏ hàng. Hệ thống kiểm tra số lượng có phải là số, không rỗng và ≥ 1. Nếu hợp lệ hệ thống thêm sản phẩm vào giỏ hàng và hiển thị thông báo thành công. |
| **Tác nhân kích hoạt:** | Người dùng nhấn nút Thêm vào giỏ hàng |
| **Điều kiện tiên quyết:** | Người dùng đang ở trang chi tiết sản phẩm; Sản phẩm còn hàng |
| **Điều kiện sau:** | Thành công: Sản phẩm được thêm vào giỏ hàng<br>Thất bại: Giỏ hàng không thay đổi |
| **Luồng chính:** | 1. Người dùng nhập số lượng hợp lệ (là số và ≥ 1)<br>2. Người dùng nhấn Thêm vào giỏ hàng<br>3. Hệ thống kiểm tra số lượng<br>4. Hệ thống thêm sản phẩm vào giỏ hàng<br>5. Hệ thống hiển thị thông báo thành công |
| **Luồng thay thế 1 – Số lượng < 1:** | - Người dùng nhập 0 hoặc giá trị âm<br>- Hệ thống KHÔNG thêm sản phẩm<br>- Không hiển thị thông báo |
| **Luồng thay thế 2 – Số lượng để trống:** | - Người dùng không nhập số lượng<br>- Hệ thống KHÔNG thêm sản phẩm<br>- Không hiển thị thông báo |
| **Ngoại lệ 1 – Số lượng không phải là số:** | - Người dùng nhập giá trị không phải số (vd: abc)<br>- Hệ thống không thể xử lý số lượng<br>- Hệ thống KHÔNG thêm sản phẩm<br>- Không hiển thị thông báo |
| **Ghi chú và vấn đề:** | Trang demo không hiển thị thông báo lỗi khi nhập số lượng không hợp lệ. |
<img width="457" height="696" alt="Screenshot 2025-11-21 105855" src="https://github.com/user-attachments/assets/4a16a3a8-19c0-42a5-a00a-374fe6c49c07" />

## 3. Weak Robust Equivalence Class Partitioning – Add to Cart

Dựa trên đặc tả của hệ thống, chức năng **Add to Cart** nhận đầu vào duy nhất là **Quantity** (số lượng sản phẩm cần thêm vào giỏ hàng).  
Theo kỹ thuật **Weak Robust Equivalence Class Partitioning**, ta chia các giá trị đầu vào thành các lớp tương đương **hợp lệ** và **không hợp lệ**, sau đó chọn một giá trị đại diện cho mỗi lớp để kiểm thử (single-fault assumption).

---

### **Các lớp tương đương (Equivalence Classes)**

#### **1. Quantity < 1**  
*(Không hợp lệ — nhỏ hơn ngưỡng cho phép)*  
Ví dụ:  
- `0`  
- `-1` (hoặc bất kỳ giá trị âm)

Hành vi mong đợi:  
→ Item **không được thêm** vào giỏ hàng  
→ **Không** hiển thị thông báo  

---

#### **2. Quantity rỗng**  
*(Không hợp lệ — không nhập dữ liệu)*  
Ví dụ:  
- `""` (empty input)

Hành vi mong đợi:  
→ Item **không được thêm**  
→ **Không** hiển thị thông báo  

---

#### **3. Quantity không phải số**  
*(Không hợp lệ — sai kiểu dữ liệu)*  
Ví dụ:  
- `'abc'`  
- `'@'`  
- `'1a'`

Hành vi mong đợi:  
→ Item **không được thêm**  
→ **Không** hiển thị thông báo  

---

#### **4. Quantity ≥ 1**  
*(Hợp lệ — thoả điều kiện nghiệp vụ)*  
Ví dụ:  
- `1`, `2`, `5`

Hành vi mong đợi:  
→ **Thêm sản phẩm thành công**  
→ Hiển thị popup:  
**“Success: You have added … to your shopping cart!”**

