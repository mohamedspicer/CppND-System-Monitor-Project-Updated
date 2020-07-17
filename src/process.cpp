#include <cctype>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

#include "process.h"
#include <linux_parser.h>

using std::stol;
using std::string;
using std::to_string;
using std::vector;

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
	return LinuxParser::Command(Process::Pid());
}

// TODO: Return this process's memory utilization
string
Process::Ram()
{
	auto vmsize	 = LinuxParser::Ram(Process::Pid());
	Process::ram = stol(vmsize);
	return vmsize;
}
long
Process::RamLast() const
{
	return Process::ram;
}

// TODO: Return the user (name) that generated this process
string
Process::User()
{
	return LinuxParser::User(Process::Pid());
}

// TODO: Return the age of this process (in seconds)
long 
Process::UpTime()
{
	return LinuxParser::UpTime(Process::Pid());
}

// DONE: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool
Process::operator<(Process const& a) const
{
	return RamLast() > a.RamLast();
}