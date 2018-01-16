#include "surat.h"
#include <QApplication>
//#include "pengelolapusatdata.h"
#include "dialogtambahanggota.h"
#include "cdateedit.h"
#include "jendalautama.h"
#include "QSqlDatabase"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("progamAdmin");

    QSqlDatabase::addDatabase("QSQLITE", "tambah_personil");
    QSqlDatabase::addDatabase("QSQLITE","tampil_personil");

    jendalaUtama ju;
    ju.showMaximized();
    return a.exec();
}
