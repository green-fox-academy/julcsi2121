#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int removeWords(std::string path);

int main() {
    int count = removeWords("../content.txt");
    std::cout << count << std::endl;
    return 0;
}

int removeWords(std::string path)
{
    std::vector<std::string> swearWords = {"fuck", "bloody", "cock", "shit", "fucker", "fuckstick", "asshole", "dick", "piss", "cunt"};

    std::ifstream myFile;
    myFile.open(path);
    std::string line;
    int count = 0;

    while (getline(myFile, line)) {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        for (int i = 0; i < swearWords.size(); ++i) {
            std::string delimiter = swearWords.at(i);
            int pos = line.find(" " + delimiter);
            if(pos != -1) {
                line.erase(pos - 1, delimiter.size());
                count ++;
            }
        }
    }
    return count;
}