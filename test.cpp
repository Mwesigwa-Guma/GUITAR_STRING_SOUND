/// @copyright Mweisgwa Thomas Guma 2020

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE cbTest

#include <stdexcept>
#include <iostream>

#include <boost/test/unit_test.hpp>
#include "CircularBuffer.h" // NOLINT

BOOST_AUTO_TEST_CASE(cbTest_constructor) {
  // testing bad constructor
  BOOST_REQUIRE_THROW(CircularBuffer cb1(-1), invalid_argument);
  // testing good constructor
  BOOST_REQUIRE_NO_THROW(CircularBuffer cb22(4));
}

BOOST_AUTO_TEST_CASE(cbTest_enqueue) {
  // testing enqueue
  CircularBuffer cb3(5);
  cb3.enqueue(1);
  cb3.enqueue(2);
  cb3.enqueue(3);
  cb3.enqueue(4);
  cb3.enqueue(5);
  BOOST_REQUIRE_THROW(cb3.enqueue(6), runtime_error);

  // testing if no throw's occur when the ring is full
  BOOST_REQUIRE_NO_THROW(cb3.isFull());
}

BOOST_AUTO_TEST_CASE(cbTest_dequeue) {
  // testing dequeue
  CircularBuffer cb4(3);
  cb4.enqueue(1);
  cb4.enqueue(2);
  cb4.enqueue(3);
  cb4.dequeue();
  cb4.dequeue();
  cb4.dequeue();
  BOOST_REQUIRE_THROW(cb4.dequeue(), runtime_error);

  // testing if no throw's occur when ring is empty
  BOOST_REQUIRE_NO_THROW(cb4.isEmpty());
}

BOOST_AUTO_TEST_CASE(cbTest_peek) {
  // testing peek
  CircularBuffer cb5(2);
  BOOST_REQUIRE_THROW(cb5.peek(), runtime_error);

  // testing if no throw's occur when ring is empty
  BOOST_REQUIRE_NO_THROW(cb5.isEmpty());
}
