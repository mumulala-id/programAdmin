#ifndef KOTAKTANDATANGAN_H
#define KOTAKTANDATANGAN_H

#include <QWidget>
#include <QLabel>

class kotaktandatangan : public QWidget
{
    Q_OBJECT
public:
    explicit kotaktandatangan(QWidget *parent = nullptr);

signals:

private:
    QString kota;
    QString tanggal;
    QString pejabat;
    QString nama_pejabat;
    QString pangkat_nrp;


    QLabel *label_tempat_tanggal;
    QLabel *label_pejabat;
    QLabel *label_nama_pejabat;
    QLabel *label_pangkat_nrp;
private slots:
    QString ambilKotaTanggal();


public slots:

    void tetapkanKota(QString);
    void tetapkanTanggal(QString);
    void tetapkanPejabat(QString);
    void tetapkanNamaPejabat(QString);
    void tetapkanPangkatNrp(QString);
protected:
    void paintEvent(QPaintEvent *);
};

#endif // KOTAKTANDATANGAN_H
