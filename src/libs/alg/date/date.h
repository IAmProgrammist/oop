#pragma once

#include <boost/date_time.hpp>

class Date {
    boost::gregorian::date data;
public:
    Date(boost::gregorian::date newDate) : data(newDate) {};
    Date(int d, int m, int y) : data(y, m, d) {};

    Date getDayAfter();
    Date getDayBefore();
    int getDaysBeforeMonthEnd();
    boost::gregorian::date getData();

    Date& operator<<(int amount);
    Date& operator>>(int amount);
    bool operator>=(Date& another) const;
};
