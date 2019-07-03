#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

namespace Qt3DExtras {
    class Qt3DWindow;
};
namespace Qt3DCore {
    class QEntity;
};
class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

signals:

public slots:
    void                            setCamPersp();
    void                            setCamFront();
    void                            setCamTop();
    void                            setCamLeft();

private:
    void                            addTorusTo(Qt3DCore::QEntity *entity);
    void                            addConeTo(Qt3DCore::QEntity *entity);
    Qt3DExtras::Qt3DWindow          *_view;
    Qt3DCore::QEntity               *_root;
};

#endif // VIEW_H
