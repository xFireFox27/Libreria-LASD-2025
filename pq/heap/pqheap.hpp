
#ifndef PQHEAP_HPP
#define PQHEAP_HPP

/* ************************************************************************** */

#include "../pq.hpp"
#include "../../heap/vec/heapvec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class PQHeap: virtual public PQ<Data>,
  protected HeapVec<Data> {
  // Must extend PQ<Data>,
  // Could extend HeapVec<Data>
  
  private:
  
  unsigned long capacity = 0;
  
  protected:
  
  using Container::size;
  using HeapVec<Data>::Elements;
  using HeapVec<Data>::Parent;
  using HeapVec<Data>::HeapifyDown;
  
  public:
  
  using HeapVec<Data>::Clear;

  // Default constructor
  PQHeap() = default;                                                       // PQHeap() specifiers;
  
  /* ************************************************************************ */
  
  // Specific constructors
  PQHeap(const TraversableContainer<Data>&);                                // PQHeap(argument) specifiers; // A priority queue obtained from a TraversableContainer
  PQHeap(MappableContainer<Data>&&);                                        // PQHeap(argument) specifiers; // A priority queue obtained from a MappableContainer
  
  /* ************************************************************************ */
  
  // Copy constructor
  PQHeap(const PQHeap<Data>&);                                              // PQHeap(argument) specifiers;
  
  // Move constructor
  PQHeap(PQHeap<Data>&&) noexcept;                                          // PQHeap(argument) specifiers;
  
  /* ************************************************************************ */
  
  // Destructor
  virtual ~PQHeap() = default;                                              // ~PQHeap() specifiers;
  
  /* ************************************************************************ */
  
  // Copy assignment
  PQHeap& operator=(const PQHeap<Data>&);                                   // type operator=(argument) specifiers;
  
  // Move assignment
  PQHeap& operator=(PQHeap<Data>&&) noexcept;                               // type operator=(argument) specifiers;
  
  /* ************************************************************************ */
  
  // Specific member functions (inherited from PQ)
  
  const Data& Tip() const override;                  // type Tip(argument) specifiers; // Override PQ member (must throw std::length_error when empty)
  void RemoveTip() override;                                                // type RemoveTip(argument) specifiers; // Override PQ member (must throw std::length_error when empty)
  Data TipNRemove() override;                                               // type TipNRemove(argument) specifiers; // Override PQ member (must throw std::length_error when empty)
  
  void Insert(const Data&) override;                                        // type Insert(argument) specifiers; // Override PQ member (Copy of the value)
  void Insert(Data&&) override;                                             // type Insert(argument) specifiers; // Override PQ member (Move of the value)
  
  void Change(unsigned long, const Data&) override;                         // type Change(argument) specifiers; // Override PQ member (Copy of the value)
  void Change(unsigned long, Data&&) override;                              // type Change(argument) specifiers; // Override PQ member (Move of the value)
  
  protected:
  
  // Auxiliary functions, if necessary!
  void Expand();
  void Reduce();
  void Resize(const unsigned long newSize) override;
  void HeapifyUp(unsigned long);
  
  
};

/* ************************************************************************** */

}

#include "pqheap.cpp"

#endif
