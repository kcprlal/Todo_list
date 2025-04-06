#include <iostream>
#include <string>
#include "todo_list.hpp" 

int main() {
    ToDoList todoList;

    todoList.loadFromFile("tasks.txt");

    bool running = true;
    while (running) {
        std::cout << "=== Menu ===\n";
        std::cout << "1. Add task\n";
        std::cout << "2. Show all tasks\n";
        std::cout << "3. Show undone tasks\n";
        std::cout << "4. Delete task\n";
        std::cout << "5. Mark task done\n";
        std::cout << "6. Mark task undone\n";
        std::cout << "7. Quit\n";
        std::cout << "Choose option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Give description: ";
                std::getline(std::cin, description);
                todoList.addTask(description);
                std::cout << "Task added!\n";
                break;
            }

            case 2: {
                std::cout << "List of all tasks:\n";
                todoList.listTasks(true);
                break;
            }

            case 3: {
                std::cout << "Tasks to do:\n";
                todoList.listTasks(false);  // Pokaż tylko zadania, które nie są zakończone
                break;
            }

            case 4: {
                int id;
                std::cout << "Provide task id: ";
                std::cin >> id;
                if (todoList.removeTask(id)) {
                    std::cout << "Task has been removed.\n";
                } else {
                    std::cout << "Could not find task with this id.\n";
                }
                break;
            }

            case 5: {
                int id;
                std::cout << "Provide task id: ";
                std::cin >> id;
                if(todoList.markTask(id, true)) {
                    std::cout << "Task is done.\n";
                } else {
                    std::cout << "Could not find task with this id.\n";
                }
                break;
            }
            
            case 6: {
                int id;
                std::cout << "Provide task id: ";
                std::cin >> id;
                if(todoList.markTask(id, false)) {
                    std::cout << "Task is undone.\n";
                } else {
                    std::cout << "Could not find task with this id.\n";
                }
                break;
            }

            case 7: {
                std::cout << "Quitting...\n";
                running = false;
                break;
            }

            default:
                std::cout << "Option does not exist.\n";
        }
    }

    todoList.saveToFile("tasks.txt");

    return 0;
}
