# GIỚI THIỆU
**Đề bài**:    Security Pattern

**Sản phẩm**: 
1.    Giao diện người dùng: Thiết kế trực quan với 9 nút điểm để nhập pattern, sử dụng TouchGFX.
2.    Chế độ đăng ký: Kích hoạt khi nhấn giữ nút Boot (GPIOA_PIN_0) trong 3 giây, cho phép đăng ký pattern mới.
3.    Chế độ mở khóa: Kiểm tra pattern nhập vào so với danh sách pattern đã lưu.
4.    Hiển thị kết quả: Màn hình thông báo "OK" khi đăng ký hoặc mở khóa thành công, tự động trở về trạng thái khóa sau 100 Tick.
5.    Quản lý bộ nhớ Flash: Lưu, đọc và xóa pattern trong sector FLASH_SECTOR_23.
6.    Phản hồi người dùng: LED tại GPIOG_PIN_13 nhấp nháy khi chuyển sang chế độ đăng ký.

# TÁC GIẢ
-    Nhóm thực hiện: The Three Musketeers
-    Thành viên trong nhóm 

| STT | Họ và tên | MSSV | Nhiệm vụ |
|-----|-----------|------|----------|
| 1   | Nguyễn Đình Tùng | 20215663 | Viết các hàm xử lý trong Screen1 |
| 2   | Lê Nhật Đức | 20215568 | Thiết kế giao diện |
| 3   | Đào Anh Quân | 20215631 | Task RTOS thực hiện logic chuyển màn hình. Thêm, xóa dữ liệu trong bộ nhớ Flash |

# MÔI TRƯỜNG HOẠT ĐỘNG
- **Phần cứng**: STM32F429 Discovery Kit
- **Phần mềm**:
    + TouchGFX (thiết kế giao diện đồ họa)
    + FreeRTOS (quản lý tác vụ thời gian thực)
    + STM32CubeIDE (môi trường phát triển)
- **Bộ nhớ**: Flash (sector FLASH_SECTOR_23 để lưu trữ pattern)

# TÍCH HỢP HỆ THỐNG
**Front-end**: TouchGFX
- **Screen1**:
    ![Screen1](https://github.com/Lenhatduc/BT070625/blob/main/Screen1.png)
    + Có các nút bấm để người dùng nhập số 
    + Chức năng hiển thị số đang nhập 
    + Nút **Unlock** để kiểm tra  
    + Nút **Register** (ẩn trong chế độ mở khóa) dùng để đăng ký  

- **Screen2**:
    ![Screen2](https://github.com/Lenhatduc/BT070625/blob/main/Screen2.png)
    + Hiển thị chữ OK thể hiện hành động (đăng nhập/đăng ký) thành công 
    + Có Interaction sẽ tự động chuyển về Screen1 sau mỗi 100 Tick

 **Back-end**: RTOS và Flash
- **Tác vụ RTOS**:
    + Kiểm tra trạng thái nút Boot (GPIOA_PIN_0) 
    + Gửi tín hiệu ‘C’ vào hàng đợi khi nhấn giữ 3 giây để chuyển sang chế độ đăng ký 

- **Quản lý Flash**:
    + Lưu pattern tại địa chỉ *FLASH_USER_START_ADDR*
    + Xóa sector FLASH_SECTOR_23 khi cần thiết 

# ĐẶC TẢ HÀM
```c
    /** 
    - Hàm task chạy trong môi trường RTOS, dùng để kiểm tra trạng thái nút nhấn tại chân GPIOA_PIN_0.
    Khi người dùng nhấn giữ nút trong 3 giây thì sẽ gửi ký tự ‘C’ vào hàng đợi, là tín hiệu để sang màn hình đăng ký.
    Ngoài ra mỗi lần phát hiện nhấn giữ đủ thời gian, LED tại GPIOG_PIN_13 sẽ nhấp nháy để phản hồi. 
    */ 

    void StartBootCheckTask(void *argument);
```

```c
    /** 
    - Khi người dùng nhấn vào các nút số trên màn hình, hàm này sẽ được gọi tương ứng.
    Hàm sẽ tính lại giá trị Password đang nhập bằng công thức: giá trị mới = giá trị cũ * 10 + i ; 
    */ 

    void Screen1View::function*() (* ở đây là từ 1 đến 9); 
```

```c
    /** 
    - Hàm sẽ được gọi khi người dùng nhấn vào nút Register trên màn hình,
    hàm sẽ lấy danh sách các Password đã được lưu trong Flash bằng hàm : Flash_Read_All_Uint32.
    Sau đó kiểm tra giá trị giá trị Password đang nhập có nằm trong các giá trị đã lưu không.
    Nếu không có, sẽ gọi hàm Flash_Append_Uint32 để lưu giá trị Password đăng ký và chuyển sang Screen2 
    */ 

    void Screen1View::functionRegister(); 
```

```c
    /** 
    - Hàm sẽ được gọi khi người dùng nhấn vào nút Unlock trên màn hình.
    Hàm sẽ lấy danh sách các Password đã được lưu trong Flash.
    Sau đó, kiểm tra giá trị Password có nằm trong danh sách đã lưu không.
    Nếu có thì mở khóa (chuyển sang Screen2)
    */ 

    void Screen1View::functionUnlock();
```

```c
    /** 
    - Hàm sẽ liên tục lặp lại trong vòng 1Tick: Với mỗi lần, hàm sẽ thực hiện các công việc: 
        + Lấy giá trị của Password đang nhập và hiển thị lên màn hình. 
        + Kiểm tra xem có giá trị trong hàng đợi không, nếu có thì chuyển màn hình sang chế độ Register 
        + Kiểm tra chế độ của màn hình Unlock hay Register bằng biến toàn cụ isUnlock. 
            Nếu isUnlock = 0 thì ẩn nút Unlock, hiện nút Register (Chế độ Register) và ngược lại. 
    */ 

    void Screen1View::function1Tick();
```

```c
    /** 
    - Thực hiện xóa toàn bộ vùng nhớ Flash tại sector lưu log dữ liệu (FLASH_SECTOR_23),
    bằng cách đặt toàn bộ giá trị về 0xFFFFFFFF 
    */ 

    void Flash_Clear_Log(); 
```

```c
    /** 
    - Hàm thực hiện đọc liên tiếp các giá trị từ bộ nhớ Flash,
    bắt đầu từ địa chỉ FLASH_USER_START_ADDR. Hàm dừng đọc khi
    gặp giá trị 0xFFFFFFFF hoặc đã đạt đến max_length phần tử. 
    - Tham số: 
    @param buffer: Con trỏ trỏ đến mảng đệm để lưu dữ liệu đọc từ Flash 
    @param max_length: Số lượng tối đa phần tử có thể lưu vào buffer 
    * Giá trị trả về: Số phần tử được đọc thành công từ bộ nhớ Flash 
    */ 

    uint32_t Flash_Read_All_Uint32(uint32_t* buffer, uint32_t max_length); 
```

```c
    /** 
    - Hàm ghi một giá trị uint32_t vào bộ nhớ Flash, bắt đầu từ địa chỉ FLASH_USER_START_ADDR.
    Dữ liệu được ghi tại vị trí trống đầu tiên (vị trí có giá trị bằng 0xFFFFFFFF. 
    - Tham số: 
    @param data: Giá trị kiểu uint32_t cần ghi vào bộ nhớ Flash 
    */ 

    void Flash_Append_Uint32(uint32_t data); 
```

# KẾT QUẢ
[Download demo video](./demoNhung.mp4)
