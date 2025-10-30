#include <iostream>
#include <cctype>

using namespace std;
// Fibonacci series using recursion.
int fibRecursion (int n){
    if(n<= 1) return n;

    return fibRecursion(n-1)+ fibRecursion(n-2);
}

// Fibonacci Series using Divide & Conquer (Matrix Multiplication) Approach
void multiplyStrassenMethod(int F[2][2], int M[2][2]){
    int p1= F[0][0]*(M[0][1] - M[1][1]);
    int p2= (F[0][0] + F[0][1])*M[1][1];
    int p3= (F[1][0] + F[1][1])*M[0][0];
    int p4= F[1][1]* (M[1][0]-M[0][0]);
    int p5= (F[0][0]+ F[1][1])*(M[0][0]+M[1][1]);
    int p6= (F[0][1]-F[1][1])*(M[1][0]+M[1][1]);
    int p7 = (F[0][0]-F[1][0])*(M[0][0]+ M[0][1]);

    F[0][0]=p5+p4-p2+p6;
    F[0][1]=p1+p2;
    F[1][0]=p3+p4;
    F[1][1]=p5+p1-p3-p7;
}

void power (int F[2][2], int n){
    if(n<=1)return;

    int M[2][2]={{1,1},{1,0}};

    power(F,n/2);
    multiplyStrassenMethod(F,F); // even

    if(n%2!=0){
        multiplyStrassenMethod(F,M); //odd
    }
}
int fibMatrix(int n ){
    if (n <= 0)return 0;

    int F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);

    return F[0][0];
}


// Fibonacci series using Dynamic Approach
int fibDynamic(int n){
    if(n<=1) return n;

    int prev1=0, prev2=1, curr;
    for(int i=2 ; i<=n ; i++){
        curr=prev1+prev2;
        prev1= prev2;
        prev2= curr;
    }
    return prev2;
}


int main() {
    char choice;
    int n;

    while (true) {
        int dataChoice;
        cout << "1) Use initialized example value\n"
             << "2) Enter your own value of n\n"
             << "3) Exit\n"
             << "Enter choice (1-3): ";
        cin >> dataChoice;

        if (dataChoice == 1) {
            cout << "\nUsing initialized example value: n = 8" << endl;
            cout << "Fibonacci(8) using Recursion = " << fibRecursion(8) << endl;
            cout << "Fibonacci(8) using Matrix Multiplication = " << fibMatrix(8) << endl;
            cout << "Fibonacci(8) using Dynamic Programming = " << fibDynamic(8) << endl;
            cout << endl;
        }
        else if (dataChoice == 2) {
            while (true) {
                cout << "\nFibonacci Series\n"
                     << "a) Recursion Method\n"
                     << "b) Divide & Conquer (Matrix Multiplication) Method\n"
                     << "c) Dynamic Approach Method\n"
                     << "d) Back to main menu\n"
                     << "Enter your choice (a-d): ";
                cin >> choice;
                choice = tolower(choice);

                if (choice == 'd') {
                    break;
                }

                cout << "Enter the value of n: ";
                cin >> n;

                switch (choice) {
                    case 'a':
                        cout << "Fibonacci("<< n <<") using Recursion = " << fibRecursion(n) << endl;
                        break;
                    case 'b':
                        cout << "Fibonacci("<< n <<") using Matrix Multiplication = " << fibMatrix(n) << endl;
                        break;
                    case 'c':
                        cout << "Fibonacci("<<n<<") using Dynamic Programming = " << fibDynamic(n) << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please select between a-d" << endl;
                }
                cout <<endl;
            }
        }
        else if (dataChoice == 3) {
            cout << "Exiting program..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please select between 1-3\n";
        }
    }

    return 0;
}
