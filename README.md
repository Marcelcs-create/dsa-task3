# CCS 2214 – Data Structures and Algorithms: Task 3 (Programs)

C solutions to the programming questions in Task 3.

| File | Question |
|------|----------|
| `q1_circular_queue.c` | Q1 – Circular queue implementation |
| `q4_recursion.c` | Q4 – Recursive sum of N naturals, factorial, Nth Fibonacci term, first N Fibonacci terms |
| `q5_queue.c` | Q5 – Enqueue / dequeue on a queue (menu driven) |
| `q6_sparse_matrix.c` | Q6 – Sparse matrix in triplet form, plus transpose |
| `q7_deque.c` | Q7 – Double-ended queue: front/rear insertion and deletion |

## Build and run
```
make            # builds all programs
./q1_circular_queue
make clean
```
Or compile one file: `gcc -std=c99 -Wall -o q4 q4_recursion.c && ./q4`
