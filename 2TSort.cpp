/**
 * @file 2TSort.cpp
 * @author TeslaRam https://github.com/TeslaRam
 * @brief Sorting algorithm
 * @date 10.7.25
 * @see https://github.com/TeslaRam/SORTs
 */

#include <iostream>

using namespace std;

/** How many elements to sort */
#define n 1000

/** Array that stores sorted elements */
int toSort[n];

/** Generate random values (1 .. 1000) into [toSort] */
void generate() {
   for (int j = 0; j < n; j++) {
      toSort[j] = rand() % 1000 + 1;  // visualy separate input and output
   }
}

/** Print all elements inside [toSort] */
void print() {
   cout << endl;

   for (int i = 0; i < n; i++) {
      cout << toSort[i] << " ";
   }

   cout << endl;
}

/** sort [toSort] array using 2TSort algorithm */
void sort() {
   while (true) {  // while changes happened
      bool changed = false;

      for (int i = 0; i < n - 1; i++) {          // loop every element
         if (toSort[i] > toSort[i + 1]) {        // if next element is smaller
            int focusedElement = toSort[i + 1];  // save it

            // shift right elements from start to current
            for (int j = (i + 1); j > 0; j--) {
               toSort[j] = toSort[j - 1];
            }

            toSort[0] = focusedElement;  // put saved element to start

            changed = true;  // change happened
         }
      }

      if (!changed) break;  // if nothing changes, array is sorted
   }
}

int main() {
   generate();
   print();

   sort();

   print();

   return 0;
}
