For this project we focused on implementing data structures using bitwise operations in C++. It was divided into four phases, each progressively building on the previous one. The primary goal was to implement core data structures and algorithms while learning bitwise operations, pointers, and memory management. Below is a breakdown of the functionality and requirements for each phase.
Phase 1: BitArray Implementation
Objective: Implement the BitArray class to handle fixed-length bit vectors.
Functions:
BitArray(int size): Constructor to initialize a bit array of a given size.
~BitArray(): Destructor to free memory.
get(int index): Retrieve the bit at a given position.
flip(int index): Flip the bit at the specified position.
set(int index, int value): Set the bit at the specified index to either 1 or 0.

Phase 2: Set Class Implementation
Objective: Build the Set class using the BitArray from Phase 1.
Core Functions:
Implement all set operations (e.g., union, intersection) except setDifference.
Note: Reuse the bitwise manipulation functions from the BitArray class to handle entire sets instead of individual bits. The functions should be concise (no more than 10 lines each).
Testing: Use a driver program to verify the functionality of the set operations.

Phase 3: Dictionary Class (Rank and Select Range)
Objective: Implement the Dictionary class to handle rank and select operations using bit arrays.
Functions:
rank_range(i, j): Count the number of 1s in the bit array between indices i and j.
select_range(i, j): Select the jth 1-bit in the bit array starting at index i.
Note: Leverage the bit manipulation methods implemented in the BitArray class for these operations.
Testing: Verify the rank and select operations using test cases in the driver program.

Phase 4: Optimizing Rank and Select
Objective: Optimize the rank and select operations using a lookup table to reduce time complexity.
Task: Build a lookup table to pre-compute the number of 1s in each byte (8 bits) of the BitArray. This will allow for efficient querying of large bit arrays by jumping 8 bits at a time.
Functionality:
Implement the get8 function in BitArray to retrieve a byte (8 bits) at a time.
Use this function in rank and select to optimize their performance.

Submission:
Repository: 
Share a GitHub repository named cs341_p3_spring2022 containing:
All .h and .cpp source files.
A makefile to compile the project.

