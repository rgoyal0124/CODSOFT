#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a task structure
struct Task {
  string description;
  bool isCompleted;
};

// Function to display the to-do list
void displayTasks(const vector<Task>& tasks) {
  if (tasks.empty()) {
    cout << "There are no tasks in the list." << endl;
    return;
  }

  cout << "To-Do List:" << endl;
  for (size_t i = 0; i < tasks.size(); ++i) {
    cout << i + 1 << ". " << tasks[i].description << " ("
         << (tasks[i].isCompleted ? "Completed" : "Pending") << ")" << endl;
  }
}

// Function to add a task to the list
void addTask(vector<Task>& tasks) {
  string description;
  cout << "Enter task description: ";
  getline(cin, description);

  Task task;
  task.description = description;
  task.isCompleted = false;
  tasks.push_back(task);

  cout << "Task added successfully!" << endl;
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
  if (tasks.empty()) {
    cout << "There are no tasks in the list." << endl;
    return;
  }

  displayTasks(tasks);

  int taskNumber;
  cout << "Enter the number of the task to mark as completed: ";
  cin >> taskNumber;

  if (taskNumber < 1 || taskNumber > tasks.size()) {
    cout << "Invalid task number." << endl;
    return;
  }

  tasks[taskNumber - 1].isCompleted = true;
  cout << "Task marked as completed successfully!" << endl;
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks) {
  if (tasks.empty()) {
    cout << "There are no tasks in the list." << endl;
    return;
  }

  displayTasks(tasks);

  int taskNumber;
  cout << "Enter the number of the task to remove: ";
  cin >> taskNumber;

  if (taskNumber < 1 || taskNumber > tasks.size()) {
    cout << "Invalid task number." << endl;
    return;
  }

  tasks.erase(tasks.begin() + taskNumber - 1);
  cout << "Task removed successfully!" << endl;
}

int main() {
  vector<Task> tasks;
  int choice;

  while (true) {
    cout << endl;
    cout << "To-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        addTask(tasks);
        break;
      case 2:
        displayTasks(tasks);
        break;
      case 3:
        markTaskCompleted(tasks);
        break;
      case 4:
        removeTask(tasks);
        break;
      case 5:
        cout << "Exiting To-Do List Manager." << endl;
        return 0;
      default:
        cout << "Invalid choice." << endl;
    }
  }

  return 0;
}
