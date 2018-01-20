/*
 *
 * Surabaya
 * KP. ABIMANYU - 7010
 * Briptu M. Mukharom
 * 31 Desember 2017

*/

#ifndef ANGGOTA_H
#define ANGGOTA_H

#include <QObject>
#include <QDate>

class anggota : public QObject
{
    Q_OBJECT
public:
    explicit anggota(QObject *parent = nullptr);
    enum status{Ijin, Dinas, Sakit, Pendidikan, TanpaKeterangan, LepasDinas, Cuti};

private :
    QString nama;
    QString pangkat;
    QString jabatan;
    QString divisi;
    QString notelp;
    QString golongan;
    QString notelp_saudara;
    QString nama_saudara;
    QString no_sprin_gabung;
    QString no_sprin_keluar;
    QString nrp;
    QDate tanggal_gabung;
    QDate tanggal_keluar;
    QString alamat;
    QString tempat_lahir;
    QString tanggal_lahir;
    QString agama;
    QByteArray byte_array_foto;
    status m_status;
    QString _status;
    QString derajat;


public slots :
    void tetapkanNama(const QString &);
    void tetapkanPangkat(const QString &);
    void tetapkanJabatan(const QString &);
    void tetapkanGolongan(const QString &);
    void tetapkanNotelp(const QString &);
    void tetapkanNrp(QString);
    void tetapkanAlamat(const QString &);
    void tetapkanDivisi(const QString &);
    void tetapkanFoto(QByteArray);
    void tetapkanNoSprinGabung(const QString &);
    void tetapkanNoSprinKeluar(const QString &);
    void tetapkanTanggalGabung(QDate);
    void tetapkanTanggalGabung(QString);
    void tetapkanTanggalKeluar(QDate);
    void tetapkanNamaSaudara(const QString &);
    void tetapkanNoTelpSaudara(const QString &_no_telp_sudara);
    void tetapkanTempatLahir(QString);
    void tetapkanTanggalLahir(QDate);
    void tetapkanTanggalLahir(QString);
    void tetapkanAgama(QString);
    void tetapkanStatus(status);
    void tetapkanDerajat(QString);


    QString ambilNama();
    QString ambilNrp();
    QString ambilPangkat();
    QString ambilDivisi();
    QString ambilJabatan();
    QString ambilGolongan();
    QString ambilPangkatNrp();
    QString ambilNoTelp();
    QString ambilAlamat();
    QString ambilTanggalGabung();
    QString ambilTanggalKeluar();
    QString ambilNoSprinGabung();
    QString ambilNoSprinKeluar();
    QString ambilNamaSaudara();
    QString ambilNoTelpSaudara();
    QString ambilAgama();
    QString ambilTempatLahir();
    QString ambilTanggalLahir();
    QString ambilTempatTanggalLahir();
    QByteArray ambilFoto();
    QString ambilStatus();
    QString ambilDerajat();

};

#endif // ANGGOTA_H
