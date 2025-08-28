#include <bits/stdc++.h>
using namespace std;

bool isOperatorValid(char numOperator){
    switch(numOperator){
        case '+':
        return true;
        case '-':
        return true;
        case '*':
        return true;
        case '/':
        return true;
        default:
        return false;
    }
}

bool isDividedByZero(int secondNumber, char numOperator){
    return secondNumber == 0 && numOperator == '/';
}

int main(){
    int firstNumber, secondNumber, result;
    char numOperator = '#';
    
    cout << "---Calculator Program---\n";
    
    cout << "Please enter your first number: ";
    cin >> firstNumber;

    cout << "Enter operator (+, -, *, /): ";
    cin >> numOperator;
    while(!isOperatorValid(numOperator)){
        cout << "Your input for operator is invalid, please try again :D\n";
        cout << "Enter operator (+, -, *, /): ";
        cin >> numOperator;
    }

    cout << "Please enter your second number: ";
    cin >> secondNumber;
    while(isDividedByZero(secondNumber, numOperator)){
        cout << "You can't divide by zero, please input other number than zero (0): ";
        cin >> secondNumber;
    }

    if(numOperator == '+') result = firstNumber + secondNumber;
    else if(numOperator == '-') result = firstNumber - secondNumber;
    else if(numOperator == '*') result = firstNumber * secondNumber;
    else if(numOperator == '/') result = firstNumber / secondNumber;

    cout << firstNumber << " " << numOperator << " " << secondNumber << " = " << result << "\n";
    return 0;
}