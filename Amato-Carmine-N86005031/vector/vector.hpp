
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector: virtual public MutableLinearContainer<Data>, 
  virtual public ResizableContainer {
  // Must extend MutableLinearContainer<Data>,
  //             ResizableContainer

private:

  // ...

protected:

  using Container::size;
  Data* Elements = nullptr;                                                       // Pointer to the array of elements
  // ...

public:

  // Default constructor
  Vector() = default;                                                                   // Vector() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const unsigned long);                                                        // Vector(argument) specifiers; // A vector with a given initial dimension
  Vector(const TraversableContainer<Data>&);                                          // Vector(argument) specifiers; // A vector obtained from a TraversableContainer
  Vector(MappableContainer<Data>&&);                                                  // Vector(argument) specifiers; // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector&);                                                               // Vector(argument) specifiers;

  // Move constructor
  Vector(Vector&&) noexcept;                                                          // Vector(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector();                                                                  // ~Vector() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  Vector& operator=(const Vector&);                                                       // type operator=(argument) specifiers;

  // Move assignment
  Vector& operator=(Vector&&) noexcept;                                                            // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector&) const noexcept;                                                    // type operator==(argument) specifiers;
  bool operator!=(const Vector&) const noexcept;                                                    // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableLinearContainer)

  Data& operator[](const unsigned long) override;                                       // type operator[](argument) specifiers; // Override MutableLinearContainer member (must throw std::out_of_range when out of range)

  Data& Front() override;                                                             // type Front() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)

  Data& Back() override;                                                              // type Back() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const unsigned long) const override;                                        // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)

  const Data& Front() const override;                                                           // type Front() specifiers; // Override LinearContainer member (must throw std::length_error when empty)

  const Data& Back() const override;                                                      // type Back() specifiers; // Override LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  void Resize(const unsigned long) override;                                                // type Resize(argument) specifiers; // Override ResizableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override;                                                                    // type Clear() specifiers; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class SortableVector: virtual public Vector<Data>,
  virtual public SortableLinearContainer<Data> {
  // Must extend Vector<Data>,
  //             SortableLinearContainer<Data>

private:

  // ...

protected:

  using Container::size;

  // ...

public:

  // Default constructor
  SortableVector() = default;                                                                     // SortableVector() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  SortableVector(const unsigned long);                                                                     // SortableVector(argument) specifiers; // A vector with a given initial dimension
  SortableVector(const TraversableContainer<Data>&);                                                      // SortableVector(argument) specifiers; // A vector obtained from a TraversableContainer
  SortableVector(MappableContainer<Data>&&);                                                            // SortableVector(argument) specifiers; // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SortableVector(const SortableVector&);                                                    // SortableVector(argument) specifiers;

  // Move constructor
  SortableVector(SortableVector&&) noexcept;                                                         // SortableVector(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  virtual ~SortableVector() = default;                                                              // ~SortableVector() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  SortableVector& operator=(const SortableVector&);                                               // type operator=(argument) specifiers;

  // Move assignment
  SortableVector& operator=(SortableVector&&) noexcept;                                       // type operator=(argument) specifiers;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
