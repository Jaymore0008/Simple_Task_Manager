#include <iostream>
#include <string>
using namespace std;

// Task class to represent individual tasks
class Task {
public:
    int id;
    string name;
    int priority; // Higher number means higher priority

    Task() {}
    Task(int i, string n, int p) : id(i), name(n), priority(p) {}
};

// TaskManager class to manage all tasks
class TaskManager {
private:
    Task tasks[100]; // Array to store tasks (maximum of 100 tasks)
    int taskCount;

public:
    TaskManager() {
        taskCount = 0;
    }

    // Add a new task
    void addTask(int id, string name, int priority) {
        tasks[taskCount++] = Task(id, name, priority);
        cout << "Task added: " << name << " with priority " << priority << endl;
    }

    // Delete a task by id
    void deleteTask(int id) {
        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].id == id) {
                // Shift the remaining tasks to fill the gap
                for (int j = i; j < taskCount - 1; j++) {
                    tasks[j] = tasks[j + 1];
                }
                taskCount--;
                cout << "Task with ID " << id << " deleted." << endl;
                return;
            }
        }
        cout << "Task with ID " << id << " not found." << endl;
    }

    // Update a task's priority by id
    void updateTaskPriority(int id, int newPriority) {
        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].id == id) {
                tasks[i].priority = newPriority;
                cout << "Task with ID " << id << " updated to priority " << newPriority << endl;
                return;
            }
        }
        cout << "Task with ID " << id << " not found." << endl;
    }

    // List all tasks
    void listTasks() {
        if (taskCount == 0) {
            cout << "No tasks available." << endl;
            return;
        }

        cout << "\nList of Tasks:\n";
        for (int i = 0; i < taskCount; i++) {
            cout << "ID: " << tasks[i].id 
                 << " | Name: " << tasks[i].name 
                 << " | Priority: " << tasks[i].priority << endl;
        }
    }

    // Sort tasks by priority using Bubble Sort
    void sortTasksByPriority() {
        for (int i = 0; i < taskCount - 1; i++) {
            for (int j = 0; j < taskCount - i - 1; j++) {
                if (tasks[j].priority < tasks[j + 1].priority) {
                    // Swap tasks
                    Task temp = tasks[j];
                    tasks[j] = tasks[j + 1];
                    tasks[j + 1] = temp;
                }
            }
        }
        cout << "Tasks sorted by priority." << endl;
    }
};

// Main function
int main() {
    TaskManager tm;
    int choice, id, priority;
    string name;

    do {
        cout << "\nSimple Task Manager";
        cout << "\n1. Add Task";
        cout << "\n2. Delete Task";
        cout << "\n3. Update Task Priority";
        cout << "\n4. List Tasks";
        cout << "\n5. Sort Tasks by Priority";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Task ID: ";
                cin >> id;
                cin.ignore(); // Ignore newline character
                cout << "Enter Task Name: ";
                getline(cin, name);
                cout << "Enter Task Priority (higher number means higher priority): ";
                cin >> priority;
                tm.addTask(id, name, priority);
                break;

            case 2:
                cout << "Enter Task ID to delete: ";
                cin >> id;
                tm.deleteTask(id);
                break;

            case 3:
                cout << "Enter Task ID to update priority: ";
                cin >> id;
                cout << "Enter new priority: ";
                cin >> priority;
                tm.updateTaskPriority(id, priority);
                break;

            case 4:
                tm.listTasks();
                break;

            case 5:
                tm.sortTasksByPriority();
                tm.listTasks();
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

