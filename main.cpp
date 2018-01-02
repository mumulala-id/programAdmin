#include "surat.h"
#include <QApplication>
#include "pengelolapusatdata.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    surat w;

    w.showMaximized();
    pengelolapusatdata pd;
    pd.hubungkan();

    return a.exec();
}
