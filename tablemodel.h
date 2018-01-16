#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QSqlTableModel>

class TableModel : public QSqlTableModel
{
    Q_OBJECT

public:

    TableModel(QObject*parent=0, QSqlDatabase db = QSqlDatabase());
    QVariant data (const QModelIndex & index,
                     int role = Qt::DisplayRole) const;
};

#endif // TABLEMODEL_H
