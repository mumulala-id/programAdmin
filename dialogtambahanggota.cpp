#include "dialogtambahanggota.h"
#include <QFile>
#include <QVBoxLayout>
#include <QCompleter>
#include <QDebug>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QFileDialog>
#include "liststringparser.h"
 #include <QMessageBox>
#include <QBuffer>

dialogTambahAnggota::dialogTambahAnggota(QWidget *parent):
    QDialog(parent)
{
    auto *tata_letak_utama = new QVBoxLayout;

    isian_nama = new QLineEdit(this);

    isian_nrp = new QLineEdit(this);

    connect(isian_nrp, SIGNAL(textChanged(QString)),this,SLOT(perikasInt(QString)));

    isian_nrp->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    pilihan_golongan = new QComboBox(this);
    pilihan_golongan->addItems(QStringList()<<"GOLONGAN"<<"INSPEKTUR"<<"BRIGADIR"<<"BHAYANGKARA"<<"PNS");
    pilihan_golongan->setItemData(0,QBrush(Qt::white),Qt::TextColorRole);
    pilihan_golongan->setItemData(0,QColor(Qt::black),Qt::BackgroundColorRole);
    pilihan_golongan->setItemData(0, false,Qt::UserRole-1);
    connect(pilihan_golongan,SIGNAL(currentIndexChanged(int)),this,SLOT(pilihPangkat(int)));
    connect(pilihan_golongan,SIGNAL(currentIndexChanged(int)),this,SLOT(ambilDivisi(int)));

    pilihan_pangkat = new QComboBox(this);
    pilihan_pangkat->addItems(QStringList()<<"PANGKAT");
    pilihan_pangkat->setItemData(0,QBrush(Qt::white),Qt::TextColorRole);
    pilihan_pangkat->setItemData(0,QColor(Qt::black),Qt::BackgroundColorRole);
    pilihan_pangkat->setItemData(0, false,Qt::UserRole-1);

    pilihan_jabatan = new QComboBox(this);
    pilihan_jabatan->addItem("JABATAN");
    pilihan_jabatan->setItemData(0,QBrush(Qt::white),Qt::TextColorRole);
    pilihan_jabatan->setItemData(0,QColor(Qt::black),Qt::BackgroundColorRole);
    pilihan_jabatan->setItemData(0, false,Qt::UserRole-1);

    isian_alamat = new QTextEdit(this);
    isian_alamat->setFixedHeight(100);
//    isian_alamat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    pilihan_agama = new QComboBox(this);
    pilihan_agama->addItems(QStringList()<<"ISLAM"<<"KRISTEN"<<"KATOLIK"<<"HINDU"<<"BUDHA");
    pilihan_agama->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    pilihan_divisi = new QComboBox(this);
    pilihan_divisi->addItems(QStringList()<<"DIVISI");
    pilihan_divisi->setItemData(0,QBrush(Qt::white),Qt::TextColorRole);
    pilihan_divisi->setItemData(0,QColor(Qt::black),Qt::BackgroundColorRole);
    pilihan_divisi->setItemData(0, false,Qt::UserRole-1);
    connect(pilihan_divisi,SIGNAL(currentIndexChanged(int)),this,SLOT(ambilDaftarJabatan(int)));
    isian_tempat_lahir = new QLineEdit(this);

    QStringList daftarKota = listStringFileParser::parse(":/berkas/namakotadankabupaten.txt");

    completer = new QCompleter(daftarKota,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    isian_tempat_lahir->setCompleter(completer);

    date_edit = new CDateEdit(this);
    date_edit->aturJangka(tahun_sekarang-60, tahun_sekarang-17);

    connect(pilihan_golongan,SIGNAL(activated(int)),this,SLOT(resetPilihan()));

   isian_sprin_gabung = new QLineEdit(this);
   isian_sprin_gabung->setFixedWidth(80);

   kombo_bulan_sprin = new QComboBox(this);
   kombo_bulan_sprin->addItems(QStringList()<<"I"<<"II"<<"III"<<"IV"<<"V"<<"VI"
                               <<"VII"<<"VIII"<<"IX"<<"X"<<"XI"<<"XII");
   kombo_bulan_sprin->setCurrentIndex(bulan_sekarang-1);

   kombo_tahun_sprin = new QComboBox(this);
   kombo_tahun_sprin->addItems(QStringList()<<QString::number(tahun_sekarang)
                               <<QString::number(tahun_sekarang-1)<<QString::number(tahun_sekarang-2)
                                <<QString::number(tahun_sekarang-3)<<QString::number(tahun_sekarang-4)
                               );


   isian_tgl_sprin = new CDateEdit(this);
   isian_tgl_sprin->aturJangka(tahun_sekarang-5, tahun_sekarang);

   QHBoxLayout *tata_letak_isian_gabung = new QHBoxLayout;
   tata_letak_isian_gabung->addWidget(new QLabel("SPRIN/"));
   tata_letak_isian_gabung->addWidget(isian_sprin_gabung);
   tata_letak_isian_gabung->addWidget(new QLabel("/"));
   tata_letak_isian_gabung->addWidget(kombo_bulan_sprin);
   tata_letak_isian_gabung->addWidget(new QLabel("/"));
   tata_letak_isian_gabung->addWidget(kombo_tahun_sprin);
   tata_letak_isian_gabung->addWidget(new QLabel("/DIRPOLAIR"));
   tata_letak_isian_gabung->addWidget(new QLabel("\tTGL"));
   tata_letak_isian_gabung->addWidget(isian_tgl_sprin);
   tata_letak_isian_gabung->addStretch();

    QHBoxLayout *lo = new QHBoxLayout;
    lo->addWidget(isian_nama);

    QHBoxLayout *tata_letak_nrp = new QHBoxLayout;
    tata_letak_nrp->addWidget(isian_nrp);

    QHBoxLayout *tata_letak_pangkat = new QHBoxLayout;
    tata_letak_pangkat->addWidget(pilihan_golongan);
    tata_letak_pangkat->addWidget(pilihan_pangkat);
    tata_letak_pangkat->addWidget(pilihan_divisi);
    tata_letak_pangkat->addWidget(pilihan_jabatan);


    QHBoxLayout *tata_letak_alamat = new QHBoxLayout;
    tata_letak_alamat->addWidget(isian_alamat);

    isian_no_telp = new QLineEdit(this);
    isian_no_telp->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    connect(isian_no_telp,SIGNAL(textChanged(QString)),this,SLOT(perikasInt(QString)));

    QHBoxLayout *tata_letak_notelp = new QHBoxLayout;
    tata_letak_notelp->addWidget(isian_no_telp);

    QHBoxLayout *tata_letak_agama = new QHBoxLayout;
    tata_letak_agama->addWidget(pilihan_agama);

    QHBoxLayout *tata_letak_ttl = new QHBoxLayout;
    tata_letak_ttl->addWidget(isian_tempat_lahir);
    tata_letak_ttl->addWidget(date_edit);

    isian_nama_saudara = new QLineEdit(this);
    isian_nama_saudara->setPlaceholderText("Nama");

    isian_notelp_saudara = new QLineEdit(this);
    isian_notelp_saudara->setPlaceholderText("No. Telp");

    QHBoxLayout *tata_letak_saudara = new QHBoxLayout;
    tata_letak_saudara->addWidget(isian_nama_saudara);
    tata_letak_saudara->addWidget(isian_notelp_saudara);


    QDialogButtonBox *kotak_tombol = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel, this);
    connect(kotak_tombol,SIGNAL(accepted()),this,SLOT(simpan()));
    connect(kotak_tombol,SIGNAL(rejected()),this,SLOT(reject()));

    QHBoxLayout *tata_letak_atas=new QHBoxLayout;

    QVBoxLayout *tata_letak_sub_atas = new QVBoxLayout;
    tata_letak_sub_atas->addWidget(buatItem("Nama", lo));
    tata_letak_sub_atas->addWidget(buatItem("NRP/NIP", tata_letak_nrp));
    tata_letak_sub_atas->addWidget(buatItem("Pangkat", tata_letak_pangkat));
    tata_letak_sub_atas->addWidget(buatItem("Tempat dan tanggal lahir", tata_letak_ttl));
    tata_letak_sub_atas->setMargin(0);
    tata_letak_sub_atas->setSpacing(0);

    tata_letak_atas->addLayout(tata_letak_sub_atas);

    QVBoxLayout *tata_letak_foto = new QVBoxLayout;
    QPushButton *tombol_foto = new QPushButton("Tambahkan Foto",this);
    connect(tombol_foto,SIGNAL(pressed()),this,SLOT(ambilFoto()));

    QPixmap pix(":/berkas/ikon/ikon_foto.png");

    foto = new QLabel(this);
    foto->setFixedSize(120,180);
    foto->setPixmap(QPixmap(pix.scaled(foto->width(),foto->height(),Qt::KeepAspectRatio , Qt::SmoothTransformation)));

    tata_letak_foto->addWidget(foto);
    tata_letak_foto->addWidget(tombol_foto);
    tata_letak_foto->setMargin(0);
    tata_letak_foto->setSpacing(0);

    tata_letak_atas->addLayout(tata_letak_foto);

    tata_letak_atas->setMargin(0);
    tata_letak_atas->setSpacing(0);

    QWidget *widget_atas = new QWidget(this);
    widget_atas->setLayout(tata_letak_atas);

    tata_letak_utama->addWidget(widget_atas);
    tata_letak_utama->addWidget(buatItem("Agama", tata_letak_agama));
    tata_letak_utama->addWidget(buatItem("Alamat", tata_letak_alamat));
    tata_letak_utama->addWidget(buatItem("No. Telp",tata_letak_notelp ));
    tata_letak_utama->addWidget(buatItem("No. Sprin Gabung", tata_letak_isian_gabung));
    tata_letak_utama->addWidget(buatItem("Saudara yang bisa dihubungi saat darurat", tata_letak_saudara));
    tata_letak_utama->addStretch();
    tata_letak_utama->addWidget(kotak_tombol);
    setLayout(tata_letak_utama);
}

