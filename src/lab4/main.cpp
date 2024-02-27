#include <iostream>

#include "../libs/alg/date/date.h"

int main() {
    Date d(23, 11, 2023);

    Date a_lot_of_days_later = d.getDayAfter().getDayAfter().getDayAfter().getDayAfter().getDayAfter().getDayAfter();
    Date a_lot_of_days_before = d.getDayBefore().getDayBefore().getDayBefore().getDayBefore().getDayBefore();

    Date time_travel = d << 1 >> 312 << 23 >> 121 >> 90 << 80;

    std::cout << a_lot_of_days_before.getData() << " " << a_lot_of_days_before.getDaysBeforeMonthEnd() << std::endl;
    std::cout << a_lot_of_days_later.getData() << " " << a_lot_of_days_later.getDaysBeforeMonthEnd() << std::endl;
    std::cout << "Is a_lot_of_days_before >= a_lot_of_days_later? " << (a_lot_of_days_before >= a_lot_of_days_later) << std::endl;
    std::cout << time_travel.getData() << std::endl;
}
