#ifndef XH_MIPS_H
#define XH_MIPS_H

#include <QMainWindow>

namespace Ui {
class XH_mips;
}

class XH_mips : public QMainWindow
{
    Q_OBJECT

public:
    explicit XH_mips(QWidget *parent = 0);
    ~XH_mips();
    void closeEvent(QCloseEvent *event);

private slots:
    //void on_pushButton_clicked();

    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_as_triggered();
    void on_actionBuild_triggered();
    void on_actionBuild_coe_triggered();

private:
    Ui::XH_mips *ui;
    bool maybeSave();
    QString deal_codeline(QString codeline,int base);
    QString biasm(QString codeline);
    //QString remove_comment(QString codeline);
    void deal_regs(QString codeline);
    QString pre_compile(QString scrs);
    //void getloop(QString scrs);
    QString curFile;
    std::map<QString, int> pc_loop;
    std::map<QString, int> reg;
    std::map<int, QString> b_reg;
    std::map<QString, int> op_code_r;
    std::map<QString, int> op_code_i;
    std::map<QString, int> op_code_j;
    std::map<int, QString> fun_r;
    std::map<int, QString> op_code;
    QString StrTmp, Temp,codes,mipsline ;
    QStringList codelines;
    QStringList words;
    int pc_addr; //储存pc地址
    unsigned int regs_value[32];
    int linenum;
    bool ok;
};

#endif // XH_MIPS_H
