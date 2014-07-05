#include "xh_mips.h"
#include "ui_xh_mips.h"
#include <QtWidgets>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <stdio.h>

XH_mips::XH_mips(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XH_mips)
{
        linenum = -1;
        reg.insert(std::map<QString, int>::value_type(("$zero"), 0));
        reg.insert(std::map<QString, int>::value_type(("$at"), 1));
        reg.insert(std::map<QString, int>::value_type(("$v0"), 2));
        reg.insert(std::map<QString, int>::value_type(("$v1"), 3));
        reg.insert(std::map<QString, int>::value_type(("$a0"), 4));
        reg.insert(std::map<QString, int>::value_type(("$a1"), 5));
        reg.insert(std::map<QString, int>::value_type(("$a2"), 6));
        reg.insert(std::map<QString, int>::value_type(("$a3"), 7));
        reg.insert(std::map<QString, int>::value_type(("$t0"), 8));
        reg.insert(std::map<QString, int>::value_type(("$t1"), 9));
        reg.insert(std::map<QString, int>::value_type(("$t2"), 10));
        reg.insert(std::map<QString, int>::value_type(("$t3"), 11));
        reg.insert(std::map<QString, int>::value_type(("$t4"), 12));
        reg.insert(std::map<QString, int>::value_type(("$t5"), 13));
        reg.insert(std::map<QString, int>::value_type(("$t6"), 14));
        reg.insert(std::map<QString, int>::value_type(("$t7"), 15));
        reg.insert(std::map<QString, int>::value_type(("$s0"), 16));
        reg.insert(std::map<QString, int>::value_type(("$s1"), 17));
        reg.insert(std::map<QString, int>::value_type(("$s2"), 18));
        reg.insert(std::map<QString, int>::value_type(("$s3"), 19));
        reg.insert(std::map<QString, int>::value_type(("$s4"), 20));
        reg.insert(std::map<QString, int>::value_type(("$s5"), 21));
        reg.insert(std::map<QString, int>::value_type(("$s6"), 22));
        reg.insert(std::map<QString, int>::value_type(("$s7"), 23));
        reg.insert(std::map<QString, int>::value_type(("$t8"), 24));
        reg.insert(std::map<QString, int>::value_type(("$t9"), 25));
        reg.insert(std::map<QString, int>::value_type(("$k0"), 26));
        reg.insert(std::map<QString, int>::value_type(("$k1"), 27));
        reg.insert(std::map<QString, int>::value_type(("$gp"), 28));
        reg.insert(std::map<QString, int>::value_type(("$sp"), 29));
        reg.insert(std::map<QString, int>::value_type(("$fp"), 30));
        reg.insert(std::map<QString, int>::value_type(("$ra"), 31));

        b_reg.insert(std::map<int, QString>::value_type(0,("$zero")));
        b_reg.insert(std::map<int, QString>::value_type(1,("$at")));
        b_reg.insert(std::map<int, QString>::value_type(2,("$v0")));
        b_reg.insert(std::map<int, QString>::value_type(3,("$v1")));
        b_reg.insert(std::map<int, QString>::value_type(4,("$a0")));
        b_reg.insert(std::map<int, QString>::value_type(5,("$a1")));
        b_reg.insert(std::map<int, QString>::value_type(6,("$a2")));
        b_reg.insert(std::map<int, QString>::value_type(7,("$a3")));
        b_reg.insert(std::map<int, QString>::value_type(8,("$t0")));
        b_reg.insert(std::map<int, QString>::value_type(9,("$t1")));
        b_reg.insert(std::map<int, QString>::value_type(10,("$t2")));
        b_reg.insert(std::map<int, QString>::value_type(11,("$t3")));
        b_reg.insert(std::map<int, QString>::value_type(12,("$t4")));
        b_reg.insert(std::map<int, QString>::value_type(13,("$t5")));
        b_reg.insert(std::map<int, QString>::value_type(14,("$t6")));
        b_reg.insert(std::map<int, QString>::value_type(15,("$t7")));
        b_reg.insert(std::map<int, QString>::value_type(16,("$s0")));
        b_reg.insert(std::map<int, QString>::value_type(17,("$s1")));
        b_reg.insert(std::map<int, QString>::value_type(18,("$s2")));
        b_reg.insert(std::map<int, QString>::value_type(19,("$s3")));
        b_reg.insert(std::map<int, QString>::value_type(20,("$s4")));
        b_reg.insert(std::map<int, QString>::value_type(21,("$s5")));
        b_reg.insert(std::map<int, QString>::value_type(22,("$s6")));
        b_reg.insert(std::map<int, QString>::value_type(23,("$s7")));
        b_reg.insert(std::map<int, QString>::value_type(24,("$t8")));
        b_reg.insert(std::map<int, QString>::value_type(25,("$t9")));
        b_reg.insert(std::map<int, QString>::value_type(26,("$k0")));
        b_reg.insert(std::map<int, QString>::value_type(27,("$k1")));
        b_reg.insert(std::map<int, QString>::value_type(28,("$gp")));
        b_reg.insert(std::map<int, QString>::value_type(29,("$sp")));
        b_reg.insert(std::map<int, QString>::value_type(30,("$fp")));
        b_reg.insert(std::map<int, QString>::value_type(31,("$ra")));

        op_code_r.insert(std::map<QString, int>::value_type(("add"), 0x20));
        op_code_r.insert(std::map<QString, int>::value_type(("sub"), 0x22));
        op_code_r.insert(std::map<QString, int>::value_type(("and"), 0x24));
        op_code_r.insert(std::map<QString, int>::value_type(("or"), 0x25));
        op_code_r.insert(std::map<QString, int>::value_type(("xor"), 0x26));
        op_code_r.insert(std::map<QString, int>::value_type(("nor"), 0x27));
        op_code_r.insert(std::map<QString, int>::value_type(("slt"), 0x2a));
        op_code_r.insert(std::map<QString, int>::value_type(("div"), 0x1a));
        op_code_r.insert(std::map<QString, int>::value_type(("divu"), 0x1b));
        op_code_r.insert(std::map<QString, int>::value_type(("mult"), 0x18));
        op_code_r.insert(std::map<QString, int>::value_type(("multu"), 0x19));
        op_code_r.insert(std::map<QString, int>::value_type(("sll"), 0));
        op_code_r.insert(std::map<QString, int>::value_type(("sllv"), 0x4));
        op_code_r.insert(std::map<QString, int>::value_type(("sra"), 3));
        op_code_r.insert(std::map<QString, int>::value_type(("srav"), 7));
        op_code_r.insert(std::map<QString, int>::value_type(("srl"), 2));
        op_code_r.insert(std::map<QString, int>::value_type(("srlv"), 6));
        op_code_r.insert(std::map<QString, int>::value_type(("subu"), 0x23));


        op_code_i.insert(std::map<QString, int>::value_type(("addi"), 0x8));
        op_code_i.insert(std::map<QString, int>::value_type(("addiu"), 0x9));
        op_code_i.insert(std::map<QString, int>::value_type(("andi"), 0xc));
        op_code_i.insert(std::map<QString, int>::value_type(("ori"), 0xd));
        op_code_i.insert(std::map<QString, int>::value_type(("xori"), 0xe));
        op_code_i.insert(std::map<QString, int>::value_type(("lui"), 0xf));
        op_code_i.insert(std::map<QString, int>::value_type(("slti"), 0xa));

        op_code_j.insert(std::map<QString, int>::value_type(("j"), 0x2));
        op_code_j.insert(std::map<QString, int>::value_type(("J"), 0x2));
        op_code_j.insert(std::map<QString, int>::value_type(("Jal"), 0x3));
        op_code_j.insert(std::map<QString, int>::value_type(("jal"), 0x3));

        fun_r.insert(std::map<int, QString>::value_type(0x20,("add")));
        fun_r.insert(std::map<int, QString>::value_type(0x21,("addu")));
        fun_r.insert(std::map<int, QString>::value_type(0x22,("sub")));
        fun_r.insert(std::map<int, QString>::value_type(0x24,("and")));
        fun_r.insert(std::map<int, QString>::value_type(0x25,("or")));
        fun_r.insert(std::map<int, QString>::value_type(0x26,("xor")));
        fun_r.insert(std::map<int, QString>::value_type(0x27,("nor")));
        fun_r.insert(std::map<int, QString>::value_type(0x2a,("slt")));
        fun_r.insert(std::map<int,QString>::value_type(0x1a,("div")));
        fun_r.insert(std::map<int,QString>::value_type(0x1b,("divu")));
        fun_r.insert(std::map<int,QString>::value_type(0x18,("mult")));
        fun_r.insert(std::map<int,QString>::value_type(0x19,("multu")));
        fun_r.insert(std::map<int,QString>::value_type(0x0,("sll")));
        fun_r.insert(std::map<int,QString>::value_type(0x4,("sllv")));
        fun_r.insert(std::map<int,QString>::value_type(0x3,("sra")));
        fun_r.insert(std::map<int,QString>::value_type(0x7,("srav")));
        fun_r.insert(std::map<int,QString>::value_type(2,("srl")));
        fun_r.insert(std::map<int,QString>::value_type(6,("srlv")));
        fun_r.insert(std::map<int,QString>::value_type(0x23,("subu")));
        fun_r.insert(std::map<int,QString>::value_type(0x8,("jr")));
        fun_r.insert(std::map<int,QString>::value_type(0x9,("jalr")));

        op_code.insert(std::map<int, QString>::value_type(0x8,("addi")));
        op_code.insert(std::map<int, QString>::value_type(0xc,("andi")));
        op_code.insert(std::map<int, QString>::value_type(0xd,("ori")));
        op_code.insert(std::map<int, QString>::value_type(0xe,("xori")));
        op_code.insert(std::map<int, QString>::value_type(0xf,("lui")));
        op_code.insert(std::map<int, QString>::value_type(0xa,("slti")));
        op_code.insert(std::map<int, QString>::value_type(0x2,("j")));
        op_code.insert(std::map<int, QString>::value_type(0x3,("jal")));
        op_code.insert(std::map<int, QString>::value_type(0x4,("beq")));
        op_code.insert(std::map<int, QString>::value_type(0x5,("bne")));
        op_code.insert(std::map<int, QString>::value_type(0x23,("lw")));
        op_code.insert(std::map<int, QString>::value_type(0x2b,("sw")));

    for (int i=0;i<32;i++) regs_value[i]=0;
    ui->setupUi(this);
}

