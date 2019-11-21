#include "notebook.h"
#include "noteedit.h"

#include <QBoxLayout>
#include <QTextStream>

NoteBook::NoteBook(QWidget *parent)
    : QMainWindow(parent)
{
    labelDateFrom = new QLabel("&From: ");
    dateFrom = new QDateEdit;
    dateFrom->setDisplayFormat("yyyy-MM-dd");
    dateFrom->setMaximumDate(QDate::currentDate());
    labelDateFrom->setBuddy(dateFrom);

    labelDateTo = new QLabel("&To: ");
    dateTo = new QDateEdit(QDate::currentDate());
    dateTo->setDisplayFormat("yyyy-MM-dd");
    dateTo->setMaximumDate(QDate::currentDate());
    labelDateTo->setBuddy(dateTo);

    fileCategory = new QFile("/home/users/jgaik/Z02/Content/Categories.txt");
    fileCategory->open(QIODevice::ReadWrite);
    QTextStream streamCategory(fileCategory);

    labelCategory = new QLabel("&Cateogry: ");
    comboCategory = new QComboBox();
    comboCategory->addItem("<All>");
    while(!streamCategory.atEnd()) {
        QString sCategory = streamCategory.readLine();
        if (sCategory != "")
            comboCategory->addItem(sCategory);
    }
    labelCategory->setBuddy(comboCategory);

    buttonFilter = new QPushButton("Filter");
    buttonClear = new QPushButton("Clear");

    treeNoteList = new QTreeView();

    buttonNewNote = new QPushButton("Add Note");
    buttonEditNote = new QPushButton("Edit Note");
    buttonDeleteNote = new QPushButton("Delete Note");

    QHBoxLayout *layoutFilter = new QHBoxLayout;
    layoutFilter->addWidget(labelDateFrom);
    layoutFilter->addWidget(dateFrom);
    layoutFilter->addWidget(labelDateTo);
    layoutFilter->addWidget(dateTo);
    layoutFilter->addWidget(labelCategory);
    layoutFilter->addWidget(comboCategory);
    layoutFilter->addWidget(buttonFilter);
    layoutFilter->addWidget(buttonClear);

    QHBoxLayout *layoutNoteActions = new QHBoxLayout;
    layoutNoteActions->addWidget(buttonNewNote);
    layoutNoteActions->addWidget(buttonEditNote);
    layoutNoteActions->addWidget(buttonDeleteNote);

    QVBoxLayout *layoutMain = new QVBoxLayout;
    layoutMain->addLayout(layoutFilter);
    layoutMain->addWidget(treeNoteList);
    layoutMain->addLayout(layoutNoteActions);

    QWidget* widgetLayoutHolder = new QWidget();
    widgetLayoutHolder->setLayout(layoutMain);
    setWindowTitle("Notebook");
    setCentralWidget(widgetLayoutHolder);
}

NoteBook::~NoteBook()
{
    fileCategory->close();
}

void NoteBook::openNote()
{
    NoteEdit note;
    note.exec();
}
