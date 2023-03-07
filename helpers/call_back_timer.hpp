//
// Created by Cezary Petryka on 21.01.2021.
//

#ifndef CINEMAS_CALL_BACK_TIMER_HPP
#define CINEMAS_CALL_BACK_TIMER_HPP

#include "../libs/headers.hpp"

class CallBackTimer {
    std::atomic<bool> _execute;
    std::thread _thd;
public:
    CallBackTimer();

    void stop();
    void start(int interval, std::function<void(void)> func);
    bool is_running() const noexcept;

    ~CallBackTimer();
};

/*
 * SOLUTION FROM:
 * https://stackoverflow.com/questions/30425772/c-11-calling-a-c-function-periodically
 * */

#endif //CINEMAS_CALL_BACK_TIMER_HPP