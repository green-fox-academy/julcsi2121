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
            std::string actualWord = swearWords.at(i);
            int pos = line.find(actualWord);
            if(pos != -1) {
                std::cout << line.substr(pos-1, 10) << std::endl;
                line.erase(pos - 1, actualWord.size());
                count ++;
            }
        }
    }
    return count;
}



/*
 * ifstream-hez badbit-et érdemes
 * ha megnézzük a badbitet, akkor nem kell az if-es izé a try-ban
 * írás: badbit, failbit is kell
 *
 * stringstream:
 * .str - átcsinálja stringgé
 *
 * szavaknak csinálni egy stringet - stringstreamből beletölteni a szavakat a változóba - 2. while
 *
 * végigmenni a káromkodós-stavas listán
 * szavakat ki lehet menteni egy vectorba, hanem matchel a szavakkal
 *
 * tolower át is alakítja
 *
 * külön lowercase fgv - végigmegy a stringen karakterenként, új stringhez hozzáfűzzük - std::tolower(string[i])
 *
 * ha írásjel van a végén:
 * extra karakter levágó fgv:
 * utolsó karakter egyenlő-e . vagy stb. (.back - utolsó karaktert kiszedi)
 * pop back - kiszedi az utolsó elemet
 *
 * ha kész a vektor - utána ki lehet íratni file-ba - ofstream
 *
 * mapnél a számolós kifejezés nem csak char-ra működik, hanem bármilyen adattípussal
 */