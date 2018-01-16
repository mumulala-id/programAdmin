#include "jendelapersonel.h"
#include <QVBoxLayout>
#include "dialogtambahanggota.h"
//#include <QAction>
//#include "dialogtambahanggota.h"
#include <QSqlQuery>
#include  <QHeaderView>

#include <QDebug>
#include <QSqlRecord>

jendelaPersonel::jendelaPersonel(QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout * tata_letak_utama= new QVBoxLayout;

    QHBoxLayout *tata_letak_tombol = new QHBoxLayout;

    tombol_tambah = new QPushButton(this);
    tombol_tambah->setIcon(QIcon::fromTheme("add"));
    tombol_tambah->setText("Tambah");
    connect(tombol_tambah,SIGNAL(pressed()),this,SLOT(bukaDialogTambah()));

    tombol_sunting = new QPushButton(this);
    tombol_sunting->setIcon(QIcon::fromTheme("edit"));
    tombol_sunting->setText("Sunting");
    tombol_sunting->setEnabled(false);
    connect(tombol_sunting,SIGNAL(pressed()),this,SLOT(editAnggota()));

    tombol_pisah = new QPushButton(this);
    tombol_pisah->setText("Mutasi");
    tombol_pisah->setIcon(QIcon::fromTheme("exit"));
    tombol_pisah->setEnabled(false);

    tombol_profil = new QPushButton("Profil", this);
    tombol_profil->setIcon(QIcon::fromTheme("contact-new"));
    tombol_profil->setEnabled(false);

    tata_letak_tombol->addStretch();
    tata_letak_tombol->addWidget(tombol_tambah);
    tata_letak_tombol->addWidget(tombol_sunting);
    tata_letak_tombol->addWidget(tombol_pisah);
    tata_letak_tombol->addWidget(tombol_profil);
     tata_letak_tombol->addStretch();
     tata_letak_tombol->setSpacing(0);
     tata_letak_tombol->setMargin(0);

    pengolah = new pengelolapusatdata(pengelolapusatdata::tampil_personil, this);
    pengolah->hubungkan();

    model = new TableModel(this, pengolah->pusatData());
    model->setTable("ANGGOTA");
    model->select();
//    m_model = new QSqlQueryModel(this);
//    m_model->setQuery("SELECT NAMA, NRP, PANGKAT, JABATAN FROM ANGGOTA", pengolah->pusatData());
//    m_model->setHeaderData(0, Qt::Horizontal,"NAMA");
//    m_model->setHeaderData(1, Qt::Horizontal,"NRP");
//    m_model->setHeaderData(2, Qt::Horizontal,"PANGKAT");
//    m_model->setHeaderData(3, Qt::Horizontal,"JABATAN");

    tabel = new QTableView(this);
    tabel->setModel(model);
    tabel ->setSelectionBehavior(QAbstractItemView::SelectRows);
    tabel->setSelectionMode(QAbstractItemView::SingleSelection);
    tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     tabel->setEditTriggers(QAbstractItemView::NoEditTriggers);
     tabel->hideColumn(1);
     tabel->hideColumn(2);
     tabel->hideColumn(4);
     tabel->hideColumn(5);
     tabel->hideColumn(7);
     tabel->hideColumn(8);
     tabel->hideColumn(9);
     tabel->hideColumn(10);
     tabel->hideColumn(11);
     tabel->hideColumn(12);
     tabel->hideColumn(13);
     tabel->hideColumn(14);
     tabel->hideColumn(15);
     tabel->hideColumn(16);
     tabel->hideColumn(17);
     tabel->hideColumn(18);
     tabel->setFixedWidth(800);
//     tabel->adjustSize();
//     tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(tabel->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(aktifkanTombol()));

    tata_letak_utama->addLayout(tata_letak_tombol,0);
    tata_letak_utama->addWidget(tabel,0,Qt::AlignCenter);
    tata_letak_utama->addStretch();
    setLayout(tata_letak_utama);
    setWindowState(Qt::WindowMaximized);

}

void jendelaPersonel::bukaDialogTambah(){

    dialogTambahAnggota dta;
    dta.aturMode(dialogTambahAnggota::tambah);
    connect(&dta,SIGNAL(accepted()),model,SLOT(select()));
    dta.exec();
}

void jendelaPersonel::segarkan(){
   if( m_model->query().exec()){
       tabel->repaint();
qDebug()<<"disegarkan";
   }
   else
       qDebug()<<"tak disegarkan";
}

void jendelaPersonel::aktifkanTombol(){

    tombol_pisah->setEnabled(1);
    tombol_sunting->setEnabled(1);
    tombol_profil->setEnabled(1);

}

void jendelaPersonel::editAnggota(){

    dialogTambahAnggota dta;
    dta.tetapkanAnggota(ambilAnggota(ambilNrp()));
    dta.aturMode(dialogTambahAnggota::sunting);
    connect(&dta,SIGNAL(accepted()),model,SLOT(select()));
    dta.exec();
}

QString jendelaPersonel::ambilNrp(){
    QModelIndexList indexlist = tabel->selectionModel()->selectedRows();
    QModelIndex index= indexlist.at(0);
    int row=index.row();
    return index.sibling(row,1).data().toString();
}

anggota *jendelaPersonel::ambilAnggota(QString _nrp){

    QSqlQuery query(pengolah->pusatData());
    query.prepare("SELECT * FROM ANGGOTA WHERE NRP="+_nrp);

    QSqlRecord rec;


    if(query.exec()){
        while(query.next()){
             rec = query.record();
        }
    }
//for(int i= 0;i<rec.count()-1;i++){

// qDebug()<<i<<rec.value(i).toString();
//}

    anggota *agt = new anggota(this);
       agt->tetapkanNama(rec.value(0).toString());
    agt->tetapkanNrp(rec.value(1).toString());
    agt->tetapkanPangkat(rec.value(2).toString());
     agt->tetapkanGolongan(rec.value(4).toString());
     agt->tetapkanDivisi(rec.value(5).toString());
     agt->tetapkanJabatan(rec.value(6).toString());
    agt->tetapkanTempatLahir(rec.value(7).toString());
    agt->tetapkanTanggalLahir(rec.value(8).toString());
    agt->tetapkanAgama(rec.value(9).toString());

    agt->tetapkanNotelp(rec.value(10).toString());
    agt->tetapkanAlamat(rec.value(11).toString());
//    agt->tetapkanNoSprinGabung(rec.value(11).toString());
//    agt->tetapkanTanggalGabung(rec.value(12).toString());
//    agt->tetapkanNamaSaudara(rec.value(15).toString());
//    agt->tetapkanNoTelpSaudara(rec.value(16).toString());
    agt->tetapkanFoto(rec.value(18).toByteArray());
    return agt;



}

jendelaPersonel::~jendelaPersonel(){

}
