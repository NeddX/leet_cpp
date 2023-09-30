#include "stdc++.h"

using size = std::size_t;
using u8 = std::uint8_t;
using i8 = std::int8_t;
using u16 = std::uint16_t;
using i16 = std::int16_t;
using u32 = std::uint32_t;
using i32 = std::int32_t;
using u64 = std::uint64_t;
using i64 = std::int64_t;
using uintptr = std::uintptr_t;
using intptr = std::intptr_t;
using char16 = char16_t;
using char32 = char32_t;

template<typename T>
auto arr_print(const T& arr, const size count) -> void {
    for (size i = 0; i < count; ++i) {
        if (count - 1 != i)
            std::cout << arr[i] << ", ";
        else
            std::cout << arr[i];
    }
    std::cout << std::endl;
};

template<typename T>
auto arr_sum(const T& arr, const size count) -> void {
    int sum = 0;
    for (size i = 0; i < count; ++i)
        sum += arr[i];
    std::cout << "Array sum is: " << sum << std::endl;
}

template<typename T>
auto arr_sum_average(const T& arr, const size count) -> void {
    int sum = 0;
    for (size i = 0; i < count; ++i)
        sum += arr[i];
    sum /= count;
    std::cout << "Average of array sum is: " << sum << std::endl;
}

