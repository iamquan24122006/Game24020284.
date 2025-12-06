# Các Thuật toán Sắp xếp Cụ thể

Tài liệu này trình bày **ý tưởng, mã giả, code C++, phân tích độ phức tạp (best / average / worst), tính ổn định** của các thuật toán sắp xếp đơn giản và nâng cao.

---

## 1.1. Các Thuật toán Sắp xếp Đơn Giản – Độ phức tạp O(n²)

### 🔹 1.1.1. Selection Sort (Sắp xếp lựa chọn)

**Ý tưởng**
- Mỗi vòng lặp tìm phần tử nhỏ nhất trong đoạn chưa sắp xếp.
- Đưa nó về đầu đoạn bằng cách đổi chỗ.

**Mã giả**
```
SelectionSort(A[0..n-1]):
    for i = 0 to n-2:
        minPos = i
        for j = i+1 to n-1:
            if A[j] < A[minPos]:
                minPos = j
        if minPos != i:
            swap(A[i], A[minPos])
```

**Code C++**
```cpp
void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        int minPos = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minPos]) minPos = j;
        if (minPos != i) swap(a[i], a[minPos]);
    }
}
```
**Code Java**
```java
public static void selectionSort(int[] a) {
        int n = a.length;
        for (int i = 0; i < n - 1; ++i) {
            int minPos = i;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < a[minPos]) {
                    minPos = j;
                }
            }
        
            if (minPos != i) {
                int temp = a[i];
                a[i] = a[minPos];
                a[minPos] = temp;
            }
        }
    }
```

**Đánh giá**

| Case           | Độ phức tạp | Giải thích |
| -------------- | ----------- | ---------- |
| Best           | O(n²)       | Luôn phải duyệt qua tất cả phần tử để tìm min |
| Average        | O(n²)       | n-1 vòng lặp, mỗi vòng duyệt trung bình n/2 phần tử |
| Worst          | O(n²)       | Luôn phải so sánh đầy đủ: (n-1) + (n-2) + ... + 1 = n(n-1)/2 |
| Không gian phụ | O(1)        | Chỉ dùng biến tạm |
| Ổn định        | ❌ Không     | Đổi chỗ có thể thay đổi thứ tự tương đối |

---

### 🔹 1.1.2. Insertion Sort (Sắp xếp chèn)

**Ý tưởng**
- Xem mảng như gồm phần **đầu đã sắp** và phần **cuối chưa sắp**.
- Lần lượt chèn phần tử tiếp theo vào đúng vị trí trong đoạn đã sắp.

**Mã giả**
```
InsertionSort(A[0..n-1]):
    for i = 1 to n-1:
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j+1] = A[j]
            j = j - 1
        A[j+1] = key
```

**Code C++**
```cpp
void insertionSort(vector<int>& a) {
    for (int i = 1; i < a.size(); ++i) {
        int x = a[i], j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = x;
    }
}
```

**Code Java**
```java
public static void insertionSort(int[] a) {
        for (int i = 1; i < a.length; ++i) {
            int x = a[i]; 
            int j = i - 1;

            while (j >= 0 && a[j] > x) {
                a[j + 1] = a[j];
                j--;
            }
            
            a[j + 1] = x;
        }
    }
```

**Đánh giá**

| Case           | Độ phức tạp | Giải thích |
| -------------- | ----------- | ---------- |
| Best           | O(n)        | Mảng đã sắp xếp, mỗi phần tử chỉ so sánh 1 lần |
| Average        | O(n²)       | Trung bình mỗi phần tử phải dịch i/2 vị trí |
| Worst          | O(n²)       | Mảng ngược thứ tự, mỗi phần tử phải dịch hết về đầu |
| Không gian phụ | O(1)        | Chỉ dùng biến tạm |
| Ổn định        | ✅ Có        | Chỉ chèn khi gặp phần tử lớn hơn thực sự |

---

### 🔹 1.1.3. Bubble Sort (Sắp xếp nổi bọt)

**Ý tưởng**
- So sánh các cặp phần tử kề nhau, nếu sai thứ tự thì đổi chỗ.
- Sau mỗi lượt, phần tử lớn nhất "nổi" về cuối mảng.

**Mã giả**
```
BubbleSort(A[0..n-1]):
    for i = 0 to n-2:
        swapped = false
        for j = 0 to n-2-i:
            if A[j] > A[j+1]:
                swap(A[j], A[j+1])
                swapped = true
        if not swapped:
            break
```

**Code C++ (tối ưu dừng sớm)**
```cpp
void bubbleSort(vector<int>& a) {
    int n = a.size(); bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; ++j)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]), swapped = true;
        if (!swapped) break;
    }
}
```

**Đánh giá**

| Case           | Độ phức tạp | Giải thích |
| -------------- | ----------- | ---------- |
| Best           | O(n)        | Mảng đã sắp, 1 lượt duyệt không có swap nào |
| Average        | O(n²)       | Trung bình n/2 lượt, mỗi lượt n/2 so sánh |
| Worst          | O(n²)       | Mảng ngược, cần đầy đủ n-1 lượt duyệt |
| Không gian phụ | O(1)        | Chỉ dùng biến cờ |
| Ổn định        | ✅ Có        | Chỉ đổi chỗ khi A[j] > A[j+1] (không có =) |

---

## 1.2. Các Thuật toán Sắp xếp Nâng Cao – Độ phức tạp O(n log n)

### 🔹 1.2.1. Merge Sort (Sắp xếp hòa nhập)

**Ý tưởng**
- Chia mảng làm đôi, sắp xếp đệ quy mỗi nửa, sau đó trộn lại.
- Áp dụng chiến lược *chia để trị (divide-and-conquer)*.

**Mã giả**
```
MergeSort(A, left, right):
    if left >= right:
        return
    mid = (left + right) / 2
    MergeSort(A, left, mid)
    MergeSort(A, mid+1, right)
    Merge(A, left, mid, right)

Merge(A, left, mid, right):
    Tạo mảng tạm L = A[left..mid], R = A[mid+1..right]
    i = 0, j = 0, k = left
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            A[k++] = L[i++]
        else:
            A[k++] = R[j++]
    Copy phần còn lại của L hoặc R vào A
```

**Code C++**
```cpp
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> L(a.begin() + l, a.begin() + m + 1);
    vector<int> R(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size())
        a[k++] = (L[i] <= R[j] ? L[i++] : R[j++]); // <= để giữ ổn định
    while (i < L.size()) a[k++] = L[i++];
    while (j < R.size()) a[k++] = R[j++];
}
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
```
**Code java**
```java
public class MergeSortAlgo {
    public static void merge(int[] a, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int[] L = new int[n1];
        int[] R = new int[n2];

        for (int i = 0; i < n1; ++i)
            L[i] = a[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = a[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) a[k++] = L[i++];
            else a[k++] = R[j++];
        }

        while (i < n1) a[k++] = L[i++];
        while (j < n2) a[k++] = R[j++];
    }

    public static void mergeSort(int[] a, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
```


**Đánh giá**

| Case           | Độ phức tạp | Giải thích |
| -------------- | ----------- | ---------- |
| Best           | O(n log n)  | Luôn chia đôi log n lần, mỗi tầng merge n phần tử |
| Average        | O(n log n)  | Không phụ thuộc dữ liệu đầu vào |
| Worst          | O(n log n)  | Cây đệ quy cân bằng, độ cao log n |
| Không gian phụ | O(n)        | Cần mảng tạm để merge |
| Ổn định        | ✅ Có        | Dùng <= khi merge giữ nguyên thứ tự |

---

### 🔹 1.2.2. Quick Sort (Sắp xếp nhanh)

**Ý tưởng**
- Chọn pivot → phân hoạch mảng → chia thành mảng con trái/phải → sắp xếp đệ quy.

**Mã giả**
```
QuickSort(A, left, right):
    if left >= right:
        return
    pivotIndex = Partition(A, left, right)
    QuickSort(A, left, pivotIndex - 1)
    QuickSort(A, pivotIndex + 1, right)

Partition(A, left, right):
    pivot = A[right]
    i = left - 1
    for j = left to right-1:
        if A[j] <= pivot:
            i = i + 1
            swap(A[i], A[j])
    swap(A[i+1], A[right])
    return i + 1
```

**Code C++**
```cpp
int partitionLomuto(vector<int>& a, int l, int r) {
    int pivot = a[r], i = l - 1;
    for (int j = l; j < r; ++j)
        if (a[j] <= pivot)
            swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}
void quickSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int p = partitionLomuto(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}
```

**Đánh giá**

| Case           | Độ phức tạp       | Giải thích |
| -------------- | ----------------- | ---------- |
| Best           | O(n log n)        | Pivot luôn chia đôi mảng, cây đệ quy cân bằng |
| Average        | O(n log n)        | Pivot ngẫu nhiên, trung bình chia khá đều |
| Worst          | O(n²)             | Pivot luôn là min/max, cây đệ quy lệch (mảng đã sắp) |
| Không gian phụ | O(log n) đến O(n) | Stack đệ quy: O(log n) nếu cân bằng, O(n) nếu lệch |
| Ổn định        | ❌ Không           | Partition có thể đổi thứ tự phần tử bằng nhau |

---

### 🔹 1.2.3. Heap Sort (Sắp xếp dùng Heap)

**Ý tưởng**
- Xây dựng **max-heap** rồi lặp lại: đưa phần tử lớn nhất ở gốc về cuối mảng và giảm kích thước heap.

**Mã giả**
```
HeapSort(A[0..n-1]):
    // Xây dựng max-heap
    for i = n/2-1 downto 0:
        Heapify(A, n, i)
    
    // Trích xuất từng phần tử
    for i = n-1 downto 1:
        swap(A[0], A[i])
        Heapify(A, i, 0)

Heapify(A, heapSize, i):
    largest = i
    left = 2*i + 1
    right = 2*i + 2
    if left < heapSize and A[left] > A[largest]:
        largest = left
    if right < heapSize and A[right] > A[largest]:
        largest = right
    if largest != i:
        swap(A[i], A[largest])
        Heapify(A, heapSize, largest)
```

**Code C++**
```cpp
void heapify(vector<int>& a, int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) swap(a[i], a[largest]), heapify(a, n, largest);
}
void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; --i) heapify(a, n, i);
    for (int i = n - 1; i > 0; --i)
        swap(a[0], a[i]), heapify(a, i, 0);
}
```
**Code java**
```java
public class QuickSortAlgo {
    static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static int partitionLomuto(int[] a, int l, int r) {
        int pivot = a[r];
        int i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= pivot) {
                swap(a, ++i, j);
            }
        }
        swap(a, i + 1, r);
        return i + 1;
    }

    public static void quickSort(int[] a, int l, int r) {
        if (l >= r) return;
        int p = partitionLomuto(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}
```

**Đánh giá**

| Case           | Độ phức tạp | Giải thích |
| -------------- | ----------- | ---------- |
| Best           | O(n log n)  | Xây heap O(n), n lần heapify mỗi lần O(log n) |
| Average        | O(n log n)  | Không phụ thuộc thứ tự dữ liệu |
| Worst          | O(n log n)  | Luôn đảm bảo độ cao cây log n |
| Không gian phụ | O(1)        | Sắp xếp tại chỗ |
| Ổn định        | ❌ Không     | Heapify có thể đổi thứ tự phần tử bằng nhau |

---

## 1.3. Thuật toán Sắp xếp Đặc biệt

### 🔹 1.3.1. Counting Sort (Sắp xếp đếm)

**Ý tưởng**
- Đếm số lần xuất hiện của mỗi giá trị.
- Xây dựng mảng kết quả dựa trên tần số.
- **Yêu cầu**: Các phần tử là số nguyên không âm trong phạm vi nhỏ (0 đến k).

**Mã giả**
```
CountingSort(A[0..n-1], k):
    // k là giá trị lớn nhất trong mảng
    Tạo mảng count[0..k] = {0}
    Tạo mảng output[0..n-1]
    
    // Đếm tần số
    for i = 0 to n-1:
        count[A[i]]++
    
    // Tính tổng tích lũy (vị trí cuối của mỗi giá trị)
    for i = 1 to k:
        count[i] += count[i-1]
    
    // Xây dựng mảng output (duyệt ngược để giữ ổn định)
    for i = n-1 downto 0:
        output[count[A[i]] - 1] = A[i]
        count[A[i]]--
    
    // Copy kết quả
    for i = 0 to n-1:
        A[i] = output[i]
```

**Code C++**
```cpp
void countingSort(vector<int>& a) {
    if (a.empty()) return;
    
    int k = *max_element(a.begin(), a.end());
    int n = a.size();
    vector<int> count(k + 1, 0);
    vector<int> output(n);
    
    // Đếm tần số
    for (int i = 0; i < n; ++i)
        count[a[i]]++;
    
    // Tính tổng tích lũy
    for (int i = 1; i <= k; ++i)
        count[i] += count[i - 1];
    
    // Xây dựng mảng output (duyệt ngược để ổn định)
    for (int i = n - 1; i >= 0; --i) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    
    // Copy kết quả
    a = output;
}
```

**Đánh giá**

| Case           | Độ phức tạp | Giải thích |
| -------------- | ----------- | ---------- |
| Best           | O(n + k)    | Duyệt mảng O(n), khởi tạo count O(k) |
| Average        | O(n + k)    | Không phụ thuộc thứ tự dữ liệu |
| Worst          | O(n + k)    | Luôn thực hiện đủ các bước |
| Không gian phụ | O(n + k)    | Mảng count[k] và output[n] |
| Ổn định        | ✅ Có        | Duyệt ngược khi xây dựng output |

**Lưu ý:**
- **Hiệu quả** khi k = O(n) (phạm vi giá trị không quá lớn)
- **Không hiệu quả** khi k >> n (ví dụ: sắp xếp 10 số từ 0 đến 1 triệu)
- Thường dùng làm bước con trong **Radix Sort**

---

## 2. Khái niệm Thuật Toán Sắp Xếp Ổn Định (Stable Sort)

**Định nghĩa**
Thuật toán sắp xếp gọi là **ổn định** nếu với hai phần tử có **khóa bằng nhau** thì **thứ tự tương đối của chúng trước và sau khi sắp xếp không thay đổi**.

Ví dụ (sắp theo điểm):
```
(5, A), (3, B), (5, C), (2, D)
→ (2, D), (3, B), (5, A), (5, C)  ✅  Ổn định
```

Ngược lại:
```
→ (2, D), (3, B), (5, C), (5, A)  ❌  Không ổn định
```

### Bảng tổng hợp

| Thuật toán     | Ổn định? |
| -------------- | -------- |
| Selection Sort | ❌        |
| Insertion Sort | ✅        |
| Bubble Sort    | ✅        |
| Merge Sort     | ✅        |
| Quick Sort     | ❌        |
| Heap Sort      | ❌        |
| Counting Sort  | ✅        |

---
## 3. Khái niệm Thuật Toán Sắp Xếp Tại Chỗ (In-Place Sort)

**Định nghĩa**  
Thuật toán sắp xếp gọi là **in-place** nếu nó **không cần mảng phụ kích thước O(n)**,  
mà chỉ dùng **O(1)** (hoặc O(log n) do stack đệ quy) bộ nhớ phụ.

→ Thuật toán **thao tác trực tiếp trên mảng ban đầu** mà không tạo thêm bản sao lớn.

---

### Ví dụ

Mảng ban đầu:

```

[5, 1, 4, 2]

```

Thuật toán in-place sẽ **swap trực tiếp**:

```

[1, 5, 4, 2]
[1, 4, 5, 2]
[1, 4, 2, 5]
...

```

→ Không tạo mảng phụ → In-place.

---

