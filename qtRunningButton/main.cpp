#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QApplication>

class JumpyButton : public QPushButton {
    int dx=10;
    int dy=10;

public:
    using QPushButton::QPushButton;

protected:
    void mousePressEvent (QMouseEvent *event) override {
        QWidget *p =this->parentWidget();
        if (p) {
            if (this->x() + dx + this->width() > p->width() || this->x() + dx < 0) {
                dx = -dx;
            }
            if (this->y() + dy + this->height() > p->height() || this->y() + dy < 0) {
                dy = -dy;
            }
            this->move(this->x() + dx, this->y() + dy);
        }
        QPushButton::mousePressEvent(event);
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    widget.setMinimumSize(300, 230);
    widget.setWindowTitle("Бегающая кнопка");

    JumpyButton* btn = new JumpyButton("Нажми на меня", &widget);
    btn->setGeometry(10, 10, 100, 30);

    widget.show();
    return a.exec();
}
