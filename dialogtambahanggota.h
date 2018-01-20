#ifndef DIALOGTAMBAHANGGOTA_H
#define DIALOGTAMBAHANGGOTA_H
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QComboBox>
#include <QCompleter>
#include <QHBoxLayout>
#include "cdateedit.h"
#include <QDate>
#include "anggota.h"
#include "pengelolapusatdata.h"
class dialogTambahAnggota : public QDialog
{
    Q_OBJECT
public:
    enum mode{tambah,sunting};
    explicit  dialogTambahAnggota(QWidget *parent=0);
     ~dialogTambahAnggota();

private:
    mode _mode;
    QString nrp_lama;
    QLineEdit *isian_nama;
    QLineEdit *isian_nrp;
    QTextEdit *isian_alamat;
    QComboBox *pilihan_agama;
    QComboBox *pilihan_golongan;
    QComboBox *pilihan_jabatan;
    QComboBox *pilihan_pangkat;
    QComboBox *pilihan_divisi;
    CDateEdit *date_edit;
    QLineEdit *isian_tempat_lahir;
    QCompleter *completer;
    QLineEdit *isian_sprin_gabung;
    QComboBox *kombo_bulan_sprin;
    QComboBox *kombo_tahun_sprin;
    int tahun_sekarang = QDate::currentDate().year();
    int bulan_sekarang = QDate::currentDate().month();
    CDateEdit *isian_tgl_sprin;
    QLineEdit *isian_no_telp;
    QLineEdit *isian_nama_saudara, *isian_notelp_saudara;
    QLabel *foto;
      bool fotoDiTambahkan;
    QString derajat;
private slots:
    void ambilDaftarJabatan(int);
    void pilihPangkat(int);
    QWidget * buatItem(QString, QHBoxLayout *);
    void perikasInt(const QString &);
    void ambilDivisi(int);
    QString ambilNoSprinGabung();
    QString ambilTanggalSprinGabung();
    void resetPilihan();
    void ambilFoto();
    void simpan();


public slots:
    void tetapkanAnggota(anggota *);
    void isiNama(QString);
    void isiNRP(QString);
    void pilihGolongan(QString);
    void isiTempatLahir(QString);
    void isiTanggalLahir(QString);
    void pilihAgama(QString);
    void isiAlamat(QString);
    void isiNoTelp(QString);
    void tetapkanPangkat(QString);
    void tetapkanDivisi(QString);
    void tetapkanJabatan(QString);
//    void tetapkanSprinGabung(QString);
    void tetapkanFoto(QByteArray);
    void tetapkanNamaSaudara(QString);
    void tetapkanNoTelpSaudara(QString);
    void aturMode(mode);
    mode ambilMode();


};

#endif // DIALOGTAMBAHANGGOTA_H