### Bảng tổng hợp: Thuật toán nào in-place?

| Thuật toán                   | In-place? | Lý do |
| --------------------------- | --------- | ----- |
| Selection Sort             | ✅        | Chỉ dùng vài biến tạm |
| Insertion Sort             | ✅        | Dịch và chèn ngay trong mảng |
| Bubble Sort                | ✅        | Swap trực tiếp trên mảng |
| Merge Sort (thường dạy)    | ❌        | Cần mảng phụ O(n) |
| Merge Sort (in-place nâng cao) | ✅*   | Khó cài, hiếm dùng |
| Quick Sort                 | ✅ (O(log n)) | Dùng stack đệ quy nhỏ |
| Heap Sort                  | ✅        | Heap nằm trực tiếp trong mảng |
| Counting Sort              | ❌        | Cần mảng đếm kích thước k |
| Radix Sort                 | ❌        | Dựa trên counting → dùng mảng phụ |

---

**Ghi chú:**

- Quick Sort vẫn được xem là in-place vì overhead chỉ O(log n) cho stack.
- Merge Sort bản chuẩn không in-place vì phải tách mảng ra hai mảng phụ.
- Counting và Radix không in-place vì dùng mảng phụ lớn.

## 4. Gợi ý lựa chọn thuật toán

| Mục đích                                | Thuật toán phù hợp                        |
| --------------------------------------- | ----------------------------------------- |
| Dữ liệu ít hoặc gần như sắp xếp         | Insertion Sort                            |
| Tốc độ cao nhất trong thực tế           | Quick Sort                                |
| Bảo đảm O(n log n) trong mọi trường hợp | Merge Sort / Heap Sort                    |
| Cần ổn định                             | Merge Sort / Insertion Sort / Counting Sort |
| Số nguyên nhỏ, phạm vi hẹp              | Counting Sort                             |
| Tiết kiệm bộ nhớ                        | Heap Sort / Quick Sort (in-place)         |


# 🧱 CẤU TRÚC DỮ LIỆU CƠ BẢN — STACK & QUEUE

---

## I. 🔺 NGĂN XẾP (STACK)

### 1. Khái niệm
Ngăn xếp (Stack hoặc Pushdown Stack) là một **Kiểu Dữ liệu Trừu tượng (Abstract Data Type – ADT)** dùng để lưu trữ các phần tử theo **thứ tự tuyến tính** nhưng **chỉ cho phép thao tác tại một đầu duy nhất — gọi là *đỉnh (Top)***.

🔹 Nguyên tắc hoạt động: **LIFO — Last In First Out**  
→ Phần tử được đưa vào sau cùng sẽ là phần tử được lấy ra trước.

🔹 Ví dụ đời thực:  
Một **chồng sách** — quyển đặt sau cùng nằm trên cùng và sẽ được lấy ra đầu tiên.

---

### 2. Các phép toán cơ bản của Stack
Giả sử `S` là một ngăn xếp và `x` là một phần tử:

| Phép toán | Ý nghĩa |
|----------|--------|
| `Empty(S)` | Trả về `true` nếu ngăn xếp rỗng |
| `Push(S, x)` | Thêm phần tử `x` lên đỉnh ngăn xếp |
| `Pop(S)` | Loại phần tử ở đỉnh và trả về nó |
| `GetTop(S)` | Trả về giá trị phần tử ở đỉnh nhưng **không xóa** |

---

### 3. Cài đặt & Hiệu quả
| Cách cài đặt | Đặc điểm | Độ phức tạp |
|-------------|----------|-------------|
| Mảng (Array) | Đỉnh thường đặt ở chỉ số lớn nhất | `O(1)` cho mọi thao tác, ngoại trừ khi cần cấp phát mảng mới `(O(n))` |
| Danh sách liên kết (Linked List) | Đỉnh lưu tại nút đầu danh sách | Mọi phép toán Push / Pop / GetTop đều `O(1)` |

📌 Stack được dùng trong nhiều hệ thống:
- Ngăn xếp thời gian chạy (Run-time stack)
- Duyệt đồ thị DFS
- Chuyển đổi biểu thức / tính giá trị biểu thức
- Quay lui (Backtracking)

---

### 4. Ví dụ minh họa hoạt động
Giả sử ta thực hiện:  
```
Push(S, 5)
Push(S, 9)
Push(S, 1)
Pop(S)
Push(S, 7)
```

| Bước | Nội dung Stack |
|------|----------------|
| Ban đầu | ∅ |
| Push 5 | [5] |
| Push 9 | [5, 9] |
| Push 1 | [5, 9, 1] |
| Pop → trả 1 | [5, 9] |
| Push 7 | [5, 9, 7] |

---

### 5. Code ví dụ (C/C++)
```cpp
#include <iostream>
using namespace std;

#define MAX 100

struct Stack {
    int arr[MAX];
    int top = -1;
};

bool Empty(Stack &S) {
    return (S.top == -1);
}

void Push(Stack &S, int x) {
    if (S.top == MAX - 1) return;
    S.arr[++S.top] = x;
}

int Pop(Stack &S) {
    if (Empty(S)) return -1;
    return S.arr[S.top--];
}

int GetTop(Stack &S) {
    if (Empty(S)) return -1;
    return S.arr[S.top];
}
```

---

---

## II. 🔷 HÀNG ĐỢI (QUEUE)

### 1. Khái niệm
Hàng đợi (Queue) là **một Kiểu Dữ liệu Trừu tượng** nơi:
- **Thêm phần tử (Insert) ở đuôi**
- **Loại phần tử (Delete) ở đầu**

🔹 Nguyên tắc hoạt động: **FIFO — First In First Out**  
→ Phần tử vào trước sẽ ra trước.

🔹 Ví dụ đời thực:  
Một người xếp hàng mua vé — người đến đầu tiên sẽ được phục vụ đầu tiên.

---

### 2. Các phép toán cơ bản của Queue

| Phép toán | Ý nghĩa |
|----------|--------|
| `Empty(Q)` | Trả về `true` nếu hàng đợi rỗng |
| `Enqueue(x, Q)` | Thêm phần tử `x` vào cuối hàng |
| `Dequeue(Q)` | Loại phần tử ở đầu và trả về nó |
| `GetHead(Q)` | Trả về phần tử ở đầu **nhưng không xóa** |

---

### 3. Cài đặt & Hiệu quả

| Cách cài đặt | Đặc điểm | Độ phức tạp |
|-------------|----------|-------------|
| Mảng | Cài đặt tốt nhất bằng **mảng vòng tròn** | `O(1)`, ngoại trừ khi cần cấp phát mảng mới |
| Danh sách liên kết | Dùng 2 con trỏ `head` & `tail` (hoặc DSLK vòng với 1 con trỏ `tail`) | `O(1)` cho mọi thao tác |

📌 Queue được dùng để:
- Mô phỏng hệ thống phục vụ (xếp hàng siêu thị)
- Thuật toán BFS
- Điều phối CPU / tiến trình
- Truyền dữ liệu theo luồng

---

### 4. Ví dụ minh họa hoạt động
Thực hiện:
```
Enqueue(Q, 4)
Enqueue(Q, 8)
Enqueue(Q, 2)
Dequeue(Q)
Enqueue(Q, 9)
```

| Bước | Nội dung Queue |
|------|----------------|
| Ban đầu | ∅ |
| Enqueue 4 | [4] |
| Enqueue 8 | [4, 8] |
| Enqueue 2 | [4, 8, 2] |
| Dequeue → trả 4 | [8, 2] |
| Enqueue 9 | [8, 2, 9] |

---

### 5. Code ví dụ (C/C++ — mảng vòng)
```cpp
#include <iostream>
using namespace std;

#define MAX 100

struct Queue {
    int arr[MAX];
    int head = 0, tail = 0, size = 0;
};

bool Empty(Queue &Q) {
    return (Q.size == 0);
}

void Enqueue(Queue &Q, int x) {
    if (Q.size == MAX) return;
    Q.arr[Q.tail] = x;
    Q.tail = (Q.tail + 1) % MAX;
    Q.size++;
}

int Dequeue(Queue &Q) {
    if (Empty(Q)) return -1;
    int x = Q.arr[Q.head];
    Q.head = (Q.head + 1) % MAX;
    Q.size--;
    return x;
}

int GetHead(Queue &Q) {
    if (Empty(Q)) return -1;
    return Q.arr[Q.head];
}
```

---

## 🔍 So sánh nhanh Stack & Queue

| Tiêu chí | Stack | Queue |
|----------|-------|-------|
| Nguyên tắc | LIFO | FIFO |
| Thêm phần tử | Đỉnh (Top) | Cuối (Tail) |
| Lấy phần tử | Đỉnh (Top) | Đầu (Head) |
| Ứng dụng | Đệ quy, DFS, biểu thức | BFS, mô phỏng hệ thống, đa tiến trình |

---

## 🎯 Kết luận

| Cấu trúc | Khi nào nên dùng? |
|----------|-------------------|
| **Stack** | Cần xử lý đảo ngược, quay lui, lưu trạng thái |
| **Queue** | Cần xử lý tuần tự công bằng, trước vào trước ra |

---
# 🌳 CÂY TÌM KIẾM NHỊ PHÂN — BINARY SEARCH TREE (BST)

## 1. 📌 Khái niệm và Đặc điểm
Cây tìm kiếm nhị phân (**BST**) là một cây nhị phân thỏa mãn tính chất:
- Với mỗi nút `x`:
  - Mọi nút trong **cây con trái** của `x` có khóa **nhỏ hơn khóa của `x`**.
  - Mọi nút trong **cây con phải** của `x` có khóa **lớn hơn khóa của `x`**.
- Cây rỗng là BST hợp lệ.
- **Duyệt theo thứ tự Inorder → nhận được dãy khóa tăng dần**.
- BST được định nghĩa tự nhiên bằng đệ quy.

### 📊 Ví dụ minh họa BST hợp lệ
```
Chèn lần lượt: 50, 30, 70, 20, 40, 60, 80

        50
       /  \
      30   70
     / \   / \
    20 40 60 80
```
- Inorder: 20, 30, 40, 50, 60, 70, 80 (dãy tăng dần ✓)
- Tất cả giá trị bên trái 50 đều < 50
- Tất cả giá trị bên phải 50 đều > 50

### ❌ Ví dụ cây KHÔNG phải BST
```
        50
       /  \
      30   70
     / \   / \
    20 60 40 80
```
- Nút 60 nằm bên trái 50 nhưng 60 > 50 → Vi phạm!
- Nút 40 nằm bên phải 50 nhưng 40 < 50 → Vi phạm!

---

## 2. ⚙️ Các Phép Toán Trên BST

### 🔍 2.1. Tìm kiếm (Search)
Dựa trên so sánh khóa cần tìm `k` với khóa tại gốc:
- `k == key(root)` → tìm thấy
- `k < key(root)` → đệ quy sang cây con trái
- `k > key(root)` → đệ quy sang cây con phải

**Ví dụ: Tìm 40 trong cây trên**
```
Bước 1: So sánh 40 với 50 → 40 < 50 → sang trái
        [50]
       /  
      30   
     / \   
    20 40

Bước 2: So sánh 40 với 30 → 40 > 30 → sang phải
      30
       \
       [40] ← Tìm thấy!
```

### 📉 2.2. Tìm Min và Max
- **Min:** đi hết nhánh trái.
- **Max:** đi hết nhánh phải.

**Ví dụ:**
```
        50
       /  \
      30   70
     / \   / \
    20 40 60 80
    ↑          ↑
   MIN        MAX
```
- Min = 20 (đi liên tục sang trái)
- Max = 80 (đi liên tục sang phải)

### ➕ 2.3. Chèn (Insert)
Đi theo đường tìm kiếm đến vị trí nút lá thích hợp rồi tạo nút mới.

**Ví dụ: Chèn 35 vào cây**
```
Bước 1: 35 < 50 → sang trái
Bước 2: 35 > 30 → sang phải
Bước 3: 35 < 40 → sang trái của 40
Bước 4: 40 chưa có con trái → chèn 35

        50
       /  \
      30   70
     / \   / \
    20 40 60 80
       /
      35 ← Mới chèn
```

### ❌ 2.4. Xóa (Delete)
Ba trường hợp:

**TH1: Nút không có con (Leaf)**
```
Xóa 20:
        50                 50
       /  \               /  \
      30   70    →       30   70
     / \   / \            \   / \
   [20] 40 60 80          40 60 80
```

**TH2: Nút có một con**
```
Xóa 30 (có 1 con là 40):
        50                 50
       /  \               /  \
     [30]  70    →       40   70
       \   / \                /\
       40 60 80             60 80
```

**TH3: Nút có hai con**
```
Xóa 50 (có 2 con):
Bước 1: Tìm successor (min của cây con phải) = 60
Bước 2: Copy 60 lên vị trí 50
Bước 3: Xóa nút 60 gốc (rơi vào TH1)

        [50]               60
       /  \               /  \
      30   70    →       30   70
     / \   / \          / \    \
    20 40 60 80        20 40   80
```

---

## 3. 🧮 Cài Đặt & Độ Phức Tạp

### 3.1. Cấu trúc nút và cây mẫu (C++)
```cpp
template<class T>
struct BSNode {
    T key;
    BSNode *left, *right;
    BSNode(T k) : key(k), left(NULL), right(NULL) {}
};

template<class T>
class BSTree {
private:
    BSNode<T>* root;

    BSNode<T>* insert(BSNode<T>* r, T x) {
        if (!r) return new BSNode<T>(x);
        if (x < r->key) r->left = insert(r->left, x);
        else if (x > r->key) r->right = insert(r->right, x);
        return r;
    }

    BSNode<T>* search(BSNode<T>* r, T x) {
        if (!r || r->key == x) return r;
        return (x < r->key) ? search(r->left, x) : search(r->right, x);
    }

    BSNode<T>* findMin(BSNode<T>* r) {
        while (r && r->left) r = r->left;
        return r;
    }

    BSNode<T>* remove(BSNode<T>* r, T x) {
        if (!r) return r;
        if (x < r->key) r->left = remove(r->left, x);
        else if (x > r->key) r->right = remove(r->right, x);
        else {
            if (!r->left) { BSNode<T>* temp = r->right; delete r; return temp; }
            if (!r->right) { BSNode<T>* temp = r->left; delete r; return temp; }
            BSNode<T>* temp = findMin(r->right);
            r->key = temp->key;
            r->right = remove(r->right, temp->key);
        }
        return r;
    }

    void inorder(BSNode<T>* r) {
        if (!r) return;
        inorder(r->left);
        cout << r->key << " ";
        inorder(r->right);
    }

public:
    BSTree() : root(NULL) {}
    void Insert(T x) { root = insert(root, x); }
    void Remove(T x) { root = remove(root, x); }
    bool Search(T x) { return search(root, x) != NULL; }
    void InOrder() { inorder(root); cout << endl; }
};
```

### 3.2. Ví dụ sử dụng
```cpp
int main() {
    BSTree<int> tree;
    
    // Chèn các phần tử
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);
    
    // In theo thứ tự Inorder
    tree.InOrder(); // Output: 20 30 40 50 60 70 80
    
    // Tìm kiếm
    cout << tree.Search(40); // Output: 1 (true)
    cout << tree.Search(99); // Output: 0 (false)
    
    // Xóa
    tree.Remove(30);
    tree.InOrder(); // Output: 20 40 50 60 70 80
    
    return 0;
}
```

### 3.3. Độ phức tạp thời gian

| Phép toán | Trung bình | Tệ nhất (cây suy biến) |
| --------- | ---------- | ---------------------- |
| Search    | O(log n)   | O(n)                   |
| Insert    | O(log n)   | O(n)                   |
| Delete    | O(log n)   | O(n)                   |

