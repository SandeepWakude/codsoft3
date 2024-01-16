#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "Sorry, invalid task." << std::endl;
        } else {
            std::cout << "Tasks:" << std::endl;
            for (const auto& task : tasks) {
                std::cout << "- " << (task.completed ? "[X] " : "[ ] ") << task.description << std::endl;
            }
        }
    }

    void markAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task is completed: " << tasks[index].description << std::endl;
        } else {
            std::cout << "Wrong task index." << std::endl;
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            std::cout << "Task removed: " << tasks[index].description << std::endl;
            tasks.erase(tasks.begin() + index);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        std::cout << "\nTodo List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "0. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore();  // Clear the buffer
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                todoList.markAsCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter task index to remove: ";
                std::cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case 0:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
