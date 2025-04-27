/* 
Casey Rose - CS310
Assignment Title: Week 7 Discussion - Simple 2D Array Program with Errors
*/

#include <iostream>
#include <string>

int main() {
  int myArray[3][2] = {{1, 2}, {3, 4}, {5, 6}};

  for (int i = 0; i < 3; i++) { // Instead of i <= 3 use i < 3
    for (int j = 0; j < 2; j++) {
      std::cout << myArray[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
