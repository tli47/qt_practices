#ifndef NOTEPAD_H
#define NOTEPAD_H
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QApplication>
#include <QMainWindow>
#include <QMenu>

class NotePad : public QMainWindow
{
    Q_OBJECT
public:
    NotePad();

private slots:
    void open();
    void save();
    void quit();

private:
    QTextEdit *textEdit;
    QAction *openAction;
    QAction *saveAction;
    QAction *exitAction;
    QMenu *fileMenu;
};

#endif // NOTEPAD_H
