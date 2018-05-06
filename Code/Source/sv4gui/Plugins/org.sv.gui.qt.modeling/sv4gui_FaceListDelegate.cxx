/* Copyright (c) Stanford University, The Regents of the University of
 *               California, and others.
 *
 * All Rights Reserved.
 *
 * See Copyright-SimVascular.txt for additional details.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "sv4gui_FaceListDelegate.h"

sv4guiFaceListDelegate::sv4guiFaceListDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}

QWidget* sv4guiFaceListDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int column=index.column();

    switch(column){
    case 2:
    {
        QComboBox* cb=new QComboBox(parent);
        cb->addItem("wall");
//        cb->addItem("inlet");
//        cb->addItem("outlet");
        cb->addItem("cap");

        return cb;
    }
    case 5:
    {
        QDoubleSpinBox* dsb=new QDoubleSpinBox(parent);
        dsb->setMinimum(0);
        dsb->setMaximum(1.0);
        dsb->setDecimals(2);
        dsb->setSingleStep(0.2);
        return dsb;
    }
    default:
        return new QWidget(parent);
    }
}

void sv4guiFaceListDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int column=index.column();

    switch(column){
    case 2:
    {
        QComboBox* cb=dynamic_cast<QComboBox*>(editor);
        if(cb)
        {
            QString type=index.model()->data(index, Qt::EditRole).toString();
            cb->setCurrentText(type);
        }
    }
        break;
    case 5:
    {
        QDoubleSpinBox* dsb=dynamic_cast<QDoubleSpinBox*>(editor);
        if(dsb)
        {
            double value=index.model()->data(index, Qt::EditRole).toDouble();
            dsb->setValue(value);
        }
    }
        break;
    default:
        break;
    }
}

void sv4guiFaceListDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    int column=index.column();

    switch(column){
    case 2:
    {
        QComboBox* cb=dynamic_cast<QComboBox*>(editor);
        if(cb)
        {
            model->setData(index, cb->currentText(), Qt::EditRole);
        }
    }
        break;
    case 5:
    {
        QDoubleSpinBox* dsb=dynamic_cast<QDoubleSpinBox*>(editor);
        if(dsb)
        {
            dsb->interpretText();
            double value = dsb->value();
            model->setData(index, value, Qt::EditRole);
        }
    }
        break;
    default:
        break;
    }
}

void sv4guiFaceListDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int column=index.column();

    switch(column){
    case 2:
    {
        QComboBox* cb=dynamic_cast<QComboBox*>(editor);
        if(cb)
        {
            editor->setGeometry(option.rect);
        }
    }
        break;
    case 5:
    {
        QDoubleSpinBox* dsb=dynamic_cast<QDoubleSpinBox*>(editor);
        if(dsb)
        {
            editor->setGeometry(option.rect);
        }
    }
        break;
    default:
        break;
    }


}
