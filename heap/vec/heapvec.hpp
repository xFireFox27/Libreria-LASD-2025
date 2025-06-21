
#ifndef HEAPVEC_HPP
#define HEAPVEC_HPP

/* ************************************************************************** */

#include "../heap.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data> 
class HeapVec: virtual public Heap<Data>, 
  protected SortableVector<Data>  {
  // Must extend Heap<Data>,
  // Could extend SortableVector<Data> 

private:

  // ...

  protected:
  
  using Container::size;
  using SortableVector<Data>::Elements;
  
  public:
  
  using SortableVector<Data>::Front;
  using SortableVector<Data>::Back;
  using SortableVector<Data>::operator[];
  using SortableVector<Data>::Clear;
  
  // Default constructor
  HeapVec() = default;                                                        // HeapVec() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  HeapVec(const TraversableContainer<Data>&);                                 // HeapVec(argument) specifiers; // A heap obtained from a TraversableContainer
  HeapVec(MappableContainer<Data>&&);                                         // HeapVec(argument) specifiers; // A heap obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HeapVec(const HeapVec<Data>&);                                              // HeapVec(argument) specifiers;

  // Move constructor
  HeapVec(HeapVec<Data>&&) noexcept;                                          // HeapVec(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  virtual ~HeapVec() = default;                                               // ~HeapVec() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  HeapVec& operator=(const HeapVec<Data>&);                                   // type operator=(argument) specifiers;

  // Move assignment
  HeapVec& operator=(HeapVec<Data>&&) noexcept;                               // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HeapVec<Data>&) const noexcept;                       // type operator==(argument) specifiers;
  bool operator!=(const HeapVec<Data>&) const noexcept;                       // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Heap)

  bool IsHeap() const override;                                               // type IsHeap(argument) specifiers; // Override Heap member

  void Heapify() override;                                                    // type Heapify(argument) specifiers; // Override Heap member


  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  void Sort() noexcept override;                                                       // type Sort(argument) specifiers; // Override SortableLinearContainer member

protected:

  // Auxiliary functions, if necessary!
  inline unsigned long Parent(unsigned long) const;
  inline unsigned long LeftChild(unsigned long) const;
  inline unsigned long RightChild(unsigned long) const;
  void HeapifyDown(unsigned long, unsigned long);
  void HeapSort();
  
};

/* ************************************************************************** */

}

#include "heapvec.cpp"

#endif
