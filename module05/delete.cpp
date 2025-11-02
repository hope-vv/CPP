#include <iostream>
#include <exception>

class Number {
private:
    int value;

public:
    Number(int val) {
        if (val < 1)
            throw TooLowException();
        if (val > 10)
            throw TooHighException();
        value = val;
    }

    int getValue() const {
        return value;
    }

    void setValue(int val) {
        if (val < 1)
            throw TooLowException();
        if (val > 10)
            throw TooHighException();
        value = val;
    }

    class TooHighException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Value is too high!";
        }
    };

    class TooLowException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Value is too low!";
        }
    };
};

int main() {
    try {
        Number n(5);
        std::cout << "Initial value: " << n.getValue() << std::endl;

        n.setValue(11); // Throws TooHighException
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Number n2(0); // Throws TooLowException
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
