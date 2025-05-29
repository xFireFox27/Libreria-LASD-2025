
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer: virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MappableContainer() = default;                                             // ~MappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator=(const MappableContainer&) = delete;                              // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  MappableContainer& operator=(MappableContainer&&) noexcept = delete;                              // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer&) const noexcept = delete;                                    // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const MappableContainer&) const noexcept = delete;                                // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using MapFun = std::function<void(Data &)>;

  virtual void Map(MapFun) = 0;                                                    // type Map(argument) specifiers;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer: virtual public MappableContainer<Data>,
  virtual public PreOrderTraversableContainer<Data> {
  // Must extend MappableContainer<Data>,
  //             PreOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PreOrderMappableContainer() = default;                                      // ~PreOrderMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer& operator=(const PreOrderMappableContainer&) = delete;              // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  PreOrderMappableContainer& operator=(PreOrderMappableContainer&&) noexcept = delete;            // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderMappableContainer&) const noexcept = delete;                        // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const PreOrderMappableContainer&) const noexcept = delete;                          // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  virtual void PreOrderMap(MapFun) = 0;                                                                 // type PreOrderMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  inline void Map(MapFun) override;                                                                      // type Map(argument) specifiers; // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer: virtual public MappableContainer<Data>,
  virtual public PostOrderTraversableContainer<Data> {
  // Must extend MappableContainer<Data>,
  //             PostOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PostOrderMappableContainer() = default;                                                                            // ~PostOrderMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  PostOrderMappableContainer& operator=(const PostOrderMappableContainer&) = delete;                                           // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  PostOrderMappableContainer& operator=(PostOrderMappableContainer&&) = delete;                                        // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderMappableContainer&) const noexcept = delete;                                             // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const PostOrderMappableContainer&) const noexcept = delete;                                             // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  virtual void PostOrderMap(MapFun) = 0;                                                                    // type PostOrderMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  inline void Map(MapFun) override;                                                       // type Map(argument) specifiers; // Override MappableContainer member

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
