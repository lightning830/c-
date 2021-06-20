#include <cstdio>

// Clock クラスの定義
class Clock
{
public:
    int hour;
    int minute;
    void set(int hour, int minute);
    void print();
};

void Clock::set(int hour, int minute)
{
    this->hour = hour % 24;
    this->minute = minute % 60;
}

void Clock::print()
{
    printf("%02d:%02d\n", hour, minute);
    fflush(stdout);
}

int main()
{
    Clock c;    // インスタンス化
    c.set(6, 30);
    c.print();  // 出力: 06:30
}