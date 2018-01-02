#ifndef SURAT_H
#define SURAT_H

#include <QWidget>
#include "kop.h"
#include "kotaktandatangan.h"
#include "judul.h"

class surat : public QWidget
{
    Q_OBJECT
public:
    explicit surat(QWidget *parent = nullptr);

private:
//    QString judul;
    QLabel *label_judul;
    Judul *judul;
    QWidget *widget_isi;
signals:
public slots:
    void tetapkanJudulAtas(QString);
    void tetapkanJudulBawah(QString);
    void tetapkanWidgetIsi(QWidget *);

private slots:
};

#endif // SURAT_H
