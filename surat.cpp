#include "surat.h"

#include <QVBoxLayout>
surat::surat(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *tata_letak_utama = new QVBoxLayout;

    kop *_kop = new kop(this);
    _kop->tetapkanNamaKesatuan("KP. ABIMANYU -7010");
    _kop->tetapkanNamaKesatuanSubInduk("SATUAN PATROLI PERAIRAN");
    _kop->tetapkanNamaKesatuanInduk("DIREKTORAT POLISI PERAIRAN");


    judul = new Judul(this);
    tetapkanJudulAtas("DAFTAR ABK KP. ABIMANYU - 7010");
    tetapkanJudulBawah("NO SPRIN : 23 /IX/2017");

    widget_isi = new QWidget(this);


    kotaktandatangan *_kotak_tandatangan = new kotaktandatangan(this);
    _kotak_tandatangan->tetapkanKota("Surabaya");
    _kotak_tandatangan->tetapkanTanggal("2 JANUARI 2017");
    _kotak_tandatangan->tetapkanPejabat("KOMANDAN KAPAL ABIMANYU - 7010");
    _kotak_tandatangan->tetapkanNamaPejabat("NUR SAPTO");
    _kotak_tandatangan->tetapkanPangkatNrp("KOMISARIS POLISI NRP 90070246");
//    _kotak_tandatangan->set
    tata_letak_utama->addWidget(_kop);
    tata_letak_utama->addWidget(judul,0, Qt::AlignTop | Qt::AlignCenter);
    tata_letak_utama->addWidget(widget_isi);
    tata_letak_utama->addWidget(_kotak_tandatangan,0, Qt::AlignRight);
    tata_letak_utama->setMargin(0);

    setLayout(tata_letak_utama);

    QPalette p;
    p.setColor(QPalette::Window, Qt::white);
    p.setColor(QPalette::WindowText, Qt::black);
    setPalette(p);


}


void surat::tetapkanWidgetIsi(QWidget *_widget_isi){

    widget_isi = _widget_isi;


}

void surat::tetapkanJudulAtas(QString _judul_atas){

     judul->tetapkanJudulAtas(_judul_atas);

}

void surat::tetapkanJudulBawah(QString _judul_bawah){
    judul->tetapkanJudulBawah(_judul_bawah);


}
