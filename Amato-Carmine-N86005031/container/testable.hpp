
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer: virtual public Container {
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~TestableContainer() = default;                                       // ~TestableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer& operator=(const TestableContainer&) = delete;                        // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  TestableContainer& operator=(TestableContainer&&) noexcept = delete;                    // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TestableContainer&) const noexcept = delete;                      // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const TestableContainer&) const noexcept = delete;                      // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  virtual bool Exists(const Data&) const noexcept = 0;                                    // type Exists(argument) specifiers; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

}

#endif
