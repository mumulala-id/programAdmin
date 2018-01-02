#include "kop.h"
#include <QVBoxLayout>
#include <QPainter>
kop::kop(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *tata_letak_utama = new QVBoxLayout;
    label_kesatuan_induk = new QLabel(this);
//    label_kesatuan_induk->setAutoFillBackground(true);
    label_kesatuan_sub_induk = new QLabel(this);
    label_kesatuan = new QLabel(this);

    tata_letak_utama->addWidget(label_kesatuan_induk);
    tata_letak_utama->addWidget(label_kesatuan_sub_induk);
    tata_letak_utama->addWidget(label_kesatuan);

    tata_letak_utama->setSpacing(0);
    setLayout(tata_letak_utama);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void kop::tetapkanNamaKesatuan(QString _nama_kesatuan){
    nama_kesatuan = _nama_kesatuan;
    label_kesatuan->setText(nama_kesatuan);
    update();
}

void kop::tetapkanNamaKesatuanSubInduk(QString _nama_kesatuan_sub_induk){
    nama_kesatuan_sub_induk = _nama_kesatuan_sub_induk;
    label_kesatuan_sub_induk->setText(nama_kesatuan_sub_induk);
    update();
}


void kop::tetapkanNamaKesatuanInduk(QString _nama_kesatuan_induk){

    nama_kesatuan_induk = _nama_kesatuan_induk;
    label_kesatuan_induk->setText(nama_kesatuan_induk);
update();
}
void kop::paintEvent(QPaintEvent *){
    //mencari yang paling panjang
//    int paling_panjang;



    QPoint titik_mulai;
    QPoint titik_akhir;

    titik_mulai = label_kesatuan->geometry().bottomLeft();
    titik_akhir = label_kesatuan->geometry().bottomRight();
    label_kesatuan_induk->setAlignment(Qt::AlignCenter);
    label_kesatuan_sub_induk->setAlignment(Qt::AlignCenter);
    label_kesatuan->setAlignment(Qt::AlignCenter);


    QPen pen(Qt::black);
//    pen.setColor(Qt::black);
    QPainter p(this);
    p.setPen(pen);
//    p.drawPoint(tit);
    p.drawLine(titik_mulai, titik_akhir);


}

kop::~kop()
{

}
