#include <chrono>
#include <iostream>

using namespace std;

#define n 10000

int toSort[n];

////////////////////////////////
/////////// GENERATE ///////////

void generateRandom() {
   for (int j = 0; j < n; j++) toSort[j] = rand() % n + 1;
}

void generateOrdered() {
   for (int j = 0; j < n; j++) toSort[j] = j;
}

void generateReversed() {
   for (int j = 0; j < n; j++) toSort[j] = n - j;
}

////////////////////////////////
/////////// GENERATE ///////////

void TSTSort() {
   while (true) {
      bool changed = false;

      for (int i = 0; i < n - 1; i++) {
         if (toSort[i] > toSort[i + 1]) {
            int focusedElement = toSort[i + 1];

            for (int j = i + 1; j > 0; j--) {
               toSort[j] = toSort[j - 1];
            }

            toSort[0] = focusedElement;

            changed = true;
         }
      }

      if (!changed) break;
   }
}

int main() {
   generateRandom();

   auto start = chrono::high_resolution_clock::now();
   TSTSort();
   auto end = chrono::high_resolution_clock::now();

   chrono::duration<double, milli> duration = end - start;
   cout << "Time elapsed: " << duration.count() << " ms\n";

   return 0;
}
