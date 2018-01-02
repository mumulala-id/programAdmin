#include "judul.h"
#include <QPainter>
#include <QVBoxLayout>
Judul::Judul(QWidget *parent) :
    QWidget(parent)
{

    QVBoxLayout *tata_letak_utama = new QVBoxLayout;
    label_atas = new QLabel(this);
    label_bawah = new QLabel(this);

    tata_letak_utama->addWidget(label_atas);
    tata_letak_utama->addWidget(label_bawah);
    tata_letak_utama->setSpacing(0);
    setLayout(tata_letak_utama);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void Judul::tetapkanJudulAtas(QString _judul_atas){
    label_atas->setText(_judul_atas);

}

void Judul::tetapkanJudulBawah(QString _judul_bawah){

    label_bawah->setText(_judul_bawah);

}

void Judul::paintEvent(QPaintEvent *){

    QPoint titik_awal = label_atas->geometry().bottomLeft();
    QPoint titik_akhir = label_atas->geometry().bottomRight();
    QPen pen(Qt::black);
    QPainter p(this);
    p.setPen(pen);
    p.drawLine(titik_awal, titik_akhir);
    label_atas->setAlignment(Qt::AlignCenter);
    label_bawah->setAlignment(Qt::AlignCenter);


}
