#include <iostream>
#include "CommandManager.hpp"
#include "ConsoleWriter.hpp"
#include "FileWriter.hpp"
#include "ConsoleReader.hpp"


int main(int argc, char* argv[])
{
    ConsoleWriter consoleWriter;
    FileWriter fileWriter("bulk");
    CommandManager commandManager;
    commandManager.addWriter(consoleWriter);
    commandManager.addWriter(fileWriter);
    ConsoleReader consoleReader(commandManager, 3);
    consoleReader.read();
}
