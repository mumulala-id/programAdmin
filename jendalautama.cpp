#include "jendalautama.h"
#include "jendelapersonel.h"
//#include <QHBoxLayout>
#include <QGridLayout>
#include <QToolButton>

#include <surat.h>
#include <QDebug>

jendalaUtama::jendalaUtama(QWidget *parent) :
    QDialog(parent)
{
    QHBoxLayout *tata_letak_utama = new QHBoxLayout;

    QWidget *widget_kiri = new QWidget(this);
    QWidget *widget_kanan = new QWidget(this);


    QGridLayout *tata_letak_tombol = new QGridLayout;

    QToolButton *tombol_surat = new QToolButton(this);
    tombol_surat->setIcon(QIcon(QPixmap(":/berkas/ikon/anggota.png")));
    tombol_surat->setIconSize(QSize(64,64));
    tombol_surat->setToolTip("Personil");
    tombol_surat->setFixedSize(QSize(100,100));

    QToolButton *tombol_dokumen = new QToolButton(this);
    tombol_dokumen->setIcon(QIcon(QPixmap(":/berkas/ikon/dokumen.png")));
    tombol_dokumen->setIconSize(QSize(64,64));
    tombol_dokumen->setToolTip("Dokumen");
    tombol_dokumen->setFixedSize(QSize(100,100));

    QToolButton *tombol_gakkum = new QToolButton(this);
    tombol_gakkum->setIcon(QIcon(QPixmap(":/berkas/ikon/borgol.png")));
    tombol_gakkum->setIconSize(QSize(64,64));
    tombol_gakkum->setToolTip("Penegakan Hukum");
    tombol_gakkum->setFixedSize(QSize(100,100));

    QToolButton *tombol_kapal = new QToolButton(this);
    tombol_kapal->setIcon(QIcon(QPixmap(":/berkas/ikon/kapal.png")));
    tombol_kapal->setIconSize(QSize(64,64));
    tombol_kapal->setToolTip("Kapal");
    tombol_kapal->setFixedSize(QSize(100,100));



    connect(tombol_surat,SIGNAL(pressed()),this,SLOT(tampilSurat()));

    tata_letak_tombol->addWidget(tombol_surat,0,0);
    tata_letak_tombol->addWidget(tombol_dokumen,0,1);
tata_letak_tombol->addWidget(tombol_gakkum,0,2);
tata_letak_tombol->addWidget(tombol_kapal,1,0);
    widget_kiri->setLayout(tata_letak_tombol);
    widget_kiri->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    tata_letak_utama->addWidget(widget_kiri, 0,Qt::AlignTop);
    tata_letak_utama->addWidget(widget_kanan);

    setLayout(tata_letak_utama);

}

void jendalaUtama::tampilSurat(){

//    qDebug()<<"masuk";
//        surat*w = new surat(this);
//        w->resize(QSize(330,210));

//        w->showMaximized();
    jendelaPersonel jp;
    jp.exec();
}
