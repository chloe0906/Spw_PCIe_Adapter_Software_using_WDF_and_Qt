#ifndef THREEDIALOG_H
#define THREEDIALOG_H

#include <QDialog>

namespace Ui {
class ThreeDialog;
}

class ThreeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThreeDialog(QWidget *parent = 0);
    ~ThreeDialog();
private slots:
    void show3D();
private:
    Ui::ThreeDialog *ui;
};

#endif // THREEDIALOG_H