**Ví dụ cây suy biến (tệ nhất):**
```
Chèn theo thứ tự: 10, 20, 30, 40, 50

10            ← Chiều cao = 5 = n
 \
  20          → Trở thành danh sách liên kết
   \
    30        → Search/Insert/Delete = O(n)
     \
      40
       \
        50
```

Nguyên nhân tệ nhất → cây mất cân bằng khi dữ liệu được chèn theo thứ tự tăng dần/giảm dần.

---

## 4. 🌟 Cây Tìm Kiếm Nhị Phân Cân Bằng

BST có nhược điểm → có thể lệch thành danh sách đơn → **O(n)**.

Giải pháp → **Cây cân bằng độ cao**:

| Loại cây          | Đặc điểm                         | Độ phức tạp        |
| ----------------- | -------------------------------- | ------------------ |
| AVL               | chênh lệch chiều cao mỗi nút ≤ 1 | O(log n)           |
| Red–Black Tree    | cân bằng màu                     | O(log n)           |
| Splay Tree        | tự điều chỉnh                    | amortized O(log n) |
| Treap / Skip List | cân bằng ngẫu nhiên              | O(log n)           |

**Ví dụ so sánh BST thường vs AVL:**
```
BST thường (dữ liệu tăng dần):    AVL (tự cân bằng):
1                                      20
 \                                    /  \
  2                                  10   30
   \                →               / \   / \
    3                               1  2  3  40
     \
      4                          Chiều cao: 3 vs 5
```

Tất cả đảm bảo operations Search/Insert/Delete **trong trường hợp xấu nhất** chỉ **O(log n)**.

---

## 5. 🚀 Tóm tắt nhanh

| BST                        | Ưu điểm    | Nhược điểm            |
| -------------------------- | ---------- | --------------------- |
| Tìm kiếm nhị phân trên cây | Cài đặt dễ | Dễ suy biến           |
| Inorder cho dãy tăng       | Bộ nhớ tốt | Phụ thuộc thứ tự chèn |
| Insert/Delete/Search nhanh |            |                       |

📌 **Với dữ liệu ngẫu nhiên → BST rất hiệu quả (O(log n)).**
📌 **Với dữ liệu có thứ tự → dùng AVL / Red-Black để tránh suy biến.**

---

💡 *BST là nền tảng quan trọng để hiểu các cây nâng cấp (AVL, Red-Black) và các cấu trúc tập động hiệu suất cao.*

# 🌲 CÂY AVL (AVL TREE) - CÂY TÌM KIẾM CÂN BẰNG

## 1. 📌 Khái niệm và Đặc điểm

### 1.1. Định nghĩa
**Cây AVL** là cây tìm kiếm nhị phân thỏa mãn điều kiện: **độ cao của cây con trái và độ cao của cây con phải của mỗi đỉnh khác nhau không quá 1**.

- Được đề xuất bởi các nhà toán học Nga **Adelson-Velskii** và **Landis**.
- Thuộc lớp các **cây tìm kiếm cân bằng** (Balanced Search Trees).
- Khắc phục nhược điểm của BST thông thường trong trường hợp xấu nhất.

### 1.2. Balance Factor (Hệ số cân bằng)
**Balance Factor (BF)** của một nút = `Chiều cao cây con trái - Chiều cao cây con phải`

**Ba trạng thái cân bằng:**
- **EH** (Equal Height): BF = 0 (cây con trái và phải có độ cao bằng nhau)
- **LH** (Left Height): BF = +1 (cây con trái cao hơn cây con phải 1)
- **RH** (Right Height): BF = -1 (cây con phải cao hơn cây con trái 1)

**Điều kiện cây AVL:** |BF| ≤ 1 tại mọi nút

### 1.3. Ví dụ minh họa

**✅ Cây AVL hợp lệ:**
```
        50 (BF=0)
       /  \
      30   70 (BF=0)
     / \   / \
    20 40 60 80
   (0) (0)(0)(0)

Tất cả các nút có |BF| ≤ 1 ✓
```

**✅ Cây AVL hợp lệ (lệch trái):**
```
        50 (BF=+1)
       /  \
      30   70 (BF=0)
     / \    \
    20 40   80
   (0) (0)  (0)

BF(50) = 2 - 1 = +1 ✓
BF(30) = 1 - 1 = 0 ✓
BF(70) = 0 - 1 = -1 ✓
```

**❌ KHÔNG phải cây AVL:**
```
        50 (BF=+2) ← Vi phạm!
       /  \
      30   70
     /      \
    20      80
   /
  10

BF(50) = 3 - 1 = +2 → |BF| > 1 ✗
```

### 1.4. Độ phức tạp
- **Độ cao cây AVL:** h = **O(log n)**
- **Tất cả phép toán:** Search, Insert, Delete = **O(log n)** (kể cả trường hợp xấu nhất)

---

## 2. ⚙️ Các Phép Toán

### 2.1. Tìm kiếm, Min, Max (O(log n))
Giống như BST thông thường, nhưng **luôn đảm bảo O(log n)** nhờ cây cân bằng.

### 2.2. Chèn (Insert) - O(log n)

**Quy trình:**
1. Chèn như BST thông thường
2. Cập nhật Balance Factor khi quay lại từ đệ quy
3. Nếu phát hiện nút mất cân bằng (|BF| > 1) → **thực hiện phép quay**
4. Chỉ cần **một phép quay đơn hoặc kép** tại nút đầu tiên mất cân bằng

**Ví dụ: Chèn 25 vào cây**
```
Bước 1: Chèn như BST
        50
       /  \
      30   70
     /
    20
      \
      25  ← Chèn vào

Bước 2: Tính lại BF
        50 (BF=+2) ← Mất cân bằng!
       /  \
      30   70
     (BF=+1)
     /
    20
   (BF=-1)
      \
      25

Bước 3: Xác định mẫu quay
- Nút 50 lệch trái (BF=+2)
- Con trái (30) lệch trái (BF=+1)
→ Nhưng cháu (20) lại lệch phải (BF=-1)
→ Mẫu Left-Right → Quay kép

Bước 4: Sau khi quay
        30
       /  \
      20   50
        \    \
        25   70
```

### 2.3. Xóa (Delete) - O(log n)

**Quy trình:**
1. Xóa như BST thông thường
2. Cập nhật Balance Factor từ nút bị xóa lên gốc
3. **Mất cân bằng có thể lan truyền lên trên** → cần quay nhiều lần
4. Đi từ nút bị xóa ngược lên gốc, khôi phục cân bằng tại mỗi nút

**Ví dụ: Xóa 70**
```
Trước khi xóa:
        50
       /  \
      30   70 ← Xóa
     / \   / \
    20 40 60 80

Sau khi xóa (thay bằng successor 80):
        50 (BF=-2) ← Mất cân bằng!
       /  \
      30   80
     / \
    20 40

Sau khi quay trái tại 50:
        80
       /  
      50   
     / \   
    30  ∅
   / \
  20 40
```

---

## 3. 🔄 Các Phép Quay (Rotations)

Phép quay là công cụ chính để khôi phục cân bằng, thời gian thực hiện: **O(1)**

### 3.1. Quay Phải (Right Rotation)
**Khi nào:** Nút lệch trái (BF = +2) và con trái cũng lệch trái (BF ≥ 0)
```
    y (BF=+2)              x
   / \                    / \
  x   C    →Quay phải→   A   y
 / \                        / \
A   B                      B   C
```

**Ví dụ cụ thể:**
```
Trước quay:              Sau quay:
    30 (BF=+2)              20
   /  \                    /  \
  20   40    →            10   30
 /                              \
10                              40
```

### 3.2. Quay Trái (Left Rotation)
**Khi nào:** Nút lệch phải (BF = -2) và con phải cũng lệch phải (BF ≤ 0)
```
  x (BF=-2)                y
 / \                      / \
A   y      →Quay trái→   x   C
   / \                  / \
  B   C                A   B
```

**Ví dụ cụ thể:**
```
Trước quay:              Sau quay:
    10 (BF=-2)              20
   /  \                    /  \
  5    20    →            10   30
        \                /
        30              5
```

### 3.3. Quay Kép Trái-Phải (Left-Right Rotation)
**Khi nào:** Nút lệch trái (BF = +2) nhưng con trái lệch phải (BF < 0)
```
    z (BF=+2)          z              y
   / \                / \            / \
  x   D   →Quay trái→ y  D  →Quay→  x   z
 / \      tại x      / \    phải   / \ / \
A   y               x   C  tại z  A  B C  D
   / \             / \
  B   C           A   B
```

**Ví dụ cụ thể:**
```
Trước quay:          Sau quay trái    Sau quay phải
                     tại 10:          tại 30:
    30 (BF=+2)          30                20
   /  \                /  \              /  \
  10   40    →        20   40    →      10   30
   \                 /                        \
   20               10                        40

Mẫu: Left-Right → Quay kép
```

### 3.4. Quay Kép Phải-Trái (Right-Left Rotation)
**Khi nào:** Nút lệch phải (BF = -2) nhưng con phải lệch trái (BF > 0)
```
  x (BF=-2)          x                y
 / \                / \              / \
A   z   →Quay phải→ A  y  →Quay→   x   z
   / \    tại z       / \   trái  / \ / \
  y   D              B   z tại x A  B C  D
 / \                    / \
B   C                  C   D
```

**Ví dụ cụ thể:**
```
Trước quay:          Sau quay phải    Sau quay trái
                     tại 30:          tại 10:
    10 (BF=-2)          10                20
   /  \                /  \              /  \
  5    30    →        5    20    →      10   30
      /                     \          /      
     20                     30        5       

Mẫu: Right-Left → Quay kép
```

---

## 4. 🧮 Cài Đặt

### 4.1. Cấu trúc dữ liệu
```cpp
enum StateType { LH = 1, EH = 0, RH = -1 };

template<class T>
struct AVLNode {
    T key;
    AVLNode *left, *right;
    StateType balance; // Lưu balance factor
    
    AVLNode(T k) : key(k), left(NULL), right(NULL), balance(EH) {}
};

template<class T>
class AVLTree {
private:
    AVLNode<T>* root;
    
    // Các hàm quay
    AVLNode<T>* rightRotation(AVLNode<T>* y);
    AVLNode<T>* leftRotation(AVLNode<T>* x);
    AVLNode<T>* LR_Rotation(AVLNode<T>* node);
    AVLNode<T>* RL_Rotation(AVLNode<T>* node);
    
    // Hàm hỗ trợ
    int height(AVLNode<T>* node);
    int getBalance(AVLNode<T>* node);
    
    // Phép toán chính
    AVLNode<T>* insert(AVLNode<T>* node, T key);
    AVLNode<T>* remove(AVLNode<T>* node, T key);
    AVLNode<T>* findMin(AVLNode<T>* node);
    
public:
    AVLTree() : root(NULL) {}
    void Insert(T key) { root = insert(root, key); }
    void Remove(T key) { root = remove(root, key); }
    void InOrder() { inorder(root); cout << endl; }
};
```

### 4.2. Hàm tính chiều cao và Balance Factor
```cpp
template<class T>
int AVLTree<T>::height(AVLNode<T>* node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

template<class T>
int AVLTree<T>::getBalance(AVLNode<T>* node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}
```

### 4.3. Các hàm quay
```cpp
// Quay phải
template<class T>
AVLNode<T>* AVLTree<T>::rightRotation(AVLNode<T>* y) {
    AVLNode<T>* x = y->left;
    AVLNode<T>* B = x->right;
    
    // Thực hiện quay
    x->right = y;
    y->left = B;
    
    // Cập nhật balance factor
    y->balance = (StateType)getBalance(y);
    x->balance = (StateType)getBalance(x);
    
    return x; // x trở thành gốc mới
}

// Quay trái
template<class T>
AVLNode<T>* AVLTree<T>::leftRotation(AVLNode<T>* x) {
    AVLNode<T>* y = x->right;
    AVLNode<T>* B = y->left;
    
    // Thực hiện quay
    y->left = x;
    x->right = B;
    
    // Cập nhật balance factor
    x->balance = (StateType)getBalance(x);
    y->balance = (StateType)getBalance(y);
    
    return y; // y trở thành gốc mới
}

// Quay kép Trái-Phải
template<class T>
AVLNode<T>* AVLTree<T>::LR_Rotation(AVLNode<T>* node) {
    node->left = leftRotation(node->left);   // Quay trái tại con trái
    return rightRotation(node);              // Quay phải tại gốc
}

// Quay kép Phải-Trái
template<class T>
AVLNode<T>* AVLTree<T>::RL_Rotation(AVLNode<T>* node) {
    node->right = rightRotation(node->right); // Quay phải tại con phải
    return leftRotation(node);                // Quay trái tại gốc
}
```

### 4.4. Hàm Insert
```cpp
template<class T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* node, T key) {
    // Bước 1: Chèn như BST thông thường
    if (!node) return new AVLNode<T>(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Không chèn khóa trùng
    
    // Bước 2: Cập nhật balance factor
    node->balance = (StateType)getBalance(node);
    
    // Bước 3: Kiểm tra mất cân bằng và quay
    
    // TH1: Left-Left (quay phải)
    if (node->balance > 1 && key < node->left->key)
        return rightRotation(node);
    
    // TH2: Right-Right (quay trái)
    if (node->balance < -1 && key > node->right->key)
        return leftRotation(node);
    
    // TH3: Left-Right (quay kép trái-phải)
    if (node->balance > 1 && key > node->left->key)
        return LR_Rotation(node);
    
    // TH4: Right-Left (quay kép phải-trái)
    if (node->balance < -1 && key < node->right->key)
        return RL_Rotation(node);
    
    return node;
}
```

### 4.5. Hàm Delete
```cpp
template<class T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* node, T key) {
    // Bước 1: Xóa như BST thông thường
    if (!node) return node;
    
    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else {
        // Tìm thấy nút cần xóa
        if (!node->left || !node->right) {
            AVLNode<T>* temp = node->left ? node->left : node->right;
            if (!temp) { // Không có con
                temp = node;
                node = NULL;
            } else // Có một con
                *node = *temp;
            delete temp;
        } else {
            // Có hai con: tìm successor
            AVLNode<T>* temp = findMin(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
    }
    
    if (!node) return node;
    
    // Bước 2: Cập nhật balance factor
    node->balance = (StateType)getBalance(node);
    
    // Bước 3: Cân bằng lại cây (có thể cần nhiều phép quay)
    
    // Left-Left hoặc Left-Right
    if (node->balance > 1) {
        if (getBalance(node->left) >= 0)
            return rightRotation(node);
        else
            return LR_Rotation(node);
    }
    
    // Right-Right hoặc Right-Left
    if (node->balance < -1) {
        if (getBalance(node->right) <= 0)
            return leftRotation(node);
        else
            return RL_Rotation(node);
    }
    
    return node;
}

template<class T>
AVLNode<T>* AVLTree<T>::findMin(AVLNode<T>* node) {
    while (node && node->left)
        node = node->left;
    return node;
}
```

### 4.6. Ví dụ sử dụng
```cpp
int main() {
    AVLTree<int> tree;
    
    // Chèn các phần tử (tự động cân bằng)
    cout << "Chèn: 10, 20, 30, 40, 50, 25\n";
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(30); // Sẽ tự động quay trái tại 10
    tree.Insert(40);
    tree.Insert(50); // Sẽ tự động quay trái tại 20
    tree.Insert(25);
    
    cout << "Inorder: ";
    tree.InOrder(); // Output: 10 20 25 30 40 50
    
    // Xóa
    cout << "\nXóa 20\n";
    tree.Remove(20);
    cout << "Inorder: ";
    tree.InOrder(); // Output: 10 25 30 40 50
    
    return 0;
}
```