XH_mips::~XH_mips()
{
    delete ui;
}

void XH_mips::closeEvent(QCloseEvent *event)
//! [3] //! [4]
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void XH_mips::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
               tr("asmble Files (*.asm)"));
       curFile = fileName;
       if (!fileName.isEmpty()) {
           QFile file(fileName);
           if (!file.open(QIODevice::ReadOnly)) {
               QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
               return;
           }
           QTextStream in(&file);
           ui->textEdit->setText(in.readAll());
           file.close();
       }
}

void XH_mips::on_actionSave_triggered()
{
    QString fileName = curFile;
    if (!fileName.isEmpty()) {
           QFile file(fileName);

           if (!file.open(QIODevice::WriteOnly)) {
               // error message
           } else {
               QTextStream stream(&file);
               ui->textEdit->document()->setModified(false);
               stream << ui->textEdit->toPlainText();
               stream.flush();
               file.close();
           }
       }
    else on_actionSave_as_triggered();
}

void XH_mips::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
               tr("Text Files (*.asm)"));
       curFile = fileName;
       ui->textEdit->document()->setModified(false);
       if (!fileName.isEmpty()) {
           QFile file(fileName);
           if (!file.open(QIODevice::WriteOnly)) {
               // error message
           } else {
               QTextStream stream(&file);
               stream << ui->textEdit->toPlainText();
               stream.flush();
               file.close();
           }
       }
}

