#include "pengelolapusatdata.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
pengelolapusatdata::pengelolapusatdata(QObject *parent):
    QObject(parent)
{

//    pusat_data = QSqlDatabase::addDatabase("QSQLITE","con1");
//    pusat_data.setDatabaseName(ambilNamaPusatData());

}

pengelolapusatdata::pengelolapusatdata(hubungan hub, QObject *parent):
    QObject(parent)
{
if(hub==hubungan::tambah_personil){
     pusat_data  =QSqlDatabase::database("tambah_personil");
}

     else if(hub==hubungan::tampil_personil){
            pusat_data  =QSqlDatabase::database("tampil_personil");

     }

 pusat_data.setDatabaseName(ambilNamaPusatData());
// qDebug()<<addin_path;

}

void pengelolapusatdata::hubungkan(){
    if(!QFile(ambilNamaPusatData()).exists())
        pulihkanPudatData();
    else
        bukaPusatData();
    
}

bool pengelolapusatdata::pulihkanPudatData(){
    if(!QDir(jalur_pusat_data).exists())
        QDir().mkpath(jalur_pusat_data);
    
    if(bukaPusatData()){
        
        if(!buatTabel()){
            return false;
        }
        return true;
        
    }
    return false;
}


bool pengelolapusatdata::bukaPusatData(){
    
    if(!pusat_data.open())
        return false;
    return true;
}

bool pengelolapusatdata::buatTabel(){
    
    QSqlQuery query(pusat_data);
    query.prepare("CREATE TABLE IF NOT EXISTS ANGGOTA ( NAMA TEXT, NRP TEXT, PANGKAT TEXT, GOLONGAN TEXT, DIVISI TEXT,  JABATAN TEXT,DERAJAT TEXT, STATUS TEXT, TEMPATLAHIR TEXT, TANGGALLAHIR TEXT, AGAMA TEXT,   NOTELP TEXT, ALAMAT TEXT, NOSPRINGABUNG TEXT, TANGGALGABUNG TEXT,NOSPRINKELUAR TEXT, TANGGALKELUAR TEXT, NAMASAUDARA TEXT, NOTELPSAUDARA TEXT, FOTO BLOB)");
    
    if(query.exec()){
        qDebug()<<"berhasil buat tabel";
            return true;}
    else{
        qDebug()<<"gagal buat tabel"<<query.lastError();


    return false;}
}

void pengelolapusatdata::tetapkanNamaPusatData(QString _nama_pusat_data){
    
    nama_pusat_data = _nama_pusat_data;
    
}

void pengelolapusatdata::tetapkanJalurPusatData(){
    
    
    
}

void pengelolapusatdata::persiapan(){
    pusat_data.transaction();
}

void pengelolapusatdata::kumpulkan(){
    pusat_data.commit();
}

QString pengelolapusatdata::ambilNamaPusatData(){
return jalur_pusat_data+QDir::separator()+nama_pusat_data;

}


void pengelolapusatdata::tambahAnggota(anggota *_anggota){

    QSqlQuery query(pusat_data);
    query.prepare("INSERT INTO ANGGOTA ( NAMA, NRP,TEMPATLAHIR, TANGGALLAHIR, AGAMA, GOLONGAN, PANGKAT, DIVISI, JABATAN, DERAJAT, STATUS,NOTELP, ALAMAT, NOSPRINGABUNG, NOSPRINKELUAR, TANGGALGABUNG, TANGGALKELUAR, NAMASAUDARA, NOTELPSAUDARA, FOTO) "
                  "VALUES ( :NAMA, :NRP, :TEMPATLAHIR, :TANGGALLAHIR, :AGAMA, :GOLONGAN, :PANGKAT,  :DIVISI, :JABATAN, :DERAJAT,:STATUS, :NOTELP, :ALAMAT, :NOSPRINGABUNG, :NOSPRINKELUAR, :TANGGALGABUNG, :TANGGALKELUAR, :NAMASAUDARA, :NOTELPSAUDARA, :FOTO)");

     query.bindValue(":NAMA", _anggota->ambilNama());
     query.bindValue(":NRP", _anggota->ambilNrp());
    query.bindValue(":TEMPATLAHIR", _anggota->ambilTempatLahir());
    query.bindValue(":TANGGALLAHIR", _anggota->ambilTanggalLahir());
    query.bindValue(":AGAMA", _anggota->ambilAgama());
    query.bindValue(":GOLONGAN", _anggota->ambilGolongan());
    query.bindValue(":PANGKAT", _anggota->ambilPangkat());
//    query.bindValue(":PANGKATNRP", _anggota->ambilPangkatNrp());
     query.bindValue(":DIVISI", _anggota->ambilDivisi());
    query.bindValue(":JABATAN", _anggota->ambilJabatan());
    query.bindValue(":STATUS", _anggota->ambilStatus());
    query.bindValue(":DERAJAT",_anggota->ambilDerajat());
    query.bindValue(":NOTELP", _anggota->ambilNoTelp());
    query.bindValue(":ALAMAT", _anggota->ambilAlamat());
    query.bindValue(":NOSPRINGABUNG", _anggota->ambilNoSprinGabung());
    query.bindValue(":NOSPRINKELUAR", _anggota->ambilNoSprinKeluar());
    query.bindValue(":TANGGALGABUNG", _anggota->ambilTanggalGabung());
    query.bindValue(":TANGGALKELUAR", _anggota->ambilTanggalKeluar());
    query.bindValue(":NAMASAUDARA", _anggota->ambilNamaSaudara());
    query.bindValue(":NOTELPSAUDARA", _anggota->ambilNoTelpSaudara());
    query.bindValue(":FOTO", _anggota->ambilFoto());

    if(!query.exec()){
        qDebug()<<"gagal";
        qDebug()<<pusat_data.lastError();
    }
    else
        qDebug()<<"berhasil";
    }

