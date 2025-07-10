/**
 * @file compare.cpp
 * @author TeslaRam https://github.com/TeslaRam
 * @brief Comparation for 2TSort
 * @date 10.7.25
 * @see https://github.com/TeslaRam/2TSort
 */

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/** Array that stores sorted elements */
vector<int> toSort;

////////////////////////////////
/////////// GENERATE ///////////

void generateRandom() {
   for (int &i : toSort) i = rand() % toSort.size() + 1;
}

void generateOrdered() {
   for (int i = 0; i < toSort.size(); i++) toSort[i] = i;
}

void generateReversed() {
   for (int i = 0; i < toSort.size(); i++) toSort[i] = toSort.size() - i;
}

/////////// GENERATE ///////////
////////////////////////////////
///////// SET - CLEAN //////////

/** Parse program args and set [toSort] size  */
void setSortSize(int argc, char *argv[]) {
   try {
      if (argc != 2) throw invalid_argument("argc != 2");

      int size = stoi(argv[1]);

      if (size < 1) throw invalid_argument("not int or is not > 1");

      toSort.resize(size);
   } catch (const exception &e) {
      cout << "Error: " << e.what() << endl;
      exit(1);
   }
}

///////// SET - CLEAN //////////
////////////////////////////////
//////////// SORTS /////////////

void _2TSort() {
   while (true) {
      bool changed = false;

      for (size_t i = 0; i < toSort.size() - 1; i++) {
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

//////////// SORTS /////////////
////////////////////////////////
//////////// MAIN //////////////

int main(int argc, char *argv[]) {
   srand(time(nullptr));

   generateRandom();

   auto start = chrono::high_resolution_clock::now();
   _2TSort();
   auto end = chrono::high_resolution_clock::now();

   chrono::duration<double, milli> duration = end - start;
   cout << "Time elapsed: " << duration.count() << " ms\n";

   return 0;
}
