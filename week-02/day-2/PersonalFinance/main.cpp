#include <iostream>
#include <vector>

void personalFinance(std::vector<int> expenses);

int main() {
    std::vector<int> expenses = {500, 1000, 1250, 175, 800, 120};
    personalFinance(expenses);

    return 0;
}

void personalFinance(std::vector<int> expenses)
{
    int sum = 0;
    for (int i = 0; i < expenses.size(); ++i) {
        sum += expenses.at(i);
    }
    std::cout << "My total expenses were " << sum << std::endl;
    int average = sum / expenses.size();
    std::cout << "My average spending was " << average << std::endl;

    std::vector<int>::iterator it = expenses.begin();
    for (int i = 0; i < expenses.size(); ++i) {
        if (*it >= expenses[i]) {
            *it = expenses[i];
        }
    }
    std::cout << "Minimum spending was: " << *it << std::endl;

    it = expenses.begin();
    for (int i = 0; i < expenses.size(); ++i) {
        if (*it <= expenses[i]) {
            *it = expenses[i];
        }
    }
    std::cout << "Maximum value was: " << *it << std::endl;

}