//#include<iostream>
//#include<ctime>
//#include<cstdlib>
//#include <cmath> 
//
//using namespace std;
//
//class Relation
//{
//public:
//    // Constructor
//    Relation();
//
//    // Destructor
//    ~Relation();
//
//    // Function to calculate the number of relations
//    int Number_oF_relations(int m, int n);
//
//    // Function to take input for arrays
//    void input(int size1, int size2, int size3);
//
//    // Function to display the arrays
//    void display();
//
//    // Function to copy a dynamic array
//    int* copyDynamicArray(const int* sourceArray, int size);
//
//
//    // Function to make relations based on user input
//    void Make_Relations();
//
//private:
//    int* f1;
//    int* f2;
//    int* f3;
//    int length1;
//    int length2;
//    int length3;
//
//    int** adjMatrix;  // Adjacency matrix
//
//    // Function to add an edge to the graph
//    void addEdge(int v, int w);
//
//    // Function to delete a 2D array
//    void delete2DArray(int** array, int rows);
//
//    // Function to make relations for a given pair of arrays
//    void MakeRelation(int* arr1, int* arr2, int size1, int size2);
//
//    // Function to display a pair of relations
//    void displayRelations(int* a1, int* a2, int i, int j);
//
//    // Function to display the chosen relations
//    void ChoosenRelations(int* a1, int* a2, int s1, int s2);
//
//    // Functions to check properties of relations
//    void IsReflexive(int s1, int s2);
//    void IsSymmetric(int s1, int s2);
//    void IsTransitive(int s1, int s2);
//    void IsAntisymmetric(int s1, int s2);
//};
//
//// Constructor implementation
//Relation::Relation() {
//    length1 = length2 = length3 = 0;
//    f1 = f2 = f3 = NULL;
//    adjMatrix = NULL;
//}
//
//// Destructor implementation
//Relation::~Relation()
//{
//    delete[] f1;
//    f1 = NULL;
//    delete[] f2;
//    f2 = NULL;
//    delete[] f3;
//    f3 = NULL;
//}
//
//// Function to take input for arrays
//void Relation::input(int size1, int size2, int size3) {
//    f1 = new int[size1];
//    f2 = new int[size2];
//    f3 = new int[size3];
//
//    cout << "Enter THE Elements for Set A : ";
//    for (int i = 0; i < size1; i++) {
//        cin >> f1[i];
//    }
//
//    cout << "Enter THE Elements for Set B : ";
//    for (int i = 0; i < size2; i++) {
//        cin >> f2[i];
//    }
//
//    cout << "Enter THE Elements for Set C : ";
//    for (int i = 0; i < size3; i++) {
//        cin >> f3[i];
//    }
//
//    length1 = size1;
//    length2 = size2;
//    length3 = size3;
//}
//
//// Function to copy a dynamic array
//int* Relation::copyDynamicArray(const int* sourceArray, int size) {
//    int* newArray = new int[size];
//    for (int i = 0; i < size; i++) {
//        newArray[i] = sourceArray[i];
//    }
//    return newArray;
//}
//
//int Relation::Number_oF_relations(int m, int n)
//{
//    return pow(2, m * n);
//}
//
//// Function to make relations based on user input
//void Relation::Make_Relations() {
//    cout << endl;
//
//    int choice = 0;
//
//    do {
//        cout << "PRESS 1 FOR A X A" << endl;
//        cout << "PRESS 2 FOR B X B" << endl;
//        cout << "PRESS 3 FOR C X C" << endl;
//        cout << "PRESS 4 FOR A X B" << endl;
//        cout << "PRESS 5 FOR A X C" << endl;
//        cout << "PRESS 6 FOR B X C" << endl;
//        cout << "PRESS 0 FOR EXIT" << endl;
//
//        cout << "ENTER YOUR CHOICE :"; cin >> choice;
//        system("cls");
//
//        switch (choice) {
//        case 0: {
//            break;
//        }
//        case 1:
//        {
//
//            MakeRelation(f1, f1, length1, length1);
//            cout << endl;
//            IsReflexive(length1, length1);
//            cout << endl;
//            IsSymmetric(length1, length1);
//            cout << endl;
//            IsTransitive(length1, length1);
//            cout << endl;
//            IsAntisymmetric(length1, length1);
//            if (adjMatrix != NULL) {
//                delete2DArray(adjMatrix, length1);
//            }
//
//            break;
//        }
//        case 2: {
//            MakeRelation(f2, f2, length2, length2);
//            cout << endl;
//            IsReflexive(length2, length2);
//            cout << endl;
//            IsSymmetric(length2, length2);
//            cout << endl;
//            IsTransitive(length2, length2);
//            cout << endl;
//            IsAntisymmetric(length2, length2);
//            if (adjMatrix != NULL) {
//                delete2DArray(adjMatrix, length2);
//            }
//            break;
//        }
//        case 3: {
//            MakeRelation(f3, f3, length3, length3);
//            cout << endl;
//            IsReflexive(length3, length3);
//            cout << endl;
//            IsSymmetric(length3, length3);
//            cout << endl;
//            IsTransitive(length3, length3);
//            cout << endl;
//            IsAntisymmetric(length3, length3);
//            if (adjMatrix != NULL) {
//                delete2DArray(adjMatrix, length3);
//            }
//            break;
//        }
//        case 4: {
//            MakeRelation(f1, f2, length1, length2);
//            cout << endl;
//            IsReflexive(length1, length2);
//            cout << endl;
//            IsSymmetric(length1, length2);
//            cout << endl;
//            IsTransitive(length1, length2);
//            cout << endl;
//            IsAntisymmetric(length1, length2);
//
//            if (adjMatrix != NULL) {
//                delete2DArray(adjMatrix, length1);
//            }
//            break;
//        }
//        case 5: {
//            MakeRelation(f1, f3, length1, length3);
//            cout << endl;
//            IsReflexive(length1, length3);
//            cout << endl;
//            IsSymmetric(length1, length3);
//            cout << endl;
//            IsTransitive(length1, length3);
//            cout << endl;
//            IsAntisymmetric(length1, length3);
//            if (adjMatrix != NULL) {
//                delete2DArray(adjMatrix, length1);
//            }
//            break;
//        }
//        case 6: {
//            MakeRelation(f2, f3, length2, length3);
//            cout << endl;
//            IsReflexive(length2, length3);
//            cout << endl;
//            IsSymmetric(length2, length3);
//            cout << endl;
//            IsTransitive(length2, length3);
//            cout << endl;
//            IsAntisymmetric(length2, length3);
//            if (adjMatrix != NULL) {
//                delete2DArray(adjMatrix, length2);
//            }
//            break;
//        }
//        default:
//            break;
//        }
//
//    } while (choice != 0);
//}
//
//// Function to make relations for a given pair of arrays
//void Relation::MakeRelation(int* arr1, int* arr2, int size1, int size2) {
//
//
//    adjMatrix = new int* [size1];
//    for (int i = 0; i < size1; ++i) {
//        adjMatrix[i] = new int[size2];
//        for (int j = 0; j < size2; ++j) {
//            adjMatrix[i][j] = 0;
//        }
//    }
//
//    for (int i = 0; i < size1; i++) {
//        for (int j = 0; j < size2; j++) {
//            int choice = 0;
//            displayRelations(arr1, arr2, i, j);
//            cout << "ENTER 1 , IF NOT 0 :"; cin >> choice;
//
//            if (choice == 1) {
//                addEdge(i, j);
//            }
//        }
//    }
//
//    ChoosenRelations(arr1, arr2, size1, size2);
//    cout << endl << "The total number of relations : " << Relation::Number_oF_relations(size1, size2) << endl;
//}
//
//// Function to add an edge to the graph
//void Relation::addEdge(int v, int w)
//{
//    // Add the edge to the adjacency matrix
//    adjMatrix[v][w] = 1;
//}
//
//// Function to delete a 2D array
//void Relation::delete2DArray(int** array, int rows) {
//    for (int i = 0; i < rows; ++i) {
//        delete[] array[i];
//    }
//    delete[] array;
//}
//
//// Function to display a pair of relations
//void Relation::displayRelations(int* a1, int* a2, int i, int j) {
//    cout << "(" << a1[i] << "," << a2[j] << ")  ";
//}
//
//// Function to display the chosen relations
//void Relation::ChoosenRelations(int* a1, int* a2, int s1, int s2) {
//    cout << endl;
//    cout << "YOUR CHOSEN RELATIONS ARE :";
//    for (int i = 0; i < s1; i++) {
//        for (int j = 0; j < s2; j++) {
//            if (adjMatrix[i][j] == 1) {
//                displayRelations(a1, a2, i, j);
//            }
//        }
//    }
//}
//
//// Function to check if the relation is reflexive
//void Relation::IsReflexive(int s1, int s2) {
//    for (int i = 0; i < s1; ++i) {
//        for (int j = 0; j < s2; j++) {
//            if (i == j && adjMatrix[i][j] != 1) {
//                cout << "THIS RELATION IS NOT REFLEXIVE " << endl;
//                return;
//            }
//        }
//    }
//    cout << "THIS RELATION IS REFLEXIVE " << endl;
//}
//
//// Function to check if the relation is symmetric
//void Relation::IsSymmetric(int s1, int s2) {
//    if (s1 != s2) {
//        cout << "THIS IS NOT A SYMMETRIC RELATION " << endl;
//        return;
//    }
//
//    for (int i = 0; i < s1; ++i) {
//        for (int j = 0; j < s2; j++) {
//            if (i != j && adjMatrix[i][j] != adjMatrix[j][i]) {
//                cout << "THIS RELATION IS NOT SYMMETRIC RELATION " << endl;
//                return;
//            }
//        }
//    }
//    cout << "THIS RELATION IS SYMMETRIC RELATION " << endl;
//}
//
//// Function to check if the relation is transitive
//void Relation::IsTransitive(int s1, int s2) {
//    int** squaredMatrix = new int* [s1];
//    for (int i = 0; i < s1; ++i) {
//        squaredMatrix[i] = new int[s2];
//        for (int j = 0; j < s2; ++j) {
//            squaredMatrix[i][j] = 0;
//            for (int k = 0; k < s1; ++k) {
//                squaredMatrix[i][j] += adjMatrix[i][k] * adjMatrix[k][j];
//            }
//        }
//    }
//
//    for (int i = 0; i < s1; ++i) {
//        for (int j = 0; j < s2; ++j) {
//            if (adjMatrix[i][j] == 0 && squaredMatrix[i][j] != 0) {
//                cout << "THIS RELATION IS NOT TRANSITIVE " << endl;
//                for (int k = 0; k < s1; ++k) {
//                    delete[] squaredMatrix[k];
//                }
//                delete[] squaredMatrix;
//                return;
//            }
//        }
//    }
//
//    cout << "THIS RELATION IS TRANSITIVE " << endl;
//
//    for (int i = 0; i < s1; ++i) {
//        delete[] squaredMatrix[i];
//    }
//    delete[] squaredMatrix;
//}
//
//// Function to check if the relation is antisymmetric
//void Relation::IsAntisymmetric(int s1, int s2) {
//    for (int i = 0; i < s1; ++i) {
//        for (int j = 0; j < s2; ++j) {
//            if (i != j && adjMatrix[i][j] == 1 && adjMatrix[j][i] == 1) {
//                cout << "THIS RELATION IS NOT ANTISYMMETRIC " << endl;
//                return;
//            }
//        }
//    }
//    cout << "THIS RELATION IS ANTISYMMETRIC " << endl;
//}
//
//int main()
//{
//    srand(time(0));
//    int size1, size2, size3;
//    cout << "ENTER THE SIZE OF A : ";
//    cin >> size1;
//    cout << "ENTER THE SIZE OF B : ";
//    cin >> size2;
//    cout << "ENTER THE SIZE OF C : ";
//    cin >> size3;
//
//    Relation r;
//    r.input(size1, size2, size3);
//    r.Make_Relations();
//
//}
