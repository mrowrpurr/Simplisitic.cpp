#pragma once

#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>

//
#include <QPushButton>
#include <functional>

namespace Simp1e::Editor {

    class LogoWindow : public QWidget {
        QVBoxLayout* _layout;
        QPixmap      _pixmap_Logo{":/logo.png"};
        QLabel       _label_Logo;
        QLabel       _label_Title{"Simp1e"};

        //
        QPushButton           _btn_DoStuff{"Do Stuff"};
        std::function<void()> _onDoStuff;

    public:
        LogoWindow(QWidget* parent = nullptr) {
            IDs();
            Classes();
            Layout();
            Styles();
            Events();
        }

        void OnDoStuff(std::function<void()> onDoStuff) { _onDoStuff = onDoStuff; }

    private:
        void IDs() { setObjectName("LogoWindow"); }

        void Classes() {
            _label_Logo.setProperty("class", "image");
            _label_Title.setProperty("class", "title");
        }

        void Layout() {
            _layout = new QVBoxLayout(this);
            _layout->addWidget(&_label_Logo, 0, Qt::AlignCenter);
            _layout->addWidget(&_label_Title, 0, Qt::AlignCenter);
            _layout->addWidget(&_btn_DoStuff, 0, Qt::AlignCenter);
        }

        void Styles() {
            _label_Logo.setScaledContents(true);
            _label_Logo.setPixmap(_pixmap_Logo);
        }

        void Events() {
            QObject::connect(&_btn_DoStuff, &QPushButton::clicked, [this]() { _onDoStuff(); });
        }
    };
}
