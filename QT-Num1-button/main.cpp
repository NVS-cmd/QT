#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    widget.setWindowTitle("Обо мне");
    widget.resize(200, 150);

    QVBoxLayout *layout = new QVBoxLayout(&widget);

    QLabel *label = new QLabel("Владислав Сергеевич");
    QLabel *op = new QLabel("МГТУ им. Баумана");
    QPushButton *btn1 = new QPushButton ("Изменить текст");

    layout->addWidget(label);
    layout->addWidget(op);
    layout->addWidget(btn1);

    QObject::connect(btn1, &QPushButton::clicked, [op]() {
        static bool isChanged = false;

        if (!isChanged) {
            op->setText("МГТУ им. Баумана");
            isChanged = true;
        } else {
            op->setText("Сборная по футболу");
            isChanged = false;
        }

    });

    widget.show();
    return a.exec();
}

