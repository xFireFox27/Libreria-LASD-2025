
#include <iostream>

/* ************************************************************************** */

#include "../zlasdtest/container/container.hpp"
#include "../zlasdtest/container/dictionary.hpp"
#include "../zlasdtest/container/linear.hpp"
#include "../zlasdtest/container/mappable.hpp"
#include "../zlasdtest/container/testable.hpp"
#include "../zlasdtest/container/traversable.hpp"

#include "../zlasdtest/vector/vector.hpp"

#include "../zlasdtest/list/list.hpp"
#include "../zlasdtest/set/set.hpp"

using namespace std;

/* ************************************************************************** */

void mytest() {
  unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of My Vector<int> Test:" << endl;
  try {
    lasd::SortableVector<int> vec1;
    Empty(loctestnum, loctesterr, vec1, true);
    lasd::SortableVector<int> vec2(5);
    vec1 = vec2;
    Empty(loctestnum, loctesterr, vec1, false);
    EqualVector(loctestnum, loctesterr, vec1, vec2, true);
    lasd::SortableVector<int> vec3;
    vec2 = vec3;
    Size(loctestnum, loctesterr, vec2, true, 0);
    EqualVector(loctestnum, loctesterr, vec1, vec2, false);
    EqualVector(loctestnum, loctesterr, vec2, vec3, true);
    SetAt(loctestnum, loctesterr, vec3, false, 0, 0);
    vec3.Resize(5);
    Size(loctestnum, loctesterr, vec3, true, 5);
    SetAt(loctestnum, loctesterr, vec3, true, 0, 5);
    SetAt(loctestnum, loctesterr, vec3, true, 1, 4);
    SetAt(loctestnum, loctesterr, vec3, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec3, true, 3, 2);
    SetAt(loctestnum, loctesterr, vec3, true, 4, 1);
    SetAt(loctestnum, loctesterr, vec3, false, 5, 1);
    Empty(loctestnum, loctesterr, vec2, true);
    Size(loctestnum, loctesterr, vec2, true, 0);
    vec2 = (std::move(vec3));
    Size(loctestnum, loctesterr, vec3, true, 0);
    Traverse(loctestnum, loctesterr, vec2, true, TraversePrint<int>);
    GetAt(loctestnum, loctesterr, vec2, false, 0, 1);
    GetAt(loctestnum, loctesterr, vec2, false, 1, 2);
    GetAt(loctestnum, loctesterr, vec2, true, 2, 3);
    GetAt(loctestnum, loctesterr, vec2, false, 3, 4);
    GetAt(loctestnum, loctesterr, vec2, false, 4, 5);
    Empty(loctestnum, loctesterr, vec3, true);
    vec2.Sort();
    Traverse(loctestnum, loctesterr, vec2, true, TraversePrint<int>);
    GetAt(loctestnum, loctesterr, vec2, true, 0, 1);
    GetAt(loctestnum, loctesterr, vec2, true, 1, 2);
    GetAt(loctestnum, loctesterr, vec2, true, 2, 3);
    GetAt(loctestnum, loctesterr, vec2, true, 3, 4);
    GetAt(loctestnum, loctesterr, vec2, true, 4, 5);
    vec2.Sort();
    Traverse(loctestnum, loctesterr, vec2, true, TraversePrint<int>);
    GetAt(loctestnum, loctesterr, vec2, true, 0, 1);
    GetAt(loctestnum, loctesterr, vec2, true, 1, 2);
    GetAt(loctestnum, loctesterr, vec2, true, 2, 3);
    GetAt(loctestnum, loctesterr, vec2, true, 3, 4);
    GetAt(loctestnum, loctesterr, vec2, true, 4, 5);
    vec2.Resize(2);
    GetAt(loctestnum, loctesterr, vec2, false, 2, 1);
    lasd::SortableVector<int> vec4(vec2);
    Empty(loctestnum, loctesterr, vec2, false);
    lasd::SortableVector<int> vec5(std::move(vec2));
    Empty(loctestnum, loctesterr, vec2, true);
    EqualVector(loctestnum, loctesterr, vec4, vec5, true);
    lasd::SortableVector<int> vec6;
    EqualVector(loctestnum, loctesterr, vec2, vec6, true);
    vec4.Resize(1);
    EqualVector(loctestnum, loctesterr, vec4, vec5, false);
    vec4.Resize(2);
    SetAt(loctestnum, loctesterr, vec4, true, 1, 2);
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec5, true, TraversePrint<int>);
    EqualVector(loctestnum, loctesterr, vec4, vec5, true);
    vec4.Resize(10);
    SetAt(loctestnum, loctesterr, vec4, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 1, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 2, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 3, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 4, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 5, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 6, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 7, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 8, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 9, 1);
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, vec4, true, FoldAdd<int>, 0, 10);
    Map(loctestnum, loctesterr, vec4, true, [](int &i) { ++i; });
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, vec4, true, FoldAdd<int>, 0, 20);
    unsigned long int pos{0};
    Map(loctestnum, loctesterr, vec4, true, [&pos](int &i) { i += pos++; });
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, vec4, true, FoldParity, 0, 1);
    lasd::List<int> lst(vec4);
    lasd::SortableVector<int> vec7(lst);
    EqualVector(loctestnum, loctesterr, vec4, vec7, true);
    Traverse(loctestnum, loctesterr, vec7, true, TraversePrint<int>);
    vec1 = vec5;
    lasd::SortableVector<int> vec8(std::move(lst));
    EqualVector(loctestnum, loctesterr, vec7, vec8, true);
    vec5 = std::move(vec7);
    Traverse(loctestnum, loctesterr, vec7, true, TraversePrint<int>);
    EqualVector(loctestnum, loctesterr, vec4, vec5, true);
    EqualVector(loctestnum, loctesterr, vec4, vec8, true);
    EqualVector(loctestnum, loctesterr, vec5, vec8, true);
    Empty(loctestnum, loctesterr, lst, false);
    Empty(loctestnum, loctesterr, vec7, false);
    EqualVector(loctestnum, loctesterr, vec1, vec7, true);
    NonEqualVector(loctestnum, loctesterr, vec1, vec7, false);
    Exists(loctestnum, loctesterr, vec7, true, 1);
    Exists(loctestnum, loctesterr, vec7, false, 12);
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    pos = 0;
    FoldPreOrder(loctestnum, loctesterr, vec4, true, [&pos](const int &i, const double &a) { return pos++ % 2 ? a - i : a + i; }, 0, -5);
    pos = 0;
    FoldPostOrder(loctestnum, loctesterr, vec4, true, [&pos](const int &i, const double &a) { return pos++ % 2 ? a - i : a + i; }, 0, 5);
    vec5.Clear();
    Size(loctestnum, loctesterr, vec5, true, 0);
    EqualVector(loctestnum, loctesterr, vec5, vec7, false);
    NonEqualVector(loctestnum, loctesterr, vec5, vec7, true);
    Exists(loctestnum, loctesterr, vec5, false, 1);
    GetAt(loctestnum, loctesterr, vec5, false, 0, 0);
    SetAt(loctestnum, loctesterr, vec5, false, 0, 0);
    lasd::List<int> lst2;
    InsertAtBack(loctestnum, loctesterr, lst2, true, 1);
    InsertAtBack(loctestnum, loctesterr, lst2, true, 2);
    InsertAtBack(loctestnum, loctesterr, lst2, true, 3);
    lasd::List<int> lst3(lst2);
    lasd::SortableVector<int> vec9(std::move(lst2));
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst3, true, TraversePrint<int>);
    NonEqualList(loctestnum, loctesterr, lst2, lst3, false);
    lasd::Vector<int> vec10(5);
    SetAt(loctestnum, loctesterr, vec10, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec10, true, 1, 2);
    SetAt(loctestnum, loctesterr, vec10, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec10, true, 3, 4);
    SetAt(loctestnum, loctesterr, vec10, true, 4, 5);
    MapPostOrder(loctestnum, loctesterr, vec10, true, [](int &i) { i += 1; });
    Traverse(loctestnum, loctesterr, vec10, true, TraversePrint<int>);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "../Unmanaged error! " << endl;
  }
  cout << "End of Vector<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;

  cout << endl << "Begin of My Vector<string> Test:" << endl;
  try {
    lasd::SortableVector<string> vec(3);
    Empty(loctestnum, loctesterr, vec, false);
    Size(loctestnum, loctesterr, vec, true, 3);

    SetAt(loctestnum, loctesterr, vec, true, 0, string("This"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("is"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("correct!"));

    GetFront(loctestnum, loctesterr, vec, true, string("This"));
    GetBack(loctestnum, loctesterr, vec, true, string("correct!"));

    Exists(loctestnum, loctesterr, vec, true, string("is"));

    MapPreOrder(loctestnum, loctesterr, vec, true, [](string & str) { MapStringAppend(str, string(" ")); });
    TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
    FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("XThis is correct! "));
    FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("Xcorrect! is This "));

    Exists(loctestnum, loctesterr, vec, false, string("is"));

    lasd::SortableVector<string> copvec(vec);
    EqualVector(loctestnum, loctesterr, vec, copvec, true);
    EqualLinear(loctestnum, loctesterr, vec, copvec, true);
    MapPreOrder(loctestnum, loctesterr, vec, true, [](string & str) { MapStringAppend(str, string(" ")); });
    NonEqualVector(loctestnum, loctesterr, vec, copvec, true);

    copvec = vec;
    EqualVector(loctestnum, loctesterr, vec, copvec, true);
    EqualLinear(loctestnum, loctesterr, vec, copvec, true);
    MapPreOrder(loctestnum, loctesterr, vec, true, [](string & str) { MapStringAppend(str, string("X")); });
    NonEqualVector(loctestnum, loctesterr, vec, copvec, true);
    NonEqualLinear(loctestnum, loctesterr, vec, copvec, true);

    FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("?"), string("?This  Xis  Xcorrect!  X"));
    copvec = move(vec);
    FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("?"), string("?This  is  correct!  "));

    lasd::SortableVector<string> movvec(move(vec));
    FoldPreOrder(loctestnum, loctesterr, movvec, true, &FoldStringConcatenate, string("?"), string("?This  is  correct!  "));
    movvec.Sort();
    FoldPreOrder(loctestnum, loctesterr, movvec, true, &FoldStringConcatenate, string("?"), string("?This  correct!  is  "));
    SetAt(loctestnum, loctesterr, vec, false, 1, string(""));

    movvec.Clear();
    Empty(loctestnum, loctesterr, movvec, true);
    Size(loctestnum, loctesterr, movvec, true, 0);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My Vector<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;

  
  cout << endl << "Begin of My List<int> Test:" << endl;
  try {
    lasd::List<int> lst1;
    Empty(loctestnum, loctesterr, lst1, true);
    lasd::Vector<int> vec1(5);
    SetAt(loctestnum, loctesterr, vec1, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec1, true, 1, 2);
    SetAt(loctestnum, loctesterr, vec1, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec1, true, 3, 4);
    SetAt(loctestnum, loctesterr, vec1, true, 4, 5);
    lasd::List<int> lst2;
    SetAt(loctestnum, loctesterr, vec1, true, 0, 2);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    lst2.Clear();
    Empty(loctestnum, loctesterr, lst2, true);
    Size(loctestnum, loctesterr, lst2, true, 0);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    lst2.Clear();
    SetAt(loctestnum, loctesterr, vec1, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec1, true, 1, 2);
    SetAt(loctestnum, loctesterr, vec1, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec1, true, 3, 4);
    SetAt(loctestnum, loctesterr, vec1, true, 4, 5);
    SetAt(loctestnum, loctesterr, vec1, true, 0, 1);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    SetAt(loctestnum, loctesterr, vec1, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec1, true, 1, 2);
    SetAt(loctestnum, loctesterr, vec1, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec1, true, 3, 4);
    SetAt(loctestnum, loctesterr, vec1, true, 4, 5);
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    Empty(loctestnum, loctesterr, lst2, true);
    for (unsigned long int i{0}; i < vec1.Size(); ++i) vec1[i] = 1;
    for (unsigned long int i{0}; i < vec1.Size(); ++i) vec1[i] = (int)i + 1;
    lst2.Clear();
    for (unsigned long int i{0}; i < vec1.Size(); ++i) vec1[i] = 10;
    vec1.Resize(0);
    vec1.Clear();
    Empty(loctestnum, loctesterr, vec1, true);
    lst2.Clear();
    InsertAtFront(loctestnum, loctesterr, lst2, true, 1);
    InsertAtFront(loctestnum, loctesterr, lst2, true, 2);
    InsertAtFront(loctestnum, loctesterr, lst2, true, 3);
    InsertAtFront(loctestnum, loctesterr, lst2, true, 4);
    InsertAtFront(loctestnum, loctesterr, lst2, true, 5);
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    lst1 = lst2;
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 5);
    EqualList(loctestnum, loctesterr, lst1, lst2, false);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 4);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 3);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 2);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 1);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 2);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 1);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 5);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 4);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 3);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 2);
    FrontNRemove(loctestnum, loctesterr, lst1, true, 1);
    FrontNRemove(loctestnum, loctesterr, lst1, false, 1);
    lst1 = lst2;
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    NonEqualList(loctestnum, loctesterr, lst1, lst2, false);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 10);
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    lst1 = lst2;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    lst2 = lst1;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    vec1.Resize(100);
    int x{100};
    for (unsigned long int i{0}; i < vec1.Size(); ++i) vec1[i] = x++;
    lst1.Clear();
    lasd::List<int> lst3(vec1);
    lasd::List<int> lst4(lst1);
    Traverse(loctestnum, loctesterr, lst3, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst4, true, TraversePrint<int>);
    EqualList(loctestnum, loctesterr, lst3, lst4, false);
    Traverse(loctestnum, loctesterr, lst4, true, TraversePrint<int>);
    lst3.Clear();
    lst3.InsertAtFront(1);
    lst4 = lst3;
    EqualList(loctestnum, loctesterr, lst3, lst4, true);
    Traverse(loctestnum, loctesterr, lst4, true, TraversePrint<int>);
    lst1.Clear();
    lst2.Clear();
    lst1 = lst2;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    lst1.InsertAtFront(1);
    lst1 = lst2;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    lst2.InsertAtFront(1);
    lst1 = lst2;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    vec1.Resize(50);
    vec1.Resize(35);
    lst3.Clear();
    lst2 = lst1;
    EqualList(loctestnum, loctesterr, lst1, lst2, true);
    lst1 = lst3;
    EqualList(loctestnum, loctesterr, lst1, lst3, true);
    x = 0;
    vec1.Resize(100);
    for (unsigned long int i{0}; i < vec1.Size(); ++i) vec1[i] = x++;
    lst4.Clear();
    lasd::List<int> lst5(std::move(vec1));
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst5, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst4, true, TraversePrint<int>);
    EqualList(loctestnum, loctesterr, lst4, lst5, false);
    x = 0;
    vec1.Resize(100);
    for (unsigned long int i{0}; i < vec1.Size(); ++i) vec1[i] = x++;
    lst1.Clear();
    lst2 = lst1;
    lst3.Clear();
    lst3 = std::move(lst1);
    EqualList(loctestnum, loctesterr, lst2, lst3, true);
    Size(loctestnum, loctesterr, lst1, true, 0);
    lasd::List<int> lst10;
    lasd::List<int> lst11(lst10);
    Traverse(loctestnum, loctesterr, lst10, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst11, true, TraversePrint<int>);
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, true, 0);
    lst10 = lst11;
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, true, 0);
    lst10 = std::move(lst11);
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, true, 0);
    lst11 = lst10;
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, false, 100);
    lst10 = std::move(lst11);
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, false, 100);
    lst10.Clear();
    lst10 = std::move(lst11);
    Traverse(loctestnum, loctesterr, lst10, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst11, true, TraversePrint<int>);
    EqualList(loctestnum, loctesterr, lst10, lst11, true);
    Size(loctestnum, loctesterr, lst11, true, 0);
    Traverse(loctestnum, loctesterr, lst10, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    lasd::List<int> lst12(std::move(lst10));
    lasd::List<int> lst13(std::move(vec1));
    Traverse(loctestnum, loctesterr, lst12, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst13, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst10, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    EqualList(loctestnum, loctesterr, lst12, lst13, false);
    vec1.Clear();
    vec1.Resize(10);
    x = 0;
    for (unsigned long int i{0}; i < vec1.Size(); ++i) vec1[i] = x++;
    lst1.Clear();
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    vec1.Resize(2);
    vec1[0] = 8;
    vec1[1] = 3;
    Traverse(loctestnum, loctesterr, lst1, true, TraversePrint<int>);
    lst1.Clear();
    for (unsigned long int i{0}; i < 5; ++i) lst1.InsertAtBack(i);
    RemoveFromFront(loctestnum, loctesterr, lst1, true);
    vec1.Clear();
    vec1.Resize(10);
    x = 0;
    for (unsigned long int i{0}; i < vec1.Size(); ++i) vec1[i] = x++;
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    lasd::List<int> lst666(vec1);
    Traverse(loctestnum, loctesterr, lst666, true, TraversePrint<int>);
    lasd::SortableVector<int> vec666;
    vec666 = std::move(vec1);
    Traverse(loctestnum, loctesterr, vec666, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    EqualLinear(loctestnum, loctesterr, lst666, vec666, true);
    vec1.Resize(1);
    vec1[0] = 9;
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec666, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst666, true, TraversePrint<int>);
    EqualLinear(loctestnum, loctesterr, lst666, vec666, true);
    vec666.Resize(vec666.Size() - 1);
    Traverse(loctestnum, loctesterr, vec666, true, TraversePrint<int>);
    EqualLinear(loctestnum, loctesterr, lst666, vec666, false);
    lasd::List<int> lst7;
    InsertAtBack(loctestnum, loctesterr, lst7, true, 1);
    InsertAtBack(loctestnum, loctesterr, lst7, true, 2);
    InsertAtBack(loctestnum, loctesterr, lst7, true, 3);
    InsertAtBack(loctestnum, loctesterr, lst7, true, 4);
    InsertAtBack(loctestnum, loctesterr, lst7, true, 5);
    Traverse(loctestnum, loctesterr, lst7, true, TraversePrint<int>);
    RemoveFromBack(loctestnum, loctesterr, lst7, true);
    Traverse(loctestnum, loctesterr, lst7, true, TraversePrint<int>);
    BackNRemove(loctestnum, loctesterr, lst7, false, 2);
    Traverse(loctestnum, loctesterr, lst7, true, TraversePrint<int>);
    BackNRemove(loctestnum, loctesterr, lst7, true, 3);
    Traverse(loctestnum, loctesterr, lst7, true, TraversePrint<int>);
    InsertAtFront(loctestnum, loctesterr, lst7, true, 33);
    Traverse(loctestnum, loctesterr, lst7, true, TraversePrint<int>);
    lasd::List<int> lst33(lst7);
    EqualList(loctestnum, loctesterr, lst7, lst33, true);
    lst7.Clear();
    EqualList(loctestnum, loctesterr, lst7, lst33, false);
    lst33.Clear();
    EqualList(loctestnum, loctesterr, lst7, lst33, true);
    Empty(loctestnum, loctesterr, lst7, true);
    Empty(loctestnum, loctesterr, lst33, true);
    lasd::Vector<int> vec33(5);
    SetAt(loctestnum, loctesterr, vec33, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec33, true, 1, 2);
    SetAt(loctestnum, loctesterr, vec33, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec33, true, 3, 4);
    SetAt(loctestnum, loctesterr, vec33, true, 4, 5);
    lasd::SortableVector<int> vec66 = std::move(vec33);
    Traverse(loctestnum, loctesterr, vec66, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec33, true, TraversePrint<int>);
    lasd::List<int> lst16;
    RemoveFromFront(loctestnum, loctesterr, lst16, false);
    InsertAtBack(loctestnum, loctesterr, lst16, true, 1);
    RemoveFromFront(loctestnum, loctesterr, lst16, true);
    FrontNRemove(loctestnum, loctesterr, lst16, false, 1);
    RemoveFromBack(loctestnum, loctesterr, lst16, false);
    InsertAtBack(loctestnum, loctesterr, lst16, true, 1);
    RemoveFromBack(loctestnum, loctesterr, lst16, true);
    BackNRemove(loctestnum, loctesterr, lst16, false, 1);
    InsertAtFront(loctestnum, loctesterr, lst16, true, 1);
    BackNRemove(loctestnum, loctesterr, lst16, true, 1);
    InsertAtBack(loctestnum, loctesterr, lst16, true, 1);
    InsertAtFront(loctestnum, loctesterr, lst16, true, 33);
    InsertAtBack(loctestnum, loctesterr, lst16, true, 27);
    GetAt(loctestnum, loctesterr, lst16, true, 0, 33);
    GetAt(loctestnum, loctesterr, lst16, false, 5, 1);
    MapPostOrder(loctestnum, loctesterr, lst16, true, [](int &i) { i += 1; });
    SetFront(loctestnum, loctesterr, lst16, true, -50);
    SetBack(loctestnum, loctesterr, lst16, true, 50);
    Traverse(loctestnum, loctesterr, lst16, true, TraversePrint<int>);
    lst16.Clear();
    Empty(loctestnum, loctesterr, lst16, true);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My List<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;

  cout << endl << "Begin of My List<string> Test:" << endl;
  try {
    lasd::List<string> lst1;
    Empty(loctestnum, loctesterr, lst1, true);
    lasd::Vector<string> vec1(5);
    SetAt(loctestnum, loctesterr, vec1, true, 0, string("1"));
    SetAt(loctestnum, loctesterr, vec1, true, 1, string("2"));
    SetAt(loctestnum, loctesterr, vec1, true, 2, string("3"));
    SetAt(loctestnum, loctesterr, vec1, true, 3, string("4"));
    SetAt(loctestnum, loctesterr, vec1, true, 4, string("5"));
    lasd::List<string> lst2;
    SetAt(loctestnum, loctesterr, vec1, true, 0, string("2"));
    lasd::Vector<string> vec2(1);
    EqualVector(loctestnum, loctesterr, vec1, vec2, false);
    lst2.Clear();
    vec2 = vec1;
    EqualVector(loctestnum, loctesterr, vec1, vec2, true);
  } catch (...) {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My List<string> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;

  cout << endl << "Begin of My SetVec<int> Test:" << endl;
  try
  {
    lasd::SetVec<int> setvec1;
    Empty(loctestnum, loctesterr, setvec1, true);
    lasd::SetVec<int> setvec2;
    InsertC(loctestnum, loctesterr, setvec2, true, 4);
    InsertC(loctestnum, loctesterr, setvec2, true, 8);
    InsertC(loctestnum, loctesterr, setvec2, true, 33);
    InsertC(loctestnum, loctesterr, setvec2, true, 6);
    InsertC(loctestnum, loctesterr, setvec2, true, 5);
    Traverse(loctestnum, loctesterr, setvec2, true, TraversePrint<int>);
    setvec1 = setvec2;
    Empty(loctestnum, loctesterr, setvec1, false);
    EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
    Predecessor(loctestnum, loctesterr, setvec1, false, 1, 1);
    Remove(loctestnum, loctesterr, setvec1, true, 8);
    InsertM(loctestnum, loctesterr, setvec1, true, 2);
    Traverse(loctestnum, loctesterr, setvec1, true, TraversePrint<int>);
    Predecessor(loctestnum, loctesterr, setvec1, false, 2, 0);
    MinNRemove(loctestnum, loctesterr, setvec1, true, 2);
    Traverse(loctestnum, loctesterr, setvec1, true, TraversePrint<int>);
    Size(loctestnum, loctesterr, setvec1, true, 4);
    lasd::SetVec<int> setvec3(std::move(setvec2));
    Traverse(loctestnum, loctesterr, setvec2, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, setvec3, true, TraversePrint<int>);
    EqualSetVec(loctestnum, loctesterr, setvec1, setvec3, false);
    Remove(loctestnum, loctesterr, setvec3, true, 4);
    Remove(loctestnum, loctesterr, setvec3, true, 5);
    Remove(loctestnum, loctesterr, setvec3, true, 6);
    Remove(loctestnum, loctesterr, setvec3, true, 33);
    Remove(loctestnum, loctesterr, setvec3, true, 8);
    Traverse(loctestnum, loctesterr, setvec3, true, TraversePrint<int>);
    Empty(loctestnum, loctesterr, setvec3, true);
    lasd::Vector<int> vec1(5);
    SetAt(loctestnum, loctesterr, vec1, true, 0, 5);
    SetAt(loctestnum, loctesterr, vec1, true, 1, 4);
    SetAt(loctestnum, loctesterr, vec1, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec1, true, 3, 2);
    SetAt(loctestnum, loctesterr, vec1, true, 4, 1);
    lasd::SetVec<int> setvec4(vec1);
    Traverse(loctestnum, loctesterr, setvec4, true, TraversePrint<int>);
    Successor(loctestnum, loctesterr, setvec4, true, 1, 2);
    Predecessor(loctestnum, loctesterr, setvec4, true, 6, 5);
    RemovePredecessor(loctestnum, loctesterr, setvec4, true, 6);
    Traverse(loctestnum, loctesterr, setvec4, true, TraversePrint<int>);
    lasd::SetVec<int> setvec5;
    InsertAllM(loctestnum, loctesterr, setvec5, true, std::move(vec1));
    Traverse(loctestnum, loctesterr, vec1, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, setvec5, true, TraversePrint<int>);
    SuccessorNRemove(loctestnum, loctesterr, setvec5, true, 4, 5);
    Traverse(loctestnum, loctesterr, setvec4, true, TraversePrint<int>);
    EqualSetVec(loctestnum, loctesterr, setvec4, setvec5, true);
    FoldPostOrder(loctestnum, loctesterr, setvec5, true, FoldAdd<int>, 1, 11);
    FoldPreOrder(loctestnum, loctesterr, setvec5, true, FoldMultiply<int>, 1, 24);
    InsertC(loctestnum, loctesterr, setvec5, false, 1);
    lasd::SetVec<int> setvec11;
    InsertC(loctestnum, loctesterr, setvec11, true, 1);
    InsertC(loctestnum, loctesterr, setvec11, true, 8);
    InsertC(loctestnum, loctesterr, setvec11, true, 10);
    InsertC(loctestnum, loctesterr, setvec11, true, 2);
    InsertC(loctestnum, loctesterr, setvec11, true, 4);
    InsertC(loctestnum, loctesterr, setvec11, false, 10);
    Traverse(loctestnum, loctesterr, setvec11, true, TraversePrint<int>);
    SuccessorNRemove(loctestnum, loctesterr, setvec11, true, 3, 4);
    Traverse(loctestnum, loctesterr, setvec11, true, TraversePrint<int>);
    RemoveSuccessor(loctestnum, loctesterr, setvec11, true, 0);
    lasd::SetVec<int> setvec12;
    Min(loctestnum, loctesterr, setvec12, false, 1);
    MinNRemove(loctestnum, loctesterr, setvec12, false, 1);
    RemoveMin(loctestnum, loctesterr, setvec12, false);
    Max(loctestnum, loctesterr, setvec12, false, 1);
    MaxNRemove(loctestnum, loctesterr, setvec12, false, 1);
    RemoveMax(loctestnum, loctesterr, setvec12, false);
    Predecessor(loctestnum, loctesterr, setvec12, false, 1, 1);
    PredecessorNRemove(loctestnum, loctesterr, setvec12, false, 1, 1);
    RemovePredecessor(loctestnum, loctesterr, setvec12, false, 1);
    Successor(loctestnum, loctesterr, setvec12, false, 1, 1);
    SuccessorNRemove(loctestnum, loctesterr, setvec12, false, 1, 1);
    RemoveSuccessor(loctestnum, loctesterr, setvec12, false, 1);
    InsertC(loctestnum, loctesterr, setvec12, true, 1);
    InsertC(loctestnum, loctesterr, setvec12, true, 4);
    InsertC(loctestnum, loctesterr, setvec12, true, 20);
    InsertC(loctestnum, loctesterr, setvec12, true, 8);
    InsertC(loctestnum, loctesterr, setvec12, true, 15);
    Traverse(loctestnum, loctesterr, setvec12, true, TraversePrint<int>);
    PredecessorNRemove(loctestnum, loctesterr, setvec12, false, 1, 1);
    RemovePredecessor(loctestnum, loctesterr, setvec12, false, 1);
    Successor(loctestnum, loctesterr, setvec12, false, 20, 1);
    SuccessorNRemove(loctestnum, loctesterr, setvec12, false, 200, 1);
    RemoveSuccessor(loctestnum, loctesterr, setvec12, false, 50);
    PredecessorNRemove(loctestnum, loctesterr, setvec12, true, 10, 8);
    Remove(loctestnum, loctesterr, setvec12, false, 33);
    GetAt(loctestnum, loctesterr, setvec12, false, 6, 1);
    lasd::SetVec<int> setvec13;
    InsertC(loctestnum, loctesterr, setvec13, true, 90);
    InsertC(loctestnum, loctesterr, setvec13, true, 47);
    InsertC(loctestnum, loctesterr, setvec13, true, 25);
    InsertC(loctestnum, loctesterr, setvec13, true, 15);
    InsertC(loctestnum, loctesterr, setvec13, true, 5);
    Traverse(loctestnum, loctesterr, setvec13, true, TraversePrint<int>);
    RemoveSuccessor(loctestnum, loctesterr, setvec13, true, 30);
    Traverse(loctestnum, loctesterr, setvec13, true, TraversePrint<int>);
    InsertC(loctestnum, loctesterr, setvec13, true, 54);
    SuccessorNRemove(loctestnum, loctesterr, setvec13, true, 30, 54);
    Remove(loctestnum, loctesterr, setvec13, true, 90);
    Remove(loctestnum, loctesterr, setvec13, false, 90);
    Traverse(loctestnum, loctesterr, setvec13, true, TraversePrint<int>);
    lasd::SetVec<int> setvec14;
    InsertC(loctestnum, loctesterr, setvec14, true, 5);
    InsertC(loctestnum, loctesterr, setvec14, true, 10);
    InsertC(loctestnum, loctesterr, setvec14, true, 15);
    InsertC(loctestnum, loctesterr, setvec14, true, 25);
    InsertC(loctestnum, loctesterr, setvec14, true, 20);
  }
  catch(...)
  {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My SetVec<int> Test! (Errors/Tests: " << loctesterr << "/"
       << loctestnum << ")" << endl;


  cout << endl << "Begin of SetVec<double> Test" << endl;
  try {
    lasd::Vector<double> vec(6);
    SetAt(loctestnum, loctesterr, vec, true, 0, 3.5);
    SetAt(loctestnum, loctesterr, vec, true, 1, 1.2);
    SetAt(loctestnum, loctesterr, vec, true, 2, 4.0);
    SetAt(loctestnum, loctesterr, vec, true, 3, 0.4);
    SetAt(loctestnum, loctesterr, vec, true, 4, 2.1);
    SetAt(loctestnum, loctesterr, vec, true, 5, 5.3);

    lasd::SetVec<double> setvec1(vec);
    Empty(loctestnum, loctesterr, setvec1, false);
    Size(loctestnum, loctesterr, setvec1, true, 6);
    TraversePreOrder(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);

    lasd::SetVec<double> setvec2;
    InsertC(loctestnum, loctesterr, setvec2, true, 2.1);
    InsertC(loctestnum, loctesterr, setvec2, true, 0.4);
    InsertC(loctestnum, loctesterr, setvec2, true, 1.2);
    InsertC(loctestnum, loctesterr, setvec2, true, 3.5);
    InsertC(loctestnum, loctesterr, setvec2, true, 5.3);
    InsertC(loctestnum, loctesterr, setvec2, true, 4.0);
    EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
    NonEqualSetVec(loctestnum, loctesterr, setvec1, setvec2, false);
    setvec1.Clear();
    InsertC(loctestnum, loctesterr, setvec1, true, 0.2);
    InsertC(loctestnum, loctesterr, setvec1, true, 1.1);
    InsertC(loctestnum, loctesterr, setvec1, true, 2.1);

    lasd::SetVec<double> vecA, vecB;
    vecB = setvec1;  
    InsertAllC(loctestnum, loctesterr, vecA, true, vecB);
    EqualSetVec(loctestnum, loctesterr, vecA, vecB, true);
    NonEqualSetVec(loctestnum, loctesterr, vecA, vecB, false);

    lasd::SetVec<double> vecC, vecD; 
    vecC = vecA;
    InsertC(loctestnum, loctesterr, vecD, true, 1.1);
    InsertC(loctestnum, loctesterr, vecD, true, 2.1);
    InsertC(loctestnum, loctesterr, vecD, true, 3.3);  
    InsertSomeC(loctestnum, loctesterr, vecC, true, vecD);
    Exists(loctestnum, loctesterr, vecC, true, 3.3);
    NonEqualSetVec(loctestnum, loctesterr, vecC, vecA, true);
    RemoveSome(loctestnum, loctesterr, vecC, true, vecD);
    Exists(loctestnum, loctesterr, vecC, false, 1.1);
    Exists(loctestnum, loctesterr, vecC, false, 2.1);
    Exists(loctestnum, loctesterr, vecC, false, 3.3);
    Exists(loctestnum, loctesterr, vecC, true, 0.2);
    InsertAllC(loctestnum, loctesterr, vecC, true, vecD);
    EqualSetVec(loctestnum, loctesterr, vecC, vecD, false);
    RemoveAll(loctestnum, loctesterr, vecC, true, vecD);
    EqualSetVec(loctestnum, loctesterr, vecC, lasd::SetVec<double>(), false);

    lasd::SetVec<double> vecF = vecB;  
    RemoveMin(loctestnum, loctesterr, vecF, true);
    Min(loctestnum, loctesterr, vecF, true, 1.1);
    RemoveMax(loctestnum, loctesterr, vecF, true);
    Max(loctestnum, loctesterr, vecF, true, 1.1);
    vecF = vecB;
    RemovePredecessor(loctestnum, loctesterr, vecF, true, 1.1);
    Exists(loctestnum, loctesterr, vecF, false, 0.2);
    vecF = vecB;
    RemoveSuccessor(loctestnum, loctesterr, vecF, true, 1.1);
    Exists(loctestnum, loctesterr, vecF, false, 2.1);
    MinNRemove(loctestnum, loctesterr, vecF, true, 0.2);
    Size(loctestnum, loctesterr, vecF, true, 1);
    vecF = vecB;
    MaxNRemove(loctestnum, loctesterr, vecF, true, 2.1);
    Size(loctestnum, loctesterr, vecF, true, 2);
    Exists(loctestnum, loctesterr, vecF, true, 0.2);
  }
  catch (...) {
    loctestnum++; 
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of SetVec<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;

  
  cout << endl << "Begin of My SetVec<String> Test:" << endl;
  try
  {
    lasd::SetVec<string> setvec1;
    Empty(loctestnum, loctesterr, setvec1, true);
    lasd::SetVec<string> setvec2;
    InsertC(loctestnum, loctesterr, setvec2, true, string("E"));
    InsertC(loctestnum, loctesterr, setvec2, true, string("D"));
    InsertC(loctestnum, loctesterr, setvec2, true, string("C"));
    InsertC(loctestnum, loctesterr, setvec2, true, string("B"));
    InsertC(loctestnum, loctesterr, setvec2, true, string("A"));
    Traverse(loctestnum, loctesterr, setvec2, true, TraversePrint<string>);
    setvec1 = setvec2;
    Empty(loctestnum, loctesterr, setvec1, false);
    EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
    Predecessor(loctestnum, loctesterr, setvec1, false, string("A"), string("A"));
    Remove(loctestnum, loctesterr, setvec1, true, string("C"));
    InsertM(loctestnum, loctesterr, setvec1, true, string("?"));
    Traverse(loctestnum, loctesterr, setvec1, true, TraversePrint<string>);
    Predecessor(loctestnum, loctesterr, setvec1, true, string("E"), string("D"));
    MaxNRemove(loctestnum, loctesterr, setvec1, true, string("E"));
    Traverse(loctestnum, loctesterr, setvec1, true, TraversePrint<string>);
    Size(loctestnum, loctesterr, setvec1, true, 4);
    FoldPreOrder(loctestnum, loctesterr, setvec1, true, FoldAdd<string>, string("!"), string("!?ABD"));
    FoldPostOrder(loctestnum, loctesterr, setvec1, true, FoldAdd<string>, string("EX33"), string("EX33DBA?"));
    Exists(loctestnum, loctesterr, setvec1, true, string("A"));
    Exists(loctestnum, loctesterr, setvec1, false, string("Z"));
    RemovePredecessor(loctestnum, loctesterr, setvec1, true, string("E"));
    Traverse(loctestnum, loctesterr, setvec1, true, TraversePrint<string>);
    lasd::SetVec<string> setvec3(std::move(setvec2));
    Traverse(loctestnum, loctesterr, setvec2, true, TraversePrint<string>);
    Traverse(loctestnum, loctesterr, setvec3, true, TraversePrint<string>);
    EqualSetVec(loctestnum, loctesterr, setvec1, setvec3, false);
    cout << "Position 2 in setvec3: " << setvec3[2] << endl;
    setvec3.Clear();
    Size(loctestnum, loctesterr, setvec3, true, 0);
    lasd::Vector<string> vec1(5);
    SetAt(loctestnum, loctesterr, vec1, true, 0, string("5"));
    SetAt(loctestnum, loctesterr, vec1, true, 1, string("4"));
    SetAt(loctestnum, loctesterr, vec1, true, 2, string("3"));   
    SetAt(loctestnum, loctesterr, vec1, true, 3, string("2"));
    SetAt(loctestnum, loctesterr, vec1, true, 4, string("1"));
    lasd::SetVec<string> setvec4;
    InsertAllC(loctestnum, loctesterr, setvec4, true, vec1);
    Traverse(loctestnum, loctesterr, setvec4, true, TraversePrint<string>);
    PredecessorNRemove(loctestnum, loctesterr, setvec4, true, string("5"), string("4"));
    Traverse(loctestnum, loctesterr, setvec4, true, TraversePrint<string>);
    RemovePredecessor(loctestnum, loctesterr, setvec4, true, string("9"));
    Traverse(loctestnum, loctesterr, setvec4, true, TraversePrint<string>);
    RemovePredecessor(loctestnum, loctesterr, setvec4, false, string("1"));
    Traverse(loctestnum, loctesterr, setvec4, true, TraversePrint<string>);
    GetFront(loctestnum, loctesterr, setvec4, true, string("1"));
    GetBack(loctestnum, loctesterr, setvec4, true, string("3"));
    TraversePreOrder(loctestnum, loctesterr, setvec4, true, TraversePrint<string>);
    TraversePostOrder(loctestnum, loctesterr, setvec4, true, TraversePrint<string>);
    setvec4.Clear();
    Empty(loctestnum, loctesterr, setvec4, true);
    GetFront(loctestnum, loctesterr, setvec4, false, string("1"));
    GetBack(loctestnum, loctesterr, setvec4, false, string("3"));
  }
  catch(...)
  {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My SetVec<String> Test! (Errors/Tests: " << loctesterr << "/"
  << loctestnum << ")" << endl;

  cout << endl << "Begin of My SetLst<int> Test:" << endl;
  try
  {
    lasd::SetLst<int> setlst11;
    Empty(loctestnum, loctesterr, setlst11, true);
    lasd::SetLst<int> setlst12;
    InsertM(loctestnum, loctesterr, setlst12, true, 4);
    InsertM(loctestnum, loctesterr, setlst12, true, 8);
    InsertM(loctestnum, loctesterr, setlst12, true, 33);
    InsertM(loctestnum, loctesterr, setlst12, true, 6);
    InsertM(loctestnum, loctesterr, setlst12, true, 5);
    Traverse(loctestnum, loctesterr, setlst12, true, TraversePrint<int>);
    setlst11 = setlst12;
    Empty(loctestnum, loctesterr, setlst11, false);
    EqualSetLst(loctestnum, loctesterr, setlst11, setlst12, true);
    Predecessor(loctestnum, loctesterr, setlst11, false, 1, 1);
    Remove(loctestnum, loctesterr, setlst11, true, 8);
    InsertC(loctestnum, loctesterr, setlst11, true, 2);
    Traverse(loctestnum, loctesterr, setlst11, true, TraversePrint<int>);
    lasd::List<int> lst1;
    InsertAtBack(loctestnum, loctesterr, lst1, true, 27);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 89);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 6);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 11);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 11);
    InsertAtBack(loctestnum, loctesterr, lst1, true, 33);
    InsertSomeC(loctestnum, loctesterr, setlst11, true, lst1);
    Traverse(loctestnum, loctesterr, setlst11, true, TraversePrint<int>);
    RemoveAll(loctestnum, loctesterr, setlst11, false, lst1);
    Traverse(loctestnum, loctesterr, setlst11, true, TraversePrint<int>);
    lasd::Vector<int> vec6(2);
    SetAt(loctestnum, loctesterr, vec6, true, 0, 4);
    SetAt(loctestnum, loctesterr, vec6, true, 1, 2);
    RemoveSome(loctestnum, loctesterr, setlst11, true, vec6);
    vec6.Resize(3);
    SetAt(loctestnum, loctesterr, vec6, true, 2, 5);
    InsertC(loctestnum, loctesterr, setlst11, true, 4);
    InsertC(loctestnum, loctesterr, setlst11, true, 2);
    RemoveAll(loctestnum, loctesterr, setlst11, true, vec6);
    Traverse(loctestnum, loctesterr, setlst11, true, TraversePrint<int>);
    RemoveSome(loctestnum, loctesterr, setlst11, false, vec6);
  }
  catch(...)
  {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My SetLst<int> Test! (Errors/Tests: " << loctesterr << "/"
  << loctestnum << ")" << endl;
  
  cout << endl << "Begin of My SetLst<string> Test:" << endl;
  try
  {
    lasd::SetLst<string> setlst1;
    InsertC(loctestnum, loctesterr, setlst1, true, string("E"));
    InsertC(loctestnum, loctesterr, setlst1, true, string("A"));
    InsertC(loctestnum, loctesterr, setlst1, true, string("D"));
    InsertC(loctestnum, loctesterr, setlst1, true, string("C"));
    InsertC(loctestnum, loctesterr, setlst1, true, string("B"));
    Traverse(loctestnum, loctesterr, setlst1, true, TraversePrint<string>);
    Remove(loctestnum, loctesterr, setlst1, true, string("C"));
    Traverse(loctestnum, loctesterr, setlst1, true, TraversePrint<string>);
    Exists(loctestnum, loctesterr, setlst1, false, string("F"));
    Exists(loctestnum, loctesterr, setlst1, true, string("D"));
    FoldPreOrder(loctestnum, loctesterr, setlst1, true, FoldAdd<string>, string("!"), string("!ABDE"));
    Size(loctestnum, loctesterr, setlst1, true, 4);
    lasd::SetLst<string> setlst2;
    setlst2 = setlst1;
    Empty(loctestnum, loctesterr, setlst2, false);
    EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);
    setlst2.Clear();
    Size(loctestnum, loctesterr, setlst2, true, 0);
    Min(loctestnum, loctesterr, setlst2, false, string("A"));
    MinNRemove(loctestnum, loctesterr, setlst2, false, string("A"));
    RemoveMin(loctestnum, loctesterr, setlst2, false);
    Max(loctestnum, loctesterr, setlst2, false, string("A"));
    MaxNRemove(loctestnum, loctesterr, setlst2, false, string("A"));
    RemoveMax(loctestnum, loctesterr, setlst2, false);
    Predecessor(loctestnum, loctesterr, setlst2, false, string("A"), string("A"));
    PredecessorNRemove(loctestnum, loctesterr, setlst2, false, string("A"), string("A"));
    RemovePredecessor(loctestnum, loctesterr, setlst2, false, string("A"));
    Successor(loctestnum, loctesterr, setlst2, false, string("A"), string("A"));
    SuccessorNRemove(loctestnum, loctesterr, setlst2, false, string("A"), string("A"));
    RemoveSuccessor(loctestnum, loctesterr, setlst2, false, string("A"));
    InsertC(loctestnum, loctesterr, setlst2, true, string("A"));
    InsertC(loctestnum, loctesterr, setlst2, true, string("B"));
    InsertC(loctestnum, loctesterr, setlst2, true, string("C"));
    PredecessorNRemove(loctestnum, loctesterr, setlst2, true, string("B"), string("A"));
    InsertC(loctestnum, loctesterr, setlst2, true, string("A"));
    RemovePredecessor(loctestnum, loctesterr, setlst2, true, string("B"));
    Traverse(loctestnum, loctesterr, setlst2, true, TraversePrint<string>);
    InsertC(loctestnum, loctesterr, setlst2, true, string("A"));
    RemovePredecessor(loctestnum, loctesterr, setlst2, true, string("G"));
    InsertC(loctestnum, loctesterr, setlst2, true, string("C"));
    PredecessorNRemove(loctestnum, loctesterr, setlst2, true, string("G"), string("C"));
    lasd::Vector<string> vec1(5);
    SetAt(loctestnum, loctesterr, vec1, true, 0, string("C"));
    SetAt(loctestnum, loctesterr, vec1, true, 1, string("C"));
    SetAt(loctestnum, loctesterr, vec1, true, 2, string("C")); 
    SetAt(loctestnum, loctesterr, vec1, true, 3, string("C"));
    SetAt(loctestnum, loctesterr, vec1, true, 4, string("C"));
    InsertAllC(loctestnum, loctesterr, setlst2, false, vec1);
    Remove(loctestnum, loctesterr, setlst2, true, string("C"));
    InsertSomeM(loctestnum, loctesterr, setlst2, true, std::move(vec1));
    Traverse(loctestnum, loctesterr, setlst2, true, TraversePrint<string>);
    Successor(loctestnum, loctesterr, setlst2, true, string("!"), string("A"));
    SuccessorNRemove(loctestnum, loctesterr, setlst2, true, string("!"), string("A"));
    InsertM(loctestnum, loctesterr, setlst2, true, string("A"));
    RemoveSuccessor(loctestnum, loctesterr, setlst2, true, string("!"));
    InsertC(loctestnum, loctesterr, setlst2, true, string("A"));
    Traverse(loctestnum, loctesterr, setlst2, true, TraversePrint<string>);
    FoldPreOrder(loctestnum, loctesterr, setlst2, true, FoldAdd<string>, string("!"), string("!ABC"));
    RemoveSuccessor(loctestnum, loctesterr, setlst2, true, string("B"));
    InsertM(loctestnum, loctesterr, setlst2, true, string("C"));
    SuccessorNRemove(loctestnum, loctesterr, setlst2, true, string("B"), string("C"));
    InsertM(loctestnum, loctesterr, setlst2, true, string("C"));
    setlst2.Clear();
    Size(loctestnum, loctesterr, setlst2, true, 0);
    lasd::SetLst<string> setlst3;
    InsertM(loctestnum, loctesterr, setlst3, true, string("A"));
    InsertM(loctestnum, loctesterr, setlst3, true, string("B"));
    InsertM(loctestnum, loctesterr, setlst3, true, string("C"));
    InsertM(loctestnum, loctesterr, setlst3, true, string("D"));
    InsertM(loctestnum, loctesterr, setlst3, true, string("E"));
    Exists(loctestnum, loctesterr, setlst3, true, string("A"));
    Exists(loctestnum, loctesterr, setlst3, true, string("E"));
    Exists(loctestnum, loctesterr, setlst3, true, string("C"));
    Exists(loctestnum, loctesterr, setlst3, false, string("F"));
    FoldPreOrder(loctestnum, loctesterr, setlst3, true, FoldAdd<string>, string("!"), string("!ABCDE"));
    FoldPostOrder(loctestnum, loctesterr, setlst3, true, FoldAdd<string>, string("EX33"), string("EX33EDCBA"));
  }
  catch(...)
  {
    loctestnum++;
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of My SetLst<string> Test! (Errors/Tests: " << loctesterr << "/"
  << loctestnum << ")" << endl;

  cout << endl << "Begin of SetLst<double> Test" << endl;
  try {
    lasd::List<double> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, 4.0);
    InsertAtBack(loctestnum, loctesterr, lst, true, 0.4);
    InsertAtFront(loctestnum, loctesterr, lst, true, 1.2);
    InsertAtBack(loctestnum, loctesterr, lst, true, 2.1);
    InsertAtFront(loctestnum, loctesterr, lst, true, 3.5);
    InsertAtBack(loctestnum, loctesterr, lst, true, 5.3);
    TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

    lasd::SetLst<double> setlst1(lst);
    Empty(loctestnum, loctesterr, setlst1, false);
    Size(loctestnum, loctesterr, setlst1, true, 6);
    TraversePreOrder(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);

    lasd::SetLst<double> setlst2;
    InsertC(loctestnum, loctesterr, setlst2, true, 2.1);
    InsertC(loctestnum, loctesterr, setlst2, true, 0.4);
    InsertC(loctestnum, loctesterr, setlst2, true, 1.2);
    InsertC(loctestnum, loctesterr, setlst2, true, 3.5);
    InsertC(loctestnum, loctesterr, setlst2, true, 5.3);
    InsertC(loctestnum, loctesterr, setlst2, true, 4.0);
    EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);
    NonEqualSetLst(loctestnum, loctesterr, setlst1, setlst2, false);
    setlst1.Clear();
    setlst2.Clear();
    InsertC(loctestnum, loctesterr, setlst1, true, 0.2);
    InsertC(loctestnum, loctesterr, setlst1, true, 1.1);
    InsertC(loctestnum, loctesterr, setlst1, true, 2.1);
    InsertC(loctestnum, loctesterr, setlst2, true, 2.1);
    InsertC(loctestnum, loctesterr, setlst2, true, 1.1);
    InsertC(loctestnum, loctesterr, setlst2, true, 0.2);
    EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);
    NonEqualSetLst(loctestnum, loctesterr, setlst1, setlst2, false);

    lasd::SetLst<double> setlstA, setlstB;
    setlstB = setlst1;  
    InsertAllC(loctestnum, loctesterr, setlstA, true, setlstB);
    EqualSetLst(loctestnum, loctesterr, setlstA, setlstB, true);
    NonEqualSetLst(loctestnum, loctesterr, setlstA, setlstB, false);

    lasd::SetLst<double> setlstC, setlstD;
    setlstC = setlstA;
    InsertC(loctestnum, loctesterr, setlstD, true, 1.1);
    InsertC(loctestnum, loctesterr, setlstD, true, 2.1);
    InsertC(loctestnum, loctesterr, setlstD, true, 3.3);  
    InsertSomeC(loctestnum, loctesterr, setlstC, true, setlstD);
    Exists(loctestnum, loctesterr, setlstC, true, 3.3);
    NonEqualSetLst(loctestnum, loctesterr, setlstC, setlstA, true);
    RemoveSome(loctestnum, loctesterr, setlstC, true, setlstD);
    Exists(loctestnum, loctesterr, setlstC, false, 1.1);
    Exists(loctestnum, loctesterr, setlstC, false, 2.1);
    Exists(loctestnum, loctesterr, setlstC, false, 3.3);
    Exists(loctestnum, loctesterr, setlstC, true, 0.2);
    InsertAllC(loctestnum, loctesterr, setlstC, true, setlstD);
    RemoveAll(loctestnum, loctesterr, setlstC, true, setlstD);
    EqualSetLst   (loctestnum, loctesterr, setlstC, setlstD, false);

    lasd::SetLst<double> setlstE = setlstB;  
    RemoveMin(loctestnum, loctesterr, setlstE, true);  
    Min(loctestnum, loctesterr, setlstE, true, 1.1);
    RemoveMax(loctestnum, loctesterr, setlstE, true);    
    Max(loctestnum, loctesterr, setlstE, true, 1.1);
    setlstE = setlstB; 
    RemovePredecessor(loctestnum, loctesterr, setlstE, true, 1.1); 
    Exists(loctestnum, loctesterr, setlstE, false, 0.2);
    setlstE = setlstB;
    RemoveSuccessor(loctestnum, loctesterr, setlstE, true, 1.1);  
    Exists(loctestnum, loctesterr, setlstE, false, 2.1);
    setlstE = setlstB; 
    RemoveMin(loctestnum, loctesterr, setlstE, true);
    RemoveMin(loctestnum, loctesterr, setlstE, true);
    Min(loctestnum, loctesterr, setlstE, true, 2.1);
    setlstE = setlstB;  
    RemoveMax(loctestnum, loctesterr, setlstE, true);
    RemoveMax(loctestnum, loctesterr, setlstE, true);
    Max(loctestnum, loctesterr, setlstE, true, 0.2);

    lasd::SetVec<double> setvec111;
    InsertC(loctestnum, loctesterr, setvec111, true, 0.2);
    InsertC(loctestnum, loctesterr, setvec111, true, 1.1);
    InsertC(loctestnum, loctesterr, setvec111, true, 2.1);
    InsertC(loctestnum, loctesterr, setvec111, true, 3.3);
    InsertC(loctestnum, loctesterr, setvec111, true, 4.4);
    InsertC(loctestnum, loctesterr, setvec111, true, 5.5);
    InsertC(loctestnum, loctesterr, setvec111, true, 6.6);
    Traverse(loctestnum, loctesterr, setvec111, true, TraversePrint<double>);
    PredecessorNRemove(loctestnum, loctesterr, setvec111, true, 1.0, 0.2);
    Traverse(loctestnum, loctesterr, setvec111, true, TraversePrint<double>);
  }
  catch (...) {
    loctestnum++; 
    loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of SetLst<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  
}

/* ************************************************************************** */


