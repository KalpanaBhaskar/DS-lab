#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int* num) {
    int original = *num;
    int reversed = 0;
    while (*num > 0) {
        reversed = reversed * 10 + (*num % 10);
        *num /= 10;
    }
    *num = original;
    return (original == reversed);
}

bool isArmstrong(int* num) {
    int original = *num;
    int sum = 0;
    int digits = 0;
    int temp = *num;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = *num;
    while (temp > 0) {
        int d = temp % 10;
        sum += pow(d, digits);
        temp /= 10;
    }
    return (sum == original);
}

bool isPerfect(int* num) {
    int sum = 0;
    for (int i = 1; i < *num; i++) {
        if (*num % i == 0) {
            sum += i;
        }
    }
    return (sum == *num);
}

int main() {
    int* num = new int;
    cout << "enter a positive integer: ";
    cin >> *num;
    while (*num <= 0) {
        cout << "reenter valid number > 0: ";
        cin >> *num;
    }

    char choice;
    while (true) {
        cout << "MENU:\na: palindrome\nb: armstrong number\nc: perfect number\nd: exit\n";
        cout << "enter character corresponding to choice of operation: ";
        cin >> choice;

        if (choice == 'a') {
            bool result = isPalindrome(num);
            if (result)
                cout << "number is a palindrome\n";
            else
                cout << "number is not a palindrome\n";
        }

        if (choice == 'b') {
            bool result = isArmstrong(num);
            if (result)
                cout << "number is an armstrong number\n";
            else
                cout << "number is not an armstrong number\n";
        }

        if (choice == 'c') {
            bool result = isPerfect(num);
            if (result)
                cout << "number is a perfect number\n";
            else
                cout << "number is not a perfect number\n";
        }

        if (choice == 'd') {
            cout << "exited\n";
            break;
        }
    }

    delete num;
    return 0;
}