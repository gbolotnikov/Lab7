#ifndef WRITER_HPP
#define WRITER_HPP

#include <string>

class IWriter {
    public:
        virtual void write(const std::string& str, uint64_t timestamp) const = 0;
        virtual ~IWriter() = default;
};

#endif