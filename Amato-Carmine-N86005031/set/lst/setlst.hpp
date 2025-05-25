
#ifndef SETLST_HPP
#define SETLST_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetLst: virtual public Set<Data>,
  virtual protected List<Data> {
  // Must extend Set<Data>,
  //             List<Data>

private:

  // ...

protected:

  using Container::size;

  using List<Data>::head;
  using List<Data>::tail;

public:

  // Default constructor
  SetLst() = default;                                                             // SetLst() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  SetLst(const TraversableContainer<Data>&);                                        // SetLst(argument) specifiers; // A set obtained from a TraversableContainer
  SetLst(MappableContainer<Data>&&);                                                // SetLst(argument) specifiers; // A set obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SetLst(const SetLst&);                                                                    // SetLst(argument) specifiers;

  // Move constructor
  SetLst(SetLst&&) noexcept;                                                                           // SetLst(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  virtual ~SetLst() = default;                                                                        // ~SetLst() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  SetLst& operator=(const SetLst&);                                                                       // type operator=(argument) specifiers;

  // Move assignment
  SetLst& operator=(SetLst&&) noexcept;                                                                   // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetLst&) const noexcept;                                                        // type operator==(argument) specifiers;
  bool operator!=(const SetLst&) const noexcept;                                                        // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  const Data& Min() const override;                                                                              // type Min(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data MinNRemove() override;                                                                                 // type MinNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMin() override;                                                                                  // type RemoveMin(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  const Data& Max() const override;                                                                           // type Max(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data MaxNRemove() override;                                                                               // type MaxNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMax() override;                                                                                // type RemoveMax(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  const Data& Predecessor(const Data&) const override;                                                    // type Predecessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data&) override;                                                        // type PredecessorNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data&) override;                                                         // type RemovePredecessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  const Data& Successor(const Data&) const override;                                                  // type Successor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data&) override;                                                          // type SuccessorNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data&) override;                                                         // type RemoveSuccessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override;                                                                  // type Insert(argument) specifiers; // Override DictionaryContainer member (copy of the value)
  bool Insert(Data&&) override;                                                                         // type Insert(argument) specifiers; // Override DictionaryContainer member (move of the value)
  bool Remove(const Data&) override;                                                                      // type Remove(argument) specifiers; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const unsigned long) const override;                                                   // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept;                                                         // type Exists(argument) specifiers; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override;                                                                      // type Clear() specifiers; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!
  typename List<Data>::Node* GetAt(const unsigned long) const;                                                              

};

/* ************************************************************************** */

}

#include "setlst.cpp"

#endif
