/*
 * @CircularBuffer.h
 * @author Mwesigwa Thomas Guma 
 * @date 10/11/20
 * @copyright Mwesigwa Thomas Guma 
 * @brief a ring buffer class declaration
 *
 * Implement a ring buffer that acts like a queue in that
 * elements are pushed and popped from the buffer
 *
 */

#include <stdint.h>

#include <iostream>

#ifndef CIRCULARBUFFER_H // NOLINT
#define CIRCULARBUFFER_H

using namespace std; // NOLINT

class CircularBuffer {
 public:
    CircularBuffer();

    explicit CircularBuffer(int capacity);

    ~CircularBuffer() {
      delete[] buffer;
    }


    int size() const {
      return currSize;
    }

    bool isEmpty() const {
      return currSize == 0;
    }

    bool isFull() const {
      return currSize == maxCapacity;
    }

    void enqueue(int16_t x);

    int16_t dequeue();

    int16_t peek();
   
    int get_capacity(){
	return maxCapacity;	
    }
    	
    void empty();

 private:
    int maxCapacity;
    int16_t *buffer;
    int currSize;
    int begin;
};

#endif // CIRCULARBUFFER_H NOLINT
