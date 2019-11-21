#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QComboBox>
#include <QDateEdit>
#include <QFile>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QTreeView>

class NoteBook : public QMainWindow
{
    Q_OBJECT

public:
    NoteBook(QWidget *parent = 0);
    ~NoteBook();
private slots:
    void openNote();
private:
    QLabel *labelDateFrom;
    QLabel *labelDateTo;
    QLabel *labelCategory;
    QDateEdit *dateFrom;
    QDateEdit *dateTo;
    QComboBox *comboCategory;
    QPushButton *buttonFilter;
    QPushButton *buttonClear;
    QTreeView *treeNoteList;
    QPushButton *buttonNewNote;
    QPushButton *buttonEditNote;
    QPushButton *buttonDeleteNote;

    QFile *fileCategory;
};

#endif // NOTEBOOK_H
