#include "processor.h"

#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  string cpu, line;
  float cpuUser, cpuNice, cpuSystem, cpuIdle;
  std::ifstream filestream("/proc/stat");
  if (filestream.is_open()) {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> cpu >> cpuUser >> cpuNice >> cpuSystem >> cpuIdle;
  }
  return (cpuUser + cpuNice + cpuSystem) /
         (cpuUser + cpuNice + cpuSystem + cpuIdle);
}