---

## 5. 📊 So Sánh BST vs AVL

| Tiêu chí           | BST thông thường      | AVL Tree         |
| ------------------ | --------------------- | ---------------- |
| Độ phức tạp TB     | O(log n)              | O(log n)         |
| Độ phức tạp TC xấu | **O(n)** (suy biến)   | **O(log n)** ✓   |
| Cài đặt            | Đơn giản              | Phức tạp hơn     |
| Overhead           | Không                 | Lưu balance, quay |
| Thích hợp          | Dữ liệu ngẫu nhiên    | Dữ liệu có thứ tự |
| Insert/Delete      | Nhanh hơn             | Chậm hơn chút    |
| Search             | Tương đương           | Đảm bảo O(log n) |

---

## 6. 🚀 Tóm Tắt

✅ **Ưu điểm:**
- Đảm bảo **O(log n)** cho mọi phép toán, kể cả trường hợp xấu nhất
- Không bao giờ suy biến thành danh sách như BST
- Tự động cân bằng sau mỗi Insert/Delete

❌ **Nhược điểm:**
- Cài đặt phức tạp hơn BST
- Overhead lưu trữ balance factor
- Insert/Delete chậm hơn BST một chút do phải quay

📌 **Khi nào dùng AVL:**
- Khi cần **đảm bảo hiệu suất ổn định** O(log n)
- Dữ liệu được chèn theo **thứ tự tăng/giảm**
- Số lượng **Search nhiều** hơn Insert/Delete
- Ứng dụng **real-time** cần độ trễ dự đoán được

💡 *AVL là cây cân bằng nghiêm ngặt nhất, thích hợp cho ứng dụng cần tìm kiếm nhanh và ổn định.*

# 🏔️ CÂY THỨ TỰ BỘ PHẬN — HEAP (PARTIALLY ORDERED TREE)

## 1. 📌 Khái niệm và Đặc điểm

### 1.1. Định nghĩa
**Heap** (Cây thứ tự bộ phận) là một cây nhị phân thỏa mãn **hai tính chất** chính:

#### Tính chất 1: Cây nhị phân hoàn toàn (Complete Binary Tree)
- Tất cả các mức đều được lấp đầy, **trừ mức thấp nhất** có thể được lấp đầy **từ bên trái**.
- Cho phép **cài đặt hiệu quả bằng mảng**.

#### Tính chất 2: Thứ tự Bộ phận (Heap Property)
Có hai loại Heap:

**Min-Heap:** Khóa của một đỉnh bất kỳ **≤** khóa của các đỉnh con.
```
        10
       /  \
      15   20
     / \   / \
    17 18 25 30
```

**Max-Heap:** Khóa của một đỉnh bất kỳ **≥** khóa của các đỉnh con.
```
        100
       /   \
      80    90
     / \    / \
    70 60  85 75
```

### 1.2. Hệ quả quan trọng
- **Phần tử nhỏ nhất (Min-Heap) hoặc lớn nhất (Max-Heap) luôn ở gốc**.
- Các giá trị trên đường đi từ gốc đến lá tạo thành **dãy không giảm (Min-Heap)** hoặc **không tăng (Max-Heap)**.
- **Không đảm bảo thứ tự hoàn toàn** như BST (Inorder không cho dãy tăng).

### 1.3. Ví dụ minh họa

**✅ Min-Heap hợp lệ:**
```
        5
       / \
      10  15
     / \  /
    20 25 30

- Gốc 5 là nhỏ nhất ✓
- 5 < {10, 15} ✓
- 10 < {20, 25} ✓
- 15 < {30} ✓
- Cây hoàn toàn (lấp từ trái) ✓
```

**❌ KHÔNG phải Min-Heap:**
```
        5
       / \
      10  15
     / \    \
    20 25   30  ← Vi phạm tính chất cây hoàn toàn!

Mức thấp nhất không lấp từ trái ✗
```

**❌ KHÔNG phải Min-Heap:**
```
        10
       /  \
      5   15  ← Vi phạm heap property!
     / \
    20 25

10 > 5 → Vi phạm tính chất thứ tự ✗
```

### 1.4. Độ phức tạp
- **Độ cao Heap:** h = **O(log n)**
- **FindMin/Max:** **O(1)** (luôn ở gốc)
- **Insert, DeleteMin:** **O(log n)**

---

## 2. 🗂️ Cài Đặt Heap Bằng Mảng

### 2.1. Công thức ánh xạ
Heap được cài đặt hiệu quả bằng **mảng** với các công thức:

| Quan hệ        | Công thức         |
| -------------- | ----------------- |
| Nút tại i      | `A[i]`            |
| Con trái của i | `A[2*i + 1]`      |
| Con phải của i | `A[2*i + 2]`      |
| Cha của i      | `A[(i-1) / 2]`    |

### 2.2. Ví dụ Min-Heap trong mảng

**Cây:**
```
        5
       / \
      10  15
     / \  /
    20 25 30
```

**Mảng:**
```
Index:  0   1   2   3   4   5
Array: [5, 10, 15, 20, 25, 30]
        ↑   ↑   ↑   ↑   ↑   ↑
       gốc  │   │   │   │   │
           con  │   │   │   │
           trái │   │   │   │
               con  │   │   │
               phải │   │   │
                   con  │   │
                   A[1] │   │
                       con  │
                       A[1] │
                           con
                           A[2]
```

**Tính toán:**
- Con trái của `A[0]=5`: `A[2*0+1]` = `A[1]=10` ✓
- Con phải của `A[0]=5`: `A[2*0+2]` = `A[2]=15` ✓
- Con trái của `A[1]=10`: `A[2*1+1]` = `A[3]=20` ✓
- Cha của `A[4]=25`: `A[(4-1)/2]` = `A[1]=10` ✓

---

## 3. ⚙️ Các Phép Toán

### 3.1. FindMin/FindMax - O(1)
**Mô tả:** Trả về phần tử ở gốc (luôn là min/max).

```cpp
T findMin() {
    if (size == 0) throw "Heap rỗng!";
    return A[0]; // Gốc luôn là min
}
```

**Ví dụ:**
```
Heap: [5, 10, 15, 20, 25, 30]
FindMin() → 5 (chỉ truy cập A[0])
```

### 3.2. Insert - O(log n)

**Quy trình:**
1. Thêm phần tử vào **cuối mảng** (vị trí lá ngoài cùng bên phải)
2. **Sift Up** (đẩy lên): So sánh với cha, nếu vi phạm heap property → hoán vị
3. Lặp lại cho đến khi thỏa mãn heap property

**Ví dụ: Insert 3 vào Min-Heap**

```
Bước 1: Thêm vào cuối
        5
       / \
      10  15
     / \  / \
    20 25 30 [3]

Mảng: [5, 10, 15, 20, 25, 30, 3]
                              ↑ Thêm vào index 6

Bước 2: So sánh với cha
3 < 15 → Hoán vị
        5
       / \
      10  [3]
     / \  / \
    20 25 30 15

Mảng: [5, 10, 3, 20, 25, 30, 15]

Bước 3: Tiếp tục so sánh
3 < 5 → Hoán vị
        [3]
       /   \
      10    5
     / \   / \
    20 25 30 15

Mảng: [3, 10, 5, 20, 25, 30, 15] ← Hoàn thành!
```

**Code:**
```cpp
void insert(T value) {
    if (size >= capacity) resize();
    
    // Thêm vào cuối
    A[size] = value;
    int i = size;
    size++;
    
    // Sift Up
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (A[i] < A[parent]) {
            swap(A[i], A[parent]);
            i = parent;
        } else break;
    }
}
```

### 3.3. DeleteMin - O(log n)

**Quy trình:**
1. **Lưu giá trị gốc** để trả về
2. **Thay gốc bằng phần tử cuối cùng** và giảm size
3. **Sift Down** (đẩy xuống): So sánh với con nhỏ hơn, nếu vi phạm → hoán vị
4. Lặp lại cho đến khi thỏa mãn heap property

**Ví dụ: DeleteMin từ Min-Heap**

```
Bước 1: Lưu gốc (5) và thay bằng phần tử cuối (30)
        [30]
       /   \
      10    15
     / \    /
    20 25  [∅]

Mảng: [30, 10, 15, 20, 25] (size giảm 1)

Bước 2: Sift Down - So sánh 30 với con
Con trái = 10, Con phải = 15
Min(10, 15) = 10 → 30 > 10 → Hoán vị với 10

        10
       /  \
     [30]  15
     / \
    20 25

Mảng: [10, 30, 15, 20, 25]

Bước 3: Tiếp tục Sift Down
Con trái = 20, Con phải = 25
Min(20, 25) = 20 → 30 > 20 → Hoán vị với 20

        10
       /  \
      20   15
     / \
   [30] 25

Mảng: [10, 20, 15, 30, 25] ← Hoàn thành!
```

**Code:**
```cpp
T deleteMin() {
    if (size == 0) throw "Heap rỗng!";
    
    T minValue = A[0];
    
    // Thay gốc bằng phần tử cuối
    A[0] = A[size - 1];
    size--;
    
    // Sift Down
    int i = 0;
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smaller = left;
        
        // Tìm con nhỏ hơn
        if (right < size && A[right] < A[left])
            smaller = right;
        
        // Nếu vi phạm heap property → hoán vị
        if (A[i] > A[smaller]) {
            swap(A[i], A[smaller]);
            i = smaller;
        } else break;
    }
    
    return minValue;
}
```

### 3.4. DecreaseKey - O(log n)

**Mô tả:** Giảm giá trị khóa tại vị trí i, sau đó **Sift Up** để khôi phục heap property.

**Ví dụ: DecreaseKey(index=4, newValue=8)**

```
Trước:
        5
       / \
      10  15
     / \
    20 [25] ← index 4

Mảng: [5, 10, 15, 20, 25]

Sau khi giảm xuống 8:
        5
       / \
      10  15
     / \
    20 [8]

Mảng: [5, 10, 15, 20, 8]

Sift Up: 8 < 10 → Hoán vị
        5
       / \
     [8]  15
     / \
    20 10

Mảng: [5, 8, 15, 20, 10] ← Hoàn thành!
```

**Code:**
```cpp
void decreaseKey(int i, T newValue) {
    if (newValue > A[i]) {
        throw "Giá trị mới phải nhỏ hơn giá trị cũ!";
    }
    
    A[i] = newValue;
    
    // Sift Up
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (A[i] < A[parent]) {
            swap(A[i], A[parent]);
            i = parent;
        } else break;
    }
}
```

---

## 4. 🏗️ Xây Dựng Heap (Heapify)

### 4.1. Phương pháp 1: Insert tuần tự - O(n log n)
Chèn từng phần tử vào heap rỗng → Mỗi lần Insert O(log n) → Tổng O(n log n)

### 4.2. Phương pháp 2: Build Heap tối ưu - O(n) ⭐

**Ý tưởng:** Bắt đầu từ nút cha cuối cùng (`n/2 - 1`), thực hiện Sift Down ngược về gốc.

**Tại sao O(n)?**
- Các nút ở mức cuối (n/2 nút) không cần sift down → O(1)
- Các nút ở mức cao hơn ít hơn nhưng sift down xa hơn
- Tổng số phép toán: Σ(số nút tại mức h × h) = O(n)

**Ví dụ: Build Heap từ mảng [20, 15, 10, 8, 6, 5]**

```
Bước 1: Xếp thành cây hoàn toàn
        20
       /  \
      15   10
     / \   /
    8  6  5

Bước 2: Tìm nút cha cuối = floor(6/2) - 1 = 2 → index 2 (giá trị 10)

Bước 3: Sift Down từ index 2 → 0

Index 2 (giá trị 10):
10 vs 5 → hoán vị
        20
       /  \
      15   5
     / \   /
    8  6  10

Index 1 (giá trị 15):
15 vs min(8,6) = 6 → hoán vị
        20
       /  \
      6    5
     / \   /
    8  15 10

Index 0 (giá trị 20):
20 vs min(6,5) = 5 → hoán vị
        5
       /  \
      6    20
     / \   /
    8  15 10

Tiếp tục:
20 vs 10 → hoán vị
        5
       /  \
      6    10
     / \   /
    8  15 20

Kết quả: [5, 6, 10, 8, 15, 20] ← Min-Heap!
```

**Code:**
```cpp
void buildHeap(T arr[], int n) {
    // Copy mảng vào heap
    for (int i = 0; i < n; i++)
        A[i] = arr[i];
    size = n;
    
    // Sift Down từ nút cha cuối về gốc
    for (int i = (n / 2) - 1; i >= 0; i--) {
        siftDown(i);
    }
}

void siftDown(int i) {
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smaller = left;
        
        if (right < size && A[right] < A[left])
            smaller = right;
        
        if (A[i] > A[smaller]) {
            swap(A[i], A[smaller]);
            i = smaller;
        } else break;
    }
}
```

---

## 5. 🧮 Cài Đặt Đầy Đủ

### 5.1. Min-Heap Template Class
```cpp
template<class T>
class MinHeap {
private:
    T* A;
    int size;
    int capacity;
    
    void resize() {
        capacity *= 2;
        T* newA = new T[capacity];
        for (int i = 0; i < size; i++)
            newA[i] = A[i];
        delete[] A;
        A = newA;
    }
    
    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (A[i] < A[parent]) {
                swap(A[i], A[parent]);
                i = parent;
            } else break;
        }
    }
    
    void siftDown(int i) {
        while (2 * i + 1 < size) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smaller = left;
            
            if (right < size && A[right] < A[left])
                smaller = right;
            
            if (A[i] > A[smaller]) {
                swap(A[i], A[smaller]);
                i = smaller;
            } else break;
        }
    }
    
public:
    MinHeap(int cap = 10) : size(0), capacity(cap) {
        A = new T[capacity];
    }
    
    ~MinHeap() { delete[] A; }
    
    void insert(T value) {
        if (size >= capacity) resize();
        A[size] = value;
        siftUp(size);
        size++;
    }
    
    T findMin() {
        if (size == 0) throw "Heap rỗng!";
        return A[0];
    }
    
    T deleteMin() {
        if (size == 0) throw "Heap rỗng!";
        T minValue = A[0];
        A[0] = A[size - 1];
        size--;
        if (size > 0) siftDown(0);
        return minValue;
    }
    
    void decreaseKey(int i, T newValue) {
        if (i >= size || newValue > A[i])
            throw "Invalid operation!";
        A[i] = newValue;
        siftUp(i);
    }
    
    bool isEmpty() { return size == 0; }
    int getSize() { return size; }
    
    void print() {
        for (int i = 0; i < size; i++)
            cout << A[i] << " ";
        cout << endl;
    }
};
```

### 5.2. Ví dụ sử dụng
```cpp
int main() {
    MinHeap<int> heap;
    
    // Insert
    cout << "Insert: 20, 15, 10, 8, 6, 5\n";
    heap.insert(20);
    heap.insert(15);
    heap.insert(10);
    heap.insert(8);
    heap.insert(6);
    heap.insert(5);
    
    heap.print(); // Output: 5 8 6 20 15 10
    
    // FindMin
    cout << "Min: " << heap.findMin() << endl; // Output: 5
    
    // DeleteMin
    cout << "DeleteMin: " << heap.deleteMin() << endl; // Output: 5
    heap.print(); // Output: 6 8 10 20 15
    
    cout << "DeleteMin: " << heap.deleteMin() << endl; // Output: 6
    heap.print(); // Output: 8 15 10 20
    
    // DecreaseKey
    heap.decreaseKey(3, 7); // Giảm 20 → 7
    heap.print(); // Output: 7 8 10 15
    
    return 0;
}
```

