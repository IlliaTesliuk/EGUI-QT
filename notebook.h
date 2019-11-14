#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QComboBox>
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
    QDateTime *dateFrom;
    QDateTime *dateTo;
    QComboBox *comboCategory;
    QPushButton *buttonFilter;
    QPushButton *buttonClear;
    QTreeView *treeNoteList;
    QPushButton *buttonNewNote;
    QPushButton *buttonEditNote;
    QPushButton *buttonDeleteNote;
};

#endif // NOTEBOOK_H
