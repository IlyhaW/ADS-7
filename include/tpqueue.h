// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <list>
#include <utility>

struct SYM {
    char ch;
    int prior;
};

bool PriorList(const SYM& num1, const SYM& num2) {
    return num1.prior > num2.prior;
}

bool ChList(const SYM& num1, const SYM& num2) {
    return num1.ch < num2.ch;
}

template<typename T>
class TPQueue {
private:
    std::list <T> List;
    int head;
    T First;

public:
    TPQueue() {
        head = -1;
    }
    void push(T num) {
        if (head == -1) {
            List.push_front(num);
            head += 1;
        }
        else {
            First = List.front();
            if (First.prior == num.prior) {
                List.push_front(num);
                List.sort(ChList);
            }
            else {
                List.push_front(num);
                List.sort(PriorList);
            }
            head += 1;
        }
    }
    bool isEmpty() {
        return head == -1;
    }
    T top() {
        return List.front();
    }
    T pop() {
        head -= 1;
        auto val = List.front();
        List.pop_front();
        return val;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
