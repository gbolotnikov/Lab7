
#include <ctime>
#include <string>
#include <algorithm>
#include "CommandManager.hpp"

void CommandManager::addWriter(const IWriter& writer) {
    _writers.emplace(&writer);
}

void CommandManager::newCommand(std::string_view cmd) {
    if (_commands.empty()) {
        _firstCmdtimeStamp = std::time(nullptr);
    }
    _commands.push_back(std::move(cmd.data()));
}

void CommandManager::endCommand() {
    notifyWriter();
    _commands.clear();
}

void CommandManager::notifyWriter() {
    if (_commands.empty()) {
        return;
    }
    std::string out("bulk: ");
    for (auto it = _commands.begin(); it != _commands.end(); ++it) {
        if (it != _commands.begin()) {
            out += ", ";
        }
        out += *it;
    }
    for (auto writer : _writers)
        writer->write(out, _firstCmdtimeStamp);
}