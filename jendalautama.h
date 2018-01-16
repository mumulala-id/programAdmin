#ifndef JENDALAUTAMA_H
#define JENDALAUTAMA_H

#include <QDialog>
class jendalaUtama : public QDialog{
    Q_OBJECT
public:
   explicit  jendalaUtama(QWidget*parent=0);
private slots:
    void tampilSurat();
};

#endif // JENDALAUTAMA_H
