
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  unsigned long size = 0;
  
  /* ************************************************************************ */

  // Default constructor
  Container() = default;

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container&) = delete;                            // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  Container& operator=(Container&&) noexcept = delete;                        // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container&) const noexcept = delete;                  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const Container&) const noexcept = delete;                  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  inline virtual bool Empty() const noexcept { return (size == 0); }          // type Empty() specifiers; // (concrete function should not throw exceptions)

  inline virtual unsigned long Size() const noexcept { return size; }         // type Size() specifiers; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

class ClearableContainer: virtual public Container {
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ClearableContainer() = default;                                    // ~ClearableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator=(const ClearableContainer&) = delete;          // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  ClearableContainer& operator=(ClearableContainer&&) noexcept = delete;      // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer&) const noexcept = delete;                // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const ClearableContainer&) const noexcept = delete;               // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Clear() = 0;                                                         // type Clear() specifiers;

};

/* ************************************************************************** */

class ResizableContainer: virtual public ClearableContainer {
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ResizableContainer() = default;                                        // ~ResizableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer& operator=(const ResizableContainer&) = delete;              // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  ResizableContainer& operator=(ResizableContainer&&) noexcept = delete;          // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResizableContainer&) const noexcept = delete;              // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const ResizableContainer&) const noexcept = delete;              // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Resize(unsigned long) = 0;                                           // type Resize(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override { Resize(0); }                                       // type Clear() specifiers; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#endif