void dialogTambahAnggota::ambilDaftarJabatan(int j){

    switch (j) {
    case 1:
pilihan_jabatan->clear();
        pilihan_jabatan->addItems(QStringList()<<"JABATAN"<<"KOMANDAN");
        pilihan_jabatan->setItemData(0,QBrush(Qt::white),Qt::TextColorRole);
        pilihan_jabatan->setItemData(0,QColor(Qt::black),Qt::BackgroundColorRole);
        pilihan_jabatan->setItemData(0, false,Qt::UserRole-1);
        break;
    case 2:
        pilihan_jabatan->clear();
                pilihan_jabatan->addItems(QStringList()<<"JABATAN"<<"WAKIL KOMANDAN");
                pilihan_jabatan->setItemData(0,QBrush(Qt::white),Qt::TextColorRole);
                pilihan_jabatan->setItemData(0,QColor(Qt::black),Qt::BackgroundColorRole);
                pilihan_jabatan->setItemData(0, false,Qt::UserRole-1);
        break;
    case 3:


        pilihan_jabatan->clear();

        if(pilihan_golongan->currentIndex()==1){
            pilihan_jabatan->addItems(QStringList()<<"JABATAN"<<"PA NOPS"<<"PA NAT I"<< "PA NAT II"<<"PA NAT III");
                             }
         else   if(pilihan_golongan->currentIndex()==2){
                pilihan_jabatan->addItems(QStringList()<<"JABATAN"<<"BA NAT I"<< "BA NAT II"<< "BA NAT III"<<"BA NAT"<<"PS. PA NAT I"<<"PS. PA NAT II"<<"PS. PA NAT III");
             }
         else  if(pilihan_golongan->currentIndex()==3){
        pilihan_jabatan->addItems(QStringList()<<"JABATAN"<<"TA NAT");


                }
                pilihan_jabatan->setItemData(0,QBrush(Qt::white),Qt::TextColorRole);
                pilihan_jabatan->setItemData(0,QColor(Qt::black),Qt::BackgroundColorRole);
                pilihan_jabatan->setItemData(0, false,Qt::UserRole-1);
        break;
    case 4:
        while(pilihan_jabatan->count()>1){
        pilihan_jabatan->removeItem(1);
           }
                if(pilihan_golongan->currentIndex()==1){
                    pilihan_jabatan->addItems(QStringList()<<"KKM"<<"PA TEK I"<< "PA TEK II"<<"PA TEK III");
                            }
                    if(pilihan_golongan->currentIndex()==2){
                        pilihan_jabatan->addItems(QStringList()<<"BA TEK I"<< "BA TEK II"<< "BA TEK III"<<"BA TEK"<<"PS. PA TEK I"<<"PS. PA TEK II"<<"PS. PA TEK III");
                                }
                        if(pilihan_golongan->currentIndex()==3){
                pilihan_jabatan->addItem("TA TEK");
                        }
                break;
    case 5:
        while(pilihan_jabatan->count()>1){
        pilihan_jabatan->removeItem(1);
           }
                if(pilihan_golongan->currentIndex()==1){
                    pilihan_jabatan->addItem("PA KOMLEK");
                            }
                    if(pilihan_golongan->currentIndex()==2){
                        pilihan_jabatan->addItem("BA KOMLEK");
                                }
                        if(pilihan_golongan->currentIndex()==3){
                pilihan_jabatan->addItem("TA KOMLEK");
                        }
                break;
    default:
        break;
    }
}
void dialogTambahAnggota::pilihPangkat(int p){

        switch (p) {
        case 1:
                    while(pilihan_pangkat->count()>1){
                    pilihan_pangkat->removeItem(1);
                       }
            pilihan_pangkat->addItems(QStringList()<<"KOMBESPOL"<<"AKBP"<<"KOMPOL"<<"AKP"<<"IPTU"<<"IPDA");
            break;
        case 2:
                           while(pilihan_pangkat->count()>1){
                    pilihan_pangkat->removeItem(1);
            }
            pilihan_pangkat->addItems(QStringList()<<"AIPTU"<<"AIPDA"<<"BRIPKA"<<"BRIGADIR"<<"BRIPTU"<<"BRIPDA");
            break;
        case 3:

                while(pilihan_pangkat->count()>1){
                    pilihan_pangkat->removeItem(1);
                }

        pilihan_pangkat->addItems(QStringList()<<"ABRIPTU"<<"ABRIPDA"<<"BHARAKA"<<"BHARATU"<<"BHARADA");
        default:
            break;
        }
}

