//
// Created by Cezary Petryka on 21.01.2021.
//

#ifndef CINEMAS_CALL_BACK_TIMER_HPP
#define CINEMAS_CALL_BACK_TIMER_HPP

#include "../libs/headers.hpp"

/**
 * @brief Class that allows to call function periodically.
 */
class CallBackTimer {
    std::atomic<bool> execute;
    std::thread thd;
public:
    CallBackTimer();

    void start(int interval, std::function<void(void)> func);
    void stop();
    bool is_running() const noexcept;

    ~CallBackTimer();
};

/*
 * SOLUTION FROM:
 * https://stackoverflow.com/questions/30425772/c-11-calling-a-c-function-periodically
 * */

#endif //CINEMAS_CALL_BACK_TIMER_HPP