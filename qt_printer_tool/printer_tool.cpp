#include "printer_tool.h"

#include <QVBoxLayout>
#include <QMessageBox>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPageSetupDialog>
#include <QIcon>
#include <QPainter>

PrinterTool::PrinterTool()
{
    openAction = new QAction(tr("&Add"), this);
    clearAction = new QAction(tr("&Clear"), this);
    exitAction = new QAction(tr("E&xit"), this);
    printAction = new QAction(tr("P&rint"), this);

    connect(openAction, SIGNAL(triggered()), this, SLOT(add()));
    connect(clearAction, SIGNAL(triggered()), this, SLOT(clear()));
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(printAction, SIGNAL(triggered()), this, SLOT(print()));

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(clearAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    fileMenu->addAction(printAction);


    textEdit = new QTextEdit;
    setCentralWidget(textEdit);

    //setWindowIcon(QIcon("C:/Users/tli/work/github/qt_practices/qt_printer_tool/printer.png"));
    // This method could only set left top icon.
    //setWindowIcon(QIcon(":/icons/printer.png"));
    setWindowTitle(tr("Printer Tool"));
    resize(800,800);
    //setIcon("");
    show();
}

void PrinterTool::quit()
{
    QMessageBox messageBox;
    messageBox.setWindowTitle(tr("Printer Tool"));
    messageBox.setText(tr("Do you really want to quit?"));
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    if (messageBox.exec() == QMessageBox::Yes)
        qApp->quit();
}

void PrinterTool::add()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Text Files (*.txt);;C++ Files (*.cpp *.h);;Pdf Files (*.pdf)"));

    if (fileName != "") {
//        QFile file(fileName);
//        if (!file.open(QIODevice::ReadOnly)) {
//            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
//            return;
//        }
//        QTextStream in(&file);
        textEdit->append(fileName);
        //file.close();
        files.push_back(fileName);
    }
}

void PrinterTool::clear()
{
    textEdit->clear();
    files.clear();
}

void PrinterTool::print()
{
    QString text = "hello, this is a test page\n";
    QPrinter printer;

    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Print Document"));
//    if (editor->textCursor().hasSelection())
//        dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if (dialog.exec() != QDialog::Accepted) {
        textEdit->append("Print cancel...");
        return;
    }

    //textEdit->setText("Print ...");
    textEdit->append("Print ...");

    // Printer text
//    QPainter painter;
//    painter.begin(&printer);
//    painter.drawText(100, 100, 500, 500, Qt::AlignLeft|Qt::AlignTop, text);
//    painter.end();

    QPainter painter(&printer);
    for (auto& fileName : files) {
        QImage img(fileName);
        painter.drawImage(QPoint(0,0),img);
    }
    painter.end();
}

// 打印预览
void PrinterTool::doPrintPreview()
{
//    QPrinter printer;
//    // 创建打印预览对话框
//    QPrintPreviewDialog preview(&printer, this);
//    // 当要生成预览页面时，发射paintRequested()信号
//    connect(&preview, SIGNAL(paintRequested(QPrinter*)),
//                  this,SLOT(printPreview(QPrinter*)));
//    preview.exec();
}

void PrinterTool::printPreview(QPrinter *printer)
{
    //textEdit->print(printer);
}
// 生成PDF文件
void PrinterTool::createPdf()
{
//    QString fileName = QFileDialog::getSaveFileName(this, tr("导出PDF文件"), QString(), "*.pdf");
//    if (!fileName.isEmpty()) {
//        // 如果文件后缀为空，则默认使用.pdf
//        if (QFileInfo(fileName).suffix().isEmpty())
//            fileName.append(".pdf");
//        QPrinter printer;
//        // 指定输出格式为pdf
//        printer.setOutputFormat(QPrinter::PdfFormat);
//        printer.setOutputFileName(fileName);
//        textEdit->print(&printer);
//    }
}

void PrinterTool::setUpPage()
{
//    QPrinter printer;
//    QPageSetupDialog pageSetUpdlg(&printer, this);
//    if (pageSetUpdlg.exec() == QDialog::Accepted)
//    {
//        printer.setOrientation(QPrinter::Landscape);
//    }
//    else
//    {
//        printer.setOrientation(QPrinter::Portrait);
//    }
}

