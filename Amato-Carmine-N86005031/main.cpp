
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
    std::cout << "3. Esegui entrambi i test" << std::endl;
    std::cout << "0. Esci" << std::endl;
    std::cout << "\nScegli un'opzione (0-3): ";
    
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
        mytest();
        break;
      case 3:
        std::cout << "\n=== Esecuzione entrambi i test ===\n" << std::endl;
        std::cout << "\n--- Esecuzione lasdtest---\n" << std::endl;
        lasdtest();
        std::cout << "\n--- Esecuzione mytest ---\n" << std::endl;
        mytest();
        break;
      default:
        std::cout << "Opzione non valida! Scegli un numero tra 0 e 3.\n" << std::endl;
    }
  }
  
  return 0;
}
