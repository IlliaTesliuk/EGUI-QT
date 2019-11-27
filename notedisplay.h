#ifndef NOTEDISPLAY_H
#define NOTEDISPLAY_H

#include <QAbstractItemModel>

class NoteDisplay : public QAbstractTableModel
{
    Q_OBJECT
public slots:
    void rowClicked( const QModelIndex &index );
public:
    explicit NoteDisplay(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    void readNoteFile(QString path);

    QList<QString> *listTitles;
    QList<QStringList> *listCategories;
    QList<QDate> *listDates;
    QList<QString> *listContents;
};

#endif // NOTEDISPLAY_H
