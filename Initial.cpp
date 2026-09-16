#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Task {
public:
    Task(const std::string& title, int priority)
        : title(title), priority(priority) {}

    const std::string& getTitle() const {
        return title;
    }

    int getPriority() const {
        return priority;
    }

private:
    std::string title;
    int priority;
};

int main() {
    std::vector<Task> tasks;

    tasks.emplace_back("Write Report", 2);
    tasks.emplace_back("Review Code", 1);
    tasks.emplace_back("Backup Files", 3);
    tasks.emplace_back("Update Database", 2);

    std::sort(tasks.begin(), tasks.end(),
        [](const Task& left, const Task& right) {
            return left.getPriority() < right.getPriority();
        });

    std::cout << "Task Queue" << std::endl;
    std::cout << "==========" << std::endl;

    for (const auto& task : tasks) {
        std::cout << task.getPriority()
                  << " | "
                  << task.getTitle()
                  << std::endl;
    }

    return 0;
}
