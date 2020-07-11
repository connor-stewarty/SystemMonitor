#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {
  CpuUtilization();
}

// DONE: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const {
  string key;
  string line;
  std::ifstream filestream(LinuxParser::kProcDirectory + to_string(pid_) +
                           LinuxParser::kStatFilename);
  if (filestream.is_open()) {
    int utime = 0;
    int stime = 0;
    int cutime = 0;
    int cstime = 0;
    float starttime = 0;
    float totaltime = 0;
    float seconds = 0;
    for (int i = 0; filestream >> key; i++) {
      if (i == 12) { //coresponds to 14th position
        filestream >> utime >> stime >> cutime >> cstime; // >> 14 >> 15 >> 16 >> 17 
        break;
      }
    }
    for (int j = 0; filestream >> key; j++) {
      if (j == 3) { //coresponds to 22nd position
        filestream >> starttime; // >> 22
        break;
      }
    }
    totaltime = (float)(utime + stime + cutime + cstime);
    seconds = LinuxParser::UpTime() - starttime / sysconf(_SC_CLK_TCK);
    return (totaltime / sysconf(_SC_CLK_TCK)) / seconds;
  }
  return 0;
}

// DONE: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(Pid()); }

// DONE: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(Pid()); }

// DONE: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(Pid()); }

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(Pid()); }

// DONE: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(const Process& a) const {
  return CpuUtilization() < a.CpuUtilization();
}