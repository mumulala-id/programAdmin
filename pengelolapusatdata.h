#ifndef PENGELOLAPUSATDATA_H
#define PENGELOLAPUSATDATA_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QDir>
#include "anggota.h"

class pengelolapusatdata
{
public:
    pengelolapusatdata();

private :
    QSqlDatabase pusat_data;
    QString nama_pusat_data = "pusatdata.db";
    QString jalur_pusat_data = QDir::homePath()+"/programadmin";
   // QString berkas_pusat_data;

private slots:
    void tetapkanNamaPusatData(QString);
    void tetapkanJalurPusatData();
    bool pulihkanPudatData();
    bool bukaPusatData();
    bool buatTabel();
    QString ambilNamaPusatData();

public slots:
    void hubungkan();
    void persiapan();
    void kumpulkan();
    void tutup();
    void sisipkanKeTabel();
    void tambahAnggota(anggota);
    void tambahAnggota(QList<anggota>);

};

#endif // PENGELOLAPUSATDATA_H
