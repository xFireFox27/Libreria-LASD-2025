
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>
#include <limits>

/* ************************************************************************** */

int main() {
  std::cout << "LASD Libraries 2025" << std::endl;
  
  int scelta;
  bool continua = true;
  
  while (continua) {
    std::cout << "\nMenu Test:" << std::endl;
    std::cout << "1. Esegui lasdtest" << std::endl;
    std::cout << "2. Esegui mytest" << std::endl;
    std::cout << "3. Esegui mytest2" << std::endl;
    std::cout << "4. Esegui tutti i test" << std::endl;
    std::cout << "0. Esci" << std::endl;
    std::cout << "\nScegli un'opzione (0-4): ";
    
    if (!(std::cin >> scelta)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Input non valido! Inserire un numero.\n" << std::endl;
      continue;
    }
    
    switch (scelta) {
      case 0:
        std::cout << "Uscita...\n" << std::endl;
        continua = false;
        break;
      case 1:
        std::cout << "\n=== Esecuzione lasdtest ===\n" << std::endl;
        lasdtest();
        break;
      case 2:
        std::cout << "\n=== Esecuzione mytest ===\n" << std::endl;
        mytest::mytest();
        break;
      case 3:
        std::cout << "\n=== Esecuzione mytest2 ===\n" << std::endl;
        mytest::mytest2();
        break;
      case 4:
        std::cout << "\n=== Esecuzione tutti i test ===\n" << std::endl;
        std::cout << "\n--- Esecuzione lasdtest---\n" << std::endl;
        lasdtest();
        std::cout << "\n--- Esecuzione mytest ---\n" << std::endl;
        mytest::mytest();
        std::cout << "\n--- Esecuzione mytest2 ---\n" << std::endl;
        mytest::mytest2();
        break;
      default:
        std::cout << "Opzione non valida! Scegli un numero tra 0 e 4.\n" << std::endl;
    }
  }
  
  return 0;
}
