#include <string>
#include <iomanip>

#include "format.h"

using std::string;
// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string
Format::ElapsedTime(long seconds [[maybe_unused]])
{
	long h, m, s;
	h		 = seconds / 3600;
	seconds	 = seconds % 3600;
	m		 = seconds / 60;
	seconds	 = seconds % 60;
	s		 = seconds;
	string s = str(format("%2% %2% %1%\n") % "world" % "hello");
	return s;
}