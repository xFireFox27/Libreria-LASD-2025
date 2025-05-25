
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer: virtual public TestableContainer<Data> {
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~TraversableContainer() = default;                              // ~TraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  TraversableContainer& operator=(const TraversableContainer&) = delete;          // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  TraversableContainer& operator=(TraversableContainer&&) noexcept = delete;          // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TraversableContainer&) const noexcept = delete;                   // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator!=(const TraversableContainer&) const noexcept = delete;                   // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using TraverseFun = std::function<void(const Data &)>;

  virtual void Traverse(TraverseFun) const = 0;                                   // type Traverse(arguments) specifiers;

  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

  template <typename Accumulator>
  Accumulator Fold(FoldFun<Accumulator>, Accumulator) const;                        // type Fold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  inline virtual bool Exists(const Data&) const noexcept override;                                  // type Exists(argument) specifiers; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer: virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PreOrderTraversableContainer() = default;                                // ~PreOrderTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  PreOrderTraversableContainer& operator=(const PreOrderTraversableContainer&) = delete;          // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  PreOrderTraversableContainer& operator=(PreOrderTraversableContainer&&) = delete;                   // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderTraversableContainer&) const noexcept = delete;                 // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator!=(const PreOrderTraversableContainer&) const noexcept = delete;                 // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PreOrderTraverse(TraverseFun) const = 0;                                               // type PreOrderTraverse(arguments) specifiers;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator PreOrderFold(FoldFun<Accumulator>, Accumulator) const;                                   // type PreOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  inline void Traverse(TraverseFun) const override;                                                   // type Traverse(arguments) specifiers; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer: virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PostOrderTraversableContainer() = default;                                       // ~PostOrderTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  PostOrderTraversableContainer& operator=(const PostOrderTraversableContainer&) = delete;          // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  PostOrderTraversableContainer& operator=(PostOrderTraversableContainer&&) noexcept = delete;          // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderTraversableContainer&) const noexcept = delete;                        // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  bool operator!=(const PostOrderTraversableContainer&) const noexcept = delete;                         // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PostOrderTraverse(TraverseFun) const = 0;                                                // type PostOrderTraverse(arguments) specifiers;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator PostOrderFold(FoldFun<Accumulator>, Accumulator) const;                             // type PostOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  inline void Traverse(TraverseFun) const override;                                               // type Traverse(arguments) specifiers; // Override TraversableContainer member

};

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif
