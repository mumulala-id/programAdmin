#ifndef JUDUL_H
#define JUDUL_H

#include <QLabel>

class Judul : public QWidget
{
public:
    Judul(QWidget *parent=0);
private:
    QLabel *label_atas;
    QLabel *label_bawah;
private slots:
public slots:
    void tetapkanJudulAtas(QString);
    void tetapkanJudulBawah(QString);

protected :
    void paintEvent(QPaintEvent *);
};

#endif // JUDUL_H
