#ifndef CDATEEDIT_H
#define CDATEEDIT_H

#include <QWidget>
#include <QComboBox>
#include <QDate>

class CDateEdit : public QWidget
{
    Q_OBJECT

public:
    CDateEdit(QWidget *parent = 0);
    ~CDateEdit();
private :
    QComboBox *kombo_tahun, *kombo_bulan,*kombo_tanggal;
    int tahun_sekarang = QDate::currentDate().year();
    QStringList daftar_tahun;
private slots:
    void ambilJumlahHari();

    void periksa();

public slots:
     void aturJangka(int, int);
       QDate ambilTanggal();
       void aturKeTanggal(QString);
       void aturKeTanggal(QDate);
};

#endif // CDATEEDIT_H
