#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to store task information
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the to-do list
void addTask(vector<Task>& todoList, const string& description) {
    Task task(description);
    todoList.push_back(task);
    cout << "Task added: " << description << endl;
}

// Function to display the to-do list
void displayList(const vector<Task>& todoList) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << "[" << (i + 1) << "] ";
        if (todoList[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << todoList[i].description << endl;
    }
}

// Function to mark a task as completed
void markTaskComplete(vector<Task>& todoList, int index) {
    if (index >= 1 && index <= static_cast<int>(todoList.size())) {
        todoList[index - 1].completed = true;
        cout << "Task marked as completed: " << todoList[index - 1].description << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> todoList;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display To-Do List" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                cin.ignore(); // Clear the newline character left in the buffer
                getline(cin, description);
                addTask(todoList, description);
                break;
            }
            case 2:
                displayList(todoList);
                break;
            case 3: {
                cout << "Enter the task number to mark as completed: ";
                int taskNumber;
                cin >> taskNumber;
                markTaskComplete(todoList, taskNumber);
                break;
            }
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
