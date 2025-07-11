/**
 * @file comp_compare.h
 * @author TeslaRam https://github.com/TeslaRam
 * @brief Data structures for comparation of 2TSort and other sorting algorithms
 * @date 11.7.25
 * @see https://github.com/TeslaRam/2TSort
 */

#pragma once
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "comp_generation.h"
#include "comp_setup_cleanup.h"
#include "comp_sorts.h"

using namespace std;

using Duration = chrono::duration<double, milli>;
using SortFun = function<void(vector<int>&)>;

/**
 * @brief Durations of sorting algorithm
 * @param random_numbers Random numbers
 * @param ordered Ordered ascending
 * @param reversed Ordered descending
 */
struct AlgoTimes {
   Duration random_numbers;
   Duration ordered;
   Duration reversed;
};

/**
 * @brief Data for specific sorting algorithm
 * @param name Name of algorithm
 * @param exec Function to sort algorithm
 * @param times Durations of specific types
 */
struct SortAlgoData {
   string name;
   SortFun exec;
   AlgoTimes times;

   SortAlgoData(const string& n, const SortFun& e, const AlgoTimes& t)
       : name(n), exec(e), times(t) {}
};

/**
 * @brief Type of generated numbers for sort algorithm
 * @param title Name of generator
 * @param generator Generator function
 * @param duration How many ms it took to sort
 */
struct SortType {
   string title;
   SortFun generator;
   Duration AlgoTimes::* duration;
};

/**
 * @brief Print results table into "comp_out.txt" with stdout as fallback
 * @param sortsData Data of measured durations of each sort
 */
void printResults(vector<SortAlgoData> sortsData);

/**
 * @brief Print emoji on start and end of whole process
 * @param emoji Emoji to print
 */
void printWholeIndicator(string emoji);