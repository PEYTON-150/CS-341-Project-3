// Author(s):
// File: set.h
// Dependencies: bitarray.h
// Compiler: g++
// Contents: A set class that supports union, intersection, and relative complement.

// The Set class will represent the mathematical concept of a set, where the universe of items corresponds
// to a BitArray within the class. If the bitarray position 23 is 1, then the number 23 is a member of the set
// If the bit position is 0, the number 23 is not a member of the set.

// The cardinality of a Set (the class) is how many elements are there. In this representation, the cardinality
// translates to the number of 1s in the underlying BitArray

#ifndef SET_H
#define SET_H

#include "bitarray.h"

class Set {

    protected:
       BitArray data;
       int LENGTH;                              // length of bit array in terms of bits
       int BYTES;  
    public:
       // Class maintenance details
       Set(int = 0);                            // constructor that builds a BitArray of the indicated size (0 is default)
       void initialize(char *);                 // given a character array, set the data appropriately to match the input character array

       ~Set();                                  // default destructor

       // get/set functions
       // We will talk about this more later, but the const at the end means you can't change the Set data type inside this function
       inline int cardinality() const;          // returns the cardinality of the set
       BitArray & getData();                    // returns the data bitArray

       // Core functionality
       // For all of these functions, if the function call looks like A.setUnion(B),
       // your code will be performing the operation A = A U B.
       // You might have to look up your set functions from Discrete to remember what these operations do!
       bool setUnion(Set &);                     // computes the union with the input set and stores it here. Returns false if it fails, otherwise true.
       bool setIntersection(Set &);             // computes the intersection with the input set and stores it here. Returns false if it fails, otherwise true.
       bool setDifference(Set &);               // computes the relative difference between this set and the input set and stores it here. Returns false if it fails, otherwise true.

}; // end class Set

#endif
