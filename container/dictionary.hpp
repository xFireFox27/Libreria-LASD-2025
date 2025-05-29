
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer: virtual public TestableContainer<Data> {
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~DictionaryContainer() = default;                                                 // ~DictionaryContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer& operator=(const DictionaryContainer&) = delete;                          // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  DictionaryContainer& operator=(DictionaryContainer&&) noexcept = delete;                      // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const DictionaryContainer&) const noexcept = delete;                            // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const DictionaryContainer&) const noexcept = delete;                            // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Insert(const Data&) = 0;                                                              // type Insert(argument) specifiers; // Copy of the value
  virtual bool Insert(Data&&) = 0;                                                                  // type Insert(argument) specifiers; // Move of the value
  virtual bool Remove(const Data&) = 0;                                                              // type Remove(argument) specifiers;

  inline virtual bool InsertAll(const TraversableContainer<Data>&);                                   // type InsertAll(argument) specifiers; // Copy of the value; From TraversableContainer; True if all are inserted
  inline virtual bool InsertAll(MappableContainer<Data>&&);                                        // type InsertAll(argument) specifiers; // Move of the value; From MappableContainer; True if all are inserted
  inline virtual bool RemoveAll(const TraversableContainer<Data>&);                                   // type RemoveAll(argument) specifiers; // From TraversableContainer; True if all are removed

  inline virtual bool InsertSome(const TraversableContainer<Data>&);                                  // type InsertSome(argument) specifiers; // Copy of the value; From TraversableContainer; True if some is inserted
  inline virtual bool InsertSome(MappableContainer<Data>&&);                                          // type InsertSome(argument) specifiers; // Move of the value; From MappableContainer; True if some is inserted
  inline virtual bool RemoveSome(const TraversableContainer<Data>&);                                  // type RemoveSome(argument) specifiers; // From TraversableContainer; True if some is removed

};

/* ************************************************************************** */

template <typename Data>
class OrderedDictionaryContainer: virtual public DictionaryContainer<Data> {
  // Must extend DictionaryContainer<Data>

private:

protected:

public:

  // Destructor
  virtual ~OrderedDictionaryContainer() = default;                                                    // ~OrderedDictionaryContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  OrderedDictionaryContainer& operator=(const OrderedDictionaryContainer&) = delete;                  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  OrderedDictionaryContainer& operator=(OrderedDictionaryContainer&&) noexcept = delete;              // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const OrderedDictionaryContainer&) const noexcept = delete;                         // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const OrderedDictionaryContainer&) const noexcept = delete;                         // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& Min() const = 0;                                                                      // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual Data MinNRemove() = 0;                                                                     // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual void RemoveMin() = 0;                                                                       // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)

  virtual const Data& Max() const = 0;                                                                      // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual Data MaxNRemove() = 0;                                                                     // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual void RemoveMax() = 0;                                                                       // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)

  virtual const Data& Predecessor(const Data&) const = 0;                                                   // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual Data PredecessorNRemove(const Data&) = 0;                                                  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual void RemovePredecessor(const Data&) = 0;                                                    // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)

  virtual const Data& Successor(const Data&) const = 0;                                                   // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual Data SuccessorNRemove(const Data&) = 0;                                              // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual void RemoveSuccessor(const Data&) = 0;                                                // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