---

## 6. 🎯 Ứng Dụng: Priority Queue (Hàng Ưu Tiên)

### 6.1. Khái niệm
**Priority Queue** là KDLTT tập động, mỗi phần tử có một **giá trị ưu tiên**, và luôn xử lý phần tử có ưu tiên cao nhất (hoặc thấp nhất) trước.

### 6.2. Các phép toán

| Phép toán   | Mô tả                                | Độ phức tạp |
| ----------- | ------------------------------------ | ----------- |
| enqueue     | Thêm phần tử với ưu tiên             | O(log n)    |
| dequeue     | Lấy và xóa phần tử ưu tiên cao nhất  | O(log n)    |
| peek        | Xem phần tử ưu tiên cao nhất         | O(1)        |
| decreaseKey | Tăng ưu tiên của phần tử             | O(log n)    |

### 6.3. Ví dụ ứng dụng: Hệ thống cấp cứu bệnh viện

```cpp
struct Patient {
    string name;
    int priority; // 1=nguy kịch, 2=nặng, 3=nhẹ
    
    bool operator<(const Patient& other) const {
        return priority > other.priority; // Min-Heap cho priority nhỏ hơn
    }
};

int main() {
    MinHeap<Patient> emergencyQueue;
    
    // Bệnh nhân đến
    emergencyQueue.insert({"An", 3});    // Bệnh nhẹ
    emergencyQueue.insert({"Bình", 1});  // Nguy kịch
    emergencyQueue.insert({"Chi", 2});   // Bệnh nặng
    emergencyQueue.insert({"Dung", 1});  // Nguy kịch
    
    // Xử lý theo ưu tiên
    while (!emergencyQueue.isEmpty()) {
        Patient p = emergencyQueue.deleteMin();
        cout << "Điều trị: " << p.name 
             << " (Ưu tiên: " << p.priority << ")\n";
    }
    
    /* Output:
    Điều trị: Bình (Ưu tiên: 1)
    Điều trị: Dung (Ưu tiên: 1)
    Điều trị: Chi (Ưu tiên: 2)
    Điều trị: An (Ưu tiên: 3)
    */
    
    return 0;
}
```

---

## 7. 📊 So Sánh Các Cấu Trúc

| Tiêu chí       | Array (sắp xếp) | Linked List | BST      | Heap         |
| -------------- | --------------- | ----------- | -------- | ------------ |
| FindMin        | O(1)            | O(n)        | O(log n) | **O(1)** ✓   |
| Insert         | O(n)            | O(1)        | O(log n) | **O(log n)** |
| DeleteMin      | O(n)            | O(n)        | O(log n) | **O(log n)** |
| Inorder sorted | ✓               | ✗           | ✓        | ✗            |
| Cài đặt        | Đơn giản        | Đơn giản    | Phức tạp | Trung bình   |
| Thích hợp      | Static data     | Insert nhiều | Tìm kiếm | Priority Q   |

---

## 8. 🚀 Tóm Tắt

✅ **Ưu điểm:**
- **FindMin/Max: O(1)** - Nhanh nhất trong các cấu trúc tập động
- Insert/Delete: **O(log n)** - Hiệu quả và ổn định
- **Build Heap: O(n)** - Xây dựng nhanh từ mảng
- Cài đặt **đơn giản bằng mảng** - Tiết kiệm bộ nhớ
- Không cần con trỏ như BST/AVL

❌ **Nhược điểm:**
- **Không hỗ trợ tìm kiếm** phần tử tùy ý hiệu quả (O(n))
- **Không duy trì thứ tự toàn phần** (Inorder không cho dãy tăng)
- Merge hai heap **không hiệu quả** trên Binary Heap (O(n))
- **DecreaseKey cần biết vị trí** của phần tử trong mảng

📌 **Khi nào dùng Heap:**
- Cần **truy cập nhanh min/max**
- Cài đặt **Priority Queue**
- **Heap Sort** (sắp xếp O(n log n) tại chỗ)
- **Dijkstra, Prim** (thuật toán đồ thị)
- **Top K elements** (tìm K phần tử lớn/nhỏ nhất)
- **Median tracking** (duy trì trung vị động)

💡 *Heap là cấu trúc tối ưu cho Priority Queue - không cố sắp xếp toàn bộ, chỉ đảm bảo phần tử quan trọng nhất luôn ở vị trí dễ truy cập nhất!*
Hiểu rồi ✔️ — bạn chỉ cần **toàn bộ phần Hash Table** và **đặt trong một khối Markdown duy nhất**.

Dưới đây là **một khối md hoàn chỉnh — đầy đủ, dài, có ví dụ xử lý va chạm**:

---

# 🌟 BẢNG BĂM (HASH TABLE) & PHƯƠNG PHÁP BĂM – TỔNG HỢP CHI TIẾT

## I. Khái niệm & Vai trò

### 🔹 Bảng băm là gì?
**Hash Table** là cấu trúc dữ liệu cài đặt **Kiểu dữ liệu trừu tượng Từ điển (Dictionary)** với 3 phép toán:
| Phép toán | Ý nghĩa | Trung bình |
|----------|--------|------------|
| Search | Tìm khóa | **O(1)** |
| Insert | Thêm dữ liệu | **O(1)** |
| Delete | Xóa dữ liệu | **O(1)** |

🔥 → Hash Table là một trong những cách hiệu quả nhất để cài đặt Dictionary.

### 🔹 Phương pháp băm
Sử dụng **hàm băm** để ánh xạ khóa `k` đến chỉ số `i` của mảng `T`:
```

i = h(k), 0 ≤ i ≤ SIZE − 1

```

---

## II. Hàm Băm (Hash Function)

### ⚠️ Va chạm (Collision)
Nhiều khóa khác nhau có thể cho cùng giá trị băm → cần chiến lược xử lý va chạm.

### 🔸 Một số cách xây dựng hàm băm
| Phương pháp | Công thức | Ghi chú |
|------------|----------|--------|
| Chia dư | `h(k) = k mod SIZE` | Chọn `SIZE` là số nguyên tố để giảm va chạm |
| Nhân | `h(k) = floor( SIZE × (αk − floor(αk)) )`, α ≈ 0.618 | Tản khóa đều |
| Băm chuỗi (String Hashing) | `value = 37×value + ASCII(code)` rồi `mod SIZE` | Phổ biến với xâu ký tự |

---

## III. Giải quyết Va chạm (Collision Resolution)

Có 2 nhóm chính:
1) **Định địa chỉ mở (Open Addressing)**  
2) **Tạo dây chuyền (Chaining)**

---

### 🔥 1. Định địa chỉ mở (Open Addressing)

📌 Dữ liệu lưu trực tiếp trong mảng → mỗi phần tử T[i] chứa **tối đa 1** dữ liệu.  
Khi va chạm, thực hiện **thăm dò** theo dãy cố định.

| Phương pháp | Dãy thăm dò | Ưu điểm | Nhược điểm |
|------------|-------------|---------|------------|
| Thăm dò tuyến tính | `i, i+1, i+2...` | Dễ cài đặt | Tạo **cụm dữ liệu** |
| Thăm dò bình phương | `i + m² mod SIZE` | Giảm cụm | Có thể không thăm hết bảng |
| Băm kép | `i = h₁(k) + m×h₂(k)` | Tốt nhất | Cần 2 hàm băm |

#### 📍 Ví dụ xử lý va chạm
SIZE = 11, `h(k) = k mod 11`  
Chèn: **22, 33, 44**

**a) Thăm dò tuyến tính**
```

22 → 0 → T[0] = 22
33 → 0 va chạm → T[1] = 33
44 → 0 va chạm → T[2] = 44
→ [22, 33, 44, -, -, -, -, -, -, -, -]

```

**b) Thăm dò bình phương**
```

22 → 0 → T[0] = 22
33 → 0 va chạm → +1² = 1 → T[1] = 33
44 → 0 va chạm → +1² = 1 (bận) → +2² = 4 → T[4] = 44
→ [22, 33, -, -, 44, -, -, -, -, -, -]

```

**c) Băm kép**
```

h₂(k) = 7 − (k mod 7)
22 → 0 → T[0] = 22
33 → 0 va chạm → 0 + 1×2 = 2 → T[2] = 33
44 → 0 va chạm → 0 + 1×5 = 5 → T[5] = 44
→ [22, -, 33, -, -, 44, -, -, -, -, -]

```

---

### 🌿 2. Tạo dây chuyền (Chaining)

📌 Mỗi ô T[i] trỏ đến **danh sách liên kết** chứa tất cả các dữ liệu có cùng giá trị băm.

Ví dụ:
```

SIZE = 5
h(k) = k mod 5
Chèn: 12, 7, 22, 17

12 → 2 → T[2] = 12
7  → 2 → T[2] = 12 → 7
22 → 2 → T[2] = 12 → 7 → 22
17 → 2 → T[2] = 12 → 7 → 22 → 17

→ Bảng:
T[2] = 12 → 7 → 22 → 17

```

✔ Chèn O(1)  
✔ Không giới hạn bởi SIZE (chỉ giới hạn bởi bộ nhớ)  
✘ Tốn con trỏ và có thể dài nếu hàm băm không đều  

---

## IV. Hiệu năng

### 1) Trường hợp xấu nhất
| Phương pháp | Xấu nhất |
|-------------|----------|
| Open Addressing | **O(N)** |
| Chaining | **O(N)** nếu mọi phần tử rơi vào một chain |

### 2) Thời gian trung bình
Được đánh giá theo **mức độ đầy (load factor)**:
```

α = N / SIZE

```

| Kỹ thuật | Search thành công | Search thất bại |
|---------|-------------------|-----------------|
| Chaining | ≈ 1 + α/2 | ≈ 1 + α |
| Open Addressing – Linear | tốt khi α thấp | ≈ 1 / (1 − α)² |
| Open Addressing – Quadratic / Double | tốt hơn | ≈ 1 / (1 − α) |

⛔ α càng tiến gần 1 → hiệu năng tụt nhanh

---

## V. So sánh với các CTDL khác

| Cấu trúc | Insert | Search | Delete | Duyệt thứ tự |
|---------|--------|--------|--------|-------------|
| Danh sách | O(n) | O(n) | O(n) | Tốt |
| BST cân bằng | O(log n) | O(log n) | O(log n) | Tốt |
| **Hash Table** | **O(1)** | **O(1)** | **O(1)** | ❌ Không hỗ trợ |

➡ Hash Table **không phù hợp** nếu cần:
- tìm min/max
- duyệt tăng dần
- truy vấn theo khoảng (range query)

---

## VI. Ẩn dụ thực tế dễ nhớ 🗂️
Tưởng tượng **một tủ hồ sơ có nhiều ngăn**:
- Hàm băm = **quy tắc phân loại hồ sơ**
- Mỗi ngăn tương ứng `T[i]`
- Nếu hai hồ sơ vào cùng một ngăn:
  - **Open Addressing** → cố gắng đặt vào ngăn gần đó
  - **Chaining** → tạo **danh sách hồ sơ phụ** trong ngăn

📌 → Phương pháp băm giúp xác định ngăn **ngay lập tức** mà không cần duyệt tuần tự.

---

## 🎯 Kết luận
| Điểm mạnh của Hash Table |
|--------------------------|
| Tốc độ vượt trội O(1) cho Insert/Search/Delete |
| Rất phù hợp cho Dictionary, Symbol Table, Map, Set |
| Hiệu quả hơn BST và Linked List trong đa số trường hợp |

⚠️ Cần thiết kế tốt:
- Hàm băm tản đều
- Kích thước bảng phù hợp
- Phương pháp xử lý va chạm tối ưu

---



# 🧠 Kiến thức Toàn diện về ĐỒ THỊ (Graph) – Cấu trúc dữ liệu & Giải thuật

Đồ thị (Graph) là mô hình toán học dùng để biểu diễn các đối tượng và mối quan hệ giữa chúng. Trong khoa học máy tính, đồ thị được sử dụng để mô phỏng mạng truyền thông, mạng xã hội, hệ thống giao thông, lập lịch thi, kiến trúc song song...

---

## I. 🧩 Các khái niệm cơ bản

### 1. Đồ thị Định hướng & Vô hướng
| Loại | Cấu trúc cung | Mối quan hệ |
|------|--------------|-------------|
| **Đồ thị định hướng (Directed Graph)** | Cung có thứ tự (u, v) | $u \to v$ |
| **Đồ thị vô hướng (Undirected Graph)** | Cặp không thứ tự {u, v} | tương đương hai cung $u \to v$ và $v \to u$ |

### 2. Đồ thị Có trọng số
- Mỗi cung/cạnh có gắn **trọng số** (weight), còn gọi là **giá** hoặc **độ dài**.

### 3. Đường đi & Chu trình
- **Đường đi**: dãy đỉnh $(v_0, v_1, …, v_k)$ sao cho tồn tại cung $v_i \to v_{i+1}$.
- **Chu trình**: đường đi bắt đầu và kết thúc tại cùng một đỉnh.
- **DAG (Directed Acyclic Graph)**: đồ thị định hướng **không có chu trình**, dùng trong *Topological Sort*.

---

## II. 🗂️ Biểu diễn Đồ thị

| Phương pháp | Ưu điểm | Nhược điểm |
|------------|---------|------------|
| **Ma trận kề (Adjacency Matrix)** | Kiểm tra tồn tại cạnh nhanh | Tốn bộ nhớ $N×N$ khi đồ thị thưa |
| **Danh sách kề (Adjacency List)** | Tiết kiệm bộ nhớ | Kiểm tra tồn tại cạnh mất thời gian |

---

## III. 🔍 Duyệt Đồ thị (Graph Traversal)

### 1. BFS – Duyệt Theo Bề Rộng (Breadth-First Search)
- Thăm lan tỏa từng lớp kề.
- Sử dụng **hàng đợi (Queue)**.
- **Time complexity:** `O(|V| + |E|)`
- Ứng dụng: tìm **đường đi ngắn nhất** trong đồ thị **không trọng số**, xác định **thành phần liên thông**.

### 2. DFS – Duyệt Theo Chiều Sâu (Depth-First Search)
- Đi sâu tối đa rồi lùi lại.
- Thường cài **đệ quy** (tương đương dùng **Stack**).
- **Time complexity:** `O(|V| + |E|)`
- **Phân loại cung trong quá trình DFS:**
  - Tree arcs – cung cây
  - Forward arcs – cung tiến
  - Back arcs – cung ngược (chỉ ra chu trình)
  - Cross arcs – cung xiên
- **Phát hiện chu trình:** đồ thị **không có cung ngược ⇒ không có chu trình**
- **Topological Sort** dựa trên **thứ tự sau của DFS** (chỉ áp dụng cho DAG).

---

## IV. 🏗️ Các thuật toán & bài toán quan trọng

### 1. Tìm đường đi ngắn nhất

| Thuật toán | Điều kiện | Chiến lược |
|------------|-----------|------------|
| **Dijkstra** | Trọng số **không âm** | Tham ăn (Greedy) |
| **Bellman–Ford** | Có thể xử lý **trọng số âm**, nhưng **không có chu trình âm khả đạt từ nguồn** (nếu có → phát hiện được) | Quy hoạch động (Dynamic Programming) – thư giãn cạnh lặp


### 2. Cây Bao Trùm Ngắn Nhất – MST (Minimum Spanning Tree)
- MST: tập cạnh nối **tất cả đỉnh**, **không tạo chu trình**, **tổng trọng số nhỏ nhất**.

