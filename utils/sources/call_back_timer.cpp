//
// Created by Cezary Petryka on 21.01.2021.
//

#include "../call_back_timer.hpp"

CallBackTimer::CallBackTimer() : execute(false) {}

void CallBackTimer::start(int interval, std::function<void(void)> func) {
    if(execute.load(std::memory_order_acquire)) {
        stop();
    }
    execute.store(true, std::memory_order_release);

    thd = std::thread([this, interval, func]()
                      {
                          while (execute.load(std::memory_order_acquire)) {
                              func();
                              std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                          }
                      });

    thd.detach();
}

void CallBackTimer::stop() {
    execute.store(false, std::memory_order_release);

    if(thd.joinable()) {
        thd.join();
    }
}


bool CallBackTimer::is_running() const noexcept {
    return execute.load(std::memory_order_acquire) && thd.joinable();
}


CallBackTimer::~CallBackTimer() {
    if(execute.load(std::memory_order_acquire)) {
        stop();
    }
}