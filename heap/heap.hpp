
#ifndef HEAP_HPP
#define HEAP_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Heap: virtual public SortableLinearContainer<Data>,
  virtual public ClearableContainer {
  // Must extend SortableLinearContainer<Data>,
  //             ClearableContainer

private:

protected:

public:

  // Destructor
  virtual ~Heap() = default;                                                  // ~Heap() specifiers

  /* ************************************************************************ */

  // Copy assignment
  Heap& operator=(const Heap&) = delete;                                    // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  Heap& operator=(Heap&&) noexcept = delete;                                // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool IsHeap() const = 0;                                                  // type IsHeap(argument) specifiers;

  virtual void Heapify() = 0;                                                       // type Heapify(argument) specifiers;

};

/* ************************************************************************** */

}

#endif
