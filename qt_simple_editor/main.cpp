#include "mainwindow.h"
#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "notepad.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    w.setGeometry(50, 50, 600, 800);
// One text shows "hello, world" string
//    QTextEdit textEdit;
//    textEdit.setText("hello, world");
//    textEdit.show();


//    QTextEdit* textEdit = new QTextEdit();
//    QPushButton* quitButton = new QPushButton("&Quit");
//    QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

//    QVBoxLayout* layout = new QVBoxLayout();
//    layout->addWidget(textEdit);
//    layout->addWidget(quitButton);

//    QWidget window;
//    window.setLayout(layout);
//    window.show();
    NotePad notepad;
    return a.exec();
}


