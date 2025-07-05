<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/en/thumb/7/74/Universiti_Teknologi_MARA_logo.svg/250px-Universiti_Teknologi_MARA_logo.svg.png" alt="UiTM Logo" width="200"/>
</p>

# Parallel Processing Lab Group Assignment (CSC580)

- `main-multithread.cpp` for parallel processing
- `main-serial.cpp` for serial processing

Task 1: Given the following mathematical expression:
A + B / C _ (D + E ^ 2) + Y _ Z

1. Produce a serial program to evaluate the above mathematical expression.
2. Produce an executable multithreading program that will enable the above
   mathematical expression to be executed using parallel processing. The main thread
   will display the overall result calculated by all threads. The program should prompt
   the user to enter the input for the values in the expression.
3. Measure and analyze the execution time for the program.

<hr>

- `sequential-sorting.cpp` for sequential sorting
- `parallel-sorting.cpp` for parallel sorting

Task 2: Discuss the implementation of a parallel sort algorithm. Demonstrate the speedup
of the selected parallel implementation (set a minimum array values). MPI or threads
approach can be used to perform the task.

Task Description (Simple Words):

- Select a sorting algorithm (e.g., Merge Sort, Quick Sort, or Bubble Sort).
- Implement it in parallel using either:
  MPI (Message Passing Interface) – used for multi-computer or multi-core
  processing, OR
- Threads (like POSIX threads or OpenMP) – used for running tasks in parallel within
  one computer.
- Sort an array that has a minimum number of values (you can decide the size, for
  example, 1,000 or 10,000).
- Compare the speed of your parallel sorting algorithm with the serial version.

[Report Docs Link](https://docs.google.com/document/d/1-VLWMDbIG8eIbUSXiviKWyEcl11v2f_TMUqTBUAHjUM/edit?usp=sharing)
