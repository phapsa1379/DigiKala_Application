#include "StarDelegate.h"
#include "StarRating.h"
#include "StarEditor.h"
#include "DetailOfAllProducts.h"
#include "DetailOfBoughtProducts.h"
#include "DetailOfOnSaleProducts.h"
#include "AddProduct1.h"
#include "Global.h"
#include "DetailOfFavoriteProducts.h"
using namespace GlobalNameSpace;


bool StarDelegate::editorEvent(
        QEvent* event,
        QAbstractItemModel* model,
        const QStyleOptionViewItem& option,
        const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        Globals::KEY_PRODUCT = Globals::DELEGATED_VECTOR_PRODUCT[index.row()].getKey();

        if (Globals::TARGET_PRODUCT_LIST == ALL_SYSTEM_PRODUCTS){
            DetailOfAllProducts *d = new DetailOfAllProducts();
            d->setModal(true);
            d->show();
        }
        else if(Globals::TARGET_PRODUCT_LIST == MY_SELL_PRODUCTS){
            DetailOfOnSaleProducts *d = new DetailOfOnSaleProducts();
            d->setModal(true);
            d->show();
        }
        else if(Globals::TARGET_PRODUCT_LIST == MY_BOUGHT_PRODUCTS){
            DetailOfBoughtProducts *d = new DetailOfBoughtProducts();
            d->setModal(true);
            d->show();
        }
        else if(Globals::TARGET_PRODUCT_LIST == MY_FAVORITE_PRODUCTS){
            DetailOfFavoriteProducts *d = new DetailOfFavoriteProducts();
            d->setModal(true);
            d->show();            
        }

        return true;
    }

    return false;
}


void StarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    if (index.data().canConvert<StarRating>()) {
        StarRating starRating = qvariant_cast<StarRating>(index.data());

        if (option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, option.palette.highlight());

        starRating.paint(painter, option.rect, option.palette,
                         StarRating::EditMode::ReadOnly);
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}


QWidget *StarDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const

{
    if (index.data().canConvert<StarRating>()) {
        StarEditor *editor = new StarEditor(parent);
        connect(editor, &StarEditor::editingFinished,
                this, &StarDelegate::commitAndCloseEditor);
        return editor;
    }
    return QStyledItemDelegate::createEditor(parent, option, index);
}


void StarDelegate::commitAndCloseEditor()
{
    StarEditor *editor = qobject_cast<StarEditor *>(sender());
    emit commitData(editor);
    emit closeEditor(editor);
}



void StarDelegate::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const
{
    if (index.data().canConvert<StarRating>()) {
        StarRating starRating = qvariant_cast<StarRating>(index.data());
        StarEditor *starEditor = qobject_cast<StarEditor *>(editor);
        starEditor->setStarRating(starRating);
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}



void StarDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                const QModelIndex &index) const
{
    if (index.data().canConvert<StarRating>()) {
        StarEditor *starEditor = qobject_cast<StarEditor *>(editor);
        model->setData(index, QVariant::fromValue(starEditor->starRating()));
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}



QSize StarDelegate::sizeHint(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    if (index.data().canConvert<StarRating>()) {
        StarRating starRating = qvariant_cast<StarRating>(index.data());
        return starRating.sizeHint();
    }
    return QStyledItemDelegate::sizeHint(option, index);
}
