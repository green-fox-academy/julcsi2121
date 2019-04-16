#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> returnIP (std::ifstream& objectName);
double ratio(std::vector<std::string> logMessage);

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

int main() {

    try {
        std::ifstream log("../logs.txt");
        if (log.is_open() == 0) {
            throw std::string("error");
        } else {
            std::cout << "File opened" << std::endl;
        }

        std::vector<std::string> ipAdresses = returnIP(log);

        log.close();

        std::vector<std::string>::iterator it = ipAdresses.begin();
        for (; it < ipAdresses.end(); ++it) {
            std::cout << *it << std::endl;
        }

    } catch (std::string& e) {
        std::cerr << e << std::endl;
    }

    return 0;
}

std::vector<std::string> returnIP (std::ifstream& objectName)
{
    std::string line;
    std::vector<std::string> ipAdresses;
    std::vector<std::string> logMessage;
    while(getline(objectName, line)) {
        std::istringstream ss(line);
        std::string ip;
        int count = 0;
        std::string delimiter = "   ";

        while (getline(ss, ip, ' ')) {
            count++;
            if(count == 9) {
                ipAdresses.push_back(ip);
            } else if (count == 12) {
                logMessage.push_back(ip);
            }
        }
    //std::cout << "Ratio of get/post: " << ratioOfMessage << std::endl;

        //line.erase(0, line.find(delimiter) + delimiter.size());
        //ip = line.substr(0, line.find(delimiter));
        //ipAdresses.push_back(ip);
        //std::cout << ip << std::endl;

    }
    double ratioOfMessage = ratio(logMessage);
    std::cout << "Ratio of messages: " << ratioOfMessage << std::endl;
    return ipAdresses;
}

double ratio(std::vector<std::string> logMessage)
{
    std::vector<std::string>::iterator it = logMessage.begin();
    double post = 0;
    double get = 0;

    for (; it < logMessage.end(); ++it) {
        if (*it == "POST") {
            post++;
        } else if (*it == "GET") {
            get++;
        }
    }
    std::cout << "Total no of get: " << get << " total no of post: " << post << std::endl;
    return get / post;
}