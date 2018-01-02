#ifndef KOP_H
#define KOP_H

#include <QWidget>
#include <QLabel>

class kop : public QWidget
{
    Q_OBJECT

public:
    kop(QWidget *parent = 0);
    ~kop();

private:
    QLabel *label_kesatuan_induk;
    QLabel *label_kesatuan_sub_induk;
    QLabel *label_kesatuan;
    QString nama_kesatuan;
    QString nama_kesatuan_sub_induk;
    QString nama_kesatuan_induk;

public slots:
    void tetapkanNamaKesatuan(QString);
    void tetapkanNamaKesatuanSubInduk(QString);
    void tetapkanNamaKesatuanInduk(QString);

protected :
    void paintEvent(QPaintEvent *);
};

#endif // kop_H
