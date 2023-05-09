#include <chrono>
#include <fstream>
#include "FileWriter.hpp"


FileWriter::FileWriter(std::string_view name): 
    _name(std::move(name.data()))
{

}

void FileWriter::write(const std::string& str, uint64_t timestamp) const {
    std::string filename = _name + std::to_string(timestamp) + FileExtension.data();
    std::ofstream file(filename);
    file << str << '\n';
}