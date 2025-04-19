#include <iostream>
using namespace std;

class Euler {
public:
    int vertices;
    char** arr;

    Euler(int v) {
        vertices = v;
        arr = new char* [v];
        for (int i = 0; i < v; ++i) {
            arr[i] = new char[v];

            for (int j = 0; j < v; ++j) {
                arr[i][j] = '0';
            }
        }
    }
    void edges(char u, char v, bool isDirected)
    {
        arr[u - 'A'][v - 'A'] = '1';
        if (!isDirected) {
            arr[v - 'A'][u - 'A'] = '1';
        }
    }

    void display() {
        for (int i = 0; i < vertices; ++i) {
            int degree = 0;
            for (int j = 0; j < vertices; ++j) {
                degree += (arr[i][j] == '1');
            }
            degree += (arr[i][i] == '1');
            cout << "Degree of vertex " << static_cast<char>('A' + i) << " : " << degree << endl;
        }
    }
    bool euler_path() {
        int oddDegreeCount = 0;
        for (int i = 0; i < vertices; ++i) {
            int degree = 0;
            for (int j = 0; j < vertices; ++j) {
                degree += (arr[i][j] == '1');
            }
            degree += (arr[i][i] == '1');

            if (degree % 2 != 0) {
                oddDegreeCount++;
            }
        }

        return oddDegreeCount == 0 || oddDegreeCount == 2;
    }
    bool euler_circuit() {
        for (int i = 0; i < vertices; ++i) {
            int degree = 0;
            for (int j = 0; j < vertices; ++j) {
                degree += (arr[i][j] == '1');
            }
            degree += (arr[i][i] == '1');
            if (degree % 2 != 0) {
                return false;
            }
        }
        return true;
    }

    ~Euler() {
        for (int i = 0; i < vertices; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main() {
    int num;
    cout << "Please Enter the number of vertices : ";
    cin >> num;


    if (num <= 0 || num > 26) {
        cout << "Invalid number of vertices. Exiting the program." << endl;
        return 1;
    }

    char graphType;
    cout << "Is the graph directed? (y/n): ";
    cin >> graphType;


    Euler obj(num);
    int choice;
    do {
        cout << "Please Enter 1 to add Edge" << endl;
        cout << "Please Enter 2 to Print Degrees" << endl;
        cout << "Please Enter 3 to Check Eulerian Circuit" << endl;
        cout << "Please Enter 4 to Check Eulerian Path" << endl;
        cout << "Please Enter 5 to Exit the Program" << endl;
        cout << "Please Enter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1: {
            char u, v;
            cout << "Please Enter Starting vertex : ";
            cin >> u;
            cout << "Please Enter Ending vertex : ";
            cin >> v;


            if (u < 'A' || u >= 'A' + num || v < 'A' || v >= 'A' + num)
            {
                cout << "Invalid vertices. Please enter vertices in the range A to " << static_cast<char>('A' + num - 1) << endl;
                break;
            }

            obj.edges(u, v, (graphType == 'y' || graphType == 'Y'));
            break;
        }
        case 2:
            cout << "The Degrees of Each vertices in the graph" << endl;
            obj.display();
            break;
        case 3:
            if (obj.euler_circuit()) {
                cout << "The graph has an Eulerian circuit." << endl;
            }
            else {
                cout << "The graph does not have an Eulerian circuit." << endl;
            }
            break;
        case 4:
            if (obj.euler_path()) {
                cout << "The graph has an Eulerian path." << endl;
            }
            else {
                cout << "The graph does not have an Eulerian path." << endl;
            }
            break;
        case 5:
            cout << "The Program is exit" << endl;
            break;
        default:
            cout << "wrong input" << endl;
        }
    } while (choice != 5);
}
