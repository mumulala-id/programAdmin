#ifndef PENGELOLAPUSATDATA_H
#define PENGELOLAPUSATDATA_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QDir>
#include "anggota.h"
#include <QStandardPaths>
class pengelolapusatdata : public QObject

{
    Q_OBJECT

public:
  enum hubungan{tambah_personil,tampil_personil,inverntaris};
  explicit  pengelolapusatdata(QObject*parent=0);
    pengelolapusatdata(hubungan,QObject *parent=0);


private :
    QSqlDatabase pusat_data;
    QString nama_pusat_data = "pusatdata.db";
    QString jalur_pusat_data = QStandardPaths::writableLocation(QStandardPaths::DataLocation);

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
    void tambahAnggota(anggota*);
    void perbaruiAnggota(QString, anggota*);
//    void tambahAnggota(QList<anggota>);
     QSqlDatabase pusatData(){return pusat_data;}

};

#endif // PENGELOLAPUSATDATA_H
