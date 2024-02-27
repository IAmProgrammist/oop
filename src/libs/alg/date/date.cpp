#include "date.h"

Date Date::getDayAfter() {
    return Date(this->data + boost::gregorian::days(1));
}

Date Date::getDayBefore() {
    return Date(this->data - boost::gregorian::days(1));
}

int Date::getDaysBeforeMonthEnd() {
    boost::gregorian::date date_next_month = this->data.end_of_month() + boost::gregorian::days(1);

    return (date_next_month - this->data).days();
}

Date& Date::operator<<(int amount) {
    this->data = this->data - boost::gregorian::days(amount);

    return *this;
}

Date& Date::operator>>(int amount) {
    this->data = this->data + boost::gregorian::days(amount);

    return *this;
}

bool Date::operator>=(Date& another) const {
    if (this->data.year() < another.data.year()) return false;
    if (this->data.year() > another.data.year()) return true;

    if (this->data.month() < another.data.month()) return false;
    if (this->data.month() > another.data.month()) return true;

    return this->data.day() >= another.data.day();
}

boost::gregorian::date Date::getData() {
    return this->data;
}
