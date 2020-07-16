#include <dirent.h>
#include <unistd.h>

#include <string>
#include <vector>

#include "linux_parser.h"
using std::stof;

using std::stoi;
using std::stol;
using std::string;
using std::to_string;
using std::vector;
// DONE: An example of how to read data from the filesystem
string
LinuxParser::OperatingSystem()
{
	string line;
	string key;
	string value;
	std::ifstream filestream(kOSPath);
	if (filestream.is_open()) {
		while (std::getline(filestream, line)) {
			std::replace(line.begin(), line.end(), ' ', '_');
			std::replace(line.begin(), line.end(), '=', ' ');
			std::replace(line.begin(), line.end(), '"', ' ');
			std::istringstream linestream(line);
			while (linestream >> key >> value) {
				if (key == "PRETTY_NAME") {
					std::replace(value.begin(), value.end(), '_', ' ');
					return value;
				}
			}
		}
	}
	return value;
}

// DONE: An example of how to read data from the filesystem
string
LinuxParser::Kernel()
{
	string os, version, kernel;
	string line;
	std::ifstream stream(kProcDirectory + kVersionFilename);
	if (stream.is_open()) {
		std::getline(stream, line);
		std::istringstream linestream(line);
		linestream >> os >> version >> kernel;
	}
	return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int>
LinuxParser::Pids()
{
	vector<int> pids;
	DIR* directory = opendir(kProcDirectory.c_str());
	struct dirent* file;
	while ((file = readdir(directory)) != nullptr) {
		// Is this a directory?
		if (file->d_type == DT_DIR) {
			// Is every character of the name a digit?
			string filename(file->d_name);
			if (std::all_of(filename.begin(), filename.end(), isdigit)) {
				int pid = stoi(filename);
				pids.push_back(pid);
			}
		}
	}
	closedir(directory);
	return pids;
}

// TODO: Read and return the system memory utilization
float
LinuxParser::MemoryUtilization()
{
	string memory;
	float n_memory, total_memory, memory_free;
	string line;
	std::ifstream stream(kProcDirectory + kMeminfoFilename);
	if (stream.is_open()) {
		std::getline(stream, line);
		std::istringstream linestream(line);
		linestream >> memory >> n_memory;
		if (memory == "MemTotal:")
			total_memory = n_memory;
		if (memory == "MemFree:")
			memory_free = n_memory;
	}
	std::cout << total_memory << memory_free "\n";
	return ((total_memory - memory_free) / total_memory);
}

// DONE: Read and return the system uptime
long
LinuxParser::UpTime()
{
	string uptime, uptime_idle;
	string line;
	std::ifstream stream(kProcDirectory + kUptimeFilename);
	if (stream.is_open()) {
		std::getline(stream, line);
		std::istringstream linestream(line);
		linestream >> uptime >> uptime_idle;
	}
	return stol(uptime);
}

// TODO: Read and return the number of jiffies for the system
long
LinuxParser::Jiffies()
{
	return 0;
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long
LinuxParser::ActiveJiffies(int pid [[maybe_unused]])
{
	return 0;
}

// TODO: Read and return the number of active jiffies for the system
long
LinuxParser::ActiveJiffies()
{
	return 0;
}

// TODO: Read and return the number of idle jiffies for the system
long
LinuxParser::IdleJiffies()
{
	return 0;
}

// TODO: Read and return CPU utilization
vector<string>
LinuxParser::CpuUtilization()
{
	return {};
}

// TODO: Read and return the total number of processes
int
LinuxParser::TotalProcesses()
{
	string total_process;
	int n_proc;
	string line;
	std::ifstream stream(kProcDirectory + kStatFilename);
	if (stream.is_open()) {
		std::getline(stream, line);
		std::istringstream linestream(line);
		linestream >> total_process >> n_proc;
		if (total_process == "processes")
			return n_proc;
	}
	return n_proc;
}

// TODO: Read and return the number of running processes
int
LinuxParser::RunningProcesses()
{
	string proc_running;
	int n_proc;
	string line;
	std::ifstream stream(kProcDirectory + kStatFilename);
	if (stream.is_open()) {
		std::getline(stream, line);
		std::istringstream linestream(line);
		linestream >> proc_running >> n_proc;
		if (proc_running == "procs_running")
			return n_proc;
	}
	return n_proc;
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string
LinuxParser::Command(int pid [[maybe_unused]])
{
	return string();
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string
LinuxParser::Ram(int pid [[maybe_unused]])
{
	return string();
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string
LinuxParser::Uid(int pid [[maybe_unused]])
{
	return string();
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string
LinuxParser::User(int pid [[maybe_unused]])
{
	return string();
}

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long
LinuxParser::UpTime(int pid [[maybe_unused]])
{
	return 0;
}