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
	double user, nice, system, idle, iowait, irq, softirq, steal, guest,
	  guest_nice;

	double prevuser, prevnice, prevsystem, previdle, previowait, previrq,
	  prevsoftirq, prevsteal, prevguest, prevguest_nice;
	std::ifstream stream(LinuxParser::kProcDirectory +
						 LinuxParser::kStatFilename);
	if (stream.is_open()) {
		std::getline(stream, line);
		std::istringstream linestream(line);
		linestream >> prevcpu >> prevuser >> prevnice >> prevsystem >>
		  previdle >> previowait >> previrq >> prevsoftirq >> prevsteal >>
		  prevguest >> prevguest_nice;
	}
	stream.close();
	usleep(5000);
	if (stream.open(LinuxParser::kProcDirectory + LinuxParser::kStatFilename)) {
		std::getline(stream, line);
		std::istringstream linestream(line);
		linestream >> cpu >> user >> nice >> system >> idle >> iowait >> irq >>
		  softirq >> steal >> guest >> guest_nice;
	}
	double PrevIdle = previdle + previowait;
	double Idle	  = idle + iowait;
	double PrevNonIdle =
	  prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
	double NonIdle		= user + nice + system + irq + softirq + steal;
	double PrevTotal		= PrevIdle + PrevNonIdle;
	double Total			= Idle + NonIdle;
	double totald			= Total - PrevTotal;
	double idled			= Idle - PrevIdle;
	double CPU_Percentage = (totald - idled) / totald;
	std::cout << CPU_Percentage << "\n";
	return CPU_Percentage;
}