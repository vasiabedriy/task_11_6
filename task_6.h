#ifndef TASK_6_H
#define TASK_6_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

namespace Ui {
class task_6;
}

class task_6 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task_6(QWidget *parent = 0);
    ~task_6();

private slots:
    void on_add_clicked();

    void on_list_currentIndexChanged(QString arg);

private:
    QLineEdit* m_name;
    QLineEdit* m_lastname;
    QLineEdit* m_group;
    QPushButton* m_add;
    QLabel* m_namegroup;
    QComboBox* m_names;
};

#endif // TASK_6_H
