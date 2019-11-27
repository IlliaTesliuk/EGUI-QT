#include "notedisplay.h"

#include <QDate>
#include <QDir>
#include <QTextStream>

NoteDisplay::NoteDisplay(QObject *parent)
    : QAbstractTableModel(parent)
{
    listTitles = new QList<QString>();
    listDates = new QList<QDate>();
    listContents = new QList<QString>();
    listCategories = new QList<QStringList>();
    QString pathDir = "/home/jgaik/Projects/Z02/Content/Notes";
    QDir *directory = new QDir(pathDir);
    QFileInfoList files = directory->entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    foreach (QFileInfo file, files)
    {
        NoteDisplay::readNoteFile(file.filePath());
    }
}

void NoteDisplay::rowClicked( const QModelIndex &index )
{
    emit listTitles->at(index.row());
}

QVariant NoteDisplay::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            if (section == 0) {
                return QString("Date");
            } else if (section == 1) {
                return QString("Title");
            }
        }
    return QVariant();
}

int NoteDisplay::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return listDates->length();
}

int NoteDisplay::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

QVariant NoteDisplay::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if (index.column() == 0)
    {
        return  listDates->at(index.row()).toString("yyyy-MM-dd");
    } else if (index.column() == 1)
    {
        return listTitles->at(index.row());
    }
    return QVariant();
}

void NoteDisplay::readNoteFile(QString path)
{
    QFile* fileNote = new QFile(path);
    fileNote->open(QIODevice::ReadOnly);
    QTextStream* streamNote = new QTextStream(fileNote);
    QStringList note = streamNote->readAll().split(QRegExp("\n|\r\n|\r"));
    listDates->append(QDate::fromString(note[1].remove("date: "),"yyyy/MM/dd"));
    listContents->append(QStringList(note.mid(2)).join("\n"));
    listCategories->append(note[0].remove("category: ").split(","));
    listTitles->append(QFileInfo(*fileNote).baseName());
}
