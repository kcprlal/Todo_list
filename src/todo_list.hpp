#pragma once
#include "task.hpp"
#include <vector>
#include <string>
class ToDoList{
    public:
        void addTask(const std::string& context);
        void listTasks(bool all);
        bool removeTask(int id);
        bool markTask(int id, bool done);
        void saveToFile(const std::string& filename) const;
        void loadFromFile(const std::string& filename);

    private:
        std::vector<Task> tasks;
        int nextId=1;
};