void dialogTambahAnggota::resetPilihan(){
    while(pilihan_jabatan->count()>1){
        pilihan_jabatan->removeItem(1);
    }

    pilihan_divisi->setCurrentIndex(0);
}


QWidget *dialogTambahAnggota::buatItem(QString _judul, QHBoxLayout *_tata_letak){

    QWidget *widget_baru = new QWidget(this);
    QHBoxLayout *tata_letak = new QHBoxLayout;
    QLabel *label = new QLabel(_judul, this);
    label->setWordWrap(1);
    QLabel *leb = new QLabel(":", this);
    leb->adjustSize();
    label->setFixedWidth(150);

    tata_letak->addWidget(label);
    tata_letak->addWidget(leb);
    tata_letak->addLayout(_tata_letak);
    tata_letak->addStretch();
    tata_letak->setMargin(0);
    widget_baru->setLayout(tata_letak);

    return widget_baru;

}


void dialogTambahAnggota::perikasInt(const QString &_string){
    QLineEdit *edit = qobject_cast<QLineEdit*>(sender());
//cek int, lebih enak ini daripada menggunakan QValidator atau inpputmask
    QStringList list = _string.split("");
          bool ok;
//dimulai dari 1 karena nilai 0 adalah string kosong
          for (int i=1;i<list.size()-1;i++){
              list.at(i).toInt(&ok);
              if(!ok)
                   edit->backspace();
          }

}


