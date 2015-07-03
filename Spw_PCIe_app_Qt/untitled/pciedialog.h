#ifndef PCIEDIALOG_H
#define PCIEDIALOG_H

#include <QDialog>

namespace Ui {
class PCIeDialog;
}

class PCIeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PCIeDialog(QWidget *parent = 0);
    ~PCIeDialog();
public slots:
    void write();
    void writeAddoffset();
    void read();
private:
    Ui::PCIeDialog *ui;

    void initActionsConnections();
};

#endif // PCIEDIALOG_H
