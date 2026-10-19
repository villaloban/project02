# Project 02 - Topological Sorting
# Group Members:
Anthony Villalobos, Ryan Broge

# How to Run the Program:
The command use to compile the project is: g++ -std=c++17 src/main.cpp src/io.cpp src/dag.cpp src/topo.cpp src/optimize.cpp -o project02

Once its compiled you can then type the command: ./project02

You will then be prompted to enter a data file to read, since my data files are in a subdirectory known as data the user will have to type data/data1.txt to be recognized. However if the test files were in the src folder you would just need to type data1.txt.

Once running the program with a data file it will produce an output file in the output folder where you will see the clients in the file, the optimal revenue, and the clients contributing. 

# Extra Credit:
### Adjacency List
Per the extra credit we decided to implement the dag in the adjacency list format rather then opting for the matrix format. The adjacency list is not only easier to read, but also has a better time complexity.
### BFS Queue
Although a DFS approach would have been easier, we went with the extra credit route and implemented the BFS queue approach aka Khan's algorithm.
