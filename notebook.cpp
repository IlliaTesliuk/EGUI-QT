#include "notebook.h"
#include "noteedit.h"

#include <QBoxLayout>

NoteBook::NoteBook(QWidget *parent)
    : QMainWindow(parent)
{
    labelDateFrom = new QLabel("From: ");
    labelDateTo = new QLabel("To: ");
    labelCategory = new QLabel("Cateogry: ");

    buttonFilter = new QPushButton("Filter");
    buttonClear = new QPushButton("Clear");

    QHBoxLayout *layoutFilter = new QHBoxLayout();
    layoutFilter->addWidget(labelDateFrom);
    layoutFilter->addWidget(dateFrom);
    layoutFilter->addWidget(labelDateTo);
    layoutFilter->addWidget(dateTo);
    layoutFilter->addWidget(labelCategory);
    layoutFilter->addWidget(comboCategory);
    layoutFilter->addWidget(buttonFilter);
    layoutFilter->addWidget(buttonClear);

    QHBoxLayout *layoutNoteActions = new QHBoxLayout();
    layoutNoteActions->addWidget(buttonNewNote);
    layoutNoteActions->addWidget(buttonEditNote);
    layoutNoteActions->addWidget(buttonDeleteNote);

    QVBoxLayout *layoutMain = new QVBoxLayout();
    layoutMain->addLayout(layoutFilter);
    layoutMain->addWidget(treeNoteList);
    layoutMain->addLayout(layoutNoteActions);
}

NoteBook::~NoteBook()
{

}

NoteBook::openNote()
{
    NoteEdit note;
    note.exec();
}
