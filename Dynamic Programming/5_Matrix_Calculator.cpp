// simple matrix calculator
#include <iostream>
#include <cstdlib>
#include <limits> 

// A 3x3 matrix
const int M_SIZE = 3;
typedef double matrix[M_SIZE][M_SIZE];

// function prototypes
void printMatrix(const matrix &mat);
bool inputMatrix(matrix &mat);
void addMat(const matrix &mat1, const matrix &mat2, matrix &result);
void subtractMat(const matrix &mat1, const matrix &mat2, matrix &result);
void defineMat();

using namespace std;

// declare matrices:
matrix matA;
matrix matB;
matrix result;

int main()
{
    int choice = -1;
	

    cout << "When filling up matrices, separate individual elements \n"
			"by a space(e.g 2 4 1.4 56.3 ...) \n\n";

    defineMat();

    system("CLS");

    while(choice != 3) {
        cout << "Matrix A:\n";
        printMatrix(matA);
        cout << "\nMatrix B:\n";
        printMatrix(matB);

        cout << "\n** You choose from the following **\n\n"
            << "0 - Redefine Matrix\n"
            << "1 - Addition\n"
            << "2 - Substraction\n"
            << "3 - Quit\n\n"
            << "enter your choice: ";

		while(!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "\nERROR: Please enter valid input!\n" 
				 << "Enter your choice again: ";
		}
			
        cout << endl;

        switch(choice) {
        case 0 :
            defineMat();
            break;

        case 1 :
            addMat(matA, matB, result);
            cout << "Addition of Matrix A and Matrix B is:\n";
            printMatrix(result);
            break;

        case 2 :
            subtractMat(matA, matB, result);
            cout << "Subtraction of Matrix A and Matrix B is:\n";
            printMatrix(result);
            break;

        case 3 : 
			cout << "Thank you for using this software! :D\n";
            break;

        default :
            cout << "That's not a choice.\n";
        }

        cout << "\npress any key...\n";

		// clears input buffer and wait for input:
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        system("CLS");
    }

    return 0;
}

void defineMat()
{ 
    while(true) {
		cout << "input 9 elements into your 3x3 matrix A: \n";
		if(inputMatrix(matA))
			break;
	}
	
	while(true) {
		cout << "input 9 elements into your 3x3 matrix B: \n";
		if(inputMatrix(matB))
			break;
	}
}

void printMatrix(const matrix &mat)
{
    for(int i = 0; i < M_SIZE; i++) {
        cout << "[";
        for(int j = 0; j < M_SIZE; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "]" << endl;
    }
}

bool inputMatrix(matrix &mat)
{
    for(int i = 0; i < M_SIZE; i++) {
        for(int j = 0; j < M_SIZE; j++) {
            cin >> mat[i][j];
			// terminates function on failure
            if(cin.fail()) {
                cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "\nERROR: Please enter valid input!\n" << endl;
                return false;
            }
        }
    }
	// trims the excess input from input buffer:
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return true;
}

void addMat(const matrix &mat1, const matrix &mat2, matrix &result)
{
    for(int i = 0; i < M_SIZE; i++) {
        for(int j = 0; j < M_SIZE; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMat(const matrix &mat1, const matrix &mat2, matrix &result)
{
    for(int i = 0; i < M_SIZE; i++) {
        for(int j = 0; j < M_SIZE; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}