template<typename T>
auto arr_max(const T& arr, const size count) -> void {
    int max = arr[0];
    for (size i = 1; i < count; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    std::cout << "Max is: " << max << std::endl;
}

template<typename T>
auto arr_min(const T& arr, const size count) -> void {
    int min = arr[0];
    for (size i = 1; i < count; ++i) {
        if (arr[i] < min)
            min = arr[i];
    }
    std::cout << "Min is: " << min << std::endl;
}

template<typename T>
auto arr_search(const T& arr, const T num, const size count) -> void {
    for (size i = 0; i < count; ++i) {
        if (arr[i] == num)
            std::cout << "Found num at index: " << i << std::endl;
    }
    std::cout << "Not found.\n";
}

template<typename T>
auto arr_bubble_sort(T& arr, const size count) -> void {
    for (size i = 0; i < count; ++i) {
        for (size j = i + 1; j < count; ++j) {
            if (arr[i] > arr[j])
                std::swap(arr[i], arr[j]);
        }
    }
    arr_print(arr, count);
}

template<typename T>
auto arr_reverse(T& arr, const size count) -> void {
    for (size i = 0; i < count; ++i) {
        std::swap(arr[i], arr[count - i - 1]);
    }
    arr_print(arr, count);
}

template<typename T>
auto arr_dupl(const T& arr, const size count) -> void {
    for (size i = 0; i < count; ++i) {
        for (size j = i + 1; j < count; ++j) {
            if (arr[i] == arr[j]) {
                std::cout << "Duplicates exist!\n";
            }
        }
    }
    std::cout << "Duplicates do not exist!\n";
}

template<typename T>
auto arr_find_prime(const T& arr, const size count) -> void {
    size is_prime = [](int num) -> bool {
        if (num == 0 || num == 1)
            return false;

        for (size i = 2; i < num/2; ++i) {
            if (!(num % i)) {
                return false;
            }
        }
        return true;
    };

    for (size i = 0; i < count; ++i) {
        if (is_prime(arr[i]))
            std::cout << arr[i] << std::endl;
    }
}

template<typename T, typename U>
auto arr_merge(const T& arr1, const size count1, const U& arr2, const size count2) -> void {
    const std::size_t merge_size = count1 + count2;
    auto merge = std::make_unique<int[]>(merge_size);

    for (size i = 0; i < count1; ++i)
        merge[i] = arr1[i];
    for (size i = count1 - 1; i < merge_size; ++i)
        merge[i] = arr2[count2 - i - 1];

    arr_print(merge.get(), merge_size);
}

template<typename T>
auto arr_print_odd_even(const T& arr, const size count) -> void {
    auto [x, y] = std::pair<std::size_t, std::size_t> { 0, 0 };
    auto odd_arr = std::make_unique<int[]>(count);
    auto even_arr = std::make_unique<int[]>(count);

    auto arr_resize = [](std::unique_ptr<int[]> arr, const std::size_t old_len, const std::size_t new_len) -> std::unique_ptr<int[]> {
    auto new_ptr = std::make_unique<int[]>(new_len);
        std::memcpy(new_ptr.get(), arr.get(), old_len);
        return std::move(new_ptr);
    };

    for (size i = 0; i < count; ++i) {
        if (!(arr[i] % 2))
            even_arr[x++] = arr[i];
        else
            odd_arr[y++] = arr[i];
    }

    even_arr = std::move(arr_resize(std::move(even_arr), count, x + 1));
    odd_arr = std::move(arr_resize(std::move(odd_arr), count, y + 1));

    arr_print(even_arr.get(), x + 1);
    arr_print(odd_arr.get(), y + 1);
}

template<typename T, const size count>
auto arr_prev_max(const T& arr) -> void {
    T max = arr[0];
    T prev = 0;
    for (size i = 1; i < count; ++i) {
        if (arr[i] > max) {
            prev = max;
            max = arr[i];
        }
    }
    std::cout << "Previous max is: " << prev << std::endl;
}

template<typename T, size rows, size cols>
auto smat_print(const T (&mat)[rows][cols]) -> void {
    for (size i = 0; i < rows; ++i) {
        std::cout << "[" << i << "]: ";
		arr_print(mat[i], cols);
    }
}

template<typename T, size n, size m>
auto smat_add(T (&mat1)[n][m], const T (&mat2)[n][m]) -> void {
    for (size i = 0; i < n; ++i) {
        for (size j = 0; j < m; ++j) {
            mat1[i][j] += mat2[i][j];
        }
    }
}

template<typename T, size n, size m>
auto smat_sort(T (&mat)[n][m]) -> void {
    for (size i = 0; i < n; ++i) {
        arr_bubble_sort(mat[i]);
    }
}

template<typename T, size rows, size cols>
auto smat_sub(T (&mat1)[rows][cols], const T (&mat2)[rows][cols]) -> void {
    for (size i = 0; i < rows; ++i) {
        for (size j = 0; j < cols; ++j) {
            mat1[i][j] -= mat2[i][j];
        }
    }
}

template<typename T, size n, size m, size p>
auto smat_mul(const T (&mat1)[n][m], const T (&mat2)[m][p], T (&res)[n][p]) -> void {
    std::memset(res, 0, n * p * sizeof(T));
    for (size i = 0; i < n; ++i) {
        for (size j = 0; j < p; ++j) {
            for (size k = 0; k < p; ++k) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

template<typename T, size n>
auto smat_transpose(T (&mat)[n][n]) -> void {
    T cpy[n][n];
    std::memcpy(cpy, mat, n * n * sizeof(T));
    for (size i = 0; i < n; ++i) {
        for (size j = 0; j < n; ++j) {
            mat[j][i] = cpy[i][j];
        }
    }
}

template<typename T, size n>
auto smat_rot_ninety(T (&mat)[n][n]) -> void {
    T cpy[n][n];
    std::memcpy(cpy, mat, n * n * sizeof(T));
    for (size i = 0; i < n; ++i) {
        for (size j = 0; j < n; ++j) {
            mat[j][n - i - 1] = cpy[i][j];
        }
    }
}

template<typename T>
auto smat_det(const T (&mat)[2][2]) -> T {
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

template<typename T, size n>
auto smat_is_ident(const T (&mat)[n][n]) -> void {
    for (size i = 0; i < n; ++i) {
        if (mat[i][i] != 1) {
            std::cout << "Matrix is not an identity matrix." << std::endl;
            return;
        }
    }
    std::cout << "Matrix is an identity matrix." << std::endl;
}

template<typename T, size n, size m>
auto smat_find_val(const T (&mat)[n][m], const T val) -> void {
    for (size i = 0; i < val; ++i) {
        if (*((T*)mat + i) == val) {
            std::cout << "Value found at: (" << i % m << ", " << i / m << ")." << std::endl;
            return;
        }
    }
    std::cout << "Value not found." << std::endl;
}

template<typename T, size n, size m>
auto smat_scale(T (&mat)[n][m], const T scaler) -> void {
    for (size i = 0; i < n * m; ++i) {
        *((T*)mat + i) = *((T*)mat + i) * scaler;
    }
}

template<typename T>
auto smat_inverse(T (&mat)[2][2]) -> void {
    T det = smat_det(mat);
    if (det) {
        det = 1 / det;
        smat_scale(mat, det);
    } else {
        std::cout << "Matrix cannot be inverted (determinant divisor is zero)." << std::endl;
    }
}

auto arr_remove_at(i32*& arr, const size index, size& n) -> void {
    i32* new_arr = new i32[n];
    for (size i = 0, j = 0; i < n; ++i) {
        if (i != index) {
            new_arr[j++] = arr[i];
        } else {
            --n;
        }
    }
    delete[] arr;
    arr = new_arr;
}

auto mat_find_max(const i32* const * const mat, const size n, const size m) -> void {
    i32* arr = new i32[n];
    size index = 0;
    for (size i = 0; i < n; ++i) {
        i32 max = mat[i][0];
        for (size j = 1; j < m; ++j) {
            max = (mat[i][j] > max) ? mat[i][j] : max;
        }
        arr[index++] = max;
    }
    std::cout << "Array: ";
    arr_print(arr, n);
    delete[] arr;
}

auto mat_remove_evens(i32** mat, const size n, size& m) -> void {
    for (size i = 0; i < n; ++i) {
        for (size j = 0; j < m; ++j) {
            if (!(mat[i][j] & 1)) {
                //arr_remove_at(mat[i], j, m);
                mat[i][j] = 0;
            }
        }
    }
}

auto mat_sum_diag_half(const i32* const * const mat, const size n, const size m) -> void {
    i32 sum = 0;
    for (size i = 0; i < n; ++i) {
        for (size j = i; j < m; ++j)
            sum += mat[i][j];
    }
    std::cout << "Sum: " << sum << std::endl;
}

auto mat_seg_sum(const i32* const * const mat, const u8 seg, const size n, const size m) -> void {
    //    0, 1, 2, 3, 4, 5
    // 0: 1, 3, 5, 7, 5, 3
    // 1: 2, 5, 1, 8, 7, 1
    // 2: 4, 5, 1, 1, 8, 6
    // 3: 4, 1, 5, 8, 2, 8
    // 4: 5, 1, 6, 3, 1, 5
    // 5: 2, 5, 3, 1, 5, 7
    i32 sum = 0;
    switch (seg) {
        case 0:
            /*for (size i = 1; i < n - j; ++i) {
                std::cout << "y: " << i << "x: 0\n";
            }*/
            break;
        case 1:
            for (size i = 0; i < n / 2; ++i) {
                for (size j = i + 1; j < m - i - 1; ++j)
                    sum += mat[i][j];
            }
            break;
        case 2:
            break;
        case 3:
            for (size i = n - 1; i > n / 2; --i) {
                for (size j = n - i; j < m - (n - i); ++j)
                    sum += mat[i][j];
            }
            break;
    }
    std::cout << "Sum: " << sum << std::endl;
}

auto main() -> int {
    int mat1[2][2] = {{2, 4}, {6, 1}};
    int mat2[2][2] = {{2, 1}, {6, 8}};
    int res[2][2];
    int smat_ident[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    smat_print(mat1);
    std::cout << std::endl;
    smat_print(mat2);
    std::cout << std::endl;
    //smat_add(mat1, mat2, res);
    //smat_rot_ninety(mat1);
    //smat_find_val(mat2, 999);
    //smat_is_ident(mat_ident);
    //smat_inverse(mat2);
    smat_mul(mat1, mat2, res);


    smat_print(res);
    return 0;
}
