#pragma once

#include "comparator.h"
#include "kernel/communication/commands.h"
#include <QWidget>

namespace Ui {
class FriendWidget;
}

using namespace std;
using namespace communication;

class FriendWidget : public Comparator
{
    Q_OBJECT

public:
    explicit FriendWidget(QWidget *parent = 0);
    ~FriendWidget();

    const data::FriendItem& properties() const {return _properties;}
    void setProperties(const data::FriendItem&);

    bool lessThan(Comparator*) const override;

private:
    void setAvatar(QPixmap avatar, bool roundCorner);

private:
    Ui::FriendWidget *ui;
    data::FriendItem _properties;
};
