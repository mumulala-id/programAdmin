#include "pengelolapusatdata.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
pengelolapusatdata::pengelolapusatdata()
{

    pusat_data = QSqlDatabase::addDatabase("QSQLITE");
    pusat_data.setDatabaseName(ambilNamaPusatData());

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
    query.prepare("CREATE TABLE IF NOT EXISTS TABEL1 (NRP INTEGER UNIQUE PRIMARY KEY, NAMA TEXT, TEMPATLAHIR TEXT, TANGGALLAHIR TEXT, AGAMA TEXT, PANGKAT TEXT, JABATAN TEXT, NOTELP TEXT, ALAMAT TEXT, NOSPRINGABUNG TEXT, NOSPRINKELUAR TEXT,TANGGALGABUNG TEXT, TANGGALKELUAR TEXT, NAMASAUDARA TEXT, NOTELPSAUDARA TEXT)");
    
    if(query.exec()){
        qDebug()<<"berhasil buat tabel";
            return true;}
    else{
        qDebug()<<"gagal buat tabel"<<pusat_data.lastError();


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
    return jalur_pusat_data+"/"+nama_pusat_data;
}


void pengelolapusatdata::tambahAnggota(anggota _anggota){

    QSqlQuery query(pusat_data);
    query.prepare("INSERT INTO TABLE1 (NRP, NAMA, TEMPATLAHIR, TANGGALLAHIR, AGAMA, PANGKAT, JABATAN, NOTELP, ALAMAT, SPRINGABUNG, SPRINKELUAR, TANGGALGABUNG, TANGGALKELUAR, NAMASAUDARA, NOTELPSAUDARA) VALUES (:nrp, :nama, :tempatlahir, :agama, :pangkat, :jabatan, :notelp, :alamat, :spingabung, sprinkeluar, :tanggalgabung, :tanggalkeluar, :namasuadara,:notelpsaudara");


    query.bindValue(":nrp", _anggota.ambilNrp());
    query.bindValue(":nama", _anggota.ambilNama());
    query.bindValue(":tempatlahir", _anggota.ambilTempatLahir());
    query.bindValue(":tanggallahir", _anggota.ambilTanggalLahir());
    query.bindValue(":agama", _anggota.ambilAgama());
    query.bindValue(":pangkat", _anggota.ambilPangkat());
    query.bindValue(":jabatan", _anggota.ambilJabatan());
    query.bindValue(":notelp", _anggota.ambilNoTelp());
    query.bindValue(":alamat", _anggota.ambilAlamat());
    query.bindValue(":springabung", _anggota.ambilNoSprinGabung());
    query.bindValue(":sprinkeluar", _anggota.ambilNoSprinKeluar());
    query.bindValue(":tanggalgabung", _anggota.ambilTanggalGabung());
    query.bindValue(":tanggalkeluar", _anggota.ambilTanggalKeluar());
    query.bindValue(":namasaudara", _anggota.ambilNamaSaudara());
    query.bindValue(":notelpsaudara", _anggota.ambilNoTelpSaudara());
}
