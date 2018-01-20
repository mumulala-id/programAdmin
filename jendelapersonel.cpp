#include "jendelapersonel.h"
#include <QVBoxLayout>
#include "dialogtambahanggota.h"
//#include <QAction>
//#include "dialogtambahanggota.h"
#include <QSqlQuery>
#include  <QHeaderView>
#include <QSqlField>
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


    tabel = new QTableWidget(this);
    tabel->setColumnCount(6);
    tabel->verticalHeader()->hide();
    tabel->setHorizontalHeaderLabels(QString("NO:NAMA:PANGKAT:NRP:JABATAN:KETERANGAN").split(":"));
    tabel ->setSelectionBehavior(QAbstractItemView::SelectRows);
    tabel->setSelectionMode(QAbstractItemView::SingleSelection);
     tabel->setEditTriggers(QAbstractItemView::NoEditTriggers);

     tabel->setFixedWidth(800);
     tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     tabel->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
          tabel->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);


    ambilData();
    connect(tabel->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(aktifkanTombol()));

    tata_letak_utama->addLayout(tata_letak_tombol);
    tata_letak_utama->addWidget(tabel,0,Qt::AlignCenter);
    tata_letak_utama->addStretch();
    setLayout(tata_letak_utama);
    setWindowState(Qt::WindowMaximized);

}

void jendelaPersonel::bukaDialogTambah(){

    dialogTambahAnggota dta;
    dta.aturMode(dialogTambahAnggota::tambah);
    connect(&dta,SIGNAL(accepted()),this,SLOT(ambilData()));
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
    connect(&dta,SIGNAL(accepted()),this,SLOT(ambilData()));
    dta.exec();
}

QString jendelaPersonel::ambilNrp(){
    QModelIndexList indexlist = tabel->selectionModel()->selectedRows();
    QModelIndex index= indexlist.at(0);
    int row=index.row();
    return index.sibling(row,3).data().toString();
}

anggota *jendelaPersonel::ambilAnggota(QString _nrp){

    QSqlQuery query(pengolah->pusatData());
    query.prepare("SELECT * FROM ANGGOTA WHERE NRP="+_nrp);
//    query.exec();
    QSqlRecord rec ;
//    while(query.next())
//    rec = query.record();


    if(query.exec()){
        while(query.next()){
             rec = query.record();
        }
    }
    else{
        return NULL;
    }
//for(int i= 0;i<rec.count()-1;i++){

// qDebug()<<i<<rec.value(i).toString();
//}

    anggota *agt = new anggota(this);
    agt->tetapkanNama(rec.value(0).toString());
    agt->tetapkanNrp(rec.value(1).toString());
    agt->tetapkanPangkat(rec.value(2).toString());
    agt->tetapkanGolongan(rec.value(3).toString());
    agt->tetapkanDivisi(rec.value(4).toString());
    agt->tetapkanJabatan(rec.value(5).toString());
    agt->tetapkanTempatLahir(rec.value(8).toString());
    agt->tetapkanTanggalLahir(rec.value(9).toString());
    agt->tetapkanAgama(rec.value(10).toString());
    agt->tetapkanNotelp(rec.value(11).toString());
    agt->tetapkanAlamat(rec.value(12).toString());
    agt->tetapkanNoSprinGabung(rec.value(13).toString());
    agt->tetapkanTanggalGabung(rec.value(14).toString());
//    agt->tetapkanNamaSaudara(rec.value(15).toString());
//    agt->tetapkanNoTelpSaudara(rec.value(16).toString());
    agt->tetapkanFoto(rec.value(19).toByteArray());
    return agt;



}

void jendelaPersonel::ambilData(){

    tabel->setRowCount(0);
    QSqlQuery query(pengolah->pusatData());
    query.prepare("SELECT NAMA ,  PANGKAT,NRP,JABATAN,DERAJAT FROM ANGGOTA ORDER BY DERAJAT ASC");
    query.exec();

    QSqlRecord record;

    int row=0;

    while(query.next()){
           record = query.record();

           tabel->setRowCount(row+1);

           QTableWidgetItem *item_no = new QTableWidgetItem(QString::number(tabel->rowCount()));
           item_no->setTextAlignment(Qt::AlignCenter);
           tabel->setItem(row,0,item_no);

           QTableWidgetItem *item_nama = new QTableWidgetItem(record.value(0).toString());
           tabel->setItem(row,1,item_nama);

           QTableWidgetItem *item_nrp = new QTableWidgetItem(record.value(1).toString());
           item_nrp->setTextAlignment(Qt::AlignCenter);
           tabel->setItem(row,2,item_nrp);

           QTableWidgetItem *item_pangkat= new QTableWidgetItem(record.value(2).toString());
            item_pangkat->setTextAlignment(Qt::AlignCenter);
           tabel->setItem(row,3,item_pangkat);

           QTableWidgetItem *item_jabatan = new QTableWidgetItem(record.value(3).toString());
           item_jabatan->setTextAlignment(Qt::AlignCenter);
           tabel->setItem(row,4,item_jabatan);

            row++;
}
}

jendelaPersonel::~jendelaPersonel(){

}
