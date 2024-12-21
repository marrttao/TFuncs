#include <iostream>
using namespace std;

template <typename T>
int calculate_days(T day_one, T month_one, T year_one, T day_two, T month_two, T year_two)
{
    int days = 0;
    int count_days = 0;

    for (int i = *year_one; i <= *year_two; i++) {
        int start_month = (i == *year_one) ? *month_one : 1;
        int end_month = (i == *year_two) ? *month_two : 12;

        for (int j = start_month; j <= end_month; j++) {
            if (j == 4 || j == 6 || j == 9 || j == 11) {
                days = 30;
            }
            else if (j == 2) {
                if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
                    days = 29;
                else
                    days = 28;
            }
            else {
                days = 31;
            }

            if (i == *year_one && j == *month_one) {
                count_days += days - *day_one + 1;
            }
            else if (i == *year_two && j == *month_two) {
                count_days += *day_two;
            }
            else {
                count_days += days;
            }
        }
    }
    return count_days;
}

int main() {
    int* day_one = new int;
    int* month_one = new int;
    int* year_one = new int;
    int* day_two = new int;
    int* month_two = new int;
    int* year_two = new int;

    cout << "First date: ";
    cin >> *day_one >> *month_one >> *year_one;
    cout << "Second date: ";
    cin >> *day_two >> *month_two >> *year_two;

    cout << "Total days: " << calculate_days(day_one, month_one, year_one, day_two, month_two, year_two) << endl;

    delete day_one;
    delete month_one;
    delete year_one;
    delete day_two;
    delete month_two;
    delete year_two;

    return 0;
}
