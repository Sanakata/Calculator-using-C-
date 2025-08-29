#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

bool isOperatorValid(string tempOp){
    if(tempOp.size() != 1) return false;
    char numOperator = tempOp[0];
    switch(numOperator){
        case '+':
        return true;
        case '-':
        return true;
        case '*':
        return true;
        case '/':
        return true;
        case '%':
        return true;
        default:
        return false;
    }
}

bool isDividedOrModByZero(int secondNumber, char numOperator){
    return secondNumber == 0 && (numOperator == '/' || numOperator == '%');
}

bool isLengthValid(string temp){
    return temp.size() < 10;
}

bool isNumInputValid(const string& temp){
    for(char character : temp){
        if(!isdigit(character)) return false;
    }
    return true;
}

int main(){
    int firstNumber, secondNumber, result, decimalPlaces;
    double resultForDivision;
    string temp1, temp2, tempOp;
    char numOperator = '#';
    
    cout << "---Calculator Program---\n";
    
    cout << "Please enter your first number: ";
    getline(cin, temp1);

    while(!isLengthValid(temp1) || !isNumInputValid(temp1)){
        if(!isLengthValid(temp1)) cout << "Your input exceed the length of the input, please make sure to input the valid length (up to 9 digits)\n";
        else if(!isNumInputValid(temp1)) cout << "Your input contains non digit character, please make sure you only input digits character\n";
        
        cout << "Please enter your first number: ";
        getline(cin, temp1);
    }

    firstNumber = stoi(temp1);

    cout << "Enter operator (+, -, *, /, %): ";
    getline(cin, tempOp);

    while(!isOperatorValid(tempOp)){
        cout << "Your input for operator is invalid, please try again :D\n";
        cout << "Enter operator (+, -, *, /): ";
        getline(cin, tempOp);
    }

    numOperator = tempOp[0];

    cout << "Please enter your second number: ";
    getline(cin, temp2);

    while(!isLengthValid(temp2) || !isNumInputValid(temp2)){
        if(!isLengthValid(temp2)) cout << "Your input exceed the length of the input, make sure to input the valid length (up to 9 digits)\n";
        else if(!isNumInputValid(temp2)) cout << "Your input contains non digit character, please make sure you only input digits characters\n";

        cout << "Please enter your second number: ";
        getline(cin, temp2);
    }

    secondNumber = stoi(temp2);

    while(isDividedOrModByZero(secondNumber, numOperator)){
        cout << "You can't divide by zero, please input other number than zero (0): ";
        cin >> secondNumber;
    }

    if(numOperator == '/'){
        cout << "Enter the number of decimal places to display: ";
        cin >> decimalPlaces;
    }

    cout << firstNumber << " " << numOperator << " " << secondNumber << " = ";

    if(numOperator == '+') cout << firstNumber + secondNumber << "\n";
    else if(numOperator == '-') cout << firstNumber - secondNumber << "\n";
    else if(numOperator == '*') cout << firstNumber * secondNumber << "\n";
    else if(numOperator == '/') cout << fixed << setprecision(decimalPlaces) << (double) firstNumber / secondNumber << "\n";
    else if(numOperator == '%') cout << firstNumber % secondNumber << "\n";

    return 0;
}