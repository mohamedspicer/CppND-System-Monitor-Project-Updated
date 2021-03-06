#include <iomanip>
#include <string>

#include "format.h"

using std::setfill;
using std::setw;
using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string
Format::ElapsedTime(long seconds)
{
	long h, m, s;
	h		= seconds / 3600;
	seconds = seconds % 3600;
	m		= seconds / 60;
	seconds = seconds % 60;
	s		= seconds;
	std::stringstream ss;
	ss << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m
	   << ":" << setw(2) << setfill('0') << s;

	return ss.str();
}