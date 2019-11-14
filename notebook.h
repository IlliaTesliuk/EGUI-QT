#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QMainWindow>

class NoteBook : public QMainWindow
{
    Q_OBJECT

public:
    NoteBook(QWidget *parent = 0);
    ~NoteBook();
};

#endif // NOTEBOOK_H
