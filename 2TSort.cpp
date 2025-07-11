/**
 * @file 2TSort.cpp
 * @author TeslaRam https://github.com/TeslaRam
 * @brief Sorting algorithm
 * @date 11.7.25
 * @see https://github.com/TeslaRam/2TSort
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/** Array that stores sorted elements */
vector<int> toSort;

////////////////////////////////////
/////////////// HELP ///////////////

/** Generate random values (1 .. n) into [toSort] */
void generate() {
   for (int &i : toSort)
      i = rand() % toSort.size() + 1;
}

/** Print all elements inside [toSort] */
void print() {
   cout << endl;
   for (int i : toSort)
      cout << i << " ";
   cout << endl;
}

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

/////////////// HELP ///////////////
////////////////////////////////////
/////////////// SORT ///////////////

/** sort [toSort] array using 2TSort algorithm */
void _2TSort() {
   while (true) {  // while change happened
      bool changed = false;

      for (size_t i = 0; i < toSort.size() - 1; i++) {  // loop every element
         if (toSort[i] > toSort[i + 1]) {               // if next element is smaller
            int focusedElement = toSort[i + 1];         // save it

            // shift right elements from start to current+1
            for (int j = i + 1; j > 0; j--) {
               toSort[j] = toSort[j - 1];
            }

            toSort[0] = focusedElement;  // put saved element to start

            changed = true;  // change happened
         }
      }

      if (!changed) break;  // if nothing changes, array is sorted
   }
}

/////////////// SORT ///////////////
////////////////////////////////////
/////////////// MAIN ///////////////

int main(int argc, char *argv[]) {
   srand(time(nullptr));

   setSortSize(argc, argv);
   generate();
   print();

   _2TSort();

   print();

   return 0;
}