bool XH_mips::maybeSave()
{
    if (ui->textEdit->document()->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("mips"),
                     tr("The document has been modified.\n"
                        "Do you want to save your changes?"),
                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save){
            on_actionSave_triggered();
            return 1;
        }

        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}
//=============================编译=====================================================
//void XH_mips::getloop(QString scrs)
//{
//    res = scrs;
//    k = res.indexOf(":");
//    if (k!=-1)
//    {
//        tmp = res.split(":");
//        if (tmp.size()!=0) pc_loop.insert(std::map<QString, int>::value_type((tmp[0]), 4*linenum));
//    }

//}


QString XH_mips::pre_compile(QString scrs)//预处理 去掉注释和记录地址
{
    QString res;
    QStringList tmp;
    int k,j;
    QString s,t;
    res = scrs;

        j = res.indexOf("#");
        s = s.number(j,10);
        //ui->textBrowser->insertPlainText("//test ‘#’ "+s+"\n");
        if (j!=-1)
        {
            res = res.left(j);
        }
        j = res.indexOf("//");
        s = s.number(j,10);
        //ui->textBrowser->insertPlainText("//test ‘//’ "+s+"\n");
        if (j!=-1)
        {
            res = res.left(j);
        }
        //===========================
        //ui->textBrowser->insertPlainText("//after del # "+res[i]+"\n");
        k = res.indexOf(":");
        s = s.number(k,10);
        //ui->textBrowser->insertPlainText("//test ‘:’ "+s+"\n");
        if (k!=-1)
        {
            tmp = res.split(":");
            if (tmp.size()!=0) pc_loop.insert(std::map<QString, int>::value_type((tmp[0]), 4*linenum));
            res = res.right(res.length()-1-k);
        }
        j = linenum;
        t = t.number(j,10);
        //if (tmp.size()!=0) ui->textBrowser->insertPlainText("//test "+tmp[0]+" "+t+"\n");
        k=0;
        j=res.length()-1;
        while(res[k]==' '||res[k]=='\n'||res[k]==';') k++;
        while(res[j]==' '||res[j]=='\n'||res[j]==';') j--;
        res = res.mid(k,j-k+1);
        //ui->textBrowser->insertPlainText("//final "+res+"\n");
    return res;
}

