
#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetVec: virtual public Set<Data>,
  virtual public ResizableContainer {
  // Must extend Set<Data>,
  //             ResizableContainer

private:

  // ...

protected:

  using Container::size;

  Vector<Data> Elements;
  unsigned long head = 0;
  unsigned long tail = 0;
  

public:

  // Default constructor
  SetVec() = default;                                                                 // SetVec() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  SetVec(const TraversableContainer<Data>&);                                          // SetVec(argument) specifiers; // A set obtained from a TraversableContainer
  SetVec(MappableContainer<Data>&&);                                                  // SetVec(argument) specifiers; // A set obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SetVec(const SetVec&);                                                           // SetVec(argument) specifiers;

  // Move constructor
  SetVec(SetVec&&) noexcept;                                                      // SetVec(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  virtual ~SetVec() = default;                                                    // ~SetVec() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  SetVec& operator=(const SetVec&);                                             // type operator=(argument) specifiers;

  // Move assignment
  SetVec& operator=(SetVec&&) noexcept;                                                 // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetVec&) const noexcept;                                        // type operator==(argument) specifiers;
  bool operator!=(const SetVec&) const noexcept;                                          // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  const Data& Min() const override;                                                   // type Min(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data MinNRemove() override;                                                         // type MinNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMin() override;                                                            // type RemoveMin(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  const Data& Max() const override;                                                     // type Max(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data MaxNRemove() override;                                                         // type MaxNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMax() override;                                                            // type RemoveMax(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  const Data& Predecessor(const Data&) const override;                                      // type Predecessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data&) override;                                              // type PredecessorNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data&) override;                                               // type RemovePredecessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  const Data& Successor(const Data&) const override;                                            // type Successor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data&) override;                                            // type SuccessorNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data&) override;                                             // type RemoveSuccessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override;                                                                   // type Insert(argument) specifiers; // Override DictionaryContainer member (copy of the value)
  bool Insert(Data&&) override;                                                                         // type Insert(argument) specifiers; // Override DictionaryContainer member (move of the value)
  bool Remove(const Data&) override;                                                                   // type Remove(argument) specifiers; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const unsigned long) const override;                                         // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override;                                                   // type Exists(argument) specifiers; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override;                                                                          // type Clear() specifiers; // Override ClearableContainer member

  
  protected:
  
  // Auxiliary functions, if necessary!
  void Resize(const unsigned long) override;           
  unsigned long FindIndex(const Data&) const;                                            
  long FindExactIndex(const Data&) const;
  void ShiftRight(unsigned long startIdx, unsigned long endIdx);
  void ShiftLeft(unsigned long startIdx, unsigned long endIdx);   
  void Expand();
  void Reduce();                                      
};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif
