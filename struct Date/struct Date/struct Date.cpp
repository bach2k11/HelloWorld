

#include <iostream>
using namespace std;
enum { SUN, MON, TUE, WED, THU, FRI, SAT };
class Date {
    int day, month, year;
public:
    /*Date() {
        day = 1;
        month = 1;
        year = 2000;
    }*/
    /*Date(int year, int month, int day) {
        this-> day = day;
        this->month = month;
        this->year = year;
    }*/
    Date(int year = 2000, int month = 1, int day = 1) :year(year), month(month), day(day) {}
public:
    int GetDay()const { return day; }
    int GetMonth()const { return month; }
    int GetYear()const { return year; }
public:
    static int GetDays(int m, int y) {
        switch (m) {
        case 2:return y & 3 ? 28 : 29;
        case 4:case 6:case 9:case 11:return 30;
        }
        return 31;
    }
    int GetDays()const { return GetDays(month, year); }
    int DayOfWeek()const {
        int sn = 0, m = 0;
        while (++m < month) sn += GetDays(m, year);
        int d = year - 2000;
        return (d + (d - 1) / 4 + sn + day - 1) % 7;
    }
    friend ostream& operator << (ostream& out, Date& d) {
        if (d.day < 10) out << '0';
        out << d.day << '/';
        if (d.month < 10) out << '0';
        out << d.month << '/';
        return out << d.year;
    }
    Date& operator ++() {
        if (++day > GetDays()) {
            day = 1;
            if (++month > 12) {
                month = 1;
                ++year;
            }
        }return *this;
    }
}; // CUOI CUA CLASS



int main()
{
    Date today(2023, 11);
    cout << today.GetMonth();// biến đơn nên truy cập bằng dấu chấm biến con trỏ sử dụng mũi tên
    cout << today.DayOfWeek();
    const char* thu[] = { "chu nhat","hai","ba","tu","nam","sau","bay" };

    int m = today.GetMonth();
    while (m == today.GetMonth()) {
        int d = today.DayOfWeek();
        cout << "Ngay " << today << " la " << (d == SUN ? "" : "thu ")
            << thu[d] << endl;
        ++today;
    };
}

