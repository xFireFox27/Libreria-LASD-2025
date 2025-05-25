
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List: virtual public MutableLinearContainer<Data>,
  virtual public ClearableContainer {
  // Must extend MutableLinearContainer<Data>,
  //             ClearableContainer

private:

  // ...

protected:

  using Container::size;

  struct Node {

    Data element;
    Node* next = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    inline Node() = default;   
    inline Node(const Data& dat);
    inline Node(Data&&) noexcept;           

    /* ********************************************************************** */

    // Copy constructor
    inline Node(const Node& nod);

    // Move constructor
    inline Node(Node&&) noexcept;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node();

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&) const noexcept;
    bool operator!=(const Node&) const noexcept;

    /* ********************************************************************** */

    // Specific member functions
    // Copy a node. Return pointer to first and set pointer to last
    Node* CopyNSetLast(Node** const) const;

  };

  Node* head = nullptr;
  Node* tail = nullptr;

public:

  // Default constructor
  List() = default;                                                                       // List() specifiers;

  /* ************************************************************************ */

  // Specific constructor
  List(const TraversableContainer<Data>&);                                              // List(argument) specifiers; // A list obtained from a TraversableContainer
  List(MappableContainer<Data>&&);                                                      // List(argument) specifiers; // A list obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  List(const List&);                                                                   // List(argument) specifiers;

  // Move constructor
  List(List&&) noexcept;                                                            // List(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  virtual ~List();                                                                    // ~List() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  List& operator=(const List&);                                                         // type operator=(argument) specifiers;

  // Move assignment
  List& operator=(List&&) noexcept;                                                     // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const List&) const noexcept;                                   // type operator==(argument) specifiers;
  inline bool operator!=(const List&) const noexcept;                                   // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions

  void InsertAtFront(const Data&);                                                      // type InsertAtFront(argument) specifier; // Copy of the value
  void InsertAtFront(Data&&);                                                           // type InsertAtFront(argument) specifier; // Move of the value
  void RemoveFromFront();                                                               // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  Data FrontNRemove();                                                                  // type FrontNRemove() specifier; // (must throw std::length_error when empty)

  void InsertAtBack(const Data&);                                                        // type InsertAtBack(argument) specifier; // Copy of the value
  void InsertAtBack(Data&&);                                                             // type InsertAtBack(argument) specifier; // Move of the value
  void RemoveFromBack();                                                                  // type RemoveFromBack() specifier; // (must throw std::length_error when empty)
  Data BackNRemove();                                                                     // type BackNRemove() specifier; // (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableLinearContainer)

  Data& operator[](const unsigned long) override;                                                     // type operator[](argument) specifiers; // Override MutableLinearContainer member (must throw std::out_of_range when out of range)

  Data& Front() override;                                                                           // type Front() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)

  Data& Back() override;                                                                            // type Back() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const unsigned long) const override;                                           // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)

  const Data& Front() const override;                                                                     // type Front() specifiers; // Override LinearContainer member (must throw std::length_error when empty)

  const Data& Back() const override;                                                                    // type Back() specifiers; // Override LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  inline void Map(MapFun) override;                                                                     // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  inline void PreOrderMap(MapFun) override;                                                   // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  inline void PostOrderMap(MapFun) override;                                                    // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  inline void Traverse(TraverseFun) const override;                                                 // type Traverse(arguments) specifiers; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  inline void PreOrderTraverse(TraverseFun) const override;                                         // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  inline void PostOrderTraverse(TraverseFun) const override;                                        // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override;                                                                   // type Clear() specifiers; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!
  void PreOrderTraverse(TraverseFun, Node*) const;                                              
  void PostOrderTraverse(TraverseFun, Node*) const;                                          
  void PreOrderMap(MapFun, Node*);                                                           
  void PostOrderMap(MapFun, Node*);                                                           

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
