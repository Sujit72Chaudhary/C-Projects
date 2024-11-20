#include <iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

// Define the Job class
class Job {
    string jobname; // String to store job name
    string jobtype; // String to store job type
    int priority, times; // Integers to store priority and time of the job

public:
    Job *next, *prev; // Pointers to the next and previous jobs in the deque

    Job() { // Constructor to initialize pointers to NULL
        next = prev = NULL;
    }

    void read() { // Function to read job details from user
        cout << "Enter the job name: "; // Prompt for job name
        cin.ignore(); // Clear the input buffer
        getline(cin, jobname); // Read job name
        cout << "Enter the job type: "; // Prompt for job type
        getline(cin, jobtype); // Read job type
        cout << "Enter the priority and time: "; // Prompt for priority and time
        cin >> priority >> times; // Read priority and time
    }

    string getJobname() { // Function to return job name
        return jobname;
    }

    int getPriority() { // Function to return job priority
        return priority;
    }

    void display() { // Function to display job details
        cout << "Job name: " << jobname << endl; // Display job name
        cout << "Job type: " << jobtype << endl; // Display job type
        cout << "Priority: " << priority << endl; // Display job priority
        cout << "Times: " << times << endl; // Display job time
    }
};

// Define the Dequeue class for job management
class Dequeue {
    Job *rear, *front; // Pointers to rear and front of deque

public:
    Dequeue() { // Constructor to initialize deque
        rear = front = NULL;
    }

    ~Dequeue() { // Destructor to clean up deque
        while (front != NULL) { // Loop until deque is empty
            remove_Job_Front(); // Remove jobs from front
        }
    }

    void add_Job_Priority() { // Function to add job based on priority
        Job *nn = new Job; // Create a new job
        nn->read(); // Read job details

        if (front == NULL) { // If deque is empty
            front = rear = nn; // New job is both front and rear
        } else if (nn->getPriority() < front->getPriority()) { // If priority is highest
            nn->next = front; // Insert new job at the front
            front->prev = nn;
            front = nn;
        } else { // Find the appropriate position based on priority
            Job *temp = front;
            while (temp->next != NULL && temp->next->getPriority() <= nn->getPriority()) {
                temp = temp->next; // Move to the next job if it has higher priority
            }

            nn->next = temp->next; // Insert new job at the found position
            if (temp->next != NULL) {
                temp->next->prev = nn;
            } else {
                rear = nn; // Update rear if job is added at the back
            }
            temp->next = nn;
            nn->prev = temp;
        }
        cout << "Job added based on priority.\n"; // Confirmation message
    }

    void remove_Job_Front() { // Function to remove job from front
        if (front == NULL) { // If deque is empty
            cout << "No jobs to remove from front.\n"; // Display message
            return;
        }
        Job *temp = front; // Temporary pointer to hold the front job
        front = front->next; // Move front pointer to next job
        if (front != NULL) {
            front->prev = NULL; // Update previous pointer of new front
        } else {
            rear = NULL; // If deque is now empty, set rear to NULL
        }
        delete temp; // Delete the removed job
        cout << "Removed job from front.\n"; // Confirmation message
    }

    void remove_Job_Back() { // Function to remove job from rear
        if (rear == NULL) { // If deque is empty
            cout << "No jobs to remove from back.\n"; // Display message
            return;
        }
        Job *temp = rear; // Temporary pointer to hold the rear job
        rear = rear->prev; // Move rear pointer to previous job
        if (rear != NULL) {
            rear->next = NULL; // Update next pointer of new rear
        } else {
            front = NULL; // If deque is now empty, set front to NULL
        }
        delete temp; // Delete the removed job
        cout << "Removed job from back.\n"; // Confirmation message
    }

    void displayJob() { // Function to display all jobs in the deque
        Job *temp = front; // Start from the front
        if (temp == NULL) { // If deque is empty
            cout << "No jobs in the queue.\n"; // Display message
            return;
        }
        cout << "Jobs in the queue:\n"; // Header message
        while (temp != NULL) { // Loop through all jobs
            temp->display(); // Display each job
            temp = temp->next; // Move to the next job
        }
    }

    void searchJob(string Jname) { // Function to search for a job by name
        Job *temp = front; // Start from the front
        while (temp != NULL) { // Loop through all jobs
            if (temp->getJobname() == Jname) { // If job name matches
                cout << "Job is found:\n"; // Display message
                temp->display(); // Display job details
                return;
            }
            temp = temp->next; // Move to the next job
        }
        cout << "Job with name '" << Jname << "' not found.\n"; // If job not found
    }
};

// Main function for job management system
int main() {
    Dequeue D; // Create an instance of the deque
    int choice; // Variable to store user choice
    cout<<"************"<<endl;
    cout<<endl<<"          MENU:   "<<endl;
    while (true) {
        cout<<"---------------------------\n"; // Infinite loop for menu
        cout << "1. Add Job Based on Priority\n" // Display menu options
             << "2. Remove Job from Front\n"
             << "3. Remove Job from Back\n"
             << "4. Display Job\n"
             << "5. Search Job\n"
             << "6. Exit\n";
        cout << "Enter your choice: "; // Prompt for choice
        cin >> choice; // Read choice
        switch (choice) { // Switch case for menu options
            case 1:
                D.add_Job_Priority(); // Add job based on priority
                break;
            case 2:
                D.remove_Job_Front(); // Remove job from front
                break;
            case 3:
                D.remove_Job_Back(); // Remove job from back
                break;
            case 4:
                D.displayJob(); // Display all jobs
                break;
            case 5: {
                string s; // Variable to hold job name for search
                cout << "Enter the job name to search: "; // Prompt for job name
                cin.ignore(); // Clear input buffer
                getline(cin, s); // Read job name
                D.searchJob(s); // Search for job
                break;
            }
            case 6:
                cout << "Exiting the program.\n"; // Exit message
                cout<<"********************\n";
                return 0; // Exit the program
            default:
                cout << "Invalid Choice! Try Again.\n"; // Message for invalid choice
        }
    }
    return 0; // End of program
}
