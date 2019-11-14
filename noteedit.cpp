#include "noteedit.h"
#include "ui_noteedit.h"

NoteEdit::NoteEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoteEdit)
{
    ui->setupUi(this);
}

NoteEdit::~NoteEdit()
{
    delete ui;
}
