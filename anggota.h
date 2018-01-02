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

private :
    QString nama;
    QString pangkat;
    QString jabatan;
    QString notelp;
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


public slots :
    void tetapkanNama(const QString &);
    void tetapkanPangkat(const QString &);
    void tetapkanJabatan(const QString &);
    void tetapkanNotelp(const QString &);
    void tetapkanNrp(QString);
    void tetapkanAlamat(const QString &);

    void tetapkanNoSprinGabung(const QString &);
    void tetapkanNoSprinKeluar(const QString &);
    void tetapkanTanggalGabung(QDate);
    void tetapkanTanggalKeluar(QDate);
    void tetapkanNamaSaudara(const QString &);
    void tetapkanNoTelpSaudara(const QString &_no_telp_sudara);
    void tetapkanTempatLahir(QString);
    void tetapkanTanggalLahir(QDate);
    void tetapkanAgama(QString);


    QString ambilNama();
    QString ambilNrp();
    QString ambilPangkat();
    QString ambilJabatan();
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

};

#endif // ANGGOTA_H
