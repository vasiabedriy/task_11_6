#include <QMessageBox>
#include "task_6.h"


std::vector<QString> name;
std::vector<QString> group;

task_6::task_6(QWidget *parent) :
    QMainWindow(parent)
{
    this->setSizeIncrement(200,200);

    m_name = new QLineEdit(this);
    m_name->setGeometry(QRect(QPoint(10,10),QSize(70,20)));

    m_lastname = new QLineEdit(this);
    m_lastname->setGeometry(QRect(QPoint(10,50),QSize(70,20)));

    m_group = new QLineEdit(this);
    m_group->setGeometry(QRect(QPoint(10,90),QSize(70,20)));

    m_names = new QComboBox(this);
    m_names->setGeometry(QRect(QPoint(100,10),QSize(70,20)));


    m_namegroup = new QLabel(this);
    m_namegroup->setGeometry(QRect(QPoint(100,50),QSize(70,20)));
    connect(m_names, SIGNAL(currentIndexChanged(QString)), this ,SLOT(on_list_currentIndexChanged(QString)));

    m_add = new QPushButton("Add",this);
    m_add->setGeometry(QRect(QPoint(100,90),QSize(70,20)));
    connect(m_add, SIGNAL(clicked(bool)), this ,SLOT(on_add_clicked()));



    m_names->addItem("");
}

task_6::~task_6()
{
    delete m_add;
    delete m_group;
    delete m_lastname;
    delete m_name;
    delete m_namegroup;
    delete m_names;
}

void task_6::on_add_clicked()
{
    if (m_name->text().length()>0 && m_lastname->text().length()>0 && m_group->text().length()>0)
    {
        QString s = m_lastname->text() + " " + m_name->text();
        name.push_back(s);
        group.push_back(m_group->text());

        m_names->addItem(s);
    }
    else
    {
        QMessageBox::information(this,"","wrong input");
    }
}

void task_6::on_list_currentIndexChanged(QString arg)
{
     m_namegroup->setText("");

     for (int i = 0; i < name.size() ; ++i) {
        if (arg == name[i]) {
            m_namegroup->setText(group[i]);
            break;
        }

    }
    //QMessageBox::information(this,"","change");
}