| Thuật toán | Ý tưởng | Công cụ  |
|------------|-------- |----------|
| **Prim** | Mở rộng cây lần lượt theo cạnh nhỏ nhất nối trong → ngoài | Hàng đợi ưu tiên |
| **Kruskal** | Chọn cạnh nhỏ nhất toàn cục, miễn không tạo chu trình | **Disjoint Set (Union-Find)** |



---

## 🌎 Tóm tắt theo KDLTT
Đồ thị là một KDLTT phức tạp. Duyệt đồ thị (BFS, DFS) là nền tảng cho nhiều thuật toán lớn như:
- tìm đường đi, phát hiện chu trình
- sắp xếp topo
- Dijkstra, Prim, Kruskal
- các bài toán NP-Hard/NP-Complete

📌 **Biểu diễn đồ thị → giống như bản đồ**
- Ma trận kề: nhiều chi tiết nhưng tốn bộ nhớ
- Danh sách kề: gọn nhẹ nhưng mất thời gian kiểm tra cạnh

📌 **Duyệt đồ thị → giống như đi thăm thành phố**
- BFS: lan tỏa từng vòng
- DFS: đi sâu đến tận cùng rồi quay lại

---
Dưới đây là nội dung **được viết lại đầy đủ – dài hơn – rõ ràng hơn – có ví dụ minh họa bằng tay – và đặt trong một khối Markdown** đúng yêu cầu:

# 🔍 Duyệt đồ thị: BFS và DFS – Giải thích chi tiết kèm ví dụ minh họa bằng tay

Trong đồ thị, **Tìm kiếm theo bề rộng (Breadth-First Search – BFS)** và **Tìm kiếm theo độ sâu (Depth-First Search – DFS)** là hai kỹ thuật then chốt để khám phá các đỉnh và cạnh. Chúng là nền tảng của nhiều thuật toán đồ thị như tìm đường đi ngắn nhất, xác định thành phần liên thông, phát hiện chu trình, sắp xếp topo…

---

## 🚀 I. BFS — Tìm kiếm theo Bề rộng

### 1. Ý tưởng và cơ chế
- Bắt đầu từ một **đỉnh gốc**.
- Thăm **tất cả các đỉnh kề trực tiếp trước** (lớp thứ nhất), sau đó thăm **các đỉnh kề của lớp đó** (lớp thứ hai), rồi lớp tiếp theo…  
→ **Lan tỏa dần theo từng lớp (layer)**.

📌 BFS sử dụng **hàng đợi (Queue)** để đảm bảo nguyên tắc:
> đỉnh nào được đưa vào trước → được xử lý trước (FIFO).
```C++
BFS(G, start):
    tạo một mảng visited[] = false
    tạo queue Q

    đánh dấu visited[start] = true
    Q.push(start)

    while Q không rỗng:
        u = Q.pop()
        xử lý u

        for mỗi đỉnh v kề với u:
            if visited[v] == false:
                visited[v] = true
                Q.push(v)
```
### 2. Phân tích hiệu quả
- **Độ phức tạp thời gian:** `O(|V| + |E|)`
- **Không phụ thuộc biểu diễn đồ thị** (ma trận kề hay danh sách kề).

### 3. Ứng dụng quan trọng
| Vấn đề | BFS ứng dụng |
|-------|--------------|
| Xác định tính đạt tới | ✔ |
| Đường đi ngắn nhất trong đồ thị không trọng số | ✔ |
| Tìm thành phần liên thông | ✔ |

---

### 📌 Ví dụ minh họa BFS (bằng tay)

#### Đồ thị vô hướng bên dưới:

```

0 ─ 1 ─ 2
│   │   │
4 ─ 5 ─ 3

```

**Danh sách kề**
- 0: 1, 4
- 1: 0, 2, 5
- 2: 1, 3
- 3: 2, 5
- 4: 0, 5
- 5: 1, 3, 4

👉 Duyệt BFS từ đỉnh **0**.

| Bước | Đỉnh đang xử lý | Hàng đợi trước bước | Hàng đợi sau bước | Đỉnh vừa thăm |
|------|-----------------|---------------------|------------------|----------------|
| 1 | 0 | [0] | [1, 4] | 0 |
| 2 | 1 | [1, 4] | [4, 2, 5] | 1 |
| 3 | 4 | [4, 2, 5] | [2, 5] | 4 |
| 4 | 2 | [2, 5] | [5, 3] | 2 |
| 5 | 5 | [5, 3] | [3] | 5 |
| 6 | 3 | [3] | [] | 3 |

🎯 **Kết quả BFS:**  
```

0 1 4 2 5 3

```

---

## 🌲 II. DFS — Tìm kiếm theo Độ sâu

### 1. Ý tưởng và cơ chế
- Bắt đầu từ một đỉnh, đi **sâu nhất có thể** theo một nhánh.
- Khi không thể đi sâu nữa, **quay lui (backtrack)** để tìm nhánh khác.
- Có thể cài bằng:
  - **Đệ quy**, hoặc
  - **Ngăn xếp (Stack)**

DFS gán cho mỗi đỉnh:
- **T[v]** – thời điểm bắt đầu thăm (preorder)
- **S[v]** – thời điểm kết thúc xử lý mọi đỉnh kề (postorder)
```C++
DFS(G, start):
    tạo visited[] = false
    tạo stack S

    S.push(start)

    while S không rỗng:
        u = S.pop()

        if visited[u] == false:
            visited[u] = true
            xử lý u

            // thêm hàng xóm theo thứ tự ngược để pop đúng thứ tự mong muốn
            for mỗi v kề u (theo thứ tự ngược):
                if visited[v] == false:
                    S.push(v)
```
### 2. Phân loại cung trong DFS
Trong quá trình duyệt, các cung được phân thành:

| Loại cung | Ý nghĩa |
|----------|---------|
| Cung cây | Theo các nhánh của cây DFS |
| Cung tiến | Từ tổ tiên đến con cháu sâu hơn |
| Cung ngược | Từ con cháu đến tổ tiên (báo hiệu chu trình) |
| Cung xiên | Giữa các nhánh độc lập |

### 3. Ứng dụng quan trọng
| Vấn đề | DFS ứng dụng |
|-------|--------------|
| Phát hiện chu trình | ✔ |
| Sắp xếp topo (DAG) | ✔ |
| Tìm thành phần liên thông | ✔ |
| Tìm cầu, khớp, SCC | ✔ |

---

### 📌 Ví dụ minh họa DFS (bằng tay)

Vẫn dùng đồ thị ví dụ như phần BFS:

```

0 ─ 1 ─ 2
│   │   │
4 ─ 5 ─ 3

```

👉 Duyệt DFS bắt đầu từ **0**, theo đúng thứ tự kề đã cho.

| Bước | Đỉnh hiện tại | Hành động |
|------|---------------|-----------|
| 1 | 0 | Thăm 0 → đi sang 1 |
| 2 | 1 | Thăm 1 → đi sang 2 |
| 3 | 2 | Thăm 2 → đi sang 3 |
| 4 | 3 | Thăm 3 → đi sang 5 |
| 5 | 5 | Thăm 5 → đi sang 4 |
| 6 | 4 | Thăm 4 → không còn đỉnh kề chưa thăm → quay lui |
| 7 | Quay lui lần lượt | 5 → 3 → 2 → 1 → 0 đều không còn đỉnh để đi tiếp |

🎯 **Kết quả DFS:**  
```

0 1 2 3 5 4

```

---

## ⚔️ So sánh tổng quan BFS vs DFS

| Đặc điểm | BFS | DFS |
|---------|-----|-----|
| Cách khám phá | Theo lớp | Theo chiều sâu |
| Cấu trúc hỗ trợ | Queue | Stack / Recursion |
| Đường đi ngắn nhất | ✔ | ❌ |
| Phát hiện chu trình | Bình thường | Mạnh hơn |
| Sắp xếp topo | ❌ | ✔ |
| Cây duyệt | Cây phân tầng | Cây đệ quy sâu |

---

## 🎯 Hình ảnh hóa trực quan (tóm tắt dễ nhớ)

| BFS | DFS |
|-----|-----|
| Giống lan sóng ra ngoài | Giống chui sâu vào hầm |
| Từng lớp gần rồi xa | Đi sâu nhất rồi mới quay lại |
| Tìm đường ngắn nhất | Khám phá toàn diện cấu trúc |
| Phù hợp đồ thị rộng | Phù hợp đồ thị sâu |

---

Dưới đây là nội dung **được viết lại rõ ràng – dễ hiểu – có ví dụ minh họa bằng tay**, và được trình bày **trong một khối Markdown** để bạn copy sử dụng ngay:


# 🧭 Sắp xếp Topo (Topological Sort) – Giải thích chi tiết + ví dụ minh họa bằng tay

## 1️⃣ Khái niệm và mục đích
**Sắp xếp Topo (Topological Sort)** là quá trình **sắp xếp tuyến tính các đỉnh của một Đồ thị định hướng không có chu trình (DAG)** sao cho:

> Nếu tồn tại cung **u → v** thì trong danh sách sắp xếp topo, **u luôn đứng trước v**.

🎯 **Ứng dụng thực tế:**
- Lập lịch môn học (môn A phải hoàn thành trước môn B)
- Trình biên dịch xác định thứ tự biên dịch các module
- Sắp xếp chuỗi nhiệm vụ có phụ thuộc
- Quản lý workflow, dependency trong hệ thống

⚠ **Chú ý quan trọng**
- Chỉ thực hiện được trên **DAG – Đồ thị định hướng không có chu trình**
- Nếu tồn tại **chu trình**, ta **không thể sắp xếp topo**
- Việc phát hiện chu trình có thể thực hiện bằng **DFS**: nếu có **cung ngược (Back arc)** → đồ thị có chu trình → **không phải DAG**

---

## 2️⃣ Thuật toán Sắp xếp Topo dựa trên DFS

### 🔍 Nguyên lý
Trong khi duyệt DFS:
- Khi rời khỏi một đỉnh (tức là thăm xong tất cả các đỉnh kề với nó), ta **đưa đỉnh đó vào đầu danh sách topo**
- Vì nếu **u → v**, thì DFS sẽ hoàn tất **v trước u**, nên khi thêm vào **đầu danh sách**, u sẽ tự động đứng trước v — đúng yêu cầu topo

### 🔥 Tóm tắt thuật toán
```

TopologicalSort(G):
khởi tạo danh sách topo = rỗng
đánh dấu các đỉnh là chưa thăm
với mỗi đỉnh u của đồ thị:
nếu u chưa được thăm → DFS(u)
trả về danh sách topo

DFS(u):
đánh dấu u đã thăm
với mỗi đỉnh v kề u:
nếu v chưa thăm → DFS(v)
thêm u vào đầu danh sách topo

```
Code DFS
```C++

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs(v);
    topo.push_back(u);     // thêm vào cuối
}

vector<int> topo_sort(int n) {
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    reverse(topo.begin(), topo.end());   // đảo lại → topo
    return topo;
}
```
Code BFS
```C++
vector<int> kahn(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);
    
    // 1. Tính in-degree
    for (int u = 0; u < n; u++)
        for (int v : adj[u])
            indeg[v]++;

    queue<int> q;

    // 2. Cho các đỉnh có indegree = 0 vào queue
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);

    vector<int> topo;

    // 3. BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    // kiểm tra chu trình
    if ((int)topo.size() != n)
        cout << "Graph has a cycle\n";

    return topo;
}

```

## 3️⃣ Ví dụ minh họa bằng tay (KHÔNG code)

### 📌 Đồ thị định hướng sau:

```

A → C → D
│   ↘
│     E
└→ B → F

```

**Danh sách kề:**
- A: C, B
- B: F
- C: D, E
- D: (không kề)
- E: (không kề)
- F: (không kề)

👉 Tiến hành DFS theo đúng thứ tự kề

### 🔎 Bảng mô phỏng DFS và xây dựng danh sách topo

| Bước khám phá | Hành động | Danh sách topo (thêm vào ĐẦU) |
|---------------|-----------|-------------------------------|
| DFS(A) → đi C | tiếp tục | [] |
| DFS(C) → đi D | tiếp tục | [] |
| DFS(D) → không còn kề | thêm D | [D] |
| trở lại C → đi E | tiếp tục | [D] |
| DFS(E) → không còn kề | thêm E | [E, D] |
| hoàn thành C | thêm C | [C, E, D] |
| trở lại A → đi B | tiếp tục | [C, E, D] |
| DFS(B) → đi F | tiếp tục | [C, E, D] |
| DFS(F) → không còn kề | thêm F | [F, C, E, D] |
| hoàn thành B | thêm B | [B, F, C, E, D] |
| hoàn thành A | thêm A | [A, B, F, C, E, D] |

### 🎯 Kết quả sắp xếp Topo
```

A  B  F  C  E  D

```

💡 Kiểm tra đúng quy tắc:
- A đứng trước C và B ✓
- B đứng trước F ✓
- C đứng trước D và E ✓

---

## 4️⃣ Ghi nhớ nhanh

| Thuộc tính | Sắp xếp Topo |
|------------|-------------|
| Đồ thị áp dụng | DAG (định hướng – không chu trình) |
| Điều kiện bắt buộc | Không có cung ngược trong DFS |
| Chiến lược | DFS – thêm đỉnh vào đầu danh sách khi hoàn tất |
| Độ phức tạp | `O(|V| + |E|)` |
| Kết quả | Một dãy tuyến tính tôn trọng mọi cung u → v |

---



# 🚦 Thuật toán Dijkstra – Giải thích rõ ràng + Ví dụ bằng tay

Thuật toán **Dijkstra** dùng để tìm **đường đi ngắn nhất từ một đỉnh nguồn `s` đến mọi đỉnh còn lại** trong **đồ thị có trọng số không âm**.

---

## I. 🎯 Mục đích & Điều kiện áp dụng

- **Bài toán:** Với đồ thị có trọng số, tìm độ dài đường đi ngắn nhất từ **nguồn `s`** đến mọi đỉnh `v`.
- **Điều kiện quan trọng:**  
  👉 *Mọi trọng số cung đều không âm*:  
  \[
  c(u, v) \ge 0 \ \forall (u, v) \in E
  \]  
  Nếu có cung trọng số âm → **Dijkstra có thể sai** → nên dùng **Bellman–Ford**.

- **Chiến lược:**  
  Thuật toán dùng **kỹ thuật tham ăn (Greedy)**:
  > Mỗi bước “chốt” **một đỉnh mới** có khoảng cách nhỏ nhất mà ta **chắc chắn** đã biết đường đi ngắn nhất tới nó.

---

## II. 🧩 Ý tưởng & Cấu trúc dữ liệu

Giả sử đồ thị \( G = (V, E) \), nguồn là đỉnh `s`.

### 1. Các cấu trúc chính

- **Tập `S`**:  
  Tập các đỉnh mà **đường đi ngắn nhất từ `s` tới chúng đã được xác định xong**.  
  Ban đầu:  
  \[
  S = \emptyset
  \]

- **Mảng khoảng cách `D[v]`**:
  - `D[v]` = độ dài **đường đi tốt nhất đang biết** từ `s` đến `v` mà chỉ đi qua:
    - các đỉnh trong `S` + chính `v`.
  - Ban đầu:
    - `D[s] = 0`
    - `D[v] = +∞` (hoặc một số rất lớn) với mọi `v ≠ s`.

- **Mảng truy vết `P[v]` (optional nhưng rất hữu ích):**
  - `P[v] = u` nghĩa là: trên đường đi ngắn nhất hiện biết đến `v`, ta đi từ `u` → `v` ở bước cuối.
  - Dùng `P` để **truy vết đường đi** sau khi tính xong.

---