void pengelolapusatdata::tutup(){


}

void pengelolapusatdata::perbaruiAnggota(QString nrp_lama,  anggota *_anggota){

    QSqlQuery query(pusat_data);
    query.prepare("UPDATE ANGGOTA SET  NAMA=:NAMA, NRP=:NRP,TEMPATLAHIR=:TEMPATLAHIR, TANGGALLAHIR=:TANGGALLAHIR, AGAMA=:AGAMA, GOLONGAN=:GOLONGAN, PANGKAT=:PANGKAT,  DIVISI=:DIVISI, JABATAN=:JABATAN, STATUS=:STATUS, DERAJAT=:DERAJAT, NOTELP=:NOTELP, ALAMAT=:ALAMAT, NOSPRINGABUNG=:NOSPRINGABUNG, NOSPRINKELUAR=:NOSPRINKELUAR, TANGGALGABUNG=:TANGGALGABUNG, TANGGALKELUAR=:TANGGALKELUAR, NAMASAUDARA=:NAMASAUDARA, NOTELPSAUDARA=:NOTELPSAUDARA, FOTO=:FOTO WHERE NRP ="+nrp_lama);

    query.bindValue(":NAMA", _anggota->ambilNama());
    query.bindValue(":NRP", _anggota->ambilNrp());
    query.bindValue(":TEMPATLAHIR", _anggota->ambilTempatLahir());
    query.bindValue(":TANGGALLAHIR", _anggota->ambilTanggalLahir());
    query.bindValue(":AGAMA", _anggota->ambilAgama());
    query.bindValue(":GOLONGAN", _anggota->ambilGolongan());
    query.bindValue(":PANGKAT", _anggota->ambilPangkat());
    query.bindValue(":STATUS",_anggota->ambilStatus());
    query.bindValue(":DERAJAT",_anggota->ambilDerajat());
    query.bindValue(":DIVISI", _anggota->ambilDivisi());
    query.bindValue(":JABATAN", _anggota->ambilJabatan());
    query.bindValue(":NOTELP", _anggota->ambilNoTelp());
    query.bindValue(":ALAMAT", _anggota->ambilAlamat());
    query.bindValue(":NOSPRINGABUNG", _anggota->ambilNoSprinGabung());
    query.bindValue(":NOSPRINKELUAR", _anggota->ambilNoSprinKeluar());
    query.bindValue(":TANGGALGABUNG", _anggota->ambilTanggalGabung());
    query.bindValue(":TANGGALKELUAR", _anggota->ambilTanggalKeluar());
    query.bindValue(":NAMASAUDARA", _anggota->ambilNamaSaudara());
    query.bindValue(":NOTELPSAUDARA", _anggota->ambilNoTelpSaudara());
    query.bindValue(":FOTO", _anggota->ambilFoto());

    if(!query.exec()){
        qDebug()<<"pembaruan gagal";
        qDebug()<<pusat_data.lastError();
    }
    else
        qDebug()<<"pembaruan berhasil";

}

void pengelolapusatdata::sisipkanKeTabel(){


}
