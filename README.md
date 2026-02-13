# 🧠 Push_Swap

![Language](https://img.shields.io/badge/language-C-blue.svg)
![Build](https://img.shields.io/badge/build-Makefile-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

## Description

`Push_Swap` is a challenging algorithm project from the 42 school curriculum. The goal is to sort a list of integers using two stacks, `A` and `B`, and a limited set of operations. The challenge lies in finding the most efficient sequence of operations to sort the numbers in stack `A` (with `B` initially empty), while minimizing the total number of operations performed. This project demonstrates strong algorithmic thinking, data structure manipulation, and problem-solving skills in C.

## ✨ Features

*   **Two-Stack Sorting:** Efficiently sorts a list of integers using only two stacks.
*   **Comprehensive Operation Set:** Implements all allowed Push_Swap operations:
    *   `sa`: swap a (swap the first two elements of stack A).
    *   `sb`: swap b (swap the first two elements of stack B).
    *   `ss`: sa and sb at the same time.
    *   `pa`: push a (take the top element from B and push it to A).
    *   `pb`: push b (take the top element from A and push it to B).
    *   `ra`: rotate a (shift all elements of stack A up by one).
    *   `rb`: rotate b (shift all elements of stack B up by one).
    *   `rr`: ra and rb at the same time.
    *   `rra`: reverse rotate a (shift all elements of stack A down by one).
    *   `rrb`: reverse rotate b (shift all elements of stack B down by one).
    *   `rrr`: rra and rrb at the same time.
*   **Optimized Sorting Algorithms:** Employs different sorting strategies based on the size of the input list for optimal performance:
    *   Specialized sorts for small number of elements (e.g., 2, 3 elements).
    *   Selection Sort for medium-sized lists.
    *   Radix Sort for larger lists, using an indexing approach for efficiency.
*   **Robust Error Handling:** Validates input to ensure it consists only of integers, handles duplicate numbers, and checks for integer overflow/underflow.
*   **Custom Utility Library (Libft):** Utilizes a dedicated `libft` for various standard C library functions re-implemented, along with additional helper functions.

## 📚 Tech Stack

*   **Language:** C
*   **Build System:** Make
*   **Libraries:** `libft` (custom C library)

## 🚀 Installation

To get a local copy up and running, follow these simple steps.

1.  **Clone the repository:**

    ```bash
    git clone git@github.com:bsen0/push_swap.git
    cd push_swap/push_swap
    ```

2.  **Compile the project:**
    The project uses a Makefile to compile both `push_swap` and its dependency `libft`.

    ```bash
    make
    ```

    This will create an executable file named `push_swap` in the `push_swap/push_swap` directory.

## ▶️ Usage

The `push_swap` program takes a list of integers as arguments. It then outputs the sequence of operations required to sort these numbers.

**Basic Usage:**

```bash
./push_swap "2 1 3 6 5 8"
```

**Example Output:**

For input `2 1 3`:
```
sa
```

For input `3 1 2`:
```
ra
sa
```

For larger inputs, the output will be a longer sequence of operations:

```bash
./push_swap "4 67 3 87 2 -1 0 54 23"
# Example output (actual output may vary based on optimization):
# pb
# pb
# ra
# pb
# ra
# ... (many more operations)
# pa
# pa
# pa
```

**Error Handling:**
The program will print "Error\n" to standard error and exit if the input is invalid (e.g., non-numeric arguments, duplicate numbers, numbers outside integer limits).

```bash
./push_swap "1 2 a 3"
# Output: Error

./push_swap "1 2 2 3"
# Output: Error

./push_swap "2147483648"
# Output: Error
```

## 🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## 📝 License

Distributed under the MIT License. See the project repository for details if a `LICENSE` file is added.