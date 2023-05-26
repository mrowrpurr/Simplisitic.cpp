#include <QApplication>
#include <QGraphicsView>

#include "Prototyping/GameCircleCube.h"
#include "Prototyping/QtGameCircleCubeScene.h"

using namespace Prototyping;

int main(int argc, char* argv[]) {
    QApplication app{argc, argv};

    GameCircleCube game{10, 10};
    QGraphicsView  view;

    QtGameCircleCubeSceneParams sceneParams = {
        .tileWidth       = 50,
        .tileHeight      = 50,
        .circleSize      = 20,
        .cubeSize        = 25,
        .renderGridLines = true,
    };
    QtGameCircleCubeScene scene(game, sceneParams);

    view.setScene(&scene);
    view.show();

    return app.exec();
}
