#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

namespace Qt3DExtras{
    class Qt3DWindow;
};
class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

signals:

public slots:

private:
    Qt3DExtras::Qt3DWindow*          _view;
};

#endif // VIEW_H