void dialogTambahAnggota::ambilFoto(){

    berkas_foto = QFileDialog::getOpenFileName(this, "Pilih Foto", QDir::homePath(), "Berkas Foto (*.jpg *.png) ");

    if(!berkas_foto.isEmpty()){
        fotoDiTambahkan=true;
        QPixmap p(berkas_foto);
        foto->setPixmap(QPixmap(p.scaled(foto->width(),foto->height(),Qt::KeepAspectRatio , Qt::SmoothTransformation)));
    }
}


void dialogTambahAnggota::simpan(){
    //cek dulu
    bool sesuai=true;
    QString info;
    if(isian_nama->text().isEmpty()) {
           info.append("Isian Nama tidak boleh kosong.<br/>");
        sesuai=false;
}
            if(isian_nrp->text()==NULL){
            info.append("Isian NRP tidak boleh kosong.<br/>");
            sesuai=false;
}

    if(pilihan_golongan->currentIndex()==0 || pilihan_pangkat->currentIndex()==0 || pilihan_divisi->currentIndex()==0 || pilihan_jabatan->currentIndex()==0){
            info.append("Pangkat tidak benar.<br/>");
        sesuai=false;
    }

    if(isian_alamat->toPlainText()==NULL){
            info.append("Isian alamat tidak boleh kosong.<br/>");
        sesuai=false;
    }

    if(isian_tempat_lahir->text()==NULL){
        info.append("Isian tempat lahir tidak boleh kosong.<br/>");
    }

    if(isian_no_telp->text()==NULL){
            info.append("isi No. Telp tidak boleh kosong.<br/>");
        sesuai=false;
    }

    if(!sesuai){

            QMessageBox pesan; //= new QMessageBox(this);
            pesan.setInformativeText(info);
            pesan.setText("Galat!");
            pesan.exec();
            return;
}


    anggota *_anggota = new anggota(this);
    _anggota->tetapkanNama(isian_nama->text());
    _anggota->tetapkanNrp(isian_nrp->text());
    _anggota->tetapkanGolongan(pilihan_golongan->currentText());
    _anggota->tetapkanPangkat(pilihan_pangkat->currentText());
    _anggota->tetapkanDivisi(pilihan_divisi->currentText());
    _anggota->tetapkanJabatan(pilihan_jabatan->currentText());
    _anggota->tetapkanAgama(pilihan_agama->currentText());
    _anggota->tetapkanTempatLahir(isian_tempat_lahir->text());
    _anggota->tetapkanTanggalLahir(date_edit->ambilTanggal());
    _anggota->tetapkanAlamat(isian_alamat->toPlainText());
    _anggota->tetapkanNotelp(isian_no_telp->text());
    _anggota->tetapkanNoSprinGabung(ambilNoSprinGabung());
    _anggota->tetapkanTanggalGabung(ambilTanggalSprinGabung());
    _anggota->tetapkanNamaSaudara(isian_nama_saudara->text());
    _anggota->tetapkanNoTelpSaudara(isian_notelp_saudara->text());

    //ambil foto
    if(fotoDiTambahkan){
//    QPixmap pix = QPixmap(berkas_foto);
    QPixmap pix = *foto->pixmap();

    QByteArray in_byte_array;
    QBuffer buffer(&in_byte_array);
    buffer.open(QIODevice::WriteOnly);
    pix.save(&buffer,"JPG");

    _anggota->tetapkanFoto(in_byte_array);
    }

    pengelolapusatdata *ppd = new pengelolapusatdata(pengelolapusatdata::tambah_personil, this);
    ppd->hubungkan();
//    aturMode(dialogTambahAnggota::tambah);

    if(ambilMode()==dialogTambahAnggota::tambah){
    ppd->tambahAnggota(_anggota);
    }
 else if(ambilMode()==dialogTambahAnggota::sunting){
        ppd->perbaruiAnggota(nrp_lama, _anggota );

    }


    accept();
    delete _anggota;
    delete ppd;

}

