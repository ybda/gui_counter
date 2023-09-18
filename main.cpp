#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Create the main window
    QWidget window;
    window.setWindowTitle("Number Counter");

    // Create a layout to arrange the widgets vertically
    QVBoxLayout layout(&window);

    // Create a label to display the current number
    QLabel numberLabel("0", &window);
    numberLabel.setAlignment(Qt::AlignCenter);
    layout.addWidget(&numberLabel);

    // Create a QLineEdit for user input
    QLineEdit inputField(&window);
    inputField.setPlaceholderText("Enter a number");
    layout.addWidget(&inputField);

    // Create an "Increase" button
    QPushButton increaseButton("Increase", &window);
    layout.addWidget(&increaseButton);

    // Create a "Decrease" button
    QPushButton decreaseButton("Decrease", &window);
    layout.addWidget(&decreaseButton);

    int number = 0;

    // Create slots to handle button clicks
    QObject::connect(&increaseButton, &QPushButton::clicked, [&]() {
        // Get the user input and convert it to an integer
        int increment = inputField.text().toInt();

        // Increment the number by the specified value and update the label
        number += increment;
        numberLabel.setText(QString::number(number));
    });

    QObject::connect(&decreaseButton, &QPushButton::clicked, [&]() {
        // Get the user input and convert it to an integer
        int decrement = inputField.text().toInt();

        // Decrement the number by the specified value and update the label
        number -= decrement;
        numberLabel.setText(QString::number(number));
    });

    // Show the main window
    window.show();

    return QApplication::exec();
}