#include "tablemodel.h"

TableModel::TableModel(QObject *parent, QSqlDatabase db):
    QSqlTableModel(parent, db)
{

}

QVariant TableModel::data (const QModelIndex & index,
               int role) const {
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole){
        if (index.column() == 0)
            return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
        else
            return Qt::AlignCenter;
    }
    else {
            return QSqlQueryModel::data(index, role);
        }
    return QVariant();
}