//===============================汇编==============================
QString XH_mips::deal_codeline(QString scr,int base)
{
    QString tmps,op;
    QStringList words,items;
    std::map<QString, int>::iterator reg_num;
    std::map<QString, int>::iterator it;
    std::map<QString, int>::iterator loop;
    unsigned int imm;
    unsigned int ans;
    unsigned int num;
    QString s;
    int reg_rs,reg_rt,reg_rd;
    tmps = scr;
    ans = 0;
    //ui->textBrowser->insertPlainText("//txt "+scr+"\n");
    words = tmps.split(" ");
    if (words.size()<1) return ("error:1\n");
    op = words[0];
    if (words.size()>1) items = words[1].split(",");
    if (op == "srl")
        {
        if (items.size()<3) return ("error:in srl\n");
            ans += 2;
            reg_num = reg.find(items[0]);
            reg_rd = reg_num->second;
            if (reg_num != reg.end()) ans += reg_num->second << 11;
            reg_num = reg.find(items[1]);
            reg_rt = reg_num->second;
            if (reg_num != reg.end()) ans += reg_num->second << 16;
            ans += items[2].toLongLong(&ok,10) << 6;
            num = items[2].toLongLong(&ok,10);
            regs_value[reg_rd] = regs_value[reg_rt] >> num;

        }else
    if (op == "jr")
        {
            if (items.size()<1) return ("error:in srl\n");
            ans += 8;
            reg_num = reg.find(items[0]);
            if (reg_num != reg.end()) ans += reg_num->second << 21;
        }else
    if (op == "jalr")
        {
            if (items.size()<2) return ("error:in jalr\n");
            ans += 9;
            reg_num = reg.find(items[0]);
            if (reg_num != reg.end()) ans += reg_num->second << 21;
            reg_num = reg.find(items[1]);
            if (reg_num != reg.end()) ans += reg_num->second << 11;
        }else
    if (op == "eret")
        {
            ans = 0x42000018;
        }else
    if (op == "syscall")
        {
            ans = 0xc;
        }else
    if (op == "lw"||op == "sw")
        {
//            ui->textBrowser->insertPlainText("//test"+items[0]+"\n");
//            ui->textBrowser->insertPlainText("//test"+items[1]+"\n");
            if (items.size()<2) return ("error:in lw/sw\n");
            if (op == "lw") ans += 0x23 << 26;else ans += 0x2b << 26;
            reg_num = reg.find(items[0]);
            if (reg_num != reg.end()) ans += reg_num->second << 16;
            int off_indexl = items[1].indexOf("(");
            int off_indexr = items[1].indexOf(")");
            QString off = items[1].left(off_indexl);
            int offset = off.toLongLong(&ok,10);
            ans += offset;
            QString rs = items[1].mid(off_indexl+1,off_indexr-off_indexl-1);
            //ui->textBrowser->insertPlainText("//test"+rs+"\n");
            reg_num = reg.find(rs);
            if (reg_num != reg.end()) ans += reg_num->second << 21;
        }else
    if (op == "beq"||op == "bne")
        {
//            ui->textBrowser->insertPlainText("//test"+items[0]+"\n");
//            ui->textBrowser->insertPlainText("//test"+items[1]+"\n");
            if (items.size()<3) return ("error:in beq/bnq\n");
            if (op == "beq") ans += 4 << 26;else ans += 5 << 26;
            reg_num = reg.find(items[0]);
            if (reg_num != reg.end()) ans += reg_num->second << 21;
            reg_num = reg.find(items[1]);
            if (reg_num != reg.end()) ans += reg_num->second << 16;
            loop = pc_loop.find(items[2]);
            if (loop != pc_loop.end()) ans += (((loop->second - 4 - linenum*4) >> 2) + (1 << 16)) % (1 << 16);
        }else
    if (op == "lui")
        {
//            ui->textBrowser->insertPlainText("//test"+items[0]+"\n");
//            ui->textBrowser->insertPlainText("//test"+items[1]+"\n");
            if (items.size()<2) return ("error:in lui\n");
            ans += 0xf << 26;
            reg_num = reg.find(items[0]);
            reg_rt = reg_num->second;
            if (reg_num != reg.end()) ans += reg_num->second << 16;
            imm = items[1].toLongLong(&ok,10);
            ans +=imm;
            regs_value[reg_rt] = imm << 16;
        }else
    {
    //为r指令
    it = op_code_r.find(op);
    if (it != op_code_r.end())
        {
            if (items.size()<3) return ("error:in formate R\n");
            ans += it->second;
            reg_num = reg.find(items[0]);
            reg_rd = reg_num->second;
            if (reg_num != reg.end()) ans += reg_num->second << 11;
            reg_num = reg.find(items[1]);
            reg_rs = reg_num->second;
            if (reg_num != reg.end()) ans += reg_num->second << 21;
            reg_num = reg.find(items[2]);
            reg_rt = reg_num->second;
            if (reg_num != reg.end()) ans += reg_num->second << 16;
            if(op == "add")regs_value[reg_rd] = regs_value[reg_rs]+regs_value[reg_rt];
            else
                if(op == "sub")regs_value[reg_rd] = regs_value[reg_rs]-regs_value[reg_rt];
            else
                    if(op == "or")regs_value[reg_rd] = regs_value[reg_rs]|regs_value[reg_rt];
            else
                        if(op == "xor")regs_value[reg_rd] = regs_value[reg_rs]^regs_value[reg_rt];
            else
                            if(op == "nor")regs_value[reg_rd] = !(regs_value[reg_rs]|regs_value[reg_rt]);
            else
                                if(op == "and")regs_value[reg_rd] = regs_value[reg_rs]&regs_value[reg_rt];
            else
                                    if(op == "div")regs_value[reg_rd] = regs_value[reg_rs]/regs_value[reg_rt];
            else
                                       if(op == "mult")regs_value[reg_rd] = regs_value[reg_rs]*regs_value[reg_rt];
            else
                                           if(op == "slt")regs_value[reg_rd] = regs_value[reg_rs]<regs_value[reg_rt];

        }
    //为j指令
    it = op_code_j.find(op);
    if (it != op_code_j.end())
        {
            if (items.size()<1) return ("error:in formate J\n");
            ans += it->second << 26;
            loop = pc_loop.find(items[0]);
            QString test;
            test = test.number(loop->second,10);
            if (loop != pc_loop.end())
            {
                ans += (loop->second & 0xFFFFFFF) >> 2;
            }else return ("not find jump!");
        }
    //为i指令
    it = op_code_i.find(op);
    if (it != op_code_i.end())
        {
            if (items.size()<3) return ("error:in formate I\n");
            ans += it->second << 26;
            reg_num = reg.find(items[0]);
            reg_rt = reg_num->second;
            if (reg_num != reg.end()) ans += reg_num->second << 16;
            reg_num = reg.find(items[1]);
            reg_rs = reg_num->second;
            if (reg_num != reg.end()) ans += reg_num->second << 21;
            imm = items[2].toLongLong(&ok,10);
            ans +=imm;
            if(op == "addi")regs_value[reg_rt] = regs_value[reg_rs]+imm;
            else
                if(op == "andi")regs_value[reg_rt] = regs_value[reg_rs]&imm;
            else
                    if(op == "ori")regs_value[reg_rt] = regs_value[reg_rs]|imm;
            else
                        if(op == "xori")regs_value[reg_rt] = regs_value[reg_rs]^imm;
            else
                            if(op == "slti")regs_value[reg_rt] = (regs_value[reg_rs]<imm);

        }
    }


    if (base == 2)
    {
        tmps = tmps.number(ans,2);
        for (int i=tmps.length();i!=32;i++) tmps="0"+tmps;
    }
    else
    {
        tmps = tmps.number(ans,16);
        for (int i=tmps.length();i!=8;i++) tmps="0"+tmps;
    }
    return tmps;
}