void dialogTambahAnggota::ambilDivisi(int d){

    switch (d){
    case 3://bhayangkara
        pilihan_divisi->clear();
        pilihan_divisi->addItems(QStringList()<<"DIVISI"<<"NAUTIKA"<<"TEKNIKA"<<"KOMLEK");
        pilihan_divisi->setItemData(0,QBrush(Qt::white),Qt::TextColorRole);
        pilihan_divisi->setItemData(0,QColor(Qt::black),Qt::BackgroundColorRole);
        pilihan_divisi->setItemData(0, false,Qt::UserRole-1);
        break;
    case 4:
        break;
        default:
        pilihan_divisi->clear();
        pilihan_divisi->addItems(QStringList()<<"DIVISI"<<"KOMANDAN"<<"WAKIL KOMANDAN"<<"NAUTIKA"<<"TEKNIKA"<<"KOMLEK"<<"KESEHATAN");
        pilihan_divisi->setItemData(0,QBrush(Qt::white),Qt::TextColorRole);
        pilihan_divisi->setItemData(0,QColor(Qt::black),Qt::BackgroundColorRole);
        pilihan_divisi->setItemData(0, false,Qt::UserRole-1);

    }

}

void dialogTambahAnggota::isiNama(QString nama){

    isian_nama->setText(nama);

}

