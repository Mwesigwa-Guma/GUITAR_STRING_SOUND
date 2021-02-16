// @copyright: Mwesigwa Thomas Guma 2020

#include <iostream>
#include <stdexcept>

#include "CircularBuffer.h"

using namespace std; // NOLINT

// create an empty buffer array of size 1
CircularBuffer::CircularBuffer() {
  maxCapacity = 1;
  buffer = new int16_t[maxCapacity];
  currSize = 0;
  begin = 0;
}

// create buffer of size given as a parameter
CircularBuffer::CircularBuffer(int capacity) {
  // throws an invalid argument if the capacity is less than 1
  if (capacity < 1) {
    throw invalid_argument
    ("CircularBuffer constructor: capacity must be greater than zero.\n");
  }

  maxCapacity = capacity;
  buffer = new int16_t[maxCapacity];
  currSize = 0;
  begin = 0;
}

void CircularBuffer::enqueue(int16_t x) {
  // runtime_error thrown if the buffer is full
  if (currSize == maxCapacity) {
    throw runtime_error("Enqueue: can't enqueue to full ring.");
  } else {
    int end = (currSize + begin) % maxCapacity;
    // push the parameter into the queue
    buffer[end] = x;
    currSize++;
  }
}

int16_t CircularBuffer::dequeue() {
  int16_t temp;

  if (isEmpty()) {
    // throw a runtime_error if buffer is empty
    throw runtime_error("Error: Can't remove from empty buffer");
  } else {
    if (begin == (maxCapacity - 1)) {
      temp = buffer[begin];
      begin = 0;
    } else {
      // store the value of the first element to a temp
      // delete the item in front from the array and return it
      temp = buffer[begin];
      begin++;
    }
    currSize--;
  }

  return temp;
}

int16_t CircularBuffer::peek() {
  // throw a runtime_error is array is empty
  if (isEmpty()) {
    throw runtime_error("Error: Can't remove from empty buffer");
  }
  // return the first item of the array
  return buffer[begin];
}

void CircularBuffer::empty(){
	this->begin = 0;
	this->currSize = 0;
}
