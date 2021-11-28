#ifndef PRINTERTOOL_H
#define PRINTERTOOL_H
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QPrinter>

class PrinterTool : public QMainWindow
{
    Q_OBJECT
public:
    PrinterTool();
    void doPrintPreview();
    void printPreview(QPrinter *printer);
    void createPdf();
    void setUpPage();

private slots:
    void add();
    void clear();
    void quit();
    void print();

private:
    QTextEdit *textEdit;
    QAction *openAction;
    QAction *clearAction;
    QAction *saveAction;
    QAction *exitAction;
    QAction *printAction;
    QMenu *fileMenu;

    std::vector<QString> files;
};

#endif // PRINTERTOOL_H
