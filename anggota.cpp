#include "anggota.h"

anggota::anggota(QObject *parent) : QObject(parent)
{

}
void anggota::tetapkanNama(const QString &_nama){
    nama = _nama;
}

void anggota::tetapkanNrp(QString _nrp){
    nrp = _nrp;
}

void anggota::tetapkanPangkat(const QString &_pangkat ){
    pangkat = _pangkat;
}

void anggota::tetapkanJabatan(const QString &_jabatan){
    jabatan = _jabatan;
}
void anggota::tetapkanGolongan(const QString &_golongan){
    golongan = _golongan;
}

void anggota::tetapkanDivisi(const QString &_divisi){

    divisi = _divisi;

}

void anggota::tetapkanNotelp(const QString &_notelp){
    notelp = _notelp;
}

void anggota::tetapkanAlamat(const QString &_alamat){
    alamat = _alamat;
}

void anggota::tetapkanNoSprinGabung(const QString &_no_sprin_gabung){
    no_sprin_gabung = _no_sprin_gabung;
}

void anggota::tetapkanNoSprinKeluar(const QString &_no_sprin_keluar){
    no_sprin_keluar = _no_sprin_keluar;
}

void anggota::tetapkanTanggalGabung(QDate _tanggal_gabung){
    tanggal_gabung = _tanggal_gabung;
}

void anggota::tetapkanTanggalGabung(QString _tanggal){

    tanggal_gabung = QDate::fromString(_tanggal, "dd/MM/yyyy");

}

void anggota::tetapkanTanggalKeluar(QDate _tanggal_keluar){
    tanggal_keluar = _tanggal_keluar;
}

void anggota::tetapkanNamaSaudara(const QString &_nama_saudara){
    nama_saudara = _nama_saudara;
}

void anggota::tetapkanNoTelpSaudara(const QString &_no_telp_sudara){
    notelp_saudara = _no_telp_sudara;
}

QString anggota::ambilNama(){
    return nama;
}

QString anggota::ambilNrp(){
    return nrp;
}

QString anggota::ambilPangkat(){
    return pangkat;
}

QString anggota::ambilPangkatNrp(){
        return pangkat+"/"+nrp;
}

QString anggota::ambilJabatan(){
    return jabatan;
}

QString anggota::ambilDivisi(){

    return divisi;

}

QString anggota::ambilNoTelp(){
    return notelp;
}


QString anggota::ambilAlamat(){
    return alamat;
}

QString anggota::ambilNamaSaudara(){
    return nama_saudara;
}

QString anggota::ambilNoTelpSaudara(){
    return notelp_saudara;
}

void anggota::tetapkanAgama(QString _agama){
    agama = _agama;

}

QString anggota::ambilAgama(){
    return agama;
}

void anggota::tetapkanTanggalLahir(QDate _tanggal_lahir){
    tanggal_lahir = _tanggal_lahir.toString(("dd/MM/yyyy"));

}

void anggota::tetapkanTanggalLahir(QString _tanggal_lahir){
    tanggal_lahir = _tanggal_lahir;

}

QString anggota::ambilTanggalLahir(){
    return tanggal_lahir;
}

void anggota::tetapkanTempatLahir(QString _tempat_lahir){

    tempat_lahir = _tempat_lahir;

}

QString anggota::ambilTempatLahir(){
    return tempat_lahir;
}

QString anggota::ambilTempatTanggalLahir(){
    return tempat_lahir+"/+"+tanggal_lahir;
}

QString anggota::ambilTanggalGabung(){
    return tanggal_gabung.toString("dd/MM/yyyy");
}

QString anggota::ambilTanggalKeluar(){
    return tanggal_keluar.toString("dd/MM/yyyy");
}

QString anggota::ambilNoSprinGabung(){
    return no_sprin_gabung;
}

QString anggota::ambilNoSprinKeluar(){
    return no_sprin_keluar;
}

QString anggota::ambilGolongan(){
    return golongan;
}

void anggota::tetapkanFoto(QByteArray _foto){

    byte_array_foto = _foto;


}

QByteArray anggota::ambilFoto(){
    return byte_array_foto;
}
