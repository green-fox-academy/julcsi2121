#include <iostream>
#include <string>

void bubbleSort(int list[], int size);

//  Create a function that takes a list of numbers as parameter
//  Don't forget you have to pass the size of the list as a parameter as well
//  Returns a list where the elements are sorted in ascending numerical order by using bubble sort
//  Make a second boolean parameter, if it's `true` sort that list descending

/* ---Pesudo-code-----
int main(int argc, char* args[])
{
    adat bekérő stuff
    fgv hívás

    return 0;
}

bubble sort növekvő (lista, lista méret):
sort:
while lista i nagyobb mint i+1   // ellenőrző ciklus: amíg a lista i eleme nagyobb, mint a kövi
    for lista méret:                 // megy egy kört
        if i nagyobb mint i+1        // utolsó elem??????
            csere
    i++                              // végigellenőrzi az egész listát

print:
bubble sort csökkenő: csak a printnek elég változnia
    ha true, akkor sima print
    ha false, akkor reverse print
*/

 int main(int argc, char* args[])
{

    int list[6] = {250, 4, 3, 5, 43, 1};
    int size = 6;
    bubbleSort(list, size);

    return 0;
}

void bubbleSort(int list[], int size) {
     //sort:
     int i;
     while (list[i] > list[i +1]) {
        for (int j = 0; j < size ; ++j) {
            std::cout << "Before: " << list[j] << " and " << list[j + 1] << std::endl;
            if (j > (j + 1)) {
                int temp;
                list[j] = temp;
                std::cout << "temp: " << temp << std::endl;
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
            std::cout << "After: " << list[j] << " and " << list[j + 1] << std::endl;
        }
        i++;
     }
     std::cout << "Sorted list: " << std::endl;
     for (int k = 0; k < size ; ++k) {
        std::cout << list[k] << std::endl;
    }
 }
