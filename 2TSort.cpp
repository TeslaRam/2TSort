/**
 * @file 2TSort.cpp
 * @author TeslaRam https://github.com/TeslaRam
 * @brief Sorting algorithm
 * @date 10.7.25
 * @see https://github.com/TeslaRam/SORTs
 */

#include <iostream>

using namespace std;

#define n 1000

int toSort[n];

/** Generate random values into [toSort] */
void generate() {
   for (int j = 0; j < n; j++) {
      toSort[j] = rand() % 1000 + 1;
   }
}

/** Print all elements inside [toSort], splitted by space */
void print() {
   for (int i = 0; i < n; i++) {
      cout << toSort[i] << " ";
   }
   cout << endl;
}

int main() {
   generate();
   print();

   while (true) {
      bool changed = false;

      for (int i = 0; i < n - 1; i++) {
         if (toSort[i] > toSort[i + 1]) {
            int c = toSort[i + 1];

            for (int j = (i + 1); j > 0; j--) {
               toSort[j] = toSort[j - 1];
            }
            toSort[0] = c;

            changed = true;
         }
      }

      if (!changed) break;
   }

   cout << endl;
   print();

   return 0;
}