## III. ⚙️ Cơ chế hoạt động (phiên bản ý tưởng)

Lặp lại cho đến khi **mọi đỉnh đều được đưa vào `S`**:

1. **Chọn đỉnh tham ăn `u`**:
   - Chọn `u ∉ S` sao cho `D[u]` là **nhỏ nhất**.
   - Lúc này ta “chốt”:  
     👉 `D[u]` chính là **độ dài đường đi ngắn nhất từ `s` tới `u`**.

2. **Đưa `u` vào tập `S`**.

3. **Thư giãn (relax) các cung từ `u`**:
   - Với mỗi đỉnh kề `v` của `u`:
     - Nếu:
       \[
       D[u] + c(u, v) < D[v]
       \]
       thì:
       - Cập nhật `D[v] = D[u] + c(u, v)`
       - Cập nhật `P[v] = u` (vết đường đi).

---

## IV. ⏱️ Hiệu quả (dùng hàng ưu tiên – Priority Queue)

Để chọn **nhanh** đỉnh `u` có `D[u]` nhỏ nhất, ta dùng **Hàng ưu tiên (Priority Queue)**:

- Mỗi phần tử hàng ưu tiên là một **đỉnh `v`**, với **khóa = `D[v]`**.
- Cần 2 phép toán:
  - **DeleteMin**: lấy ra đỉnh có `D[u]` nhỏ nhất → tương ứng với **chọn đỉnh tham ăn**.
  - **DecreaseKey**: khi thư giãn cung `(u, v)` và tìm được giá trị `D[v]` nhỏ hơn → giảm khóa của `v` trong hàng ưu tiên.

Nếu priority queue được cài bằng **binary heap**:
- Các phép:
  - `DeleteMin` → `O(log |V|)`
  - `DecreaseKey` → `O(log |V|)`
- Tổng:
  \[
  O(|V| \log |V| + |E| \log |V|)
  \]

---

## V. ✋ Ví dụ bằng tay Dijkstra

Xét đồ thị vô hướng, có trọng số không âm:

```

s --- a -------- c
| \    \        |
(5) \    (1)    (1)
|   \     \     |
b    \     \    d
\    (2)   \  /
---------  /
(6)

```

Ta ký hiệu đỉnh:
- `s = 0`
- `a = 1`
- `b = 2`
- `c = 3`
- `d = 4`

**Các cạnh & trọng số** (vô hướng → 2 chiều):
- 0–1: 2
- 0–2: 5
- 1–2: 1
- 1–3: 3
- 2–4: 6
- 3–4: 1

👉 Mục tiêu: tìm **độ dài đường đi ngắn nhất từ `s` (0)** tới mọi đỉnh.

---

### 1️⃣ Khởi tạo

- `S = ∅`
- `D[0] = 0` (nguồn)
- Các đỉnh khác: `D[1] = D[2] = D[3] = D[4] = ∞`
- `P[*] = undefined`

Bảng ban đầu:

| Đỉnh v | D[v] | P[v] |
|--------|------|------|
| 0 (s)  | 0    | -    |
| 1 (a)  | ∞    | -    |
| 2 (b)  | ∞    | -    |
| 3 (c)  | ∞    | -    |
| 4 (d)  | ∞    | -    |

---

### 2️⃣ Bước 1 – Chọn đỉnh gần nhất ngoài S

- Đỉnh có D[v] nhỏ nhất ngoài `S`: **0**
- Đưa 0 vào `S`: `S = {0}`

**Thư giãn các cạnh từ 0:**
- Cạnh `0–1` trọng số 2:
  - `D[0] + 2 = 2 < D[1] = ∞` → cập nhật:
    - `D[1] = 2`, `P[1] = 0`
- Cạnh `0–2` trọng số 5:
  - `D[0] + 5 = 5 < D[2] = ∞` → cập nhật:
    - `D[2] = 5`, `P[2] = 0`

Bảng sau bước 1:

| Đỉnh v | D[v] | P[v] |
|--------|------|------|
| 0 (s)  | 0    | -    |
| 1 (a)  | 2    | 0    |
| 2 (b)  | 5    | 0    |
| 3 (c)  | ∞    | -    |
| 4 (d)  | ∞    | -    |

---

### 3️⃣ Bước 2 – Lặp tiếp

Đỉnh gần nhất ngoài S hiện tại:  
👉 `1` với `D[1] = 2`  
`S = {0, 1}`

**Thư giãn các cạnh từ 1:**
- Cạnh `1–2` trọng số 1:
  - Đi từ `0 → 1 → 2`:  
    `D[1] + 1 = 2 + 1 = 3 < D[2] = 5` → cập nhật:
    - `D[2] = 3`, `P[2] = 1`
- Cạnh `1–3` trọng số 3:
  - `D[1] + 3 = 2 + 3 = 5 < D[3] = ∞` → cập nhật:
    - `D[3] = 5`, `P[3] = 1`

Bảng sau bước 2:

| Đỉnh v | D[v] | P[v] |
|--------|------|------|
| 0 (s)  | 0    | -    |
| 1 (a)  | 2    | 0    |
| 2 (b)  | 3    | 1    |
| 3 (c)  | 5    | 1    |
| 4 (d)  | ∞    | -    |

---

### 4️⃣ Bước 3 – Tiếp tục

Đỉnh gần nhất ngoài S:  
👉 `2` với `D[2] = 3`  
`S = {0, 1, 2}`

**Thư giãn các cạnh từ 2:**
- Cạnh `2–4` trọng số 6:
  - Đi `0 → 1 → 2 → 4`:  
    `D[2] + 6 = 3 + 6 = 9 < D[4] = ∞` → cập nhật:
    - `D[4] = 9`, `P[4] = 2`

Bảng sau bước 3:

| Đỉnh v | D[v] | P[v] |
|--------|------|------|
| 0 (s)  | 0    | -    |
| 1 (a)  | 2    | 0    |
| 2 (b)  | 3    | 1    |
| 3 (c)  | 5    | 1    |
| 4 (d)  | 9    | 2    |

---

### 5️⃣ Bước 4 – Tiếp tục

Đỉnh gần nhất ngoài S:  
👉 `3` với `D[3] = 5`  
`S = {0, 1, 2, 3}`

**Thư giãn các cạnh từ 3:**
- Cạnh `3–4` trọng số 1:
  - Đi `0 → 1 → 3 → 4`:
    `D[3] + 1 = 5 + 1 = 6 < D[4] = 9` → cập nhật:
    - `D[4] = 6`, `P[4] = 3`

Bảng sau bước 4:

| Đỉnh v | D[v] | P[v] |
|--------|------|------|
| 0 (s)  | 0    | -    |
| 1 (a)  | 2    | 0    |
| 2 (b)  | 3    | 1    |
| 3 (c)  | 5    | 1    |
| 4 (d)  | 6    | 3    |

---

### 6️⃣ Bước 5 – Đỉnh cuối cùng

Đỉnh còn lại: `4`,  
`S = {0, 1, 2, 3, 4}` – đã chứa tất cả đỉnh → **dừng**.

---

### ✅ Kết luận từ ví dụ

**Khoảng cách ngắn nhất từ `s (0)` tới các đỉnh:**

| Đỉnh | Độ dài đường đi ngắn nhất | Đường đi |
|------|---------------------------|----------|
| 0 | 0 | 0 |
| 1 | 2 | 0 → 1 |
| 2 | 3 | 0 → 1 → 2 |
| 3 | 5 | 0 → 1 → 3 |
| 4 | 6 | 0 → 1 → 3 → 4 |

---
Dưới đây là phần **trình bày đầy đủ – rõ ràng – giống cấu trúc của Dijkstra và Prim – kèm ví dụ minh họa bằng tay** cho **Thuật toán Bellman–Ford**, đặt trong **một khối Markdown** để bạn copy sử dụng dễ dàng.

---

# 🔁 Thuật toán Bellman–Ford – Đường đi ngắn nhất có trọng số âm + Ví dụ bằng tay

Bellman–Ford là thuật toán đồ thị quan trọng dùng để tìm **đường đi ngắn nhất từ một đỉnh nguồn `s` đến tất cả các đỉnh còn lại**, **kể cả khi đồ thị có trọng số âm**.

---

## I. 🎯 Mục đích và Điều kiện áp dụng

| Thuật toán | Trọng số âm | Phát hiện chu trình âm | Tính đường đi |
|-----------|------------|------------------------|----------------|
| Dijkstra | ❌ Không | ❌ Không | ✔ |
| Bellman–Ford | ✔ Có | ✔ Có | ✔ |
| BFS | Không trọng số | Không | ✔ |

📌 **Điểm mạnh nhất của Bellman–Ford:**  
👉 **Xử lý được trọng số âm và phát hiện được chu trình âm.**

📌 **Điểm yếu:**  
Chạy **chậm hơn Dijkstra** (độ phức tạp `O(|V|·|E|)`).

---

## II. 🔧 Ý tưởng của thuật toán

- Với mỗi cung `(u, v)` có trọng số `c(u, v)`, phép **thư giãn (relax)** kiểm tra:

\[
\text{Nếu } D[u] + c(u, v) < D[v] \Rightarrow \text{cập nhật } D[v] = D[u] + c(u, v)
\]

- **Trọng tâm thuật toán:**
  → **Lặp lại việc thư giãn toàn bộ các cung `|V| − 1` lần.**

Vì:
- Đường đi ngắn nhất không bao giờ đi qua **quá `|V| − 1` cạnh**
- Sau vòng lặp thứ `|V| − 1`, mọi giá trị `D[v]` đã chính xác **nếu không tồn tại chu trình âm**

### 🔥 Kiểm tra chu trình âm
Sau khi thư giãn xong `|V| − 1` vòng:
- Nếu **vẫn còn cung `(u, v)`** thỏa:
  \[
  D[u] + c(u, v) < D[v]
  \]
  → **đồ thị có chu trình âm khả đạt từ nguồn** → không tồn tại lời giải hợp lệ.

---

## III. ✋ Ví dụ minh họa bằng tay Bellman–Ford

### 📌 Đồ thị có trọng số âm (không có chu trình âm)
Bài toán: tìm đường đi ngắn nhất từ `S`.

```

```
  4
```

S ------> A
| \       |
2  \1    -3
|    \    |
v     v   v
B --> C -> D
2     3

```

Đặt tên đỉnh:  
`S = 0`, `A = 1`, `B = 2`, `C = 3`, `D = 4`

### 📎 Danh sách cung
| u | v | c(u, v) |
|---|---|---------|
| S | A | 4 |
| S | B | 2 |
| S | C | 1 |
| B | C | 2 |
| A | D | -3 |
| C | D | 3 |

### 🎯 Khởi tạo
- `D[S] = 0`
- `D[đỉnh khác] = +∞`

| Đỉnh | D[v] | P[v] |
|------|------|------|
| S | 0 | - |
| A | ∞ | - |
| B | ∞ | - |
| C | ∞ | - |
| D | ∞ | - |

---

### 🔁 Lặp thư giãn toàn bộ cung — **vòng 1**

| Cung xét | Kết quả cập nhật |
|---------|-------------------|
| S → A (4) | D[A] = 4 |
| S → B (2) | D[B] = 2 |
| S → C (1) | D[C] = 1 |
| B → C (2) | `2 + 2 = 4 > 1` → không đổi |
| A → D (-3) | `4 - 3 = 1 < ∞` → D[D] = 1 |
| C → D (3) | `1 + 3 = 4 > 1` → không đổi |

| Đỉnh | D[v] | P[v] |
|------|------|------|
| S | 0 | - |
| A | 4 | S |
| B | 2 | S |
| C | 1 | S |
| D | 1 | A |

---

### 🔁 Vòng 2 (không thay đổi gì – do các giá trị đã tối ưu)
Thử lại toàn bộ cung → không có cập nhật mới.

### 🔁 Vòng 3 (không thay đổi gì)
→ Các giá trị đã **tối ưu** → dừng (dù vẫn phải kiểm tra chu trình âm ở bước cuối)

---

### 🔍 Kiểm tra chu trình âm (vòng cuối)
- Không tìm được cung `(u, v)` mà `D[u] + c(u, v) < D[v]`
→ **Đồ thị không có chu trình âm khả đạt từ nguồn**

---

### 🏁 Kết quả cuối cùng

| Đỉnh | Khoảng cách | Đường đi |
|------|-------------|----------|
| S | 0 | S |
| A | 4 | S → A |
| B | 2 | S → B |
| C | 1 | S → C |
| D | 1 | S → A → D |

📌 **Đường đi ngắn nhất từ `S` đến `D` là:**  
```

S → A → D  (tổng trọng số = 1)

```

---

## IV. 🧠 Ghi nhớ nhanh

| Tính chất | Bellman–Ford |
|----------|-------------|
| Trọng số âm | ✔ |
| Chu trình âm | ✔ phát hiện được |
| Chiến lược | Quy hoạch động + thư giãn lặp |
| Số vòng | `|V| − 1` vòng thư giãn + 1 vòng phát hiện chu trình âm |
| Khi nào dùng | Khi đồ thị **có trọng số âm** |

---

## V. So sánh siêu ngắn Dijkstra ↔ Bellman–Ford

| Thuật toán | Trọng số | Độ phức tạp | Phát hiện chu trình âm |
|-----------|----------|-------------|------------------------|
| Dijkstra | Không âm | `O(|E| log |V|)` | ❌ |
| Bellman–Ford | Có thể âm | `O(|V| · |E|)` | ✔ |

🔑 Cách nhớ:
> Nếu đồ thị có **cung âm** → **Dijkstra không dùng được** → **phải dùng Bellman–Ford**

---


# 🔗 Thuật toán Kruskal – Cây bao trùm nhỏ nhất (MST) + Ví dụ minh họa bằng tay

Thuật toán **Kruskal** là một thuật toán đồ thị kinh điển dùng để xây dựng **Cây bao trùm nhỏ nhất (MST – Minimum Spanning Tree)** trong đồ thị **vô hướng – liên thông – có trọng số**.

---

## I. 🎯 Mục đích và Điều kiện áp dụng

- **MST (Minimum Spanning Tree):** tập gồm `|V| - 1` cạnh
  - Nối tất cả các đỉnh
  - Không tạo chu trình
  - Tổng trọng số là **nhỏ nhất**

- **Áp dụng cho đồ thị:**
  ✔ vô hướng  
  ✔ liên thông  
  ✔ có trọng số

---

## II. 💡 Ý tưởng thuật toán Kruskal

Kruskal xây dựng MST theo hướng **từ cạnh nhỏ nhất trở lên**:

1. Sắp xếp **tất cả các cạnh theo trọng số tăng dần**
2. Duyệt từng cạnh theo thứ tự đó
3. **Chọn cạnh nếu nó không tạo chu trình** với các cạnh đã chọn
4. Tiếp tục cho đến khi chọn đủ `|V| − 1` cạnh

⏱ Để **phát hiện chu trình nhanh**, Kruskal sử dụng **cấu trúc dữ liệu Disjoint Set (Union–Find)**:
- `Find(x)` → tìm tập chứa `x`
- `Union(x, y)` → hợp nhất hai tập

---

## III. ⚙️ Độ phức tạp

| Thành phần | Độ phức tạp |
|------------|-------------|
| Sắp xếp các cạnh | `O(|E| log |E|)` |
| Duyệt cạnh + Union–Find | xấp xỉ `O(|E| α(|V|)) ≈ O(|E|)` |
| **Tổng thời gian** | 🔥 `O(|E| log |E|)` |

> α(|V|) là hàm Ackermann nghịch đảo – cực nhỏ (≈ 4 với mọi dữ liệu thực tế)

---

## IV. ✋ Ví dụ minh họa bằng tay Kruskal

