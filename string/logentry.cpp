//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        3/12/24
// Author:      Troy Sellman
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>


// REQUIRES: dateParts to be a vector where the indices are:
// index: 0 - day,  1 - month, 2 - year
Date::Date(std::vector<String> dateParts) {
    if (dateParts.size() == 3) {
        day   = (dateParts[0]).substr(1, dateParts[0].length() - 1);
        month = dateParts[1];
        year  = dateParts[2];
    }
}

// REQUIRES: timeParts to be a vector where the indices are:
// index: 0 - dateParts,  1 - hour, 2 - minute, 3 - second
Time::Time(std::vector<String> timeParts) {
    if (timeParts.size() == 4) {
        hour   = timeParts[1];
        minute = timeParts[2];
        second = timeParts[3];
    }
}

int LogEntry::byteConverter(const String& byteStr) {
    int result = 0;
    int i = 0;
    while (i < byteStr.length()) {
        result += byteStr[i] - '0';
        if (i + 1 != byteStr.length()) result = result * 10;
        ++i;
    }
    return result;
}

// REQUIRES:
// ENSURES:
LogEntry::LogEntry(const String& line) {
    //Use split to create LogEntry
    std::vector<String> logEntryParts = line.split(' ');
    // index: 0 - host, 3 - timeParts, 5+6 - request,
    //  8 - status, 9 - # of bytes
    if (logEntryParts.size() == 10) {
        std::vector<String> timeParts = logEntryParts[3].split(':');
        // index: 0 - dateParts, 1 - hour,  2 - minute, 3 - second
        std::vector<String> dateParts = timeParts[0].split('/');
        // index: 0 - day,  1 - month, 2 - year 
        host    = logEntryParts[0];
        date    = Date(dateParts);
        time    = Time(timeParts);
        request = (logEntryParts[5] + " " + logEntryParts[6]).substr(1, (logEntryParts[5] + " " + logEntryParts[6]).length() - 1);
        status  = logEntryParts[8]; 
        if (logEntryParts[9] == '-') number_of_bytes = 0;
        else number_of_bytes = byteConverter(logEntryParts[9]);
    }
}


// REQUIRES:
// ENSURES:
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    char line[500];
    in.getline(line, 500);
    while(!in.eof()) {
        LogEntry log(line);
        result.push_back(log);
        in.getline(line, 500);
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const LogEntry& log) {
    out << "-------------------------------------------------------------------------" << '\n';
    out << "Host :::: " << log.host << '\n';
    out << "Date :::: " << log.date.getday()  << "/" << log.date.getmonth()  << "/" << log.date.getyear()   << '\n';
    out << "Time :::: " << log.time.gethour() << ":" << log.time.getminute() << ":" << log.time.getsecond() << '\n';
    out << "Request : " << log.request << '\n';
    out << "Status :: " << log.status << '\n';
    out << "Bytes ::: " << log.number_of_bytes << "\n";
    out << "=========================================================================" << "\n\n";
    return out;
}


// REQUIRES:
// ENSURES:
void output_all(std::ostream& out, const std::vector<LogEntry>& logs) {
    for (size_t i = 0; i < logs.size(); ++i) {
        out << logs[i];
    }
}

// REQUIRES:
// ENSURES:
void by_host(std::ostream& out, const std::vector<LogEntry>& logs) {
    for (size_t i = 0; i < logs.size(); ++i) {
        out << "Host : " << logs[i].gethost() << '\n';
    }
}

// REQUIRES:
// ENSURES:
int byte_count(const std::vector<LogEntry>& logs) {
    int sum = 0;
    for (size_t i = 0; i < logs.size(); ++i) {
        sum += logs[i].getbytes();
    }
    return sum;
}

