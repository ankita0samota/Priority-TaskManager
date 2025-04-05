#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

struct Task {
    string description;
    int priority;
    bool iscomplete;

    Task(const string& desc, int prio) : description(desc), priority(prio), iscomplete(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description, int priority) {
        tasks.push_back(Task(description, priority));
        cout << "Task added successfully.\n";
    }
    
    void removeTask(const string& description) {
        auto it = remove_if(tasks.begin(), tasks.end(), [&](const Task& task) {
            return task.description == description;
        });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "Task removed successfully.\n";
        } else {
            cout << "Task not found.\n";
        }
    }

    void markTaskComplete(const string& description) {
        auto it = find_if(tasks.begin(), tasks.end(), [&](const Task& task) {
            return task.description == description;
        });

        if (it != tasks.end()) {
            it->iscomplete = true;
            cout << "Task marked as complete.\n";
        } else {
            cout << "Task not found.\n";
        }
    }

    void listTasks() const {
        vector<Task> sortedTasks = tasks;
        sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
            return a.priority > b.priority;
        });

        for (const auto& task : sortedTasks) {
            cout << "Description: " << task.description << "\n";
            cout << "Priority: " << task.priority << "\n";
            cout << "Status: " << (task.iscomplete ? "Completed" : "Pending") << "\n";
            cout << "-\n";
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string description;
    int priority;

    do {
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Mark Task Complete\n";
        cout << "4. List Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter task priority (integer): ";
                cin >> priority;
                cin.ignore();
                todoList.addTask(description, priority);
                break;

            case 2:
                cout << "Enter task description: ";
                getline(cin, description);
                todoList.removeTask(description);
                break;

            case 3:
                cout << "Enter task description: ";
                getline(cin, description);
                todoList.markTaskComplete(description);
                break;

            case 4:
                todoList.listTasks();
                break;

            case 5:
                cout << "Exiting...\n";
                
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);
    
    cout<<"=== Code Execution Successful ===";
    
    cin.get();


    return 0;
}

