#include "kotaktandatangan.h"
#include <QVBoxLayout>

#include <QPainter>
kotaktandatangan::kotaktandatangan(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *tata_letak_utama = new QVBoxLayout;
    label_tempat_tanggal = new QLabel(this);
    label_pejabat = new QLabel(this);
    label_nama_pejabat  = new QLabel(this);
    label_pangkat_nrp = new QLabel(this);

    tata_letak_utama->addWidget(label_tempat_tanggal);
    tata_letak_utama->addWidget(label_pejabat);
    tata_letak_utama->addSpacing(100);
    tata_letak_utama->addWidget(label_nama_pejabat);
    tata_letak_utama->addWidget(label_pangkat_nrp);
    tata_letak_utama->setSpacing(0);
    setLayout(tata_letak_utama);

   setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void kotaktandatangan::tetapkanKota(QString _kota){

    kota = _kota;
    label_tempat_tanggal->setText(ambilKotaTanggal());
}

void kotaktandatangan::tetapkanTanggal(QString _tanggal){

    tanggal = _tanggal;
     label_tempat_tanggal->setText(ambilKotaTanggal());

}

void kotaktandatangan::tetapkanPejabat(QString _pejabat){
     pejabat = _pejabat;
label_pejabat->setText(pejabat);
}

void kotaktandatangan::tetapkanNamaPejabat(QString _nama_pejabat){

    nama_pejabat = _nama_pejabat;
    label_nama_pejabat->setText(nama_pejabat);


}

void kotaktandatangan::tetapkanPangkatNrp(QString _pangkat_nrp){

    pangkat_nrp = _pangkat_nrp;
    label_pangkat_nrp->setText(pangkat_nrp);
}

QString kotaktandatangan::ambilKotaTanggal(){

    return kota+", "+tanggal;

}

void kotaktandatangan::paintEvent(QPaintEvent *){

    QPoint titik_awal = label_nama_pejabat->geometry().bottomLeft();
    QPoint titik_akhir = label_nama_pejabat->geometry().bottomRight();

    QPen pen(Qt::black);
    QPainter p(this);
    p.drawLine(titik_awal, titik_akhir);

    label_tempat_tanggal->setAlignment(Qt::AlignCenter);
            label_pejabat->setAlignment(Qt::AlignCenter);
            label_nama_pejabat->setAlignment(Qt::AlignCenter);
            label_pangkat_nrp->setAlignment(Qt::AlignCenter);




}
