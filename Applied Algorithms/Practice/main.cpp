#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

int timeToSeconds(const string& time) {
    int h, m, s;
    sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

int main() {
    vector<string> logs;
    map<string, int> call_count;
    map<string, int> total_time;
    
    string line;
    
    while (getline(cin, line) && line != "#") {
        logs.push_back(line);
        istringstream iss(line);
        string call_keyword, from_number, to_number, date, from_time, end_time;
        
        iss >> call_keyword >> from_number >> to_number >> date >> from_time >> end_time;
        
        if (call_keyword == "call") {
            call_count[from_number]++;
            
            int duration = timeToSeconds(end_time) - timeToSeconds(from_time);
            total_time[from_number] += duration;
        }
    }

    while (getline(cin, line) && line != "#") {
        istringstream iss(line);
        string query;
        iss >> query;
        
        if (query == "?check_phone_number") {
            bool valid = true;
            for (const auto & log : logs) {
                istringstream log_stream(log);
                string call_keyword, from_number, to_number;
                log_stream >> call_keyword >> from_number >> to_number;
                
                if (from_number.size() != 10 || to_number.size() != 10) {
                    valid = false;
                }
            }
            cout << (valid ? 1 : 0) << endl;
        }
        else if (query == "?number_calls_from") {
            string phone_number;
            iss >> phone_number;
            cout << call_count[phone_number] << endl;
        }
        else if (query == "?number_total_calls") {
            // Truy v?n t?ng s? cu?c g?i
            cout << logs.size() << endl;
        }
        else if (query == "?count_time_calls_from") {
            string phone_number;
            iss >> phone_number;
            cout << total_time[phone_number] << endl;
        }
    }

    return 0;
}

