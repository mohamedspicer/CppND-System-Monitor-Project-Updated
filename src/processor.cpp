#include <iostream>
#include <string>
#include <unistd.h>

#include "linux_parser.h"
#include "processor.h"
using std::string;

// TODO: Return the aggregate CPU utilization
float
Processor::Utilization()
{
	string cpu, prevcpu;
	string line;
	long user, nice, system, idle, iowait, irq, softirq, steal, guest,
	  guest_nice;

	long prevuser, prevnice, prevsystem, previdle, previowait, previrq, prevsoftirq, prevsteal, prevguest,
	  prevguest_nice;
	std::ifstream stream(LinuxParser::kProcDirectory +
						 LinuxParser::kStatFilename);
	if (stream.is_open()) {
		std::getline(stream, line);
		std::istringstream linestream(line);
		linestream >> prevcpu >> prevuser >> prevnice >> prevsystem >> previdle >> previowait >> previrq >>
		  prevsoftirq >> prevsteal >> prevguest >> prevguest_nice;
	}
	stream.close();
	usleep(5000);
	stream.open()
	if (stream.is_open()) {
		std::getline(stream, line);
		std::istringstream linestream(line);
		linestream >> cpu >> user >> nice >> system >> idle >> iowait >> irq >>
		  softirq >> steal >> guest >> guest_nice;
	}
	long PrevIdle = previdle + previowait;
	long Idle	  = idle + iowait;
	long PrevNonIdle =
	  prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
	long NonIdle		= user + nice + system + irq + softirq + steal;
	long PrevTotal		= PrevIdle + PrevNonIdle;
	long Total			= Idle + NonIdle;
	long totald			= Total - PrevTotal;
	long idled			= Idle - PrevIdle;
	long CPU_Percentage = (totald - idled) / totald;
	std::cout << CPU_Percentage << "\n";
	return CPU_Percentage;
}