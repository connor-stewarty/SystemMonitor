#include "format.h"

#include <iostream>
#include <string>

using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  long hours, minutes;
  hours = seconds / 3600;
  seconds = seconds % 3600;
  minutes = seconds / 60;
  seconds = seconds % 60;
  string SS = std::to_string(seconds);
  SS.insert(0, 2 - SS.length(), '0');
  string MM = std::to_string(minutes);
  MM.insert(0, 2 - MM.length(), '0');
  string HH = std::to_string(hours);
  HH.insert(0, 2 - HH.length(), '0');
  return (HH + ":" + MM + ":" + SS);
}
