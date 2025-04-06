#pragma once
#include <string>

class Task
{
    int id;
    std::string context;
    bool done = false;

public:
    std::string makeString() const;
    Task(int id, std::string context) : id(id), context(context) {};
    Task(int id, std::string context, bool done) : id(id), context(context), done(done){};

    std::string getContext() const { return context; }
    bool getDone() const { return done; }
    void setDone(bool val) { done = val; }
    int getId() const { return id; }
};