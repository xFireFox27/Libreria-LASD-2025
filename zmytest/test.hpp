#include <iostream>
#ifndef MYTEST_HPP
#define MYTEST_HPP
#include "../zlasdtest/pq/pq.hpp"

/* ************************************************************************** */
namespace mytest {

void mytest();
void mytest2();

template <typename Data>
void InsertMove(unsigned int& testnum, unsigned int& testerr, lasd::PQ<Data>& pq, Data&& val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " Insert on the priority queue of the value \"" << val << "\": ";
    pq.Insert(std::move(val));
    std::cout << "Correct!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
    tst = false;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void ChangeMove(unsigned int& testnum, unsigned int& testerr, lasd::PQ<Data>& pq, bool chk, unsigned long idx, Data&& val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " Change the value \"" << pq[idx] << "\" at index << \"" << idx << "\" to the value \"" << val << "\" in the priority queue: ";
    pq.Change(idx, std::move(val));
    std::cout << "Correct!" << std::endl;
  }
  catch (std::out_of_range & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
    tst = false;
  }
  testerr += (1 - (uint) tst);
}

template <typename Data>
void ChangeCopy(unsigned int& testnum, unsigned int& testerr, lasd::PQ<Data>& pq, bool chk, unsigned long idx, const Data& val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " Change the value \"" << pq[idx] << "\" at index << \"" << idx << "\" to the value \"" << val << "\" in the priority queue: ";
    pq.Change(idx, val);
    std::cout << "Correct!" << std::endl;
  }
  catch (std::out_of_range & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
    tst = false;
  }
  testerr += (1 - (uint) tst);
}

/* ************************************************************************** */

}

#endif
