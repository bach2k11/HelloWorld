// LedDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../OOP/Screen.h" //chi duong dan thu vien 
#include "../OOP/Array.h"

Screen screen;

class Process {
protected:
    static int value;
    static int length;

    virtual void init() = 0;
    virtual void next() = 0;
    virtual bool eop() = 0;
    virtual void show_one(bool on) { 
        screen.SetColor(on ? 10 : 8) << char(254) << ' ';
    }

public:
    void Play();
};
void Process::Play() {

    init();
    while (!eop()) {
        screen.SetCursor(1, 1);
        for (int i = 0; i < length; i++) {
            show_one(value & (1 << i));
        }
        Sleep(200); // hàm tạm dừng trong Windows.h

        next();
    }
}


int Process::value = 0; // bắt buộc phải khai báo lại biến static
int Process::length = 8; // 8 LEDs

class SingleL2R : public Process {
protected:
    void init() override { value = 1; }
    void next() override { value <<= 1; }
    bool eop() override { return value >= (1 << length); }
};
class SingleR2L : public Process {
protected:
    void init() override { value = 1 << (length - 1); }
    void next() override { value >>= 1; }
    bool eop() override { return value == 0; }
};
class TurnOnL2R : public SingleL2R {
protected:
    void next() override {
        SingleL2R::next();
        value |= 1;
    }
};
class TurnOffR2L : public SingleR2L {
protected:
    void init() override { value = (1 << length) - 1; }
};

class TurnIn : public Process {
    int left;
    int right;

    void merge() { value = (left |= 1) | (right |= 1 << (length - 1)); }

protected:
    void init() override { 
        left = right = 0;
        merge();
    }
    void next() override {
        left <<= 1;
        right >>= 1;
        merge();
    }
    bool eop() override { return left >= (1 << (length >> 1)); }
};

class Blink : public Process {
protected:
    int count, times;
    void init() override { 
        value = 0;
        count = times;
        for (int i = 0; i < (length >> 3); i++) {
            value <<= 8;
            value |= 0xAA;
        }
    }
    void next() override { 
        --count;
        value = ~value;
    }
    bool eop() override { return count == 0; }

public:
    Blink(int times = 10) : count(0), times(times) {}

};
int main()
{
    screen.ShowCursor(false);

    Process* ps[] = {
        new SingleL2R(),
        new SingleR2L(),
        new TurnOnL2R(),
        new TurnOffR2L(),
        new TurnIn(),
        new Blink(),
        0
    };
    Process** p = ps;
    while (true) {
        (**p).Play();
        if (*(++p) == 0) p = ps;
    }
}
