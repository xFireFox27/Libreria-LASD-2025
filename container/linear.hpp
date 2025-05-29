
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer: virtual public PreOrderTraversableContainer<Data>,
  virtual public PostOrderTraversableContainer<Data> {
  // Must extend PreOrderTraversableContainer<Data>,
  //             PostOrderTraversableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  // Destructor
  virtual ~LinearContainer() = default;                                                       // ~LinearContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator=(const LinearContainer&) = delete;                                // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  LinearContainer& operator=(LinearContainer&&) noexcept = delete;                                // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const LinearContainer&) const noexcept;                                          // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  bool operator!=(const LinearContainer&) const noexcept;                                         // type operator!=(argument) specifiers; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& operator[](const unsigned long) const = 0;                                    // type operator[](argument) specifiers; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  
  virtual inline const Data& Front() const;                                                          // type Front() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)

  virtual inline const Data& Back() const;                                                            // type Back() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  inline void Traverse(TraverseFun) const override;                                                   // type Traverse(argument) specifiers; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  void PreOrderTraverse(TraverseFun) const override;                                           // type PreOrderTraverse(argument) specifiers; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  void PostOrderTraverse(TraverseFun) const override;                                          // type PostOrderTraverse(argument) specifiers; // Override PostOrderTraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableLinearContainer: virtual public LinearContainer<Data>,
  virtual public PreOrderMappableContainer<Data>,
  virtual public PostOrderMappableContainer<Data> {
  // Must extend LinearContainer<Data>,
  //             PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  // Destructor
  virtual ~MutableLinearContainer() = default;                                                        // ~MutableLinearContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  MutableLinearContainer& operator=(const MutableLinearContainer&) = delete;                        // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  MutableLinearContainer& operator=(MutableLinearContainer&&) noexcept = delete;                            // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions
  using LinearContainer<Data>::operator[];
  using LinearContainer<Data>::Front;
  using LinearContainer<Data>::Back;

  virtual Data& operator[](const unsigned long) = 0;                                                          // type operator[](argument) specifiers; // (mutable version; concrete function must throw std::out_of_range when out of range)

  virtual inline Data& Front();                                                                                      // type Front() specifiers; // (mutable version; concrete function must throw std::length_error when empty)

  virtual inline Data& Back();                                                                                    // type Back() specifiers; // (mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  inline void Map(MapFun) override;                                                                             // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun) override;                                                                          // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun) override;                                                                           // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

};

template <typename Data>
class SortableLinearContainer: virtual public MutableLinearContainer<Data> {
  // Must extend MutableLinearContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  // Destructor
  virtual ~SortableLinearContainer() = default;                                                                               // ~SortableLinearContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  SortableLinearContainer& operator=(const SortableLinearContainer&) = delete;                                                  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  SortableLinearContainer& operator=(SortableLinearContainer&&) noexcept = delete;                                              // type operator=(argument); // Move assignment of abstract types is not be possible.

  /* ************************************************************************ */

  // Specific member function

  inline virtual void Sort() noexcept;                                                                                                 // type Sort() specifiers;

protected:

  // Auxiliary member functions

  void insertionSort();                                                         

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
