#ifndef CONSOLE_WRITER_HPP
#define CONSOLE_WRITER_HPP

#include <iostream>
#include "Interfaces/Writer.hpp"

class ConsoleWriter : public IWriter {
public:
    ~ConsoleWriter() = default;
    void write(const std::string& str, uint64_t timestamp) const override {
        std::cout << str << std::endl;
    }
};

#endif