### 📌 Đồ thị vô hướng có trọng số bên dưới


  (4)
```

A -------- B
| \     /  |
(2)| (3) /    |(6)
|  \  /     |
C -- D ---- E
(5)

```

Danh số đỉnh: A = 0, B = 1, C = 2, D = 3, E = 4

### 📎 Danh sách cạnh

| Cạnh | Trọng số |
|------|----------|
| A – C | 2 |
| A – D | 3 |
| A – B | 4 |
| C – D | 5 |
| D – E | 6 |

### 🔽 Bước 1 — Sắp xếp cạnh theo trọng số tăng dần

| Thứ tự | Cạnh | Trọng số |
|-------|------|----------|
| 1 | A – C | 2 |
| 2 | A – D | 3 |
| 3 | A – B | 4 |
| 4 | C – D | 5 |
| 5 | D – E | 6 |

---

### 🔄 Bước 2 — Xét từng cạnh và chọn nếu không tạo chu trình

Ban đầu **MST = ∅**, mỗi đỉnh là 1 tập riêng (Union–Find):

| Đỉnh | Tập |
|------|-----|
| A | {A} |
| B | {B} |
| C | {C} |
| D | {D} |
| E | {E} |

| Thứ tự xét | Cạnh | Chọn hay bỏ? | Lý do | MST sau bước |
|-----------|-------|--------------|-------|----------------|
| 1 | A – C | ✔ | không tạo chu trình | {A–C} |
| 2 | A – D | ✔ | không tạo chu trình | {A–C, A–D} |
| 3 | A – B | ✔ | không tạo chu trình | {A–C, A–D, A–B} |
| 4 | C – D | ❌ | tạo chu trình (A–C–D–A) | không đổi |
| 5 | D – E | ✔ | không tạo chu trình | {A–C, A–D, A–B, D–E} |

Đã chọn **4 cạnh = |V| − 1** → DỪNG (không cần xét tiếp)

---

## 🏁 Kết quả cuối cùng – Cây bao trùm nhỏ nhất (MST)

| Cạnh trong MST | Trọng số |
|----------------|----------|
| A – C | 2 |
| A – D | 3 |
| A – B | 4 |
| D – E | 6 |

📌 Tổng trọng số MST:
\[
2 + 3 + 4 + 6 = 15
\]

---

## 🧠 Ghi nhớ nhanh

| Đặc điểm | Prim | Kruskal |
|---------|-------|----------|
| Bắt đầu từ | Một đỉnh | Cạnh nhỏ nhất |
| Mở rộng | Nối thêm đỉnh gần nhất vào cây | Chọn cạnh rẻ nhất không tạo chu trình |
| Cấu trúc mạnh | Priority Queue | Union–Find |
| Hợp với đồ thị | Dày (nhiều cạnh) | Thưa (ít cạnh) |
| Độ phức tạp | `O(|E| log |V|)` | `O(|E| log |E|)` |

🔑 Mẹo nhớ:
> Prim xây MST **từ đỉnh ra ngoài**,  
> Kruskal xây MST **từ cạnh nhỏ nhất trở lên**.

---


# 🌳 Thuật toán Prim – Cây bao trùm nhỏ nhất (MST) + Ví dụ bằng tay

Thuật toán **Prim** là một trong những thuật toán đồ thị quan trọng nhất. Nó được dùng để xây dựng **Cây Bao Trùm Nhỏ Nhất (Minimum Spanning Tree – MST)** cho một **đồ thị vô hướng có trọng số**.

---

## I. 🎯 Khái niệm và Mục đích

- **Cây bao trùm (Spanning Tree):**  
  Là một tập con các cạnh của đồ thị vô hướng liên thông, chứa **tất cả các đỉnh** và **không tạo chu trình**.

- **Cây bao trùm nhỏ nhất (MST – Minimum Spanning Tree):**  
  Trong các cây bao trùm có thể có, **MST là cây có tổng trọng số các cạnh nhỏ nhất**.

---

## II. 🔍 Ý tưởng và Điều kiện áp dụng

- **Đồ thị áp dụng:**  
  Đồ thị **vô hướng – liên thông – có trọng số**.

- **Mục tiêu:**  
  Chọn **|V| − 1 cạnh** sao cho:
  - Nối được **tất cả các đỉnh**
  - **Không tạo chu trình**
  - **Tổng trọng số cạnh là nhỏ nhất**

- **Chiến lược:**  
  Prim là thuật toán **Tham ăn (Greedy)**:
  > luôn chọn cạnh rẻ nhất nối **tập các đỉnh đã được chọn** với **một đỉnh mới**.

---

## III. ⚙️ Cơ chế hoạt động (phiên bản ý tưởng)

1. Chọn **bất kỳ đỉnh nào** làm điểm bắt đầu.
2. Gọi:
   - `S`: tập các đỉnh đã được đưa vào MST
   - `key[v]`: trọng số **cạnh rẻ nhất** nối từ `S` đến `v`.
   - `P[v]`: lưu vết (đỉnh nối vào `v` bằng cạnh rẻ nhất)

3. Lặp lại cho đến khi mọi đỉnh vào `S`:
   1. Chọn đỉnh `u ∉ S` có **key[u] nhỏ nhất**
   2. Đưa `u` vào `S`
   3. Với mỗi đỉnh kề `v` của `u`:
      - Nếu cạnh `(u, v)` có trọng số nhỏ hơn `key[v]`
        → cập nhật `key[v]` và `P[v] = u`

⏱ Độ phức tạp với **priority queue (binary heap)**:
\[
O(|E| \log |V|)
\]

---

## IV. ✋ Ví dụ minh họa bằng tay Prim

Xét đồ thị vô hướng có trọng số:

```

```
 (2)
```

A ------ B
| \     / 
(3)|  \  /2  (7)
|   /      
C -- D --(1)- E
(4)

```

Nhập vai đánh số (A=0, B=1, C=2, D=3, E=4) để dễ trình bày.

### 📌 Ma trận cạnh (tóm lược)
| Cặp | Trọng số |
|-----|----------|
| A – B | 2 |
| A – C | 3 |
| A – D | 6 |
| B – D | 2 |
| B – E | 7 |
| C – D | 4 |
| D – E | 1 |

👉 Bắt đầu Prim tại đỉnh **A**

---

### 🔄 Bảng mô phỏng Prim theo từng bước

#### Khởi tạo
- `S = ∅`
- `key[A] = 0` (vì bắt đầu tại A)
- `key[đỉnh còn lại] = ∞`

| Đỉnh | key[v] | P[v] |
|-------|--------|-----|
| A | 0 | - |
| B | ∞ | - |
| C | ∞ | - |
| D | ∞ | - |
| E | ∞ | - |

---

### Bước 1 – Chọn A
`S = {A}`

Cập nhật đỉnh kề với A:
- A–B = 2 → key[B] = 2, P[B] = A
- A–C = 3 → key[C] = 3, P[C] = A
- A–D = 6 → key[D] = 6, P[D] = A

| Đỉnh | key[v] | P[v] |
|-------|--------|-----|
| A | 0 | - |
| B | 2 | A |
| C | 3 | A |
| D | 6 | A |
| E | ∞ | - |

---

### Bước 2 – Chọn đỉnh nhỏ nhất ngoài S → B
`S = {A, B}`

Thư giãn cạnh:
- B–D = 2 (nhỏ hơn key[D]=6)  
  → `key[D] = 2`, `P[D] = B`
- B–E = 7 → lớn hơn key[E] (∞) → cập nhật:
  → `key[E] = 7`, `P[E] = B`

| Đỉnh | key[v] | P[v] |
|-------|--------|-----|
| A | 0 | - |
| B | 2 | A |
| C | 3 | A |
| D | 2 | B |
| E | 7 | B |

---

### Bước 3 – Chọn đỉnh nhỏ nhất ngoài S → D
`S = {A, B, D}`

Thư giãn cạnh:
- D–E = 1 (< key[E]=7) → `key[E] = 1`, `P[E] = D`
- D–C không rẻ hơn key[C] (4 > 3 → bỏ qua)

| Đỉnh | key[v] | P[v] |
|-------|--------|-----|
| A | 0 | - |
| B | 2 | A |
| C | 3 | A |
| D | 2 | B |
| E | 1 | D |

---

### Bước 4 – Chọn đỉnh nhỏ nhất ngoài S → E
`S = {A, B, D, E}`

- B–E, D–E đều không giảm key cho đỉnh chưa xét
→ Không cập nhật gì

| Đỉnh | key[v] | P[v] |
|-------|--------|-----|
| A | 0 | - |
| B | 2 | A |
| C | 3 | A |
| D | 2 | B |
| E | 1 | D |

---

### Bước 5 – Đỉnh còn lại → C
`S = {A, B, C, D, E}` → thuật toán kết thúc

---

## 🎯 Kết quả cuối cùng – Các cạnh trong MST

| Cạnh chọn | Trọng số |
|----------|----------|
| A – B | 2 |
| B – D | 2 |
| D – E | 1 |
| A – C | 3 |

📌 Tổng trọng số MST:
\[
2 + 2 + 1 + 3 = 8
\]

---

## 🧠 Tóm tắt dễ nhớ

| Thuật toán | Bài toán | Chiến lược | Kết quả |
|-----------|----------|------------|---------|
| **Prim** | Cây bao trùm nhỏ nhất | Tham ăn – luôn chọn cạnh rẻ nhất nối vào cây | MST |
| **Dijkstra** | Đường đi ngắn nhất từ nguồn | Tham ăn – “chốt” đỉnh gần nhất tiếp theo | Shortest path tree |

🔑 Nhớ điểm khác biệt quan trọng:
- Dijkstra tối ưu hóa **đường đi ngắn nhất** → giá trị **tích lũy**
- Prim tối ưu hóa **cạnh rẻ nhất mỗi lần** → giá trị **theo cạnh**
Dưới đây là **phiên bản đầy đủ hơn**, có **ví dụ minh họa rõ ràng** cho cả 3 kiểu duyệt, vẫn nằm trong **1 khối HackMD**.

---

# 📝 Ba cách duyệt cây nhị phân + Ví dụ minh họa

Giả sử cây nhị phân sau:


```
    10
   /  \
  5    15
 / \     \
2   7     20
```


---

## 1. Pre-order (N-L-R)
**Thứ tự duyệt:**  
1. N — thăm nút hiện tại  
2. L — duyệt cây con trái  
3. R — duyệt cây con phải  

**Duyệt trên cây ví dụ:**  
- Bắt đầu tại 10  
- Sang trái: 5 → 2 → 7  
- Sang phải: 15 → 20  

**Kết quả Pre-order:**  
```

10 5 2 7 15 20

```

**Pseudocode:**
```

PreOrder(u):
if u == NULL: return
visit(u)
PreOrder(u.left)
PreOrder(u.right)

```

---

## 2. In-order (L-N-R)
**Thứ tự duyệt:**  
1. L — duyệt cây con trái  
2. N — thăm nút hiện tại  
3. R — duyệt cây con phải  

**Duyệt trên cây ví dụ:**  
- Duyệt trái: 2 → 5 → 7  
- Gốc: 10  
- Duyệt phải: 15 → 20  

**Kết quả In-order:**  
```

2 5 7 10 15 20

```
*(Đặc biệt: Với BST → đây là dãy đã được sắp xếp tăng dần.)*

**Pseudocode:**
```

InOrder(u):
if u == NULL: return
InOrder(u.left)
visit(u)
InOrder(u.right)

```

---

## 3. Post-order (L-R-N)
**Thứ tự duyệt:**  
1. L — duyệt cây con trái  
2. R — duyệt cây con phải  
3. N — thăm nút hiện tại  

**Duyệt trên cây ví dụ:**  
- Trái: 2 → 7 → 5  
- Phải: 20 → 15  
- Gốc: 10  

**Kết quả Post-order:**  
```

2 7 5 20 15 10

```

**Pseudocode:**
```

PostOrder(u):
if u == NULL: return
PostOrder(u.left)
PostOrder(u.right)
visit(u)

```

---
# 📌 Cheatsheet Độ Phức Tạp Thuật Toán (DSA)

## 1. Độ phức tạp truy cập cấu trúc dữ liệu

| Cấu trúc dữ liệu | Truy cập | Tìm kiếm | Chèn | Xoá |
|------------------|----------|----------|------|------|
| Array (tĩnh)     | O(1)     | O(n)     | O(n) | O(n) |
| Dynamic Array    | O(1)     | O(n)     | Amortized O(1) | O(n) |
| Linked List      | O(n)     | O(n)     | O(1) | O(1) |
| Skip List        | O(log n) | O(log n) | O(log n) | O(log n) |
| Hash Table       | -        | Avg O(1), Worst O(n) | Avg O(1) | Avg O(1) |
| Binary Search Tree | O(log n)* | O(log n)* | O(log n)* | O(log n)* |
| AVL / Red-Black   | O(log n) | O(log n) | O(log n) | O(log n) |
| Heap (Binary Heap) | O(1)     | O(n)     | O(log n) | O(log n) |

\* Với BST cân bằng. Nếu không, Worst-case = O(n).

---

## 2. Độ phức tạp các thuật toán sắp xếp

| Thuật toán | Best | Average | Worst | Ghi chú |
|-----------|------|---------|-------|---------|
| Selection Sort | O(n²) | O(n²) | O(n²) | Không ổn định |
| Bubble Sort | O(n) | O(n²) | O(n²) | Ổn định |
| Insertion Sort | O(n) | O(n²) | O(n²) | Ổn định, tốt khi gần sorted |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | Ổn định, cần O(n) memory |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | Không ổn định |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | Không ổn định |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | Ổn định |
| Radix Sort | O(d(n + k)) | O(d(n+k)) | O(d(n+k)) | Ổn định |
| Bucket Sort | O(n + k) | O(n + k) | O(n²) | Phụ thuộc dữ liệu |

---

## 3. Đồ thị – Graph Algorithms

| Thuật toán | Thời gian |
|-----------|-----------|
| BFS | O(V + E) |
| DFS | O(V + E) |
| Dijkstra (Min-Heap) | O((V + E) log V) |
| Bellman–Ford | O(VE) |
| Floyd–Warshall | O(V³) |
| Prim (Min-Heap) | O((V + E) log V) |
| Kruskal | O(E log V) |
| Topo Sort (Kahn/DFS) | O(V + E) |
| Kiểm tra 2 phía (Bipartite, BFS/DFS) | O(V + E) |

---

## 4. Cấu trúc cây nâng cao

| Cấu trúc | Tìm kiếm | Chèn | Xoá |
|----------|----------|------|------|
| Trie | O(m) | O(m) | O(m) |
| Segment Tree | O(log n) | O(log n) | O(log n) |
| Fenwick Tree (BIT) | O(log n) | O(log n) | - |
| Treap | O(log n) | O(log n) | O(log n) |

---

## 5. Độ phức tạp đệ quy thường gặp

| Công thức | Độ phức tạp |
|-----------|-------------|
| T(n) = T(n/2) + O(1) | O(log n) |
| T(n) = T(n/2) + O(n) | O(n) |
| T(n) = 2T(n/2) + O(1) | O(n) |
| T(n) = 2T(n/2) + O(n) | O(n log n) |
| T(n) = T(n-1) + O(1) | O(n) |
| T(n) = T(n-1) + O(n) | O(n²) |

---

## 6. Độ phức tạp khi dùng mảng + danh sách kề

| Biểu diễn | Duyệt cạnh | Tìm cạnh (u,v) |
|-----------|------------|----------------|
| Adjacency Matrix | O(V²) | O(1) |
| Adjacency List | O(V+E) | O(deg(u)) |


---

