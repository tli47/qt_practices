#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "printer_tool.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PrinterTool printerTool;
    return a.exec();
}