void dialogTambahAnggota::isiNRP(QString nrp){

    nrp_lama=nrp;
    isian_nrp->setText(nrp);
}

void dialogTambahAnggota::pilihGolongan(QString golongan){

    pilihan_golongan->setCurrentText(golongan);
}

void dialogTambahAnggota::isiAlamat(QString alamat){

    isian_alamat->setText(alamat);

}

void dialogTambahAnggota::pilihAgama(QString agama){
    pilihan_agama->setCurrentText(agama);
}

void dialogTambahAnggota::isiNoTelp(QString notelp){
    isian_no_telp->setText(notelp);
}

void dialogTambahAnggota::isiTempatLahir(QString tempatLahir){

    isian_tempat_lahir->setText(tempatLahir);

}


void dialogTambahAnggota::isiTanggalLahir(QString tanggallahir){

    date_edit->aturKeTanggal(tanggallahir);
    qDebug()<<"tl"<<tanggallahir;

}

void dialogTambahAnggota::tetapkanPangkat(QString pangkat){
    pilihan_pangkat->setCurrentText(pangkat);

}
void dialogTambahAnggota::tetapkanDivisi(QString divisi){

    pilihan_divisi->setCurrentText(divisi);

}

void dialogTambahAnggota::tetapkanJabatan(QString jabatan){

    pilihan_jabatan->setCurrentText(jabatan);

}



void dialogTambahAnggota::tetapkanAnggota(anggota *_anggota){
    isiNama(_anggota->ambilNama());
    isiNRP(_anggota->ambilNrp());
    isiNoTelp(_anggota->ambilNoTelp());
    isiAlamat(_anggota->ambilAlamat());
    isiTempatLahir(_anggota->ambilTempatLahir());
    pilihGolongan(_anggota->ambilGolongan());
    tetapkanPangkat(_anggota->ambilPangkat());
    tetapkanDivisi(_anggota->ambilDivisi());
    tetapkanJabatan(_anggota->ambilJabatan());
    pilihAgama(_anggota->ambilAgama());
    isiTanggalLahir(_anggota->ambilTanggalLahir());
    tetapkanFoto(_anggota->ambilFoto());
    tetapkanNamaSaudara(_anggota->ambilNamaSaudara());
    tetapkanNoTelpSaudara(_anggota->ambilNoTelpSaudara());
}

void dialogTambahAnggota::aturMode(mode md){


    _mode = md;

}

dialogTambahAnggota::mode dialogTambahAnggota::ambilMode(){

    return _mode;
}

QString dialogTambahAnggota::ambilNoSprinGabung(){


    return isian_sprin_gabung->text()+"/"+kombo_bulan_sprin->currentText()+"/"+kombo_tahun_sprin->currentText();

}
QString dialogTambahAnggota::ambilTanggalSprinGabung(){

   return isian_tgl_sprin->ambilTanggal().toString("dd/MM/yyyy");

}

dialogTambahAnggota::~dialogTambahAnggota(){

}


void dialogTambahAnggota::tetapkanFoto(QByteArray _foto){

    QPixmap outPixmap = QPixmap();
        outPixmap.loadFromData( _foto );

   foto->setPixmap(outPixmap.scaled(foto->width(),foto->height(),Qt::KeepAspectRatio , Qt::SmoothTransformation));

}
void dialogTambahAnggota::tetapkanNamaSaudara(QString _nama_saudara){
    
    isian_nama_saudara->setText(_nama_saudara);
    
    
}

void dialogTambahAnggota::tetapkanNoTelpSaudara(QString _no_telp_saudara){

    isian_notelp_saudara->setText(_no_telp_saudara);

}