//==============================反汇编==============================
QString XH_mips::biasm(QString src)
{
    QString op,rs,rt,rd,shamt,func,imm,addr,ans,offset,pc;
    QString test1;

    unsigned int opcode,funcode,rs_num,rt_num,rd_num,offset_num,pc_num;
    std::map<int, QString>::iterator it;
    //std::map<QString, int>::iterator funit;

    op = src.left(6);
    opcode = op.toLongLong(&ok,2);
    rs = src.mid(6,5);
    rs_num = rs.toLongLong(&ok,2);
    addr = src.mid(6,-1);
    addr = addr.number(addr.toLongLong(&ok,2),10);
    rt = src.mid(11,5);
    rt_num = rt.toLongLong(&ok,2);
    rd = src.mid(16,5);
    rd_num = rd.toLongLong(&ok,2);
    imm = src.mid(16);
    imm = imm.number(imm.toLongLong(&ok,2),10);
    shamt = src.mid(21,5);
    func = src.mid(26);
    funcode = func.toLongLong(&ok,2);
//    ui->textBrowser->insertPlainText("//test rs"+rs+"\n");
//test1=test1.number(funcode,10);
//    ui->textBrowser->insertPlainText("//test rt"+rt+"\n");
//    ui->textBrowser->insertPlainText("//test rd"+rd+"\n");
    //========R================
    if (opcode == 0)
    {
        it = fun_r.find(funcode);
        if (it != fun_r.end()) ans = it->second+" ";
        if (it->second =="jr")
        {
            it = b_reg.find(rs_num);
            if (it != b_reg.end()) ans = ans+it->second;
            return ans;
        }
        if (it->second =="jalr")
        {
            it = b_reg.find(rs_num);
            if (it != b_reg.end()) ans = ans+it->second;
            it = b_reg.find(rd_num);
            if (it != b_reg.end()) ans = ans+","+it->second;
            return ans;
        }
        if (it->second =="srl")
        {
            it = b_reg.find(rd_num);
            if (it != b_reg.end()) ans = ans+it->second;
            it = b_reg.find(rt_num);
            if (it != b_reg.end()) ans = ans+","+it->second;
            QString shamtnum;
            shamtnum = shamtnum.number(shamt.toLongLong(&ok,2),10);
            ans = ans+","+shamtnum;
            return ans;
        }
        it = b_reg.find(rd_num);
        if (it != b_reg.end()) ans = ans+it->second;
        it = b_reg.find(rs_num);
        if (it != b_reg.end()) ans = ans+","+it->second;
        it = b_reg.find(rt_num);
        if (it != b_reg.end()) ans = ans+","+it->second;
    }
    else
    {
        it = op_code.find(opcode);
        if (it != op_code.end()) ans = it->second+" ";
        if (it->second=="bne"||it->second=="beq")
        {
            offset = src.mid(16);
            if (offset[0]=='0')
            {
                offset_num = offset.toLongLong(&ok,2);
            }
            else
            {
                offset_num = 32768-(offset.mid(1)).toLongLong(&ok,2);
            }
            pc_num = offset_num;
            pc = pc.number(pc_num,10);

            it = b_reg.find(rt_num);
            if (it != b_reg.end()) ans = ans+it->second;
            it = b_reg.find(rs_num);
            if (it != b_reg.end()) ans = ans+","+it->second;
            ans = ans+","+pc;
            return ans;
        }
        if (it->second =="sw"||it->second =="lw")
        {
            it = b_reg.find(rt_num);
            if (it != b_reg.end()) ans = ans+it->second;
            offset = src.mid(16);
            offset_num = offset.toLongLong(&ok,2);
            offset = offset.number(offset_num,10);
            ans = ans+","+offset;
            it = b_reg.find(rs_num);
            if (it != b_reg.end()) ans = ans+"("+it->second;
            ans = ans+")";
            return ans;
        }
        if (it->second =="lui")
        {
            it = b_reg.find(rt_num);
            if (it != b_reg.end()) ans = ans+it->second;
            ans = ans+","+imm;
            return ans;
        }
        if (it->second!="j"&&it->second!="jal")
        {
            it = b_reg.find(rt_num);
            if (it != b_reg.end()) ans = ans+it->second;
            it = b_reg.find(rs_num);
            if (it != b_reg.end()) ans = ans+","+it->second;
            ans = ans+","+imm;
        }else
        {
            ans = ans+addr;
        }
    }
    return ans;

}

