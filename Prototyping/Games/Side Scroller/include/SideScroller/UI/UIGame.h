#pragma once

#include <QDebug>
#include <QKeyEvent>
#include <memory>

#include "IUIGame.h"
#include "UIFrame.h"
#include "UILevel.h"

namespace SideScroller {

    class UIGame : public IUIGame {
        UIFrame                  _frame{this};
        std::unique_ptr<UILevel> _levelUI;
        double                   _viewportWidth = 500;

    public:
        UIGame(int& argc, char** argv) : IUIGame(argc, argv) {
            _frame.GetViewport()->OnKeyPress([this](QKeyEvent* event) { OnKeyPress(event); });
        }

    private:
        void OnKeyPress(QKeyEvent* event) {
            switch (event->key()) {
                case Qt::Key_Escape:
                    _frame.close();
                    break;
                case Qt::Key_A:
                    _levelUI->GetPlayer()->MoveLeft();
                    break;
                case Qt::Key_D:
                    _levelUI->GetPlayer()->MoveRight();
                    break;
                case Qt::Key_Space:
                    _levelUI->GetPlayer()->Jump();
                    break;
                default:
                    break;
            }
        }

    public:
        void LoadLevel(const Level& level) override {
            _levelUI = std::make_unique<UILevel>(this);
            _levelUI->LoadLevel(level);

            _frame.SetLevelUI(_levelUI.get());
            _frame.SetViewportWidth(_viewportWidth);
            _frame.setWindowTitle(level.name.c_str());
            qDebug() << "Frame Level size: " << level.width << "x" << level.height;
            _frame.setFixedSize(_viewportWidth + 10, level.height + 10);
            _frame.show();
        }
    };
}
