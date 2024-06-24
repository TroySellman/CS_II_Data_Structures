//
// File:        logentry.hpp
//
// Version:     1.0
// Date:        3/12/24
// Author:      Troy Sellman
//
// Description: Class definition for a log entry.
//
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>

// modify this as needed
// use split function
// make logview
// ./logview all log_1_tiny.txt
// ./logview bytes log_1_tiny.txt


//BONUS POINTS DESCRIPTION:
// implemented in logview.cpp
//used map to solve the problem
// #include <map>
// add option[3] ip;
// else if (argv[1] == option[3]) {
    // only print unique items
    // use map
    // std::unordered_map<String, int> myMap;
    // iterate over hosts (IPs)
    // i = String(host)
    // myMap[i]++;
    // go through hosts, and push them into the map
    // it will only insert the ones that are not duplicated
    // if key already exists, increment int
//}
class Date {
public:
            Date() {};
            Date(std::vector<String>); 
            String getday  () const { return day; };
            String getmonth() const { return month; };
            String getyear () const { return year; };
private:
    String  day, month, year;
};

//
class Time {
  public:
            Time() {};
            Time(std::vector<String>);
            String gethour()   const { return hour; };
            String getminute() const { return minute; };
            String getsecond() const { return second; };
  private:
    String  hour, minute, second;
};


// A single log entry
class LogEntry {
public:
            LogEntry() {};
            LogEntry(const String&);
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);
            String gethost()  const { return host; };
    int     getbytes() const { return number_of_bytes; };
    int     byteConverter(const String&);
private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry>&);
void                    by_host     (std::ostream&, const std::vector<LogEntry>&);
int                     byte_count  (const std::vector<LogEntry>&);


#endif
