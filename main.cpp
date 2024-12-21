#include <iostream>
using namespace std;

template <typename T>
int calculate_days(T day_one, T month_one, T year_one, T day_two, T month_two, T year_two)
{
    int days = 0;
    int count_days = 0;

    for (int i = year_one; i <= year_two; i++) {
        int start_month = (i == year_one) ? month_one : 1;
        int end_month = (i == year_two) ? month_two : 12;

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

            if (i == year_one && j == month_one) {
                count_days += days - day_one + 1;
            }
            else if (i == year_two && j == month_two) {
                count_days += day_two;
            }
            else {
                count_days += days;
            }
        }
    }
    return count_days;
}

int main() {
    cout << "Total days: " << calculate_days(1, 1, 2020, 25, 12, 2022) << endl;
    return 0;
}
