#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QComboBox>
#include <QDateEdit>
#include <QFile>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QTableView>
#include "notedisplay.h"

class NoteBook : public QMainWindow
{
    Q_OBJECT

public:
    NoteBook(QWidget *parent = nullptr);
    ~NoteBook();
private slots:
    void openNote(QString noteTitle);
private:
    NoteDisplay *notes;
    QLabel *labelDateFrom;
    QLabel *labelDateTo;
    QLabel *labelCategory;
    QDateEdit *dateFrom;
    QDateEdit *dateTo;
    QComboBox *comboCategory;
    QPushButton *buttonFilter;
    QPushButton *buttonClear;
    QTableView *tableNoteList;
    QPushButton *buttonNewNote;
    QPushButton *buttonEditNote;
    QPushButton *buttonDeleteNote;

    QFile *fileCategory;
};

#endif // NOTEBOOK_H
