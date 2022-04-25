Banker's Algorithm Sequence Calculator

What is the banker's algorithm?
- The banker's algorithm is used to avoid deadlocks and allocated resources for different programs. This algorithm allows us to test the saftey of allocating resources by using a set of tests to test all possible activitys becfore actually allocating resources to processes

How does the code work?
- The program will take inputs from the input.csv file that we formatted in a specific way so that no errors occure. The data taken from the file will be read into 3 different vectors. The program will iterate through the different processes and determine weather or not there is spot in the sequence that the process will finish and if so its needed resources will be met. This will continue to run until all processes are marked as finished. If the sequence cannot finish the program will inform you that the process is unsafe.

How to fomat the csv file:
- Each row of the matrix must be delimited by a newline character
- Each cell of the matrix must be delimited by a space character
- Columns must be delimited by a ','
- The file must be named input.csv

Example of csv file?
- Allocated Resource matrix
  - 0 1 0
  - 2 0 0
  - 3 0 2
  - 2 1 1
  - 0 0 2
- Max Resource Matrix
  - 7 5 3
  - 3 2 2
  - 9 0 2
  - 2 2 2
  - 4 3 3
- Availble Resource list
  - 3 3 2
- Input.csv File must be formated as
  - $ 0 1 0, 7 5 3, 3 3 2
  - $ 2 0 0, 3 2 2,
  - $ 3 0 2, 9 0 2,
  - $ 2 1 1, 2 2 2,
  - $ 0 0 2, 4 3 3,

How to Run this program:
1. Download the source code into a directory
2. Create or add input.csv file into the directory you created
3. open terminal in directory
4. compile program using
   - $ g++ bankers.cpp -o bankers
5. Then run program using
   - $ ./bankers

Example Output using the Input.csv file above:
-Terminal
  - $ g++ bankers.cpp -o bankers
  - $ ./bankers
  - $
  - $ Allocated Resource Table
  - $ 0 1 0
  - $ 2 0 0
  - $ 3 0 2
  - $ 2 1 1
  - $ 0 0 2
  - $
  - $ Maxinum Resource Table
  - $ 7 5 3
  - $ 3 2 2
  - $ 9 0 2
  - $ 2 2 2
  - $ 4 3 3
  - $
  - $ List of Avilable Resources
  - $ 3 2 2
  - $
  - $ List of Needed Resources
  - $ 7 4 3
  - $ 1 2 2
  - $ 6 0 0
  - $ 0 1 1
  - $ 4 3 1
  - $
  - $ The Safe Sequence Is:
  - $ P1 to P3 to P4 to P0 to P2