void XH_mips::deal_regs(QString codeline)
{
    return;
}

void XH_mips::on_actionBuild_triggered()
{
    QMessageBox::StandardButton ret;
    QString mes,mes2,test,linestop;
    int stopnum;
    mes = ui->comboBox->currentText();
    mes2 = ui->comboBox_2->currentText();
    linestop =ui->lineEdit->text();
    stopnum = linestop.toInt();
    std::map<int, QString>::iterator it;
    unsigned long long itr;
    //ui->textBrowser->insertPlainText(mes+"\n");
    if (linenum==-1)
    {
        codes = ui->textEdit->toPlainText();
        if (mes =="汇编代码") codelines = codes.split("\n",QString::SkipEmptyParts);else  codelines = codes.split(",",QString::SkipEmptyParts);
    }
    if (linenum < codelines.size()-1)
    {
        linenum++;
        Temp = codelines[linenum];
        if ((mes == "汇编代码"&&mes2 == "汇编代码")||(mes == "2进制"&&mes2=="2进制")||(mes=="16进制"&&mes2=="16进制"))
        {
            Temp = pre_compile(Temp);
            mipsline = Temp;
        }else
        if (mes=="汇编代码"&&mes2=="16进制")
        {
            Temp = pre_compile(Temp);
            mipsline = deal_codeline(Temp,16);
            deal_regs(Temp);
        }else
        if (mes=="汇编代码"&&mes2=="2进制")
        {
            Temp = pre_compile(Temp);
            mipsline = deal_codeline(Temp,2);
            deal_regs(Temp);
        }else
        if (mes=="16进制"&&mes2=="2进制")
        {
            Temp = pre_compile(Temp);
            itr = Temp.toLongLong(&ok,16);
            mipsline = mipsline.number(itr,2);
            //test = test.number(2351235108,10);
            //ui->textBrowser->insertPlainText("//test itr"+test+"\n");
            for (int i=mipsline.length();i!=32;i++) mipsline="0"+mipsline;
        }else
        if (mes=="2进制"&&mes2=="16进制")
        {
            Temp = pre_compile(Temp);
            itr = Temp.toLongLong(&ok,2);
            mipsline = mipsline.number(itr,16);
            for (int i=mipsline.length();i!=8;i++) mipsline="0"+mipsline;
        }else
        if (mes=="2进制"&&mes2=="汇编代码")
        {
            Temp = pre_compile(Temp);
            for (int i=Temp.length();i!=32;i++) Temp="0"+Temp;
            mipsline = biasm(Temp);
        }else
        if (mes=="16进制"&&mes2=="汇编代码")
        {
            Temp = pre_compile(Temp);
            itr = Temp.toLongLong(&ok,16);
            Temp = Temp.number(itr,2);
            for (int i=Temp.length();i!=32;i++) Temp="0"+Temp;
            //ui->textBrowser->insertPlainText("//test"+Temp+"\n");
            mipsline = biasm(Temp);
        }

        ui->textBrowser->insertPlainText(mipsline+"\n");
        for (int i=0;i<32;i++)
        {
            it=b_reg.find(i);
            if (it!=b_reg.end())
            {
                test = test.number(regs_value[i],10);
                ui->tableWidget->setItem(0,i,new QTableWidgetItem(it->second));
                ui->tableWidget->setItem(1,i,new QTableWidgetItem(test));
            }

        }


    }
    else
    {
        ret = QMessageBox::warning(this, tr("mips"),
                 tr("The document has been run over.\n"),
                   QMessageBox::Reset | QMessageBox::Cancel);
        if (ret == QMessageBox::Reset){
            linenum = -1;
            ui->textBrowser->setText("");
            for (int i=0;i<32;i++) regs_value[i]=0;
            pc_loop.clear();
        }
        return;
    }

}

