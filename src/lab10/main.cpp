#include "mainwindow.h"
#include "smartptr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    smart_ptr<QMainWindow> w(new QMainWindow());
    Ui_MainWindow b;
    b.setupUi(w.operator->());

    w->show();

    return a.exec();
}
