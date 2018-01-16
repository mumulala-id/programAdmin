#ifndef JENDELAPERSONEL_H
#define JENDELAPERSONEL_H

#include <QDialog>
#include <QTableView>
#include <QSqlTableModel>
#include <QPushButton>
#include <QSqlQueryModel>
#include "anggota.h"
#include "pengelolapusatdata.h"
#include "tablemodel.h"
class jendelaPersonel : public QDialog
{
    Q_OBJECT
public:
    explicit jendelaPersonel(QWidget*parent=0);
    ~jendelaPersonel();
 private:
QPushButton *tombol_sunting ;
QPushButton *tombol_pisah;
QPushButton *tombol_tambah;
QPushButton *tombol_profil;
    QTableView *tabel;
    TableModel *model;
    pengelolapusatdata *pengolah;
    QSqlQueryModel *m_model;
private slots:
    void bukaDialogTambah();
    void editAnggota();
    void aktifkanTombol();
    QString ambilNrp();
    anggota *ambilAnggota(QString);
    void segarkan();
public slots:

};

#endif // JENDELAPERSONEL_H