void XH_mips::on_actionBuild_coe_triggered()
{
    unsigned long long itr,stopnum;
    QString rol_num,linestop;
    QString head,tail;
    head = "memory_initialization_radix=16;\r\nmemory_initialization_vector=\n";
    tail = ";";
    linestop =ui->lineEdit->text();
    if (linestop.size()!=0) stopnum = linestop.toInt(); else stopnum = 100000;
    pc_loop.clear();
    linenum = -1;
    ui->textBrowser->setText("");
    ui->textBrowser->insertPlainText(head);
    codes = ui->textEdit->toPlainText();
    QString mes,mes2;
    mes = ui->comboBox->currentText();
    mes2 = ui->comboBox_2->currentText();
     if (mes =="汇编代码") codelines = codes.split("\n",QString::SkipEmptyParts);else  codelines = codes.split(",",QString::SkipEmptyParts);
    for (linenum=0;linenum!=codelines.size();++linenum)
    {
        codelines[linenum] = pre_compile(codelines[linenum]);
    }
    for (linenum=0;linenum!=codelines.size();++linenum){
        Temp = codelines[linenum];
        if (linenum == stopnum) return;
        Temp = pre_compile(Temp);
        if ((mes == "汇编代码"&&mes2 == "汇编代码")||(mes == "2进制"&&mes2=="2进制")||(mes=="16进制"&&mes2=="16进制"))
        {
            mipsline = Temp;
        }else
        if (mes=="汇编代码"&&mes2=="16进制")
        {
            Temp = pre_compile(Temp);
            mipsline = deal_codeline(Temp,16);
            deal_regs(Temp);
        }else
        if (mes=="汇编代码"&&mes2=="2进制")
        {
            Temp = pre_compile(Temp);
            mipsline = deal_codeline(Temp,2);
            deal_regs(Temp);
        }else
        if (mes=="16进制"&&mes2=="2进制")
        {
            Temp = pre_compile(Temp);
            itr = Temp.toLongLong(&ok,16);
            mipsline = mipsline.number(itr,2);
            for (int i=mipsline.length();i!=32;i++) mipsline="0"+mipsline;
        }else
        if (mes=="2进制"&&mes2=="16进制")
        {
            Temp = pre_compile(Temp);
            itr = Temp.toLongLong(&ok,2);
            mipsline = mipsline.number(itr,16);
            for (int i=mipsline.length();i!=8;i++) mipsline="0"+mipsline;
        }else
        if (mes=="2进制"&&mes2=="汇编代码")
        {
            Temp = pre_compile(Temp);
            for (int i=Temp.length();i!=32;i++) Temp="0"+Temp;
            mipsline = biasm(Temp);
        }else
        if (mes=="16进制"&&mes2=="汇编代码")
        {
            Temp = pre_compile(Temp);
            itr = Temp.toLongLong(&ok,16);
            Temp = Temp.number(itr,2);
            for (int i=Temp.length();i!=32;i++) Temp="0"+Temp;
            //ui->textBrowser->insertPlainText("//test"+Temp+"\n");
            mipsline = biasm(Temp);
        }
        rol_num = rol_num.number(linenum,10);
        if (mes2=="16进制")
            if (linenum < codelines.size())
                ui->textBrowser->insertPlainText(mipsline+",\n");
            else
                ui->textBrowser->insertPlainText(mipsline);
        else
            ui->textBrowser->insertPlainText(mipsline+";\n");
    }
    ui->textBrowser->insertPlainText(tail);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
               tr("CEO (*.coe)"));
       if (!fileName.isEmpty())
       {
           QFile file(fileName);
           if (!file.open(QIODevice::WriteOnly))
           {
               // error message
           }
           else
           {
               QTextStream stream(&file);
               stream << ui->textBrowser->toPlainText();
               stream.flush();
               file.close();
           }
        }
       linenum = -1;
}
