#include "cdateedit.h"
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDebug>
CDateEdit::CDateEdit(QWidget *parent)
    : QWidget(parent),daftar_tahun()
{
    QHBoxLayout *tata_letak_utama = new QHBoxLayout;

    kombo_tahun = new QComboBox(this);

    for(int i=tahun_sekarang; i>(tahun_sekarang-60);i--){

        daftar_tahun<<QString::number(i);

    }
    kombo_tahun->addItems(daftar_tahun);
    kombo_tahun->setMaxVisibleItems(10);

    kombo_bulan = new QComboBox(this);
    QStringList daftar_bulan;
  daftar_bulan <<"Januari"<<"Pebruari"<<"Maret"<<"Aprli"<<"Mei"<<"Juni"
              <<"Juli"<<"Agustus"<<"September"<<"Oktober"<<"Nopember"<<"Desember";

    kombo_bulan->addItems(daftar_bulan);

    kombo_tanggal = new QComboBox(this);
    kombo_tanggal->setAutoFillBackground(1);
    kombo_tanggal->setMaxVisibleItems(10);

    QStringList daftar_tanggal;
    for(int i=1;i<32;i++){
        daftar_tanggal<<QString::number(i);
    }
    kombo_tanggal->addItems(daftar_tanggal);

    connect(kombo_tanggal,SIGNAL(activated(int)),this,SLOT(periksa()));
    connect(kombo_bulan,SIGNAL(activated(int)),this,SLOT(periksa()));
    connect(kombo_tahun,SIGNAL(activated(int)),this,SLOT(periksa()));


        tata_letak_utama->addWidget(kombo_tanggal);
        tata_letak_utama->addWidget(kombo_bulan);
        tata_letak_utama->addWidget(kombo_tahun);
        tata_letak_utama->setSpacing(0);

    setLayout(tata_letak_utama);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void CDateEdit::ambilJumlahHari(){
    int bulan = kombo_bulan->currentIndex()+1;
    int tahun = kombo_tahun->currentText().toInt();
    int hari;

 if(bulan== 4 || bulan==6 ||bulan ==9 ||bulan==11){
     hari = 30;

 }
 else if (bulan==2){
     if(tahun%4==0){
         hari=29;
     }
     else
         hari=28;
 }
     else{
  hari=31;
 }

    QStringList daftar_tanggal;
    for(int i=1;i<hari+1;i++){
        daftar_tanggal<<QString::number(i);

    }

    kombo_tanggal->clear();
    kombo_tanggal->addItems(daftar_tanggal);


}

QDate CDateEdit::ambilTanggal(){

    QDate d(kombo_tahun->currentText().toInt(), kombo_bulan->currentIndex()+1, kombo_tanggal->currentText().toInt());
    return d;
}

void CDateEdit::periksa(){

    int bulan = kombo_bulan->currentIndex()+1;
    int tahun = kombo_tahun->currentText().toInt();
    int hari = kombo_tanggal->currentText().toInt();
    QDate d(tahun,bulan,hari);

    if(!d.isValid()){
    QPalette p= kombo_tanggal->palette();
    p.setColor(QPalette::Window,Qt::red);
    kombo_tanggal->setPalette(p);
    ambilJumlahHari();
}
else{
    QPalette p= kombo_tanggal->palette();
    p.setColor(QPalette::Window,palette().base().color());
    kombo_tanggal->setPalette(p);
}

}

void CDateEdit::aturJangka(int min, int max){

  kombo_tahun->clear();

  int i=max;
  daftar_tahun.clear();
    while(i!=min){
         daftar_tahun<<QString::number(i);
         i--;
    }

   kombo_tahun->addItems(daftar_tahun);



}

void CDateEdit::aturKeTanggal(QString tanggal){

    QDate d(QDate::fromString(tanggal,"dd/MM/yyyy"));
    qDebug()<<"atnggal"<<d.day()<<d.month()<<d.year();

    kombo_tanggal->setCurrentIndex(d.day()-1);
    kombo_bulan->setCurrentIndex(d.month()-1);
    kombo_tahun->setCurrentText(QString::number(d.year()));


}

void CDateEdit::aturKeTanggal(QDate d){

qDebug()<<"dday"<<d.day();
    kombo_tanggal->setCurrentIndex(d.day()-1);
    kombo_bulan->setCurrentIndex(d.month()-1);
    kombo_tahun->setCurrentText(QString::number(d.year()));


}

CDateEdit::~CDateEdit()
{

}
