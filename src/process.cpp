#include <cctype>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

#include "process.h"
#include <linux_parser.h>

using std::string;
using std::to_string;
using std::vector;
using std::stol;

// TODO: Return this process's ID
int
Process::Pid()
{
	return Process::pid;
}

// TODO: Return this process's CPU utilization
float
Process::CpuUtilization()
{
	return 0;
}

// TODO: Return the command that generated this process
string
Process::Command()
{
	return LinuxParser::Command(Process::pid);
}

// TODO: Return this process's memory utilization
string
Process::Ram()
{
	return LinuxParser::Ram(Process::pid);
}

// TODO: Return the user (name) that generated this process
string
Process::User()
{
	return LinuxParser::User(Process::pid);
}

// TODO: Return the age of this process (in seconds)
long int
Process::UpTime()
{
	return LinuxParser::UpTime(Process::pid);
}

// DONE: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool
Process::operator<(Process &a)
{
	return stol(Ram()) > stol(a.Ram());
}