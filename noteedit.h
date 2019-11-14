#ifndef NOTEEDIT_H
#define NOTEEDIT_H

#include <QDialog>

namespace Ui {
class NoteEdit;
}

class NoteEdit : public QDialog
{
    Q_OBJECT

public:
    explicit NoteEdit(QWidget *parent = 0);
    ~NoteEdit();

private:
    Ui::NoteEdit *ui;
};

#endif // NOTEEDIT_H
