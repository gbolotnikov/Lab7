#ifndef COMMAND_MANAGER_HPP
#define COMMAND_MANAGER_HPP

#include <unordered_set>
#include "Interfaces/Manager.hpp"

class CommandManager: public IManager{
public:
    void addWriter(const IWriter& writer) override;
    void newCommand(std::string_view cmd) override;
    void endCommand() override;

    ~CommandManager() = default;
private:

    void notifyWriter();

    size_t _firstCmdtimeStamp;
    std::vector<std::string> _commands;
    std::unordered_set<const IWriter*> _writers;

};

#endif