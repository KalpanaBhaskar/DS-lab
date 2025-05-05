#include <iostream>
using namespace std;

class Area {
    double length, breadth, height;

public:
    Area() {
        length = breadth = height = 0;
    }

    void setLength(double l) {
        length = l;
    }

    void setBreadth(double b) {
        breadth = b;
    }

    void setHeight(double h) {
        height = h;
    }

    double areaSquare() {
        return length * length;
    }

    double areaCube() {
        return 6 * length * length;
    }

    double areaRectangle() {
        return length * breadth;
    }

    double areaCuboid() {
        return 2 * (length * breadth + breadth * height + length * height);
    }
};

int main() {
    Area a;
    char choice;

    while (true) {
        cout << "MENU:\na: square\nb: cube\nc: rectangle\nd: cuboid\ne: exit\n";
        cout << "enter character corresponding to choice of operation: ";
        cin >> choice;

        if (choice == 'a') {
            double side;
            cout << "enter length of square: ";
            cin >> side;
            while (side <= 0) {
                cout << "reenter valid length > 0: ";
                cin >> side;
            }
            a.setLength(side);
            cout << "area of square: " << a.areaSquare() << "\n";
        }

        if (choice == 'b') {
            double side;
            cout << "enter length of cube: ";
            cin >> side;
            while (side <= 0) {
                cout << "reenter valid length > 0: ";
                cin >> side;
            }
            a.setLength(side);
            cout << "surface area of cube: " << a.areaCube() << "\n";
        }

        if (choice == 'c') {
            double l, b;
            cout << "enter length and breadth of rectangle: ";
            cin >> l >> b;
            while (l <= 0 || b <= 0) {
                cout << "reenter valid length and breadth > 0: ";
                cin >> l >> b;
            }
            a.setLength(l);
            a.setBreadth(b);
            cout << "area of rectangle: " << a.areaRectangle() << "\n";
        }

        if (choice == 'd') {
            double l, b, h;
            cout << "enter length, breadth and height of cuboid: ";
            cin >> l >> b >> h;
            while (l <= 0 || b <= 0 || h <= 0) {
                cout << "reenter valid length, breadth, height > 0: ";
                cin >> l >> b >> h;
            }
            a.setLength(l);
            a.setBreadth(b);
            a.setHeight(h);
            cout << "surface area of cuboid: " << a.areaCuboid() << "\n";
        }

        if (choice == 'e') {
            cout << "exited\n";
            break;
        }
    }

    return 0;
}
