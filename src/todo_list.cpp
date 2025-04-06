#include "todo_list.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

void ToDoList::addTask(const std::string &context)
{
    Task t(nextId++, context);
    tasks.push_back(t);
    std::cout << "Added task: " << t.getContext() << std::endl;
}

void ToDoList::listTasks(bool all = true)
{
    for (const auto &t : tasks)
    {
        if (!all && t.getDone())
            continue;
        std::cout << t.makeString() << std::endl;
    }
}

bool ToDoList::markTask(int id, bool done)
{
    for (auto &t : tasks)
    {
        if (t.getId() == id)
        {
            done ? t.setDone(true) : t.setDone(false);
            std::cout << t.getContext() << " is done!" << std::endl;
            return true;
        }
    }
    return false;
}

bool ToDoList::removeTask(int id)
{
    for (auto i = tasks.begin(); i != tasks.end(); i++)
    {
        if (i->getId() == id)
        {
            std::cout << "Removed task: " << i->getContext() << std::endl;
            tasks.erase(i);
            return true;
        }
    }
    return false;
}

void ToDoList::saveToFile(const std::string &filename) const
{
    std::ofstream out(filename);
    for (const auto &t : tasks)
    {
        out << t.getId() << ";" << t.getContext() << ";" << t.getDone() << std::endl;
    }
}

void ToDoList::loadFromFile(const std::string &filename)
{
    tasks.clear();
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line))
    {
        std::istringstream iss(line);
        std::getline(iss, line, ';');
        int id = std::stoi(line);

        std::string context;
        std::getline(iss, context, ';');

        std::string doneMark;
        std::getline(iss, doneMark);

        Task t(id, context, (doneMark == "1"));

        tasks.emplace_back(t);
        nextId = std::max(nextId, t.getId() + 1);
    }
}