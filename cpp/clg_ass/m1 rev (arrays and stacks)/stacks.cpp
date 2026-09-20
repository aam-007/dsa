#include <iostream>
#include <cstddef>

namespace lds {

    enum class CONDITION {
        OVERFLOW,
        UNDERFLOW,
        OK
    };

    constexpr std::size_t MAX{ 100 };

    struct STACK {
        std::size_t arr[MAX];
        int top{ -1 };
    };

    CONDITION status(const STACK& s) {
        if (s.top == -1) {
            return CONDITION::UNDERFLOW;
        }

        if (s.top == MAX - 1) {
            return CONDITION::OVERFLOW;
        }

        return CONDITION::OK;
    }

    void disp(const STACK& s) {
        for (auto k{ 0 }; k <= s.top; ++k) {
            std::cout << s.arr[k] << '\n';
        }

        std::cout << '\n';
    }

    void push(STACK& s, auto item) {
        if (status(s) == CONDITION::OVERFLOW) {
            return;
        }

        s.arr[++s.top] = item;
    }

    void pop(STACK& s) {
        if (status(s) == CONDITION::UNDERFLOW) {
            return;
        }

        --s.top;
    }
}

int main() {
    lds::STACK s{ {5, 3, 4, 8, 6}, 4 };

    lds::disp(s);

    lds::pop(s);

    lds::disp(s);

    lds::push(s, 10);

    lds::disp(s